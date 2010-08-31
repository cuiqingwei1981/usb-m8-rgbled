// UART.C
// Generic software uart written in C
//
// Generic code from
// Colin Gittins, Software Engineer, Halliburton Energy Services
// (available from the iar.com web-site)
//
// adapted to AVR using avr-gcc 3.4.3/avr-libc 1.2.3 (WinAVR 2/2005)
// by Martin Thomas, Kaiserslautern, Germany
// <eversmith@heizung-thomas.de> www.siwawi.arubi.uni-kl.de/avr_projects
// AVR-port Version 0.1  3/2005
//
// ---------------------------------------------------------------------
//
// Remarks from Colin Gittis:
//
// Generic software uart written in C, requiring a timer set to 3 times
// the baud rate, and two software read/write pins for the receive and
// transmit functions.
//
// * Received characters are buffered
// * putchar(), getchar(), kbhit() and flush_input_buffer() are available
// * There is a facility for background processing while waiting for input
// The baud rate can be configured by changing the BAUD_RATE macro as
// follows:
//
// #define BAUD_RATE			19200.0
//
// The function init_uart() must be called before any comms can take place
//
// Interface routines required:
// 1. get_rx_pin_status()
//    Returns 0 or 1 dependent on whether the receive pin is high or low.
// 2. set_tx_pin_high()
//    Sets the transmit pin to the high state.
// 3. set_tx_pin_low()
//    Sets the transmit pin to the low state.
// 4. idle()
//    Background functions to execute while waiting for input.
// 5. timer_set( BAUD_RATE )
//    Sets the timer to 3 times the baud rate.
// 6. set_timer_interrupt( timer_isr )
//    Enables the timer interrupt.
//
// Functions provided:
// 1. void flush_input_buffer( void )
//    Clears the contents of the input buffer.
// 2. char kbhit( void )
//    Tests whether an input character has been received.
// 3. char getchar( void )
//    Reads a character from the input buffer, waiting if necessary.
// 4. void turn_rx_on( void )
//    Turns on the receive function.
// 5. void turn_rx_off( void )
//    Turns off the receive function.
// 6. void putchar( char )
//    Writes a character to the serial port.
//
// ---------------------------------------------------------------------

/* 
Remarks by Martin Thomas (avr-gcc):
- stdio.h not used
- AVR-Timer in CTC-Mode ("manual" reload may not be accurate enough)
  Timer1 used here (Timer0 CTC not available i.e. on ATmega8)
- Global Interrupt Flag has to be enabled (see Demo-Application)
- Interface timer_set and set_timer_interrupt not used here
- internal_rx_buffer was defined as unsigned char - thas could not
  work since more than 8 bytes are needed, changed to unsigned short
- some variables moved from "global scope" into ISR function-scope
- GPIO initialisation included
- Tested with ATmega32 @ 8MHz System-Clock (internal R/C)
- Added functions for string-output inspired by P. Fleury's AVR UART-lib.
*/

#include <avr/io.h>
#include <avr/interrupt.h>
//#include <avr/signal.h>
#include <avr/pgmspace.h>

#include "softuart.h"

#define SU_TRUE 1
#define SU_FALSE 0

#define RX_NUM_OF_BITS (10)
#define TX_NUM_OF_BITS (10)

volatile static unsigned char		inbuf[SOFTUART_IN_BUF_SIZE];
volatile static unsigned char		qin = 0;
volatile static unsigned char		qout = 0;

volatile static char 			flag_rx_off;
volatile static char 			flag_rx_ready;
volatile static char 			flag_tx_ready;
volatile static char 			timer_tx_ctr;
volatile static char 			bits_left_in_tx;
volatile static short			internal_tx_buffer; /* ! mt: was type uchar - this was wrong */

#define set_tx_pin_high() (SOFTUART_TXPORT |= (1<<SOFTUART_TXBIT) )
#define set_tx_pin_low() (SOFTUART_TXPORT &= ~(1<<SOFTUART_TXBIT) )
#define get_rx_pin_status() ( (SOFTUART_RXPIN & (1<<SOFTUART_RXBIT) ) ? 1 : 0 )
	
// void softuart_timer_isr(void)
SIGNAL(SIG_OUTPUT_COMPARE1A)
	{
	static char flag_rx_waiting_for_stop_bit = SU_FALSE;
	static char rx_mask;
	static char timer_rx_ctr;
	static char bits_left_in_rx;
	static short internal_rx_buffer;
	
	char start_bit, flag_in;
	char tmp;
	
// Transmitter Section
	if ( flag_tx_ready )
		{
		tmp = timer_tx_ctr;
		if ( --tmp <= 0 ) // if ( --timer_tx_ctr <= 0 )
			{
			if ( internal_tx_buffer & 0x01 )
				{
				set_tx_pin_high();
				}
			else
				{
				set_tx_pin_low();
				}
			internal_tx_buffer >>= 1;
			tmp = 3; // timer_tx_ctr = 3;
			if ( --bits_left_in_tx<=0 )
				{
				flag_tx_ready = SU_FALSE;
				}
			}
		timer_tx_ctr = tmp;
		}

// Receiver Section
	if ( flag_rx_off == SU_FALSE )
		{
		if ( flag_rx_waiting_for_stop_bit )
			{
			if ( --timer_rx_ctr<=0 )
				{
				flag_rx_waiting_for_stop_bit = SU_FALSE;
				flag_rx_ready = SU_FALSE;
				internal_rx_buffer &= 0xFF;
				if ( internal_rx_buffer != 0xC2 )
					{
					inbuf[qin] = internal_rx_buffer;
					if ( ++qin>=SOFTUART_IN_BUF_SIZE )
						{
						qin = 0;
						}
					}
				}
			}
		else		// rx_test_busy
			{
			if ( flag_rx_ready==SU_FALSE )
				{
				start_bit = get_rx_pin_status();
// Test for Start Bit
				if ( start_bit==0 )
					{
					flag_rx_ready = SU_TRUE;
					internal_rx_buffer = 0;
					timer_rx_ctr = 4;
					bits_left_in_rx = RX_NUM_OF_BITS;
					rx_mask = 1;
					}
				}
			else	// rx_busy
				{
				if ( --timer_rx_ctr<=0 )
					{				// rcv
					timer_rx_ctr = 3;
					flag_in = get_rx_pin_status();
					if ( flag_in )
						{
						internal_rx_buffer |= rx_mask;
						}
					rx_mask <<= 1;
					if ( --bits_left_in_rx<=0 )
						{
						flag_rx_waiting_for_stop_bit = SU_TRUE;
						}
					}
				}
			}
		}
	}

static void avr_io_init(void)
{
	// TX-Pin as output
	SOFTUART_TXDDR |= ( 1 << SOFTUART_TXBIT );
	// RX-Pin as input
	SOFTUART_RXDDR &= ~( 1 << SOFTUART_RXBIT );
}

static void avr_timer_init(void)
{
	OCR1A  = SOFTUART_TIMERTOP;     /* set top */

#if (SOFTUART_PRESCALE==8)
	/*  Mode 4 - CTC with Prescaler 8 */
	TCCR1B = (1<<WGM12)|(1<<CS11);
#elif (SOFTUART_PRESCALE==1)
	/*  Mode 4 - CTC with Prescaler 8 */
	TCCR1B = (1<<WGM12)|(1<<CS10);
#else
#error "timer_init for prescaler not defined"
#endif

	TIMSK |= (1<<OCIE1A); /* enable output-compare int */
	TCNT1 = 0; /* reset counter */
}

void softuart_init( void )
	{
	flag_tx_ready = SU_FALSE;
	flag_rx_ready = SU_FALSE;
	flag_rx_off = SU_FALSE;
	
	avr_io_init();
	// set_tx_pin_low(); /* ! - mt: set to high to avoid garbage on init */
	set_tx_pin_high(); /* ! */

	// timer_set( BAUD_RATE );
	// set_timer_interrupt( timer_isr ); 	// Enable timer interrupt
	avr_timer_init();
	}

static void idle(void)
{
	// TODO: timeout handling - but there is a "softuart_kbhit" in this code...
}

void softuart_turn_rx_on( void )
	{
	flag_rx_off = SU_FALSE;
	}

void softuart_turn_rx_off( void )
	{
	flag_rx_off = SU_TRUE;
	}

unsigned char softuart_getchar( void )
	{
	unsigned char		ch;

	do
		{
		while ( qout==qin )
			{
			idle();
			}
		ch = inbuf[qout] & 0xFF;
		if ( ++qout>=SOFTUART_IN_BUF_SIZE )
			{
			qout = 0;
			}
		}
	while ( ch==0x0A || ch==0xC2 );
	
	return( ch );
	}

char softuart_kbhit( void )
	{
	return( qin!=qout );
	}

void softuart_flush_input_buffer( void )
	{
	qin = 0;
	qout = 0;
	}
	
void softuart_putchar( const unsigned char ch )
	{	
	while ( flag_tx_ready );

// invoke_UART_transmit
	timer_tx_ctr = 3;
	bits_left_in_tx = TX_NUM_OF_BITS;
	internal_tx_buffer = (ch<<1) | 0x200;
	flag_tx_ready = SU_TRUE;
	}
	
void softuart_puts( const unsigned char *s )
	{
	while ( *s ) softuart_putchar( *s++ );
	}
	
void softuart_puts_p( const unsigned char *prg_s )
	{
	unsigned char c;

	while ( ( c = pgm_read_byte( prg_s++ ) ) ) softuart_putchar(c);
	}

