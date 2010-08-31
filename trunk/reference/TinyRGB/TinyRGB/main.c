/*************************************************************************************
* 
* Project Tiny RGB
* Display multi color using RGB LED
* MCU ATTINY2313 @ Internal clock 8MHz
* By Jirawat Kongkaen
* Web site http://www.avrportal.com
* 
*************************************************************************************/

#include <avr/io.h>

// i/o definition
#define PORT_R		PORTB
#define DDR_R		DDRB
#define PORT_G		PORTB
#define DDR_G		DDRB
#define PORT_B		PORTD
#define DDR_B		DDRD

#define PORT_SW		PORTB
#define PIN_SW		PINB
#define DDR_SW		DDRB

#define IO_MASK_R	0xe0
#define IO_MASK_G	0x1c
#define IO_MASK_B	0x70
#define IO_SW		PB0

// all color table please visit http://www.avrportal.com/TinyRGB/rgb-table.php
unsigned char r_color_list[8] = { 3,0,0,0,3,3,3,0 };
unsigned char g_color_list[8] = { 0,3,0,3,3,0,3,0 };
unsigned char b_color_list[8] = { 0,0,3,3,0,3,3,0 };
unsigned char counter=0;

unsigned char check_buttom(void)
{
	static unsigned char delay=0, key_press=0;

	// buttom is not press
	if((PIN_SW & _BV(IO_SW)) != 0)
	{
		key_press = 0;
		return 0;
	}

	if(key_press)
		return 0;
	
	// delay 10/250 ms
	if(++delay == 10)
	{
		delay = 0;
		key_press = 1;
		return 1;
	}

	return 0;
}

int main(void)
{
	unsigned char color_index=0, r,g,b, delay=0;

	// setup i/o
	DDR_R = IO_MASK_R|IO_MASK_G;
	//DDR_G |= IO_MASK_G;
	DDR_B = IO_MASK_B;
	//PORT_R = IO_MASK_R|IO_MASK_G;
	//PORT_G |= IO_MASK_G;
	//PORT_B = IO_MASK_B;
	
	// pull-up input i/o for color switch
	PORT_SW |= _BV(PA0);

	// setup timer0
	// 8MHz/64
	TCCR0B = 0x03;
	
	// initial color
	r = r_color_list[0];
	g = g_color_list[0];
	b = b_color_list[0];

	for(;;)
	{
		// wait until timer0 is overflow
		// 64*256/8MHz = 2.048ms
		while ( (TIFR & _BV ( TOV0 )) == 0 );
		TIFR |= _BV(TOV0);
		
		// turn off LED
		if(counter == r && r != 3)
		{
			PORT_R |= IO_MASK_R;
		}
		if(counter == g && g != 3)
		{
			PORT_G |= IO_MASK_G;
		}
		if(counter == b && b != 3)
		{
			PORT_B |= IO_MASK_B;
		}
		// turn on LED
		if(++counter == 4)
		{
			counter = 0;
			if(r != 0 )
				PORT_R &= ~IO_MASK_R;
			if(g != 0 )
				PORT_G &= ~IO_MASK_G;
			if(b != 0 )
				PORT_B &= ~IO_MASK_B;
		}
		
		// change color
		if( check_buttom() )
		{
			if(++color_index == 9)
				color_index = 0;
			if(color_index<8)
			{
				r = r_color_list[color_index];
				g = g_color_list[color_index];
				b = b_color_list[color_index];
			}
		}
		if(color_index == 8)
		{
			if(++delay == 125)
			{
				delay = 0;
				if(++r == 4)
				{
					r = 0;
					if(++g == 4)
					{
						g = 0;
						if(++b == 4)
						{
							b = 0;
						}
					}
				}
			}
		}
	}
	return 0;
}
