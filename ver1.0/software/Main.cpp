/******************************************************************************
 * Main.h
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

#include <vcl.h>
#pragma hdrstop

#include "Main.h"
#include "UsbCfg.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "iComponent"
#pragma link "iCustomComponent"
#pragma link "iPositionComponent"
#pragma link "iScaleComponent"
#pragma link "iSlider"
#pragma link "iVCLComponent"
#pragma link "AACtrls"
#pragma link "AAFont"
#pragma link "AACtrls"
#pragma link "AAFont"
#pragma resource "*.dfm"
TmForm *mForm;
//---------------------------------------------------------------------------
__fastcall TmForm::TmForm(TComponent* Owner)
        : TForm(Owner)
{
    state=0;
    usbDev_open();
}
/////////////////////////////////////
__fastcall TmForm::~TmForm()
{
    usbDev_close();
}
//---------------------------------------------------------------------------

void __fastcall TmForm::senddata(void)
{
    unsigned char send[4];
    unsigned char buffer[8];
    if ( state )
    {
        send[0] = H->Position;
        send[1] = S->Position;
        send[2] = V->Position;
    }
    else
    {
        send[0] = R->Position;
        send[1] = G->Position;
        send[2] = B->Position;
    }
    usbDev_transmit(USB_ENDPOINT_OUT,
                 state,
                 send,
                 buffer,
                 sizeof(buffer));
}
void __fastcall TmForm::rgbPositionChangeFinished(TObject *Sender)
{
    H->Position = 0;
    S->Position = 0;
    V->Position = 0;

    state = 0;
    senddata();
}
//---------------------------------------------------------------------------

void __fastcall TmForm::hsvPositionChangeFinished(TObject *Sender)
{
    R->Position = 0;
    G->Position = 0;
    B->Position = 0;

    state = 1;
    senddata();
}

/*------------------------------------------------------------------------------
										  0ooo
								ooo0     (   )
								(   )     ) /
								 \ (     (_/
	    				          \_)        By:cuiqingwei [gary]
------------------------------------------------------------------------------*/

