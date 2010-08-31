//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "THidthread.h"
#include "main.h"

#pragma package(smart_init)

//---------------------------------------------------------------------------

//   Important: Methods and properties of objects in VCL can only be
//   used in a method called using Synchronize, for example:
//
//      Synchronize(UpdateCaption);
//
//   where UpdateCaption could look like:
//
//      void __fastcall HidThread::UpdateCaption()
//      {
//        Form1->Caption = "Updated in a thread";
//      }
//---------------------------------------------------------------------------

__fastcall THidthread::THidthread(bool CreateSuspended)
        : TThread(CreateSuspended)
{
}
//---------------------------------------------------------------------------
void __fastcall THidthread::Execute()
{
   while(!Terminated)
   {
      Sleep(HID_INTERVAL_TIME);
      usb_HID->GetHIDData();
   }  
}
//---------------------------------------------------------------------------






