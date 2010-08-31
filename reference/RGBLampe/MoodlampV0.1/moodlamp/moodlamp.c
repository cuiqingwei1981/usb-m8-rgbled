/*
		moodlamp.c
		
		This software belongs to the Moddlamp project that can be found at http://www.blinkenlichts.net/
		
		Target MC: ATmega8-16AI @ 12MHz
		Compiler version: avr-gcc 3.4.6 (Winavr)
		
		This software is licensed under the GNU GPL Version 2.
		2006 Tobias Schneider
		
		This software uses code from Fly and Benedikt K.
		(see http://www.mikrocontroller.net/topic/54561)
		
		The softuart library is provided by Martin Thomas
		(see http://www.siwawi.arubi.uni-kl.de/avr_projects)
		
		The USART library is provided by Peter Fleury
		(see http://homepage.hispeed.ch/peterfleury/index.html)
		
		
		Version 0.1:	Initial release
*/


#include <stdlib.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/eeprom.h>
#include <stdio.h>

#include "uart.h"
#include "softuart.h"


/*
Explanation of the HSV color space:

H:          Hue, the color type (such as red, blue, or yellow)
S:			Saturation, the "vibrancy" of the color
V:			Value, the brightness of the color

Scaling of the HSV values:
H:			0-255, 0=red, 42=yellow, 85=green, 128=turquoise, 171=blue, 214=purple
S:			0-255, 0=white, 255=pure colors
V:			0-255, 0=off, 255=maximum brightness

From http://en.wikipedia.org/wiki/HSV_color_space and the source code from Benedikt K.(http://www.mikrocontroller.net/topic/54561#433279)
*/

typedef struct {
	unsigned char r;
	unsigned char g;
	unsigned char b;
} RGB;


#define     Ledport             PORTC		// RGB Led Port
#define     DDR_Ledport         DDRC
#define     R_PIN               0			// R Output
#define     G_PIN               1			// G
#define     B_PIN               2			// B
#define		INVERT				1			// Output low active ?

//#define		Time				1			// Flag for color change

#define STATE_MAX 				2
#define STATE_FADEHSV			0
#define STATE_FADERND			1
#define STATE_MANUAL			2

unsigned char eeSpeed	EEMEM = 20;
unsigned char eeState	EEMEM = 2;
unsigned char eeH		EEMEM = 85;
unsigned char eeS		EEMEM = 255;
unsigned char eeV		EEMEM = 255;


// Prototypes
void init(void);
void hsv_to_rgb (unsigned char h, unsigned char s, unsigned char v, RGB * out);
unsigned char fade(RGB * newc, RGB * oldc);
void newRandomColor(RGB * rgb);
void nextColor(RGB * rgb);
void newFadeColor(RGB * rgb);
void makeLog(RGB * lamp,RGB * loglamp);
void checkState(void);
void getInput(void);
void parseInput(void);

// Global variables
volatile unsigned char Flags;
RGB lamp = {0,0,0};
RGB temp = {0,0,0};
RGB loglamp = {0,0,0};
unsigned char H,S,V;
unsigned char state = 0;
unsigned char speed = 20;

unsigned char analog1 = 127;
unsigned char analog2 = 127;
unsigned char disco = 0;
unsigned char gotanalog2 = 0;
unsigned char gotRemote = 0;

/*
	Logarithmic tables for the PWM output
	Formula := f(x) = e^(x/46) - 1 - 0.000615*t * x^2 + 0.156865*t * x
	
	The brightness perceived by the human eye is approximately a logartihmic function of the absolut brightness of the light source.
	Thus the table is a exponential function to convert the desired brightness values into values for the PWM.
	I introduced a parameter 't' into the function to influence the lower part of the function. If you set t=0 you'll get table0[].
	As you can see there are big areas which are 0,1 or 2. These limit the resolution of the PWM and are perceived as weak flickering when
	the colors start lightning.
	With an increasing t the lower parts of the function will get a little elevated. This leads to smoother colors at lower PWM values.
	An increase in PWM resolution might be a better way to solve this.
*/

/*unsigned char table0[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,
2,2,2,2,3,3,3,3,3,3,3,3,3,3,4,4,4,4,4,4,4,4,4,5,5,5,5,5,5,5,6,6,6,6,6,6,7,7,7,7,7,7,8,8,8,8,9,9,9,9,9,10,10,10,10,11,11,11,12,12,12,12,13,13,13,14,
14,14,15,15,15,16,16,17,17,17,18,18,19,19,20,20,20,21,21,22,22,23,24,24,25,25,26,26,27,28,28,29,30,30,31,32,32,33,34,35,35,36,37,38,39,40,41,42,43,43,
44,45,47,48,49,50,51,52,53,54,56,57,58,60,61,62,64,65,67,68,70,71,73,74,76,78,79,81,83,85,87,89,91,93,95,97,99,101,104,106,108,111,113,116,118,121,124,
126,129,132,135,138,141,144,147,151,154,157,161,164,168,172,176,180,184,188,192,196,200,205,209,214,219,224,228,234,239,244,249,255};*/

unsigned char table1[] = {0,0,0,0,0,0,1,1,1,1,1,1,2,2,2,2,2,2,3,3,3,3,3,3,4,4,4,4,4,4,5,5,5,5,5,5,6,6,6,6,6,6,6,7,7,7,7,7,7,8,8,8,8,8,8,9,9,9,9,9,
9,10,10,10,10,10,10,11,11,11,11,11,11,12,12,12,12,12,12,13,13,13,13,13,14,14,14,14,14,15,15,15,15,15,16,16,16,16,16,17,17,17,17,18,18,18,18,18,19,19,
19,20,20,20,20,21,21,21,21,22,22,22,23,23,23,24,24,24,25,25,25,26,26,27,27,27,28,28,29,29,29,30,30,31,31,32,32,33,33,34,34,35,35,36,37,37,38,38,39,40,
40,41,42,42,43,44,45,45,46,47,48,49,49,50,51,52,53,54,55,56,57,58,59,60,61,62,64,65,66,67,68,70,71,72,74,75,77,78,80,81,83,84,86,88,89,91,93,95,97,99,
101,103,105,107,109,111,113,116,118,121,123,126,128,131,133,136,139,142,145,148,151,154,157,161,164,167,171,174,178,182,186,190,194,198,202,206,211,215,
220,224,229,234,239,244,250,255};

/*unsigned char table3[] = {0,0,0,1,1,2,2,3,3,4,4,5,5,6,6,7,7,7,8,8,9,9,10,10,10,11,11,12,12,12,13,13,14,14,14,15,15,16,16,16,17,17,18,18,18,19,
19,19,20,20,20,21,21,21,22,22,22,23,23,23,24,24,24,25,25,25,26,26,26,27,27,27,28,28,28,29,29,29,29,30,30,30,31,31,31,32,32,32,32,33,33,33,34,34,
34,34,35,35,35,36,36,36,37,37,37,37,38,38,38,39,39,39,39,40,40,40,41,41,41,42,42,42,43,43,43,44,44,44,45,45,45,46,46,46,47,47,48,48,48,49,49,50,
50,50,51,51,52,52,53,53,54,54,55,55,56,56,57,57,58,58,59,60,60,61,61,62,63,63,64,65,66,66,67,68,69,69,70,71,72,73,74,75,75,76,77,78,79,80,81,83,
84,85,86,87,88,90,91,92,94,95,96,98,99,101,102,104,105,107,109,111,112,114,116,118,120,122,124,126,128,130,132,135,137,140,142,144,147,150,152,155,
158,161,164,167,170,173,176,180,183,187,190,194,198,201,205,209,213,218,222,226,231,235,240,245,250,255};*/

#define table	table1
#define useLog  1	//If no logarithmic conversion is desired set this to 0

int main(void)
{
	unsigned int i = 0;
	init();
	
	while(1)
	{
		getInput();
		parseInput();

//		if (Flags&Time){
//			Flags&=~Time;
			if((speed < 250) || state == STATE_MANUAL)									//If speed > 250 stop the fading.
			if((i++ >= ((speed*50) + ((speed*5500)/V))) || state == STATE_MANUAL){	//As V gets lower fade() will take less steps to get to the next color.
				i=0;																	//This speeds things up. The (speed*5500)/V term drives against this.
				if(fade(&temp,&loglamp)){				//There a different approaches to fade the color. This code will fade between PWM values that are already
//				if(fade(&temp,&lamp)){					//made logartihmic to use the full range of the PWM outputs.
					nextColor(&temp);
					makeLog(&temp,&temp);
//					PORTC ^= (1<<3);			//For debugging only
				}
//				makeLog(&lamp,&loglamp);
//				nextColor(&lamp);
//				PORTC ^= (1<<5);				//For debugging only
			}
//		}
	}
	
}

// Reads input values from the UART and processes key hits
void getInput(void)
{
	static unsigned int tempanalog = 0;
	unsigned char c = 0;
	if(softuart_kbhit()){
		c=softuart_getchar();
		
		if((c & 0xF0) ==0x10)
			tempanalog = c << 4;
			
		if((c & 0xF0) ==0x20){
			tempanalog |= (c&0x0F);
			analog1 = tempanalog;
		}
		
		if((c & 0xF0) ==0x50)
			tempanalog = c << 4;
			
		if((c & 0xF0) ==0x60){
			tempanalog |= (c&0x0F);
			analog2 = tempanalog;
			gotanalog2=1;
		}
		
		if(c==0x41){
			state++;
			if(state >STATE_MAX)
				state=0;
		}
		
		if(c==0x42){
			disco = 1;
		}
		
		if(c==0x43){
			eeprom_write_byte(&eeState, state);
			eeprom_write_byte(&eeSpeed, speed);
			eeprom_write_byte(&eeH, H);
			eeprom_write_byte(&eeS, S);
			eeprom_write_byte(&eeV, V);
		}
		
		gotRemote = 1;
		//softuart_putchar(analog1);
	}
}

// Interprets new input values
void parseInput(void)
{
	if(gotRemote){
		if(state == STATE_FADERND || state == STATE_FADEHSV){
			if(gotanalog2){
				V=analog2;
				hsv_to_rgb(H,S,V,&temp);
				makeLog(&temp,&temp);
				gotanalog2=0;
			}
			if(disco == 0){
				if(analog1 < 250)
					speed=analog1+2;
				else
					speed= analog1;
			}else{
				speed= analog1;
			}
			S = 255;
		}else if(state == STATE_MANUAL){
			H = analog1;
			S = analog2;
			speed = 2;
		}
	}
}

// Uses the table to transform the brightness values into PWM values
void makeLog(RGB * lamp,RGB * loglamp)
{
	if(useLog){
		cli();
		loglamp->r = table[lamp->r];
		loglamp->g = table[lamp->g];
		loglamp->b = table[lamp->b];
		sei();
	}else{
		cli();
		loglamp->r = lamp->r;
		loglamp->g = lamp->g;
		loglamp->b = lamp->b;
		sei();
	}


//	loglamp->b = table[(int)(lamp->b*0.7)];		//Might be used to adjust the brightness of different LEDs
}

// Switches to the next color
void nextColor(RGB * rgb)
{
	switch(state){
		case STATE_FADERND:
			newRandomColor(rgb);
		break;
		case STATE_FADEHSV:
			newFadeColor(rgb);
		break;
		case STATE_MANUAL:
			hsv_to_rgb(H,S,V,rgb);
		break;
	}
}

// Generates a random color 
void newRandomColor(RGB * rgb)
{
	H = rand() / (RAND_MAX / 255);
	hsv_to_rgb(H,S,V,rgb);
}

// Generates a new color that lies next to the old color
void newFadeColor(RGB * rgb)
{
	H++;
	hsv_to_rgb(H,S,V,rgb);
}

// Gets initial values from the EEPROM and initialises the hardware
void init(void)
{
	//H=0;
	//S=255;
	//V=155;
	state = eeprom_read_byte(&eeState);
	speed = eeprom_read_byte(&eeSpeed);
	H = eeprom_read_byte(&eeH);
	S = eeprom_read_byte(&eeS);
	V = eeprom_read_byte(&eeV);
	
	if(state > STATE_MAX)				//Protection against empty EEPROM
		state = 0;
	
	TCCR0=1;
	TIMSK = (1<<TOIE0);				// Overflow Interrupt f/256
	
//   uart_init( UART_BAUD_SELECT(115200,F_CPU) );			//Only for debugging
	DDR_Ledport = (1<<R_PIN)|(1<<G_PIN)|(1<<B_PIN);
//	DDR_Ledport |= (1<<3)|(1<<5);							//Only for debugging
	
	ADCSRA = 0xE6;
	ADMUX = 1;//(1<<REFS0) + 1;
	
    sei();
//	uart_putc(0);											//Only for debugging
//	uart_putc(0xFF);										//Only for debugging
	
	hsv_to_rgb(H,S,V,&lamp);
	hsv_to_rgb(H,S,V,&temp);
	
	softuart_init();
	//softuart_turn_rx_on(); /* redundant - on by default */
}


// Fades one color into another color.
// Returns 1 if no further changes are necessary
unsigned char fade(RGB * newc, RGB * oldc)
{

	if(oldc->g==newc->g && oldc->r==newc->r && oldc->b==newc->b)
		return 1;
	if( newc->r > oldc->r ){
		oldc->r++;
	}else if(newc->r < oldc->r ){
		oldc->r--;
	}
	
	if( newc->g > oldc->g ){
		oldc->g++;
	}else if(newc->g < oldc->g ){
		oldc->g--;
	}
	
	if( newc->b > oldc->b ){
		oldc->b++;
	}else if(newc->b < oldc->b ){
		oldc->b--;
	}
	return 0;
}

//-------------------------------------------------------------------------------
//Converts HSV to RGB
//-------------------------------------------------------------------------------
void hsv_to_rgb (unsigned char h, unsigned char s, unsigned char v, RGB * out)
{
	unsigned char r=0,g=0,b=0, i, f;
	unsigned int p, q, t;

	if( s == 0 ) 
 	{	r = g = b = v;
	}
	else
	{	i=h/43;
		f=h%43;
		p = (v * (255 - s))/256;
		q = (v * ((10710 - (s * f))/42))/256;
		t = (v * ((10710 - (s * (42 - f)))/42))/256;

		switch( i )
		{	case 0:
				r = v; g = t; b = p; break;
			case 1:
				r = q; g = v; b = p; break;
			case 2:
				r = p; g = v; b = t; break;
			case 3:
				r = p; g = q; b = v; break;			
			case 4:
				r = t; g = p; b = v; break;				
			case 5:
	 			r = v; g = p; b = q; break;
		}
	}
	out->r=r; out->g=g; out->b=b;
}


//-------------------------------------------------------------------------------
//Timer  0 Interrupt, f/256
//-------------------------------------------------------------------------------
SIGNAL (SIG_OVERFLOW0)
{	static unsigned char PWM_cnt;
	static unsigned char prescale;
	if(prescale++){					//Used to halve the PWM frequency
		prescale=0;
		return;
	}
#if (INVERT==1)
	if (PWM_cnt <loglamp.r)
		Ledport &=~(1 << R_PIN);
	else
		Ledport |= (1 << R_PIN);

	if (PWM_cnt <loglamp.g)
		Ledport &=~(1 << G_PIN);
	else
		Ledport |= (1 << G_PIN);

	if (PWM_cnt <loglamp.b)
		Ledport &=~(1 << B_PIN);
	else
		Ledport |= (1 << B_PIN);
#else
	if (PWM_cnt <lamp.r)
		Ledport |= (1 << R_PIN);
	else
		Ledport &=~(1 << R_PIN);

	if (PWM_cnt <lamp.g)
		Ledport |= (1 << G_PIN);
	else
		Ledport &=~(1 << G_PIN);

	if (PWM_cnt <lamp.b)
		Ledport |= (1 << B_PIN);
	else
		Ledport &=~(1 << B_PIN);
#endif
	PWM_cnt++;
//	if (PWM_cnt==00){
//		PWM_cnt=0;
		//Flags|=Time;
//	}
}


