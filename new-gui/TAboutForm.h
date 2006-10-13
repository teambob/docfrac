//---------------------------------------------------------------------------
#ifndef TAboutFormH
#define TAboutFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TAboutForm : public TForm
{
__published:	// IDE-managed Components
    TStaticText *DocfracText;
    TImage *DocfracImage;
    TLabel *Label1;
    TStaticText *VersionText;
    TButton *OkButton;
    TLabel *LinkLabel;
    void __fastcall LinkLabelClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TAboutForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TAboutForm *AboutForm;
//---------------------------------------------------------------------------
#endif
