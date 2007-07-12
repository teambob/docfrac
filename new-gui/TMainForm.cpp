//---------------------------------------------------------------------------
#include <vcl.h>
#include <Registry.hpp>
#include <windows.h>


#pragma hdrstop
#include <map>
#include <vector>
#include <iterator>
#include <dos.h>

#include "Document.h"
#include "CheckArguments.h"
#include "AddNewFiles.h"
#include "FilenameClass.h"


#include "../core/ExtensionToFormatMap.h"

#include "TMainForm.h"
#include "TEngineThread.h"
#include "TProgressForm.h"
#include "TAboutForm.h"
#include "TFilePropertiesForm.h"
#include "keyname.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"




TMainForm *MainForm;
//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
    : TForm(Owner)
{

}
//---------------------------------------------------------------------------
void __fastcall TMainForm::FileAddClick(TObject *Sender)
{
  TRegistry *reg = new TRegistry;

  reg->RootKey = HKEY_CURRENT_USER;
  if (reg->OpenKey(KEY_NAME, false))
  {
    if (reg->ValueExists("filename"))
    {
      OpenFilesDialog->InitialDir = reg->ReadString("filename");
    }
    reg->CloseKey();
  }



  if (OpenFilesDialog->Execute())
  {
    Documents newDocuments;

    for (int i=0;i<OpenFilesDialog->Files->Count;i++)
    {
      Document newDocument;
      newDocument.SetInputFilename(OpenFilesDialog->Files->Strings[i].c_str());
      newDocuments.push_back(newDocument);
    }



    if (AddNewFiles(newDocuments))
    {
      std::copy(newDocuments.begin(), newDocuments.end()
        , std::back_inserter(documents));
      UpdateDisplay();
    }



    FilenameClass filename(OpenFilesDialog->Files->Strings[0].c_str());

    reg->RootKey = HKEY_CURRENT_USER;
    if (reg->OpenKey(KEY_NAME, false))
    {
      reg->WriteString("filename", filename.GetDirectory().c_str());
      reg->CloseKey();
    }

  }

  delete reg;
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::ContextMenuPopup(TObject *Sender)
{
  PopupProperties->Enabled = FileList->SelCount;
  PopupRemove->Enabled = FileList->SelCount;
}
//---------------------------------------------------------------------------

void TMainForm::UpdateDisplay(void)
{
  Documents::iterator i;

  FileList->Items->Clear();
  for(i=documents.begin();i!=documents.end();i++)
  {
    TListItem *item;
    item = FileList->Items->Add();
    item->Caption = i->GetInputPathname();

    // Create output filename on the fly
    item->SubItems->Add(i->GetOutputPathname());

  }

  MainStatusBar->SimpleText = documents.size();

  UpdateEnabled();
}

void TMainForm::UpdateEnabled(void)
{
  ClearIcon->Enabled = !documents.empty();
  EditClear->Enabled = !documents.empty();
  EditSelectAll->Enabled = !documents.empty();


  RemoveIcon->Enabled = FileList->SelCount;
  EditRemove->Enabled = FileList->SelCount;

  ConvertIcon->Enabled = !documents.empty();
  FileConvert->Enabled = !documents.empty();

  // Can only set properties for one file
  if (FileList->SelCount == 1)
  {
    PropertiesIcon->Enabled = true;
    FileProperties->Enabled = true;
  }
  else
  {
    PropertiesIcon->Enabled = false;
    FileProperties->Enabled = false;
  }



}


void __fastcall TMainForm::ClearIconClick(TObject *Sender)
{
  if (Application->MessageBox(
    "Are you sure you want to clear your list of files?",
    "Clear list?",
    MB_YESNO) == IDYES)
  {
    documents.clear();
    UpdateDisplay();
  }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::FormShow(TObject *Sender)
{
  Documents newDocuments(CheckArguments(_argc, _argv));

  std::copy(newDocuments.begin(), newDocuments.end(),
    std::back_inserter(documents));

  DragAcceptFiles(Handle, TRUE);
  UpdateDisplay();
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::FileExitClick(TObject *Sender)
{
  Close();    
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::ConvertClick(TObject *Sender)
{
  Document i;

  while(!documents.empty())
  {
    // Equivalent to std::queue::front()
    i = documents.front();

    ProgressForm->SetInPathname(i.GetInputPathname());
    ProgressForm->SetOutPathname(i.GetOutputPathname());

    TEngineThread *thread = new TEngineThread(true, i);
    thread->SetOnFinished(ProgressForm->OnFinished);
    thread->SetOnProgress(ProgressForm->OnProgress);
    thread->Resume();

    if (ProgressForm->ShowModal() == mrCancel)
    {
      thread->Terminate();
      thread->WaitFor();
      delete thread;
      break;
    }
    else
    {
      thread->WaitFor();
      if (thread->GetError())
      {
        MessageBox(Handle, thread->GetErrorMessage().c_str(), "Error"
          , MB_OK|MB_ICONERROR);
        delete thread;
        break;
      }
      else
        delete thread;
    }

    // Equivalent to std::queue::pop() or pop_front()
    documents.erase(documents.begin());

  }

  UpdateDisplay();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::HelpAboutClick(TObject *Sender)
{
  AboutForm->ShowModal();    
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::OnDropFiles(TWMDropFiles& Message)
{
  char buff[MAX_PATH];
  HDROP hDrop = (HDROP)Message.Drop;
  Documents newDocuments;
  int numFiles = DragQueryFile(hDrop, -1, NULL, NULL);

  for (int i=0;i<numFiles;i++)
  {
    DragQueryFile(hDrop, i, buff,sizeof(buff));
    Document document;
    document.SetInputFilename(buff);

    newDocuments.push_back(document);
  } // for
  DragFinish(hDrop);

  if (AddNewFiles(newDocuments))
  {
    std::copy(newDocuments.begin(), newDocuments.end()
      , std::back_inserter(documents));
    UpdateDisplay();
  }
}
void __fastcall TMainForm::PropertiesClick(TObject *Sender)
{

  FilePropertiesForm->SetMultiFile(false);
  Document *document = &((documents)[FileList->Selected->Index]);

  // Set the values of File Properties here
  if (document->IsAutomatic())
  {
    FilePropertiesForm->AutomaticFilenameSelect->Checked = true;
    if (document->IsOtherDirectory())
    {
      FilePropertiesForm->OutputDirectorySelect->Checked = true;
      FilePropertiesForm->OutputDirectoryEdit->Text =
        document->GetDirectory();
    }
    else
    {
      FilePropertiesForm->InputDirectorySelect->Checked = true;
    }

  }
  else
  {
    FilePropertiesForm->AutomaticFilenameSelect->Checked = false;

  }



  if (FilePropertiesForm->ShowModal() == mrOk)
  {
    DoxEngine::ExtensionToFormatMap extensionMap;
    FileFormat outFormat
      = extensionMap[FilePropertiesForm->OutputFormatSelect->Text.LowerCase().c_str()];

    // Input pathname already set


    document->SetOutputFormat(outFormat);

    // There is probably a better object oriented way to do this but... oh well
    if (!FilePropertiesForm->AutomaticFilenameSelect->Checked)
    {
      // Manual filename
      document->SetOutputManual(FilePropertiesForm->OutputFilenameEdit->Text.c_str());

    }
    else // Automatic filename
    {
      if(FilePropertiesForm->InputDirectorySelect->Checked)
        document->SetOutputAutomatic();
      else if (FilePropertiesForm->OutputDirectorySelect->Checked)
        document->SetOutputAutomatic(FilePropertiesForm->OutputDirectoryEdit->Text);
    }

    UpdateDisplay();
  }


}
//---------------------------------------------------------------------------



void __fastcall TMainForm::EditSelectAllClick(TObject *Sender)
{
  for (int i=0;i<FileList->Items->Count;i++)
    FileList->Items->Item[i]->Selected = true;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::RemoveIconClick(TObject *Sender)
{
  // Note that we delete items *backward* this is so that indexes are not
  // affected when we continue to delete other indexes
  // Also note that the iterator is invalidated after each erase()
  for (int i=FileList->Items->Count;i>0;i--)
  {
    if (FileList->Items->Item[i-1]->Selected)
      documents.erase(documents.begin()+(i-1));
  }
  UpdateDisplay();

}
//---------------------------------------------------------------------------

void __fastcall TMainForm::FileListChange(TObject *Sender, TListItem *Item,
      TItemChange Change)
{
  if(Change == ctState)
    UpdateEnabled();    
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::FormCloseQuery(TObject *Sender, bool &CanClose)
{
  if (!documents.empty())
  {
    if (Application->MessageBox(
      "Your list of files will be cleared. Are you sure you want to exit?",
      "Exit?",
      MB_YESNO) == IDNO)
    {
      CanClose = false;
    }

  }
}
//---------------------------------------------------------------------------

