
#define SOFTUART_RXPIN	PINC
#define SOFTUART_RXDDR	DDRC
#define SOFTUART_RXBIT	PC1

#define SOFTUART_TXPORT	PORTC
#define SOFTUART_TXDDR 	DDRC
#define SOFTUART_TXBIT  PC0

#if !defined(F_CPU)
#warning F_CPU not defined in makefile - now defined in softuart.h
#define F_CPU 8000000UL
#endif

#define SOFTUART_BAUD_RATE		4800

/* "A timer interrupt must be set to interrupt at three times 
	the required baud rate." */
#define SOFTUART_PRESCALE (8)
//#define SOFTUART_PRESCALE (1)
#define SOFTUART_TIMERTOP ( F_CPU/SOFTUART_PRESCALE/SOFTUART_BAUD_RATE/3 -1)

#if (SOFTUART_TIMERTOP > 0xff)
#warning "Check SOFTUART_TIMERTOP"
#endif

#define SOFTUART_IN_BUF_SIZE		32

// Init the Software Uart
void softuart_init(void);
// Clears the contents of the input buffer.
void softuart_flush_input_buffer( void );
// Tests whether an input character has been received.
char softuart_kbhit( void );
// Reads a character from the input buffer, waiting if necessary.
unsigned char softuart_getchar( void );
// Writes a character to the serial port.
void softuart_putchar( const unsigned char );
// Turns on the receive function.
void softuart_turn_rx_on( void );
// Turns off the receive function.
void softuart_turn_rx_off( void );

// Write a NULL-terminated string from RAM to the serial port
void softuart_puts(const unsigned char *s);
// Write a NULL-terminated string from program-space (flash) to the serial port
// i.e. softuart_puts_p(PSTR("test"))
void softuart_puts_p( const unsigned char *prg_s );
// Helper-Macro - "automaticly" inserts PSTR
#define softuart_puts_P(s___) softuart_puts_p(PSTR(s___))
