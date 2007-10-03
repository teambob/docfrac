//---------------------------------------------------------------------------
//
// Name:        wxDocfracApp.h
// Author:      Andrew Punch
// Created:     19/09/2007 10:04:41 PM
// Description: 
//
//---------------------------------------------------------------------------

#ifndef __MAINFORMApp_h__
#define __MAINFORMApp_h__

#ifdef __BORLANDC__
	#pragma hdrstop
#endif

#ifndef WX_PRECOMP
	#include <wx/wx.h>
#else
	#include <wx/wxprec.h>
#endif

class MainFormApp : public wxApp
{
	public:
		bool OnInit();
		int OnExit();
};

#endif
