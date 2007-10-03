//---------------------------------------------------------------------------
//
// Name:        wxDocfracApp.cpp
// Author:      Andrew Punch
// Created:     19/09/2007 10:04:41 PM
// Description: 
//
//---------------------------------------------------------------------------

#include "wxDocfracApp.h"
#include "MainForm.h"

IMPLEMENT_APP(MainFormApp)

bool MainFormApp::OnInit()
{
    MainForm* frame = new MainForm(NULL);
    SetTopWindow(frame);
    frame->Show();
    return true;
}
 
int MainFormApp::OnExit()
{
	return 0;
}
