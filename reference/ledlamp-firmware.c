//
// Atmega code for three-color LED lamp
// Author: Thomas Driemeyer, 9.9.2006. This code is licensed under the GPL.
//
// Atmel pinout:
//	pc0: out, red LED, 0=on
//	pc1: out, green LED, 0=on
//	pc2: out, blue LED, 0=on
//	pc3: out, buzzer, 0=on
//	pc4: in, key0
//	pc5, in, key1
//
// serial commands: line begins with '=' and ends with \r or \n. Blanks are
// ignored, all numbers are hex 0..f or 0..F. Max 80 chars. 9600 baud, 8 bits,
// no parity.
//
//	+ 0		start action 0..f
//
//	- 0		stop action 0..f
//
//	= 0		define action 0..f, followed by zero or more of:
//	  p 0000	pattern: show fg color if 1, or bg color if 0
//	  s 0000	speed: duration of one bit in 10 ms units
//	  l 00		length: # of bits, first 16 are from pattern, rest is 0
//	  o 00		override length: # of bits where this color replaces
//	  r 00		repeat, 00=infinite, 01..ff = # of repetitions
//	  f 000000	fg color: rrggbb, each 00..3f = dark..full brightness
//	  b 000000	bg color: rrggbb, each 00..3f = dark..full brightness
//	  S		soft, fades between fg and bg colors
//	  H		hard, switches between fg and bg colors
//	  C		clear action, set all fields to 0
//	  A		activate immediately
//
// An "action" is a single color stream, consisting of a foreground (on) and
// background (off) color. 16 such actions can be defined; higher ones can
// override (replace) lower ones, or just blend with them.
//
// One tick is 10 ms. Speed determines how many ticks are one time unit for an
// action, and length is the number of time units before an action expires or
// repeats. It can run forever (r=0), once (r=1), or up to 255 times. The
// pattern controls whether the foreground or background color is shown: if
// bit 0 of the pattern is 0, the first time unit shows the background color;
// if it is 1, the foreground color is shown. Only the first 16 time units can
// be controlled; all later units are implicitly 0. For example, a pattern 0x5
// has two bits set, so the foreground color flashes twice (if the length is
// at least 3).
//
// The override length controls whether the action's colors replace the colors
// from lower actions, or are blended in. For example, to flash red twice, it's
// not enough to set the pattern to 0x5, the length to 3, and the fg color to
// red, because the some lower action might show green, so our red would look
// yellow (green + red). Instead, set the pattern to 0x0a and the override
// length to 5, giving an off-on-off-on-off sequence during which the lower
// actions are overwritten. The length can be much longer than the override.
//

#include <avr/io.h>
#include <inttypes.h>
#define F_CPU 1000000UL  // 1 MHz
#include <util/delay.h>
#include <avr/interrupt.h>

typedef unsigned char	uchar;
typedef unsigned short	ushort;
typedef unsigned char	bool;
#define true  1
#define false 0


//
// describes a color action. d_ fields are defined by the user, and i_ fields
// are manipulated during interrupts to keep track of timing.
//

typedef struct {
    ushort	d_pattern;	// bit0..f cycle, 0->f->length->0, 1=on;0000=off
    ushort	d_speed;	// duration of one tick in 20ms units
    uchar	d_length;	// action ticks between pattern repetitions
    uchar	d_override;	// override length: suppress lower action color
    uchar	d_repeat;	// repeat this many times, 0=forever
    uchar	d_color0[3];	// RGB if pattern bit is 0, 0=off, 16=full on
    uchar	d_color1[3];	// RGB if pattern bit is 1, 0=off, 16=full on
    bool	d_soft;		// interpolate between colors 0 and 1
    bool	d_blend;	// if pattern bit is 1, don't replace, blend

    ushort	i_speed;	// counts 0..d_speed, next tick if == d_speed
    ushort	i_ticks;	// next pattern bit 0..15, >15 is in length
    uchar	i_repeat;	// # of times pattern has repeated, sticky @255
    bool	i_on_now;	// currently showing color1
    bool	i_on_next;	// next showing color1 when i_repeat expires
    bool	i_ov_now;	// does i_color overwrite lower action colors?
    bool	i_ov_next;	// next override now (for i_on_next)
    bool	i_active;	// doing anything?
    uchar	i_color[3];	// current color
} Action;


#define NACTIONS 16
Action	action[NACTIONS];	// instructions
ushort	irq_count;		// continuously counts up every 1/4 ms
uchar	curr_color[3];		// currently shown RGB color, 0=off, 32=full on
uchar	next_color[3];		// next color to show after 32 interrupts
bool	need_next;		// IRQ has copied next -> curr, calc new next
uchar	serial_buf[80];		// incoming command buffer
uchar	serial_len;		// number of valid chars in command buffer


//------------------------------------- interrupts ----------------------------

//
// timer interrupt handler. Can't show more than 64 brightness levels because
// the lamp would flicker. A 64-interrupt run takes 10 ms.
//

ISR(TIMER1_COMPA_vect)
{
    // pulse LEDs, using the low 6 bits of irq_count. Dark LEDs turn off at
    // count 0, and full on LEDs turn off at count 64 (never because 64 is max)
    int count = irq_count & 63;
    if (count >= curr_color[0]) PORTC |= 1<<PC0; else PORTC &= ~(1<<PC0);
    if (count >= curr_color[1]) PORTC |= 1<<PC1; else PORTC &= ~(1<<PC1);
    if (count >= curr_color[2]) PORTC |= 1<<PC2; else PORTC &= ~(1<<PC2);

    // got the color fully displayed, use next and ask for another next
    if (++irq_count >= 128) {
	curr_color[0] = next_color[0];
	curr_color[1] = next_color[1];
	curr_color[2] = next_color[2];
	irq_count = 0;
	need_next = true;
    }
}


//
// calculate the next color to display. Call this after every 64 interrupts.
// But not in the interrupt handler because it takes a little over a milli-
// second to execute, so it would eat interrupts and cause the lamp to flicker.
//

void recalculate(void)
{
    int a;
    Action *ap;

    for (a=0; a < NACTIONS; a++) {
	// at start of pattern bit duration interval: calculate this and next
	// on/off status. Tick is the bit counter, first 16 are in pattern.
	ap = &action[a];
	if (!ap->i_active)
	    continue;
	if (!ap->i_speed) {
	    ap->i_on_now  = ap->i_on_next;
	    ap->i_on_next = ap->i_ticks < 16 &&
			   (ap->d_pattern & (1<<ap->i_ticks)) != 0;

	    ap->i_ov_now  = ap->i_ov_next;
	    ap->i_ov_next = ap->i_ticks < ap->d_override;
	    if (++ap->i_ticks >= ap->d_length) {
		ap->i_ticks = 0;
		if (!++ap->i_repeat)
		    ap->i_repeat = 255;
		if (ap->d_repeat && ap->i_repeat >= ap->d_repeat) {
		    ap->i_active = false;
		    continue;
		}
	    }
	}

	// inside the interval, interpolate or select color 0 and color 1
	ushort fade;
	if (ap->d_soft) {
	    if (!ap->i_on_now && !ap->i_on_next)	// off->off: color 0
		fade = 0;

	    else if (ap->i_on_now && ap->i_on_next)	// on->on: color 1
		fade = 256;

	    else if (!ap->i_on_now && ap->i_on_next)	// off->on: color 0->1
		fade = 256 * ap->i_speed / ap->d_speed;

	    else					// on->off: color 1->0
		fade = 256 - (256 * ap->i_speed / ap->d_speed);
	} else
		fade = ap->i_on_now ? 256 : 0;

	// compute the color
	ushort omf = 256 - fade;
	ap->i_color[0] = (omf * ap->d_color0[0] + fade * ap->d_color1[0]) >> 8;
	ap->i_color[1] = (omf * ap->d_color0[1] + fade * ap->d_color1[1]) >> 8;
	ap->i_color[2] = (omf * ap->d_color0[2] + fade * ap->d_color1[2]) >> 8;

	// at end of pattern bit duration interval: increment repetition and
	// begin a new pattern bit duration interval
	if (++ap->i_speed >= ap->d_speed)
	    ap->i_speed = 0;
    }

    // merge actions to arrive at the current color
    next_color[0] = next_color[1] = next_color[2] = 0;
    for (a=0; a < NACTIONS; a++) {
	ap = &action[a];
	if (ap->i_active && ap->d_pattern) {
	    if (ap->i_ov_now) {
		next_color[0] = ap->i_color[0];
		next_color[1] = ap->i_color[1];
		next_color[2] = ap->i_color[2];
	    } else {
		if (next_color[0] < ap->i_color[0])
		    next_color[0] = ap->i_color[0];
		if (next_color[1] < ap->i_color[1])
		    next_color[1] = ap->i_color[1];
		if (next_color[2] < ap->i_color[2])
		    next_color[2] = ap->i_color[2];
	    }
	}
    }
}


//------------------------------------- main helpers --------------------------

//
// have completed setting up an action, start it rolling at the beginning
//

void start_action(
    int		a)		// start this action
{
    Action *ap = &action[a];
    ap->i_speed    = 0;
    ap->i_ticks    = 0;
    ap->i_repeat   = 0;
    ap->i_on_now   = false;
    ap->i_on_next  = false;
    ap->i_ov_now   = false;
    ap->i_ov_next  = false;
    ap->i_color[0] = 0;
    ap->i_color[1] = 0;
    ap->i_color[2] = 0;
    ap->i_active   = true;
}


//
// stop an action
//

void stop_action(
    int		a)		// start this action
{
    action[a].i_active = false;
}


//
// convert hexadecimal number string (4, 8, or 16 bits) to unsigned integer.
// subfunctions of the command parser below.
//

uchar get_hex4(
    uchar	*p)		// convert this hex string to unsigned integer
{
    return (*p > '9' ? *p - 'A' + 10 : *p - '0') & 15;
}


uchar get_hex8(
    uchar	*p)		// convert this hex string to unsigned integer
{
    return (get_hex4(p) << 4) + get_hex4(p+1);
}


ushort get_hex16(
    uchar	*p)		// convert this hex string to unsigned integer
{
    return (get_hex8(p) << 8) + get_hex8(p+2);
}


//
// received a command line from the serial interface. Parse and execute.
//

void parse_serial(void)
{
    int a = (serial_buf[1] - '0');
    if (a >= NACTIONS) a = 0;
    Action *ap = &action[a];

    switch(serial_buf[0]) {
      case '+':					// command '+': start action
	    start_action(a);
	    return;

      case '-':					// command '-': stop action
	    stop_action(a);
	    return;

      case '=':					// command '=': define action
	    ap->i_active = false;		// deactivate redefined action
	    uchar i = 2;
	    while (i < serial_len)
		switch(serial_buf[i++]) {
		  case 'p':			// p 0000   = pattern
			ap->d_pattern = get_hex16(serial_buf+i);
			i += 4;
			break;
		  case 's':			// s 0000   = speed
			ap->d_speed = get_hex16(serial_buf+i);
			i += 4;
			break;
		  case 'l':			// l 00     = length
			ap->d_length = get_hex8(serial_buf+i);
			i += 2;
		  case 'o':			// o 00     = override length
			ap->d_override = get_hex8(serial_buf+i);
			i += 2;
			break;
		  case 'r':			// r 00     = repeat
			ap->d_repeat = get_hex8(serial_buf+i);
			i += 2;
			break;
		  case 'f':			// f 000000 = fg color
			ap->d_color1[0] = get_hex8(serial_buf+i);
			ap->d_color1[1] = get_hex8(serial_buf+i+2);
			ap->d_color1[2] = get_hex8(serial_buf+i+4);
			i += 6;
			break;
		  case 'b':			// b 000000 = bg color
			ap->d_color0[0] = get_hex8(serial_buf+i);
			ap->d_color0[1] = get_hex8(serial_buf+i+2);
			ap->d_color0[2] = get_hex8(serial_buf+i+4);
			i += 6;
			break;
		  case 'S':			// S        = soft
			ap->d_soft = true;
			break;
		  case 'H':			// H        = hard
			ap->d_soft = false;
			break;
		  case 'C':			// C        = clear
			{int j;
			for (j=0; j < sizeof(Action); j++)
			    ((char *)ap)[i] = 0;
			break;}
		  case 'A':			// A        = activate
			start_action(a);
		}
    }
}


//
// set some pretty default actions at startup, and activate 0..4
//

void set_default_actions(void)
{
#define SPEED 50
    action[0].d_pattern		= 0x003;	// red
    action[0].d_length		= 10;
    action[0].d_speed		= SPEED;
    action[0].d_repeat		= 0;
    action[0].d_color0[0]	= 0;
    action[0].d_color0[1]	= 0;
    action[0].d_color0[2]	= 0;
    action[0].d_color1[0]	= 64;
    action[0].d_color1[1]	= 0;
    action[0].d_color1[2]	= 0;
    action[0].d_soft		= true;

    action[1].d_pattern		= 0x00c;	// green
    action[1].d_length		= 10;
    action[1].d_speed		= SPEED;
    action[1].d_repeat		= 0;
    action[1].d_color0[0]	= 0;
    action[1].d_color0[1]	= 0;
    action[1].d_color0[2]	= 0;
    action[1].d_color1[0]	= 0;
    action[1].d_color1[1]	= 64;
    action[1].d_color1[2]	= 0;
    action[1].d_soft		= true;

    action[2].d_pattern		= 0x030;	// magenta
    action[2].d_length		= 10;
    action[2].d_speed		= SPEED;
    action[2].d_repeat		= 0;
    action[2].d_color0[0]	= 0;
    action[2].d_color0[1]	= 0;
    action[2].d_color0[2]	= 0;
    action[2].d_color1[0]	= 64;
    action[2].d_color1[1]	= 0;
    action[2].d_color1[2]	= 48;
    action[2].d_soft		= true;

    action[3].d_pattern		= 0x0c0;	// yellow
    action[3].d_length		= 10;
    action[3].d_speed		= SPEED;
    action[3].d_repeat		= 0;
    action[3].d_color0[0]	= 0;
    action[3].d_color0[1]	= 0;
    action[3].d_color0[2]	= 0;
    action[3].d_color1[0]	= 64;
    action[3].d_color1[1]	= 20;
    action[3].d_color1[2]	= 0;
    action[3].d_soft		= true;

    action[4].d_pattern		= 0x300;	// blue
    action[4].d_length		= 10;
    action[4].d_speed		= SPEED;
    action[4].d_repeat		= 0;
    action[4].d_color0[0]	= 0;
    action[4].d_color0[1]	= 0;
    action[4].d_color0[2]	= 0;
    action[4].d_color1[0]	= 0;
    action[4].d_color1[1]	= 0;
    action[4].d_color1[2]	= 64;
    action[4].d_soft		= true;

    action[5].d_pattern		= 0x2aa;	// five fast white flashes
    action[5].d_length		= 11;
    action[5].d_override	= 11;
    action[5].d_speed		= 2;
    action[5].d_repeat		= 1;
    action[5].d_color0[0]	= 0;
    action[5].d_color0[1]	= 5;
    action[5].d_color0[2]	= 0;
    action[5].d_color1[0]	= 64;
    action[5].d_color1[1]	= 64;
    action[5].d_color1[2]	= 64;
    action[5].d_soft		= false;

    action[6].d_pattern		= 0x2a;		// red triple pulses for 5 min
    action[6].d_length		= 32;
    action[6].d_override	= 7;
    action[6].d_speed		= 10;
    action[6].d_repeat		= 46;
    action[6].d_color0[0]	= 0;
    action[6].d_color0[1]	= 0;
    action[6].d_color0[2]	= 0;
    action[6].d_color1[0]	= 64;
    action[6].d_color1[1]	= 0;
    action[6].d_color1[2]	= 0;
    action[6].d_soft		= false;

    action[7].d_pattern		= 0x5555;	// red/blue flashing forever
    action[7].d_length		= 16;
    action[7].d_override	= 16;
    action[7].d_speed		= 4;
    action[7].d_repeat		= 0;
    action[7].d_color0[0]	= 64;
    action[7].d_color0[1]	= 0;
    action[7].d_color0[2]	= 0;
    action[7].d_color1[0]	= 0;
    action[7].d_color1[1]	= 0;
    action[7].d_color1[2]	= 64;
    action[7].d_soft		= true;

    action[8].d_pattern		= 0x55;		// blue flashing, 1 min
    action[8].d_length		= 8;
    action[8].d_override	= 2;
    action[8].d_speed		= 2;
    action[8].d_repeat		= 185;
    action[8].d_color0[0]	= 64;
    action[8].d_color0[1]	= 0;
    action[8].d_color0[2]	= 0;
    action[8].d_color1[0]	= 0;
    action[8].d_color1[1]	= 0;
    action[8].d_color1[2]	= 0;
    action[8].d_soft		= false;

    action[9].d_pattern		= 0x55;		// red flashing, 1 min
    action[9].d_length		= 8;
    action[9].d_override	= 8;
    action[9].d_speed		= 2;
    action[9].d_repeat		= 185;
    action[9].d_color0[0]	= 0;
    action[9].d_color0[1]	= 0;
    action[9].d_color0[2]	= 64;
    action[9].d_color1[0]	= 0;
    action[9].d_color1[1]	= 0;
    action[9].d_color1[2]	= 0;
    action[9].d_soft		= false;

    start_action(0);
    start_action(1);
    start_action(2);
    start_action(3);
    start_action(4);
}


//------------------------------------- main ----------------------------------

int main(void)
{
    DDRC  = 0x3f;	// data direction
    PORTC = 0x3f;	// LEDs and buzzer off

    // timer 1 ctrl: 7654=0000 (no pins), 32=00 (no irq), 10=00 (ocr1a cmp)
    TCCR1A = 0;
    // timer 1 ctrl: 76=00 (no pin), 43=01 (ocr1a cmp), 210=001 (no prescaler)
    TCCR1B = (1<<WGM12) | (1<<CS10);
    // timer comparison, less than 150 is too fast for this CPU. 156 = 10/64 ms
    OCR1A = 156;
    // enable timer 1 output compare A match
    TIMSK = 1<<OCIE1A;

    // uart: U2X=1 and UBRR=0,12 means 9600 baud. With a 1-MHz clock, this is
    // the highest reliable speed supported by Atmega chips (see spec p. 156).
    UBRRH = 0;					// 9600 baud (if U2X=1)
    UBRRL = 12;
    UCSRA = (1<<U2X);				// double-speed baudrate set
    UCSRB = (1<<RXEN) | (1<<TXEN);		// enable receiver&transmitter
    UCSRC = (1<<URSEL) | (3<<UCSZ0);		// frame format: 8 data, 1 stop

    char *p = (char *)action;			// clear all actions, dark
    int i;
    for (i=0; i < sizeof(action); i++)
	p[i] = 0;

    set_default_actions();			// some interesting defaults

    serial_len = 0;				// prime serial command buffer

    sei();					// enable timer interrupts

    for (;;) {					// event loop
	if (need_next) {				// bit is done, do next
	    recalculate();
	    need_next = false;
	}
	if (UCSRA & (1<<RXC)) {				// serial byte received
	    uchar data = UDR;				// fetch byte from host
	    if (serial_len == 0) {			// first char:
		if (data != '=' &&			//   = define action
		    data != '+' &&			//   + start action
		    data != '-')			//   - stop action
			data = '?';
		else
		    serial_buf[serial_len++] = data;
	    } else {					// following char:
		if (data == '\t' || data == ' ')	// skip whitespace
		    ;
		else if (data == '\n' ||		// newline: parse cmd
			 data == '\r') {
		    serial_buf[serial_len] = 0;
		    parse_serial();
		    serial_len = 0;
		} else					// other char: store
		    if (serial_len > sizeof(serial_buf)-2)
			data = '?';
		    else
			serial_buf[serial_len++] = data;
	    }
	    while (!(UCSRA & (1<<UDRE)));		// wait for tx ready
	    UDR = data;					// echo byte
	}
    }
    return 0;
}
