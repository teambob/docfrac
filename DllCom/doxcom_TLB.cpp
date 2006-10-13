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

/* File generated on 2/06/2004 6:47:16 PM from Type Library described below. */

// ************************************************************************ //
// Type Lib: C:\data\DOX_ST~1\DOCFRA~1.0\DllCom\doxcom.tlb
// IID\LCID: {984AF200-1620-11D4-AD01-00C0DFE60BB5}\0
// Helpfile: C:\data\DOX_ST~1\DOCFRA~1.0\DllCom\doxcom.tlb
// DepndLst: 
//   (1) v2.0 stdole, (C:\WINNT\system32\stdole2.tlb)
// ************************************************************************ //

#include <vcl.h>
#pragma hdrstop
#if defined(USING_ATLVCL)
#include <atl\atlvcl.h>
#endif

#include "doxcom_TLB.h"

#if !defined(__PRAGMA_PACKAGE_SMART_INIT)
#define      __PRAGMA_PACKAGE_SMART_INIT
#pragma package(smart_init)
#endif

namespace Doxcom_tlb
{


// *********************************************************************//
// GUIDS declared in the TypeLibrary                                    //
// *********************************************************************//
extern "C" const GUID LIBID_doxcom = {0x984AF200, 0x1620, 0x11D4,{ 0xAD, 0x01, 0x00, 0xC0, 0xDF, 0xE6, 0x0B, 0xB5} };
extern "C" const GUID IID_IDoxLib = {0x984AF201, 0x1620, 0x11D4,{ 0xAD, 0x01, 0x00, 0xC0, 0xDF, 0xE6, 0x0B, 0xB5} };
extern "C" const GUID CLSID_DoxLib = {0x984AF203, 0x1620, 0x11D4,{ 0xAD, 0x01, 0x00, 0xC0, 0xDF, 0xE6, 0x0B, 0xB5} };
extern "C" const GUID IID_IDocFracLib = {0x87657306, 0xE15B, 0x45CA,{ 0x94, 0x43, 0xAA, 0x97, 0x46, 0x52, 0x68, 0x01} };
extern "C" const GUID CLSID_DocFracLib = {0xFD70E1F4, 0x00C7, 0x47B4,{ 0xB7, 0x39, 0xB9, 0xA2, 0x90, 0xAD, 0x51, 0x85} };



// *********************************************************************//
// COCLASS DEFAULT INTERFACE CREATOR
// (The following methods provide an easy way to create an instance of
//  the default interface, IDoxLib, of the CoClass DoxLib)
// *********************************************************************//

HRESULT CoDoxLib::Create(TCOMIDoxLib& _intf)
{
  static TInitOle __initializeOle;
  return CoCreateInstance(CLSID_DoxLib, IID_IDoxLib, (LPVOID*)&_intf);
};

TCOMIDoxLib CoDoxLib::Create(void)
{
  TCOMIDoxLib _intf;
  Create(_intf);
  return _intf;
};

HRESULT CoDoxLib::CreateRemote(LPWSTR machineName, TCOMIDoxLib& _intf)
{
  static TInitOle __initializeOle;
  COSERVERINFO ServerInfo = { 0, machineName, NULL, 0 };
  MULTI_QI MQI = { &IID_IDoxLib, NULL, 0 };
  HRESULT _hr = ::CoCreateInstanceEx(CLSID_DoxLib, NULL,
                                     CLSCTX_LOCAL_SERVER|
                                     CLSCTX_REMOTE_SERVER|
                                     CLSCTX_INPROC_SERVER,
                                     &ServerInfo, 1, &MQI);
  if (SUCCEEDED(_hr))
    _intf = (IDoxLib*)MQI.pItf;
  return _hr;
};

TCOMIDoxLib CoDoxLib::CreateRemote(LPWSTR machineName)
{
  TCOMIDoxLib _intf;
  CreateRemote(machineName, _intf);
  return _intf;
};




// *********************************************************************//
// COCLASS DEFAULT INTERFACE CREATOR
// (The following methods provide an easy way to create an instance of
//  the default interface, IDocFracLib, of the CoClass DocFracLib)
// *********************************************************************//

HRESULT CoDocFracLib::Create(TCOMIDocFracLib& _intf)
{
  static TInitOle __initializeOle;
  return CoCreateInstance(CLSID_DocFracLib, IID_IDocFracLib, (LPVOID*)&_intf);
};

TCOMIDocFracLib CoDocFracLib::Create(void)
{
  TCOMIDocFracLib _intf;
  Create(_intf);
  return _intf;
};

HRESULT CoDocFracLib::CreateRemote(LPWSTR machineName, TCOMIDocFracLib& _intf)
{
  static TInitOle __initializeOle;
  COSERVERINFO ServerInfo = { 0, machineName, NULL, 0 };
  MULTI_QI MQI = { &IID_IDocFracLib, NULL, 0 };
  HRESULT _hr = ::CoCreateInstanceEx(CLSID_DocFracLib, NULL,
                                     CLSCTX_LOCAL_SERVER|
                                     CLSCTX_REMOTE_SERVER|
                                     CLSCTX_INPROC_SERVER,
                                     &ServerInfo, 1, &MQI);
  if (SUCCEEDED(_hr))
    _intf = (IDocFracLib*)MQI.pItf;
  return _hr;
};

TCOMIDocFracLib CoDocFracLib::CreateRemote(LPWSTR machineName)
{
  TCOMIDocFracLib _intf;
  CreateRemote(machineName, _intf);
  return _intf;
};

};     // namespace Doxcom_tlb
