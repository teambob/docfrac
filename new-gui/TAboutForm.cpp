//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "TAboutForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TAboutForm *AboutForm;
//---------------------------------------------------------------------------
__fastcall TAboutForm::TAboutForm(TComponent* Owner)
    : TForm(Owner)
{
  DWORD dwHandle = 0;
  LPTSTR lpFileName = Application->ExeName.c_str();
  DWORD dwLen = GetFileVersionInfoSize(lpFileName, &dwHandle);
  if(dwLen)
  {
    LPVOID lpData = new char[dwLen];

    // the next call fails, but GetLastError returns 0
    if(GetFileVersionInfo(lpFileName, dwHandle, dwLen, lpData))
    {
        LPVOID lplpBuffer = NULL;
        UINT uLen;

        VerQueryValue(lpData, "\\", &lplpBuffer, &uLen);
        VS_FIXEDFILEINFO Info = *(VS_FIXEDFILEINFO *)lplpBuffer;

        VersionText->Caption =
            IntToStr(HIWORD(Info.dwFileVersionMS))
            + "." + IntToStr(LOWORD(Info.dwFileVersionMS))
            + "." + IntToStr(HIWORD(Info.dwFileVersionLS))
            + "." + IntToStr(LOWORD(Info.dwFileVersionLS));

    }
    delete lpData;
  }
}
//---------------------------------------------------------------------------
void __fastcall TAboutForm::LinkLabelClick(TObject *Sender)
{
  ShellExecute(Handle, "open", "http://docfrac.sourceforge.net/", NULL, NULL, 0);
}
//---------------------------------------------------------------------------

