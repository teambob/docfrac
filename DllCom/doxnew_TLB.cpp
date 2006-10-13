// ************************************************************************ //
// WARNING                                                                  //
// -------                                                                  //
// The types declared in this file were generated from data read from a     //
// Type Library. If this type library is explicitly or indirectly (via      //
// another type library referring to this type library) re-imported, or the //
// 'Refresh' command of the Type Library Editor activated while editing the //
// Type Library, the contents of this file will be regenerated and all      //
// manual modifications will be lost.                                       //
// ************************************************************************ //

/* File generated on 8/06/2001 11:18:34 PM from Type Library described below. */

// ************************************************************************ //
// Type Lib: F:\Data\Old disc\Data\pro\dox\DllCom\doxnew.tlb
// IID\LCID: {AC409B5B-9405-4D46-B7CC-39EB8C3B1F50}\0
// Helpfile: F:\Data\Old disc\Data\pro\dox\DllCom\doxnew.tlb
// DepndLst: 
//   (1) v2.0 stdole, (F:\WINNT\System32\stdole2.tlb)
//   (2) v4.0 StdVCL, (F:\WINNT\System32\STDVCL40.DLL)
// ************************************************************************ //

#include <vcl.h>
#pragma hdrstop
#if defined(USING_ATLVCL)
#include <atl\atlvcl.h>
#endif

#include "doxnew_TLB.h"

#if !defined(__PRAGMA_PACKAGE_SMART_INIT)
#define      __PRAGMA_PACKAGE_SMART_INIT
#pragma package(smart_init)
#endif

namespace Doxnew_tlb
{


// *********************************************************************//
// GUIDS declared in the TypeLibrary                                    //
// *********************************************************************//
extern "C" const GUID LIBID_doxnew = {0xAC409B5B, 0x9405, 0x4D46,{ 0xB7, 0xCC, 0x39, 0xEB, 0x8C, 0x3B, 0x1F, 0x50} };
extern "C" const GUID IID_IDoxNG = {0x724B9527, 0x477D, 0x4BE1,{ 0x93, 0xEA, 0x77, 0x5C, 0xD8, 0xD5, 0x92, 0xFE} };
extern "C" const GUID CLSID_DoxNG = {0xE113C0B0, 0x288C, 0x4FE1,{ 0x8E, 0x97, 0x4C, 0xEF, 0x96, 0xD1, 0xBE, 0x40} };



// *********************************************************************//
// COCLASS DEFAULT INTERFACE CREATOR
// (The following methods provide an easy way to create an instance of
//  the default interface, IDoxNG, of the CoClass DoxNG)
// *********************************************************************//

HRESULT CoDoxNG::Create(TCOMIDoxNG& _intf)
{
  static TInitOle __initializeOle;
  return CoCreateInstance(CLSID_DoxNG, IID_IDoxNG, (LPVOID*)&_intf);
};

TCOMIDoxNG CoDoxNG::Create(void)
{
  TCOMIDoxNG _intf;
  Create(_intf);
  return _intf;
};

HRESULT CoDoxNG::CreateRemote(LPWSTR machineName, TCOMIDoxNG& _intf)
{
  static TInitOle __initializeOle;
  COSERVERINFO ServerInfo = { 0, machineName, NULL, 0 };
  MULTI_QI MQI = { &IID_IDoxNG, NULL, 0 };
  HRESULT _hr = ::CoCreateInstanceEx(CLSID_DoxNG, NULL,
                                     CLSCTX_LOCAL_SERVER|
                                     CLSCTX_REMOTE_SERVER|
                                     CLSCTX_INPROC_SERVER,
                                     &ServerInfo, 1, &MQI);
  if (SUCCEEDED(_hr))
    _intf = (IDoxNG*)MQI.pItf;
  return _hr;
};

TCOMIDoxNG CoDoxNG::CreateRemote(LPWSTR machineName)
{
  TCOMIDoxNG _intf;
  CreateRemote(machineName, _intf);
  return _intf;
};

};     // namespace Doxnew_tlb
