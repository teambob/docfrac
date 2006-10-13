//---------------------------------------------------------------------------
#ifndef TProgressFormH
#define TProgressFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TProgressForm : public TForm
{
__published:	// IDE-managed Components
    TProgressBar *ProgressBar;
    TLabel *Label1;
    TLabel *Label2;
    TButton *CancelButton;
    TStaticText *FromText;
    TStaticText *ToText;
    void __fastcall FormShow(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TProgressForm(TComponent* Owner);
    void __fastcall OnFinished(TObject *Sender);
    void __fastcall OnProgress(System::TObject *Sender, int percent);
    void SetInPathname(const AnsiString &string);
    void SetOutPathname(const AnsiString &string);
};
//---------------------------------------------------------------------------
extern PACKAGE TProgressForm *ProgressForm;
//---------------------------------------------------------------------------
#endif
