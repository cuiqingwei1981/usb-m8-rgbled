/******************************************************************************
 * rgbAuto.h 
 *
 * Copyright XiaoCui' Products
 *
 * DESCRIPTION: 
 *
 * modification history
 * --------------------
 * 01a, 01jan2008, cuiqingwei written
 * --------------------
 ******************************************************************************/

#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/pgmspace.h>
#include <avr/wdt.h>

/*
Explanation of the HSV color space:

H: Hue        - 色调(如红，蓝，黄，绿...)
S: Saturation - 饱和度
V: Value      - 亮度

Scaling of the HSV values:
H: [0-255] 0 = red,   42  = yellow, 85 = green, 128 = turquoise, 171 = blue, 214 = purple
S: [0-255] 0 = white, 255 = pure colors
V: [0-255] 0 = off,   255 = maximum brightness

*/

typedef struct {
	unsigned char r;
	unsigned char g;
	unsigned char b;
} RGB;

#define	Ledport 		PORTD		// RGB Led Port
#define DDR_Ledport	    DDRD
#define R_PIN           5			// R Output
#define G_PIN           6			// G
#define B_PIN           7			// B

/* 函数声名 */
void init(void);
void hsv_to_rgb (unsigned char h, unsigned char s, unsigned char v, RGB * out);

/* 全局变量 */

RGB lamp = {0,0,0};

unsigned char H,S,V,h;

//-------------------------------------------------------------------------------
// Init
//-------------------------------------------------------------------------------
void init(void)
{
  	PORTD = 0;
 	PORTB = 0;			// no pullups on USB and ISP pins 
  	DDRD = ~(1 << 2);	// all outputs except PD2 = INT0 
  	DDRB = 0;           // all USB and ISP pins inputs 

	DDR_Ledport = (1<<R_PIN)|(1<<G_PIN)|(1<<B_PIN);

	TCCR0  = 1;
 	TCNT1H = 0xB6; 		// setup
 	TCNT1L = 0xC2;
 	TCCR1B = 0x03; 		// start Timer
	TIMSK  = (1<<TOIE1)|(1<<TOIE0);	// Overflow Interrupt f/256
}


//-------------------------------------------------------------------------------
// Main
//-------------------------------------------------------------------------------
int main(void)
{	
	cli();
	init();
   	sei();
	
   	H = 0;
	S = 255;
	V = 255;
			
	for(;;)
	{
		if ( H != h )
		{
			hsv_to_rgb(H,S,V,&lamp);
			h = H;
		}
	}
	return 0;
}

//-------------------------------------------------------------------------------
// Converts HSV to RGB
//-------------------------------------------------------------------------------
void hsv_to_rgb (unsigned char h, unsigned char s, unsigned char v, RGB * out)
{
	unsigned char r=0,g=0,b=0, i, f;
	unsigned int p, q, t;

	if( s == 0 ) {	
		r = g = b = v;
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
// Timer  0 Interrupt, f/256
//-------------------------------------------------------------------------------
SIGNAL (SIG_OVERFLOW0)
{	
	static unsigned char PWM_cnt;
	static unsigned char prescale;


	if(prescale++){				
		prescale=0;				// Used to halve the PWM frequency
		return;
	}

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

	PWM_cnt++;
}

//-------------------------------------------------------------------------------
// Timer  0 Interrupt, 100mSec, f/64
//-------------------------------------------------------------------------------
SIGNAL (SIG_OVERFLOW1)
{
	TCNT1H = 0xB6; 	
 	TCNT1L = 0xC2;

	H++;
}
/*------------------------------------------------------------------------------
										  0ooo
								ooo0     (   )
								(   )     ) /
								 \ (     (_/
	    				          \_)        By:cuiqingwei [gary]
------------------------------------------------------------------------------*/
