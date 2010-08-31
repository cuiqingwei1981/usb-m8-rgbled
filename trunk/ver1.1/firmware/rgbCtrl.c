/******************************************************************************
 * rgbCtrl.h 
 *
 * Copyright XiaoCui' Products
 *
 * DESCRIPTION: ver1.1 hid免驱版 基于vusb-20090415
 *
 * modification history
 * --------------------
 * 01a, 2009-08-20, cuiqingwei written
 * --------------------
 ******************************************************************************/


#include <avr/io.h>
#include <avr/wdt.h>
#include <avr/interrupt.h>  /* for sei() */
#include <util/delay.h>     /* for _delay_ms() */

#include <avr/pgmspace.h>   /* required by usbdrv.h */

#include "usbdrv.h"
#include "requests.h"       /* The custom request numbers we use */

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

unsigned char type,H,S,V;

/* ------------------------------------------------------------------------- */
/* ----------------------------- USB interface ----------------------------- */
/* ------------------------------------------------------------------------- */

PROGMEM char usbHidReportDescriptor[22] = {    /* USB report descriptor */
    0x06, 0x00, 0xff,              // USAGE_PAGE (Generic Desktop)
    0x09, 0x01,                    // USAGE (Vendor Usage 1)
    0xa1, 0x01,                    // COLLECTION (Application)
    0x15, 0x00,                    //   LOGICAL_MINIMUM (0)
    0x26, 0xff, 0x00,              //   LOGICAL_MAXIMUM (255)
    0x75, 0x08,                    //   REPORT_SIZE (8)
    0x95, 0x01,                    //   REPORT_COUNT (1)
    0x09, 0x00,                    //   USAGE (Undefined)
    0xb2, 0x02, 0x01,              //   FEATURE (Data,Var,Abs,Buf)
    0xc0                           // END_COLLECTION
};
/* The descriptor above is a dummy only, it silences the drivers. The report
 * it describes consists of one byte of undefined data.
 * We don't transfer our data through HID reports, we use custom requests
 * instead.
 */

/* ------------------------------------------------------------------------- */

usbMsgLen_t usbFunctionSetup(uchar data[8])
{
	usbRequest_t    *rq = (void *)data;

    if((rq->bmRequestType & USBRQ_TYPE_MASK) == USBRQ_TYPE_VENDOR)
	{
        if(rq->bRequest == CUSTOM_RQ_SET_STATUS)
		{
		#if 0
            if(rq->wValue.bytes[0] & 1)
			{    /* set LED */
               ;// LED_PORT_OUTPUT |= _BV(LED_BIT);
            }
			else
			{                          /* clear LED */
               ;// LED_PORT_OUTPUT &= ~_BV(LED_BIT);
            }
		#endif
   	H = 0;
	S = 255;
	V = 255;

	type = 1;
		
        }
		else if(rq->bRequest == CUSTOM_RQ_GET_STATUS)
		{
            static uchar dataBuffer[1];     /* buffer must stay valid when usbFunctionSetup returns */
          //  dataBuffer[0] = ((LED_PORT_OUTPUT & _BV(LED_BIT)) != 0);
		  	dataBuffer[0] = 0;
            usbMsgPtr = dataBuffer;         /* tell the driver which data to return */
            return 1;                       /* tell the driver to send 1 byte */
        }
    }
	else
	{
        /* calss requests USBRQ_HID_GET_REPORT and USBRQ_HID_SET_REPORT are
         * not implemented since we never call them. The operating system
         * won't call them either because our descriptor defines no meaning.
         */
		type = 1;
		H = rq->wValue.bytes[0];
		S = rq->wValue.bytes[1];
		V = rq->wValue.bytes[2];
		
    }
    return 0;   /* default for not implemented requests: return no data back to host */
}
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

	TCCR0 = 1;
	TIMSK = (1<<TOIE0);	// Overflow Interrupt f/256
}

/*
uchar usbFunctionSetup(uchar data[8]) 
{
	usbRequest_t *rq = (void *)data;

    if( rq->bRequest )
	{
		type = 1;
		H = rq->wValue.bytes[0];
		S = rq->wValue.bytes[1];
		V = rq->wValue.bytes[2];
	}
	else
	{
	    type = 0;
		lamp.r = rq->wValue.bytes[0];
		lamp.g = rq->wValue.bytes[1];
		lamp.b = rq->wValue.bytes[2];
	}
  	//computeOutputStatus();
    return 0;
}
*/

//-------------------------------------------------------------------------------
// Main
//-------------------------------------------------------------------------------
int main(void)
{	
	uchar i;

	cli();

 //   wdt_enable(WDTO_1S);

	
	init();

	usbInit();
    usbDeviceDisconnect();  /* enforce re-enumeration, do this while interrupts are disabled! */
  
    i = 0;
    while(--i){             /* fake USB disconnect for > 250 ms */
        wdt_reset();
        _delay_ms(1);
    }
    usbDeviceConnect();

   	sei();
		
   	H = 0;
	S = 150;
	V = 255;

	type = 1;
		
				
	for(;;)
	{
	//	wdt_reset();

		usbPoll();

		if ( type )
		{
			type = 0;
			hsv_to_rgb(H,S,V,&lamp);
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

	if( s == 0 ) 
	{	
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


	if(prescale++)
	{				
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

/*------------------------------------------------------------------------------
										  0ooo
								ooo0     (   )
								(   )     ) /
								 \ (     (_/
	    				          \_)        By:cuiqingwei [gary]
------------------------------------------------------------------------------*/
