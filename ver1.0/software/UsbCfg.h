/******************************************************************************
 * UsbCfg.h
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

#ifndef UsbCfgH
#define UsbCfgH
//---------------------------------------------------------------------------
extern int  usbDev_open (void);
extern void usbDev_close(void);
int usbDev_transmit(unsigned char dir,
                    unsigned char functionid,
                    unsigned char send[4],
                    unsigned char *buffer,
                    int buffersize);
#endif

/*------------------------------------------------------------------------------
										  0ooo
								ooo0     (   )
								(   )     ) /
								 \ (     (_/
	    				          \_)        By:cuiqingwei [gary]
------------------------------------------------------------------------------*/

