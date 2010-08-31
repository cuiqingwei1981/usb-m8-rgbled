//---------------------------------------------------------------------------

#ifndef HidthreadH
#define HidthreadH
//---------------------------------------------------------------------------
#include <Classes.hpp>
//---------------------------------------------------------------------------
class THidthread : public TThread
{            
private:
protected:
        void __fastcall Execute();
public:
        __fastcall THidthread(bool CreateSuspended);

};
//---------------------------------------------------------------------------
#endif
