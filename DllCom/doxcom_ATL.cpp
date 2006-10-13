//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "doxcom_ATL.h"

#ifdef _ATL_STATIC_REGISTRY
#include <statreg.h>
#include <statreg.cpp>
#endif

#include <atlimpl.cpp>
#include <atlctl.cpp>

#if defined(USING_ATLVCL)
#include <atlvcl.cpp>
#else
#include <atlwin.cpp>
#endif

//---------------------------------------------------------------------------
#pragma package(smart_init)
