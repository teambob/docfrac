//---------------------------------------------------------------------------
//
// Name:        MainForm.h
// Author:      Andrew Punch
// Created:     19/09/2007 10:04:41 PM
// Description: MainForm class declaration
//
//---------------------------------------------------------------------------

#ifndef __MAINFORM_h__
#define __MAINFORM_h__

#ifdef __BORLANDC__
	#pragma hdrstop
#endif

#ifndef WX_PRECOMP
	#include <wx/wx.h>
	#include <wx/frame.h>
#else
	#include <wx/wxprec.h>
#endif

//Do not add custom headers between 
//Header Include Start and Header Include End.
//wxDev-C++ designer will remove them. Add custom headers after the block.
////Header Include Start
#include <wx/filedlg.h>
#include <wx/menu.h>
#include <wx/listctrl.h>
#include <wx/statusbr.h>
#include <wx/toolbar.h>
////Header Include End
#include "Document.h"

////Dialog Style Start
#undef MainForm_STYLE
#define MainForm_STYLE wxCAPTION | wxRESIZE_BORDER | wxSYSTEM_MENU | wxMINIMIZE_BOX | wxMAXIMIZE_BOX | wxCLOSE_BOX
////Dialog Style End

class MainForm : public wxFrame
{
	private:
		DECLARE_EVENT_TABLE();
		Documents documents;
		
	public:
		MainForm(wxWindow *parent, wxWindowID id = 1, const wxString &title = wxT("DocFrac"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = MainForm_STYLE);
		virtual ~MainForm();
	void OnFilesAddClick(wxCommandEvent& event);
	void OnFileConvertClick(wxCommandEvent& event);
		
	private:
		//Do not add custom control declarations between
		//GUI Control Declaration Start and GUI Control Declaration End.
		//wxDev-C++ will remove them. Add custom code after the block.
		////GUI Control Declaration Start
		wxFileDialog *OpenFilesDialog;
		wxMenuBar *MenuBar;
		wxListCtrl *FileList;
		wxStatusBar *WxStatusBar1;
		wxToolBar *ToolBar;
		////GUI Control Declaration End
		
	private:
		//Note: if you receive any error with these enum IDs, then you need to
		//change your old form code that are based on the #define control IDs.
		//#defines may replace a numeric value for the enum names.
		//Try copy and pasting the below block in your old form header files.
		enum
		{
			////GUI Enum Control ID Start
			ID_MNU_FILE = 1000,
			ID_MNU_FILES_ADD = 1001,
			ID_MNU_FILE_PROPERTIES = 1002,
			ID_MNU_FILE_CONVERT = 1003,
			ID_MNU_FILE_MENU = 1005,
			ID_MNU_EDIT = 1200,
			ID_MNU_EDIT_SELECT_ALL = 1201,
			ID_MNU_EDIT_REMOVE = 1202,
			ID_MNU_EDIT_CLEAR = 1203,
			ID_MNU_HELP = 1300,
			ID_MNU_ABOUT = 1301,
			
			ID_FILELIST = 1005,
			ID_WXSTATUSBAR1 = 1003,
			ID_TOOLBAR = 1002,
			////GUI Enum Control ID End
			ID_DUMMY_VALUE_ //don't remove this value unless you have other enum values
		};
		
	private:
		void OnClose(wxCloseEvent& event);
		void CreateGUIControls();
		bool AddNewFiles(Documents &newDocuments);
		void UpdateDisplay(void);
};

#endif
