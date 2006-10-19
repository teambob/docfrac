//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include <shlobj.h>
#include <filectrl.hpp>
#include <Registry.hpp>

#include <string>
#include <vector>


#include "TFilePropertiesForm.h"
#include "FilenameClass.h"
#include "keyname.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFilePropertiesForm *FilePropertiesForm;



//---------------------------------------------------------------------------
__fastcall TFilePropertiesForm::TFilePropertiesForm(TComponent* Owner)
    : TForm(Owner)
{
  lastFile = new FilenameClass;
}

__fastcall TFilePropertiesForm::~TFilePropertiesForm()
{
  delete lastFile;
}

void TFilePropertiesForm::SetMultiFile(bool value)
{
  multiFile = value;

  if (multiFile)
  {
    AutomaticFilenameSelect->Checked = true;
    AutomaticFilenameSelect->Enabled = false;
  }
  else
  {
    AutomaticFilenameSelect->Enabled = true;
  }

  // Update the enabled state of the controls
  AutomaticFilenameSelectClick(this);
}
//---------------------------------------------------------------------------
void __fastcall TFilePropertiesForm::OutputFilenameBrowseClick(
      TObject *Sender)
{
  OutputFilenameDialog->InitialDir = lastFile->GetDirectory().c_str();
  if (OutputFilenameDialog->Execute())
  {
    OutputFilenameEdit->Text = OutputFilenameDialog->FileName;
    *lastFile = OutputFilenameDialog->FileName.c_str();
  }
}
//---------------------------------------------------------------------------
void __fastcall TFilePropertiesForm::AutomaticFilenameSelectClick(
      TObject *Sender)
{
  OutputFilenameEdit->Enabled = !AutomaticFilenameSelect->Checked;
  OutputFilenameBrowse->Enabled = !AutomaticFilenameSelect->Checked;

  InputDirectorySelect->Enabled = AutomaticFilenameSelect->Checked;
  OutputDirectorySelect->Enabled = AutomaticFilenameSelect->Checked;

  OutputDirectoryEdit->Enabled = AutomaticFilenameSelect->Checked
    && OutputDirectorySelect->Checked;
  OutputDirectoryBrowse->Enabled = AutomaticFilenameSelect->Checked
    && OutputDirectorySelect->Checked;

}
//---------------------------------------------------------------------------
void __fastcall TFilePropertiesForm::InputDirectorySelectClick(
      TObject *Sender)
{
  OutputDirectoryEdit->Enabled = false;
  OutputDirectoryBrowse->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TFilePropertiesForm::OutputDirectorySelectClick(
      TObject *Sender)
{
  OutputDirectoryEdit->Enabled = true;
  OutputDirectoryBrowse->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TFilePropertiesForm::OutputDirectoryBrowseClick(
	  TObject *Sender)
{
	char Buffer[MAX_PATH];
	BROWSEINFO Lpbi; // See MS OLE Reference.
  LPITEMIDLIST PIDL;


  Lpbi.hwndOwner = Application->DialogHandle; // Window housekeeping
  Lpbi.pidlRoot = NULL;                         // Start from desktop
  Lpbi.pszDisplayName = Buffer;                 // Buffer for value
  Lpbi.lpszTitle = "Please select an output folder.";
  Lpbi.ulFlags = 0;   // No restrictions
  Lpbi.lpfn = NULL;   // No callback
  Lpbi.lParam = NULL; // No callback
  Lpbi.iImage = NULL; // No icon return


  PIDL=SHBrowseForFolder(&Lpbi);
  if (PIDL)
	{
		if (SHGetPathFromIDList(PIDL, Buffer))
		  OutputDirectoryEdit->Text = Buffer;
  }
}
//---------------------------------------------------------------------------

void __fastcall TFilePropertiesForm::FormShow(TObject *Sender)
{
  OutputFilenameEdit->Enabled = !AutomaticFilenameSelect->Checked;
  OutputFilenameBrowse->Enabled = !AutomaticFilenameSelect->Checked;
  InputDirectorySelect->Enabled = AutomaticFilenameSelect->Checked;
  OutputDirectorySelect->Enabled = AutomaticFilenameSelect->Checked;

  OutputDirectoryEdit->Enabled = AutomaticFilenameSelect->Checked
    && OutputDirectorySelect->Checked;
  OutputDirectoryBrowse->Enabled = AutomaticFilenameSelect->Checked
    && OutputDirectorySelect->Checked;
}
//---------------------------------------------------------------------------
void TFilePropertiesForm::LoadOptions()
{
  TRegistry *reg = new TRegistry();

  reg->RootKey = HKEY_CURRENT_USER;

  if (reg->OpenKey(KEY_NAME + "\\properties", false))
  {
    if ( reg->ValueExists("format")
      && reg->ValueExists("filename")
      && reg->ValueExists("outputDirectory")
      && reg->ValueExists("browseDirectory")
      && reg->ValueExists("useAutofilename")
      && reg->ValueExists("useCustomDirectory") )
    {
      OutputFormatSelect->ItemIndex = OutputFormatSelect->Items->IndexOf(reg->ReadString("format"));
      OutputDirectoryEdit->Text = reg->ReadString("outputDirectory");
      *lastFile = reg->ReadString("browseDirectory").c_str();

      AutomaticFilenameSelect->Checked = reg->ReadBool("useAutofilename");
      OutputDirectorySelect->Checked = reg->ReadBool("useCustomDirectory");
    }
    reg->CloseKey();
  }
  delete reg;
}

void TFilePropertiesForm::SaveOptions()
{
	TRegistry *reg = new TRegistry();

	reg->RootKey = HKEY_CURRENT_USER;

  if (reg->OpenKey(KEY_NAME + "\\properties", true))
  {
    reg->WriteString("format", OutputFormatSelect->Text);
    reg->WriteString("filename", OutputFilenameEdit->Text);
    reg->WriteString("outputDirectory", OutputDirectoryEdit->Text);
    reg->WriteString("browseDirectory", lastFile->GetDirectory().c_str());

    reg->WriteBool("useAutofilename", AutomaticFilenameSelect->Checked);
    reg->WriteBool("useCustomDirectory", OutputDirectorySelect->Checked);

    reg->CloseKey();

  }
  delete reg;
}

void __fastcall TFilePropertiesForm::Button1Click(TObject *Sender)
{
  if (OutputFormatSelect->ItemIndex == -1)
  {
    ShowMessage("No output format is selected");
    ModalResult = mrNone;
    return;
  }

  if ( AutomaticFilenameSelect->Checked &&
	!InputDirectorySelect->Checked && !OutputDirectoryEdit->Text.Length() )
  {
    ShowMessage("No output filename specified");
    ModalResult = mrNone;
    return;
  }

  if ( !AutomaticFilenameSelect->Checked &&  !OutputFilenameEdit->Text.Length() )
  {
    ShowMessage("No output filename specified");
    ModalResult = mrNone;
  }

}
//---------------------------------------------------------------------------

