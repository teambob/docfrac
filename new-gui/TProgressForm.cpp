//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include <string>
#include "TProgressForm.h"
#include "FilenameClass.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TProgressForm *ProgressForm;
//---------------------------------------------------------------------------
__fastcall TProgressForm::TProgressForm(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TProgressForm::OnFinished(TObject *Sender)
{
  ModalResult = mrOk;
  Invalidate();

}

void __fastcall TProgressForm::OnProgress(System::TObject *Sender, int percent)
{
  ProgressBar->Position = percent;

}
void __fastcall TProgressForm::FormShow(TObject *Sender)
{
  ProgressBar->Position = 0;    
}
//---------------------------------------------------------------------------
void TProgressForm::SetInPathname(const AnsiString &string)
{
  FilenameClass pathname(string.c_str());
  FromText->Caption = pathname.GetFilename().c_str();
  FromText->Hint = pathname.c_str();
}

void TProgressForm::SetOutPathname(const AnsiString &string)
{
  FilenameClass pathname(string.c_str());
  ToText->Caption = pathname.GetFilename().c_str();
  ToText->Hint = pathname.c_str();

}

