/******************************************************************************
 *  UsbCfg.c
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

#pragma hdrstop
#include <vcl.h>
#include "UsbCfg.h"
#include "Main.h"

//---------------------------------------------------------------------------
int usbDev_open(void)
{
    struct usb_bus    *bus;
    struct usb_device *dev = 0;

    usb_init();
    usb_find_busses();
    usb_find_devices();
    for(bus=usb_get_busses(); bus; bus=bus->next)
    {
        for(dev=bus->devices; dev; dev=dev->next)
        {
            if((dev->descriptor.idVendor == USBDEV_VENDOR) && (dev->descriptor.idProduct == USBDEV_PRODUCT))
	        break;
        }
        if(dev)
            break;
    }
    if(!dev)
    {
        ShowMessage("Please Connect U-rgbLED Device!");
        usbhandle=NULL;
        return 1;
    }
    usbhandle = usb_open(dev);
    if(!usbhandle)
    {
        ShowMessage("Can't Open USB!");
        usbhandle=NULL;
        return 2;
    }
    return 0;
}
/////////////////////////////////////////////////////////////////
void usbDev_close(void)
{
    if(!usbhandle)
        return;
    usb_close(usbhandle);
}
/////////////////////////////////////////////////////////////////////
int usbDev_transmit(unsigned char dir, unsigned char functionid,
			   unsigned char send[4], unsigned char * buffer, int buffersize)
{
    int nbytes;
    if(usbhandle)
    nbytes = usb_control_msg(usbhandle,
                USB_TYPE_VENDOR | USB_RECIP_DEVICE | dir ,
			    functionid,
			    (send[1] << 8) | send[0],
			    (send[3] << 8) | send[2],
			    buffer, buffersize,
			    5000);
    else
    {
        usbDev_close();
        usbDev_open();
    }
    if(nbytes < 0)
    {
        ShowMessage("Communication Error!");
        usbDev_close();
        usbDev_open();
    }
    return nbytes;
}
#pragma package(smart_init)

/*------------------------------------------------------------------------------
										  0ooo
								ooo0     (   )
								(   )     ) /
								 \ (     (_/
	    				          \_)        By:cuiqingwei [gary]
------------------------------------------------------------------------------*/