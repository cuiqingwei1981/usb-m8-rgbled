/*
		moodlampremote.c
		
		This software belongs to the Moddlamp project that can be found at http://www.blinkenlichts.net/
		
		Target MC: ATmega8-16AI @ 12MHz
		Compiler version: avr-gcc 3.4.6 (Winavr)
		
		This software is licensed under the GNU GPL Version 2.
		2006 Tobias Schneider
		
		The softuart library is provided by Martin Thomas
		(see http://www.siwawi.arubi.uni-kl.de/avr_projects)
		
		
		Version 0.1:	Initial release	(quite a nasty hack...)
*/

/*
	
		This software reads two analog inputs and two digital inputs and outputs their values over the softuart with 4800 baud
		The protocol is fairly simple:
		
			0x1X	X = lower nibble of the analog channel 1
			0x2X	X = higher nibble of the analog channel 1
			
			0x40:	Button 1 was pressed down
			0x41:	Button 1 was released
			0x42:	Button 1 was pressed at startup
			0x43:	Button 1 was pressed about 3 seconds
			
			0x5X	X = lower nibble of the analog channel 2
			0x6X	X = higher nibble of the analog channel 2

			0x70:	Button 2 was pressed down
			0x71:	Button 2 was released
*/

/*
		As the receiver is easily overwhelmed with incoming data after every byte transmitted a delay-loop is activated.
*/

#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/eeprom.h>
#include <avr/wdt.h>

#include "softuart.h"
#define BUTTON1_PINREG	PIND
#define BUTTON1_PORTREG	PORTD
#define BUTTON1_PIN		PD6
#define BUTTON1 (PIND & (1<<PD6))

#define BUTTON2_PINREG	PIND
#define BUTTON2_PORTREG	PORTD
#define BUTTON2_PIN		PD7
#define BUTTON2 (PIND & (1<<PD7))

// Prototypes
void init(void);
void checkState(void);
void printAnalog1(void);
void printButton1(void);
void printAnalog2(void);
void printButton2(void);

unsigned char oldbutton1 = 255;
unsigned char oldbutton2 = 0;
unsigned int analog1 = 127;
unsigned int oldanalog1 = 127;
unsigned int analog2 = 127;
unsigned int oldanalog2 = 127;
unsigned int buttoncount = 0;

unsigned int analogs[2][32];

unsigned char analogi1 = 0, analogi2 = 0;
unsigned char gotanalogs = 0;

volatile unsigned long l = 0;
	
int main(void)
{
	wdt_enable(WDTO_120MS);
	
	init();
	softuart_putchar(255);
	
	while(1){
		wdt_reset();
		checkState();
		if(gotanalogs){
			printAnalog1();
			printAnalog2();
			printButton1();
			printButton2();
		}
		for(l=0;l<1000;l++);
	}
}

void printAnalog1(void)
{
	unsigned int temp;
	analog1 += 20;
	if((((oldanalog1)<=(analog1+1)) && ((oldanalog1) >= (analog1-1))) || (analog1 ==oldanalog1) || (analog1/4 == oldanalog1/4))
		return;
	oldanalog1 = analog1;
	analog1-=20;
	temp = analog1 /4;
	softuart_putchar(0x10 + ((temp>>4) & 0x0F));
	for(l=0;l<1000;l++);
	softuart_putchar(0x20 + ((temp>>0) & 0x0F));
	for(l=0;l<1000;l++);
}

void printAnalog2(void)
{
	unsigned int temp;
	analog2 += 20;
	if((((oldanalog2)<=(analog2+1)) && ((oldanalog2) >= (analog2-1))) || (analog2 ==oldanalog2))
		return;
	oldanalog2 = analog2;
	analog2-=20;
	temp = analog2 /4;
	softuart_putchar(0x50 + ((temp>>4) & 0x0F));
	for(l=0;l<1000;l++);
	softuart_putchar(0x60 + ((temp>>0) & 0x0F));
	for(l=0;l<1000;l++);
}

void printButton1(void)
{
	if(BUTTON1==0 && buttoncount != 0xFFFF)
		buttoncount++;
	if(buttoncount > 300 && BUTTON1==0){
		if(buttoncount == 0xFFFF){
			return;
		}
		softuart_putchar(0x40 + 3);
		for(l=0;l<1000;l++);
		buttoncount = 0xFFFF;
		return;
	}
	if(BUTTON1 == oldbutton1)
		return;
	
	if(oldbutton1 == 255){
		if((BUTTON1==0)){
			softuart_putchar(0x40 + 2);
			for(l=0;l<1000;l++);
			oldbutton1 = 254;
			return;
		}else{
			//softuart_putchar(0x40 + 4);
			//for(l=0;l<1000;l++);
			oldbutton1=BUTTON1;
			return;
		}
	}
	if(oldbutton1 == 254){
		if(BUTTON1==0)
			return;
		//softuart_putchar(0x40 + 2);
		oldbutton1 = BUTTON1;
		return;
	}
	
	oldbutton1 = BUTTON1;

	if(buttoncount==0xFFFF){
		buttoncount=0;
		return;
	}
	buttoncount=0;
	if(BUTTON1)
		softuart_putchar(0x40 + 1);
	else
		softuart_putchar(0x40 + 0);
	for(l=0;l<1000;l++);
}

void printButton2(void)
{
	if(BUTTON2 == oldbutton2)
		return;
	oldbutton2 = BUTTON2;
	if(BUTTON2)
		softuart_putchar(0x70 + 1);
	else
		softuart_putchar(0x70 + 0);
	for(l=0;l<1000;l++);
}

void checkState(void)
{
	unsigned int temp;
	unsigned int ltemp;
	while(ADCSRA & (1<<ADSC));
	ADMUX = 2;
	ADCSRA |= (1<<ADSC);
	while(ADCSRA & (1<<ADSC));
	temp = ADCL;
	temp |= (ADCH<<8);

	analogs[0][analogi1++]=temp;
	if(analogi1 == 32){
		analogi1 = 0;
		gotanalogs = 1;
	}
	
	ADMUX = 5;
	ADCSRA |= (1<<ADSC);
	while(ADCSRA & (1<<ADSC));
	temp = ADCL;
	temp |= (ADCH<<8);

	analogs[1][analogi2++]=temp;
	if(analogi2 == 32){
		analogi2 = 0;
	}
	
	if(gotanalogs){
		ltemp = 0;
		for(temp=0;temp<32;temp++)
			ltemp += analogs[0][temp];
		ltemp = ltemp / 32;
		analog1=ltemp;
		
		ltemp = 0;
		for(temp=0;temp<32;temp++)
			ltemp += analogs[1][temp];
		ltemp = ltemp / 32;
		analog2=ltemp;
	}
}

void init(void)
{
	//ADCSRA = 0xE7;
	ADCSRA = 0x87;
	ADMUX = 2;//(1<<REFS0) + 1;
	ADCSRA |= (1<<ADSC);
	
	BUTTON1_PORTREG |= (1<<BUTTON1_PIN);
	BUTTON2_PORTREG |= (1<<BUTTON2_PIN);
	
    sei();
	
	softuart_init();
	softuart_turn_rx_on(); /* redundant - on by default */
}




