//---------------------------------------------------------------------------

#ifndef MainH
#define MainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include "usb.h"
#include "iComponent.hpp"
#include "iCustomComponent.hpp"
#include "iPositionComponent.hpp"
#include "iScaleComponent.hpp"
#include "iSlider.hpp"
#include "iVCLComponent.hpp"
#include "AACtrls.hpp"
#include "AAFont.hpp"

#define	USBDEV_VENDOR	0x16c0
#define	USBDEV_PRODUCT	0x05dc

static usb_dev_handle *usbhandle;
static unsigned char state;
//---------------------------------------------------------------------------
class TmForm : public TForm
{
__published:	// IDE-managed Components
    TGroupBox *rgbGroup;
    TiSlider *R;
    TiSlider *G;
    TiSlider *B;
    TGroupBox *hsvGroup;
    TiSlider *H;
    TiSlider *S;
    TiSlider *V;
    TLabel *Rl;
    TLabel *Gl;
    TLabel *Bl;
    TLabel *Hl;
    TLabel *Sl;
    TLabel *Vl;
    TAAFadeText *AAFadeText;
    void __fastcall rgbPositionChangeFinished(TObject *Sender);
    void __fastcall hsvPositionChangeFinished(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TmForm(TComponent* Owner);
        __fastcall ~TmForm();
        void __fastcall senddata(void);
};
//---------------------------------------------------------------------------
extern PACKAGE TmForm *mForm;
//---------------------------------------------------------------------------
#endif
