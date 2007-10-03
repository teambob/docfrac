// DocfracDlg.cpp : implementation file
//

#include "stdafx.h"
#include <fstream>
#include <algorithm>

#include "Docfrac.h"
#include "DocfracDlg.h"
#include "winmgr.h"

#include "tstring.h"
#include "FilePropertiesDlg.h"
#include "ExtensionToFormatMap.h"

#include "WriterFactory.h"
#include "ReaderFactory.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


BEGIN_WINDOW_MAP(MyMainWinMap)
BEGINROWS(WRCT_REST,0,0)
  RCREST(IDC_FILE_LIST)
ENDGROUP()
END_WINDOW_MAP()



// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CDocfracDlg dialog




CDocfracDlg::CDocfracDlg(CWnd* pParent /*=NULL*/)
: m_winMgr(MyMainWinMap), CDialog(CDocfracDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDI_APP_ICON);
}

void CDocfracDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_FILE_LIST, m_fileList);
}

BEGIN_MESSAGE_MAP(CDocfracDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_WM_SIZE()
	ON_COMMAND(ID_FILE_ADDFILES, &CDocfracDlg::OnFileAddfiles)
	ON_COMMAND(ID_FILE_CONVERT, &CDocfracDlg::OnFileConvert)
END_MESSAGE_MAP()



// CDocfracDlg message handlers

BOOL CDocfracDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon


	m_winMgr.CalcLayout(this);
	m_winMgr.SetWindowPositions(this);

	LVCOLUMN lvColumn;
	CString localised;

	lvColumn.mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH;
	lvColumn.fmt = LVCFMT_LEFT;
	lvColumn.cx = 120;
	localised.LoadStringW(IDS_INPUT_FILENAME);
	lvColumn.pszText = (LPWSTR)(LPCWSTR) localised;
	m_fileList.InsertColumn(0, &lvColumn);

	lvColumn.mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH;
	lvColumn.fmt = LVCFMT_LEFT;
	lvColumn.cx = 120;
	localised.LoadStringW(IDS_OUTPUT_FILENAME);
	lvColumn.pszText = (LPWSTR)(LPCWSTR) localised;
	m_fileList.InsertColumn(1, &lvColumn);


	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CDocfracDlg::RecalcLayout(BOOL bNotify)
{
   m_winMgr.CalcLayout(this);
   m_winMgr.SetWindowPositions(this);
// Don't call CFrameWnd!
// CFrameWnd::RecalcLayout(bNotify);
}

void CDocfracDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CDocfracDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CDocfracDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CDocfracDlg::OnSize(UINT nType, int cx, int cy)
{
	//CDialog::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here
	m_winMgr.CalcLayout(cx,cy,this);
	m_winMgr.SetWindowPositions(this);
}


void CDocfracDlg::OnFileAddfiles()
{
	// TODO: Add your command handler code here
	CFileDialog openFile(TRUE, NULL, NULL, 0, NULL);


	openFile.m_ofn.lpstrFilter = _TEXT("All supported files|*.rtf,*.htm,*.html,*.txt|RTF files (*.rtf)|*.rtf|HTML files (*.html,*.htm)|*.html,*.htm|Text files (*.txt)|*.txt");
	openFile.m_ofn.Flags |= OFN_ALLOWMULTISELECT;
	
	if ( openFile.DoModal() == IDOK )
	{
		size_t index = 0;
		tstring file;
		tstrings files;
		
		while (openFile.m_ofn.lpstrFile[index])
		{
			file.assign(&openFile.m_ofn.lpstrFile[index]);

			files.push_back(file);

			index += file.size() + 1;

		} 

		if ( files.size() > 1)
		{
			// Multiple files selected: first is directory
			file = files.at(0);
			file = file.append(TEXT("\\"));
			files.erase(files.begin());

			for ( tstrings::iterator i = files.begin() ; i != files.end() ; i++ )
			{
				*i = file + *i;
			}
		}

		Documents newDocuments;
		for (tstrings::iterator i = files.begin(); i != files.end(); i++)
		{
			Document document;
			document.SetInputFilename(*i);
			newDocuments.push_back(document);
		}
		AddNewFiles(newDocuments);

		m_documents.insert(m_documents.end(), newDocuments.begin(), newDocuments.end());



			UpdateDisplay();

			

		



	}

	
	


}

// Update list, menus and status bar
void CDocfracDlg::UpdateDisplay(void)
{
	m_fileList.DeleteAllItems();

	for(Documents::iterator i=m_documents.begin();i!=m_documents.end();i++)
	{
		AddBatchItem(i->GetInputPathname(), i->GetOutputPathname());
	}
	


}

void CDocfracDlg::AddBatchItem(tstring input, tstring output)
{
	LVITEM lvItem;
	int nItem;

	lvItem.mask = LVIF_TEXT;
	lvItem.iItem = 0;
	lvItem.iSubItem = 0;
	lvItem.pszText = (LPTSTR)input.c_str();
	nItem = m_fileList.InsertItem(&lvItem);

	m_fileList.SetItemText(nItem, 1, output.c_str());

}

void CDocfracDlg::OnFileConvert()
{
  Document i;
  DoxEngine::DebugLog log;

  while(!m_documents.empty())
  {
	// Equivalent to std::queue::front()
    i =m_documents.front();

	std::ifstream input(i.GetInputPathname().c_str());
	std::ofstream output(i.GetOutputPathname().c_str());

	DoxEngine::WriterFactories &writerFactories = DoxEngine::WriterFactoriesSingleton::GetWriterFactories();
	DoxEngine::WriterInterface *writer;
	DoxEngine::ReadInterface *reader = NULL;

		DoxEngine::WriterFactories::iterator writerIterator = writerFactories.find(i.GetOutputFormat());
		if (writerIterator == writerFactories.end())
		{
			//throw ThreadException("Internal error initialising writer");
		}
		else
		{
			// First type is the key (file format)
			// Second type is the value (factory instance)
			writer = writerIterator->second->Create(output, log);
		}
	
		DoxEngine::ReaderFactories &readerFactories = DoxEngine::ReaderFactoriesSingleton::GetReaderFactories();

		DoxEngine::ReaderFactories::iterator readerIterator = readerFactories.find(i.GetInputFormat());
		if (readerIterator == readerFactories.end())
		{
			//throw ThreadException("Internal error initialising reader");
		}
		else
		{
			// First type is the key (file format)
			// Second type is the value (factory instance)
			reader = readerIterator->second->Create(input, *writer, log);
		}

		input.exceptions(input.badbit);
		output.exceptions(output.badbit);


		while (reader->processData()/*&&!Terminated*/ && input.good())
		{
			//percentage = 100*input.tellg()/fileSize; // Calculate percentage
			//Synchronize((TThreadMethod)&UpdateProgress);
		}

    delete reader;
    delete writer;


    // Equivalent to std::queue::pop() or pop_front()
    m_documents.erase(m_documents.begin());

  }

  UpdateDisplay();

}


bool CDocfracDlg::AddNewFiles(Documents &newDocuments)
{
  DoxEngine::ExtensionToFormatMap extensionMap;
  FilePropertiesDlg dialog;

  // Get the last saved settings here
  /* TODO
  FilePropertiesForm->LoadOptions();

  if (newDocuments.size() > 1)
    FilePropertiesForm->SetMultiFile(true);
  else
    FilePropertiesForm->SetMultiFile(false);*/



  if (dialog.DoModal() == IDOK)
  {
    tstring outFormatString(dialog.m_OutputFormatSelect.GetString());
	std::transform(outFormatString.begin(),outFormatString.end(), outFormatString.begin(), tolower); 


	FileFormat outFormat
		= extensionMap[outFormatString];

    Documents::iterator i;

    for (i=newDocuments.begin();i!=newDocuments.end();i++)
    {
      // Input pathname already set


      i->SetOutputFormat(outFormat);

      // There is probably a better object oriented way to do this but... oh well
	  if (!dialog.m_AutomaticFilenameSelect)
      {
        // Manual filename
		  i->SetOutputManual(dialog.m_OutputFilenameEdit.GetString());

      }
      else // Automatic filename
      {
		if(dialog.m_InputDirectorySelect)
          i->SetOutputAutomatic();
		else if (dialog.m_OtherDirectorySelect)
			i->SetOutputAutomatic(dialog.m_OutputDirectoryEdit.GetString());
      }
      // Save the last settings here
      // TODO: FilePropertiesForm->SaveOptions();
    }
    return true;
  }
  else
  {
    newDocuments.clear();
    return false;
  }



} 
