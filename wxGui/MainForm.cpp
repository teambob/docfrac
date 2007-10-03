//---------------------------------------------------------------------------
//
// Name:        MainForm.cpp
// Author:      Andrew Punch
// Created:     19/09/2007 10:04:41 PM
// Description: MainForm class implementation
//
//---------------------------------------------------------------------------

#include "MainForm.h"
#include "Document.h"
//Do not add custom headers between
//Header Include Start and Header Include End
//wxDev-C++ designer will remove them
////Header Include Start
#include "Images/Self_MainForm_XPM.xpm"
////Header Include End
#include "ExtensionToFormatMap.h"
#include "FilePropertiesForm.h"

//----------------------------------------------------------------------------
// MainForm
//----------------------------------------------------------------------------
//Add Custom Events only in the appropriate block.
//Code added in other places will be removed by wxDev-C++
////Event Table Start
BEGIN_EVENT_TABLE(MainForm,wxFrame)
	////Manual Code Start
	////Manual Code End
	
	EVT_CLOSE(MainForm::OnClose)
	EVT_MENU(ID_MNU_FILES_ADD, MainForm::OnFilesAddClick)
	EVT_MENU(ID_MNU_FILE_CONVERT, MainForm::OnFileConvertClick)
END_EVENT_TABLE()
////Event Table End

MainForm::MainForm(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &position, const wxSize& size, long style)
: wxFrame(parent, id, title, position, size, style)
{
	CreateGUIControls();
}

MainForm::~MainForm()
{
}

void MainForm::CreateGUIControls()
{
	//Do not add custom code between
	//GUI Items Creation Start and GUI Items Creation End
	//wxDev-C++ designer will remove them.
	//Add the custom code before or after the blocks
	////GUI Items Creation Start

	ToolBar = new wxToolBar(this, ID_TOOLBAR, wxPoint(0,0), wxSize(622,29));
	ToolBar->SetFont(wxFont(12, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	WxStatusBar1 = new wxStatusBar(this, ID_WXSTATUSBAR1);

	FileList = new wxListCtrl(this, ID_FILELIST, wxPoint(35,92), wxSize(250,150), wxLC_REPORT);
	FileList->InsertColumn(0,wxT("Output Filename"),wxLIST_FORMAT_LEFT,320 );
	FileList->InsertColumn(0,wxT("Input Filename"),wxLIST_FORMAT_LEFT,320 );
	FileList->SetFont(wxFont(12, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	MenuBar = new wxMenuBar();
	wxMenu *ID_MNU_FILE_Mnu_Obj = new wxMenu(0);
	ID_MNU_FILE_Mnu_Obj->Append(ID_MNU_FILES_ADD, wxT("&Add Files...\tCtrl+O"), wxT(""), wxITEM_NORMAL);
	ID_MNU_FILE_Mnu_Obj->Append(ID_MNU_FILE_PROPERTIES, wxT("&Properties..."), wxT(""), wxITEM_NORMAL);
	ID_MNU_FILE_Mnu_Obj->Append(ID_MNU_FILE_CONVERT, wxT("&Convert...\tCtrl+S"), wxT(""), wxITEM_NORMAL);
	ID_MNU_FILE_Mnu_Obj->AppendSeparator();
	ID_MNU_FILE_Mnu_Obj->Append(ID_MNU_FILE_MENU, wxT("E&xit"), wxT(""), wxITEM_NORMAL);
	MenuBar->Append(ID_MNU_FILE_Mnu_Obj, wxT("&File"));
	
	wxMenu *ID_MNU_EDIT_Mnu_Obj = new wxMenu(0);
	ID_MNU_EDIT_Mnu_Obj->Append(ID_MNU_EDIT_SELECT_ALL, wxT("Select &All\tCtrl+A"), wxT(""), wxITEM_NORMAL);
	ID_MNU_EDIT_Mnu_Obj->Append(ID_MNU_EDIT_REMOVE, wxT("&Remove from list\tDel"), wxT(""), wxITEM_NORMAL);
	ID_MNU_EDIT_Mnu_Obj->Append(ID_MNU_EDIT_CLEAR, wxT("&Clear list\tShift+Del"), wxT(""), wxITEM_NORMAL);
	MenuBar->Append(ID_MNU_EDIT_Mnu_Obj, wxT("&Edit"));
	
	wxMenu *ID_MNU_HELP_Mnu_Obj = new wxMenu(0);
	ID_MNU_HELP_Mnu_Obj->Append(ID_MNU_ABOUT, wxT("&About"), wxT(""), wxITEM_NORMAL);
	MenuBar->Append(ID_MNU_HELP_Mnu_Obj, wxT("&Help"));
	SetMenuBar(MenuBar);

	OpenFilesDialog =  new wxFileDialog(this, wxT("Choose a file"), wxT(""), wxT(""), wxT("*.*"), wxOPEN | wxMULTIPLE);

	SetStatusBar(WxStatusBar1);
	ToolBar->Realize();
	SetToolBar(ToolBar);
	SetTitle(wxT("DocFrac"));
	SetIcon(Self_MainForm_XPM);
	SetSize(8,8,630,420);
	Center();
	
	////GUI Items Creation End
}

void MainForm::OnClose(wxCloseEvent& event)
{
	Destroy();
}

/*
 * OnFilesAddClick
 */
void MainForm::OnFilesAddClick(wxCommandEvent& event)
{
/*
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
*/


  if (OpenFilesDialog->ShowModal() == wxID_OK)
  {
    Documents newDocuments;
    wxArrayString paths;
    
    OpenFilesDialog->GetPaths(paths);


    for (int i=0;i<paths.Count();i++)
    {
      Document newDocument;
      newDocument.SetInputFilename(tstring(paths[i].c_str()));
      newDocuments.push_back(newDocument);
    }

    AddNewFiles(newDocuments);
/*
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
*/
  }
/*
  delete reg;
*/
}


bool  MainForm::AddNewFiles(Documents &newDocuments)
{
  DoxEngine::ExtensionToFormatMap extensionMap;
  FilePropertiesForm form(this);

  // Get the last saved settings here
  /*FilePropertiesForm->LoadOptions();

  if (newDocuments.size() > 1)
    FilePropertiesForm->SetMultiFile(true);
  else
    FilePropertiesForm->SetMultiFile(false);


*/
  if (form.ShowModal() == wxID_OK)
  {
    wxString formatString(form.OutputFormatSelect->GetValue());
    formatString.LowerCase();
    FileFormat outFormat
      = extensionMap[formatString.c_str()];

    Documents::iterator i;

    for (i=newDocuments.begin();i!=newDocuments.end();i++)
    {
      // Input pathname already set


      i->SetOutputFormat(outFormat);

      // There is probably a better object oriented way to do this but... oh well
      if (!form.AutomaticFilenameSelect->IsChecked())
      {
        // Manual filename
        i->SetOutputManual(form.OutputFilenameEdit->GetValue().c_str());

      }
      else // Automatic filename
      {
        if(form.InputDirectorySelect->GetValue())
          i->SetOutputAutomatic();
        else if (form.OutputDirectorySelect->GetValue())
          i->SetOutputAutomatic(form.OutputDirectoryEdit->GetValue().c_str());
      }
      // Save the last settings here
      //FilePropertiesForm->SaveOptions();
    }
    std::copy(newDocuments.begin(), newDocuments.end()
    , std::back_inserter(documents));
    UpdateDisplay();
    
    return true;
  }
  else
  {
    newDocuments.clear();
    return false;
  }



}


void MainForm::UpdateDisplay(void)
{
  Documents::iterator i;

  FileList->DeleteAllItems();

  for(i=documents.begin();i!=documents.end();i++)
  {
    long row = FileList->InsertItem(FileList->GetItemCount(),wxString(i->GetInputPathname().c_str()));
    FileList->SetItem(row, 1, wxString(i->GetOutputPathname().c_str()));
  }

  //MainStatusBar->SimpleText = documents.size();

  //UpdateEnabled();
}

/*
 * OnFileConvertClick
 */
void MainForm::OnFileConvertClick(wxCommandEvent& event)
{
	// insert your code here
}
