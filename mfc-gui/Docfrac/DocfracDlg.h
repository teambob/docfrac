// DocfracDlg.h : header file
//

#pragma once
#include "winmgr.h"
#include "afxcmn.h"
#include "Document.h"

// CDocfracDlg dialog
class CDocfracDlg : public CDialog
{
// Construction
public:
	CDocfracDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_DOCFRAC_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;
	CWinMgr m_winMgr;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	void RecalcLayout(BOOL bNotify);
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnSize(UINT nType, int cx, int cy);
protected:
	CListCtrl m_fileList;
public:
	afx_msg void OnMenuSelect(UINT nItemID, UINT nFlags, HMENU hSysMenu);
	afx_msg void OnFileAddfiles();
private:
	Documents m_documents;
	// Update list, menus and status bar
	void UpdateDisplay(void);
	// Add batch item to list control
	void AddBatchItem(tstring input, tstring output);
	bool AddNewFiles(Documents &newDocuments);
public:
	afx_msg void OnFileConvert();
};
