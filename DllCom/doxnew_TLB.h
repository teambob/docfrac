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
#ifndef   __doxnew_TLB_h__
#define   __doxnew_TLB_h__

#pragma option push -b


#include <sysdefs.h>
#include <utilcls.h>
#include <stdvcl.hpp>
#include <ocxproxy.h>

namespace Doxnew_tlb
{

// *********************************************************************//
// HelpString: Power version of Dox COM/ActiveX library.
// Version:    1.0
// *********************************************************************//


// *********************************************************************//
// GUIDS declared in the TypeLibrary. Following prefixes are used:      //
//   Type Libraries     : LIBID_xxxx                                    //
//   CoClasses          : CLSID_xxxx                                    //
//   DISPInterfaces     : DIID_xxxx                                     //
//   Non-DISP interfaces: IID_xxxx                                      //
// *********************************************************************//
DEFINE_GUID(LIBID_doxnew, 0xAC409B5B, 0x9405, 0x4D46, 0xB7, 0xCC, 0x39, 0xEB, 0x8C, 0x3B, 0x1F, 0x50);
DEFINE_GUID(IID_IDoxNG, 0x724B9527, 0x477D, 0x4BE1, 0x93, 0xEA, 0x77, 0x5C, 0xD8, 0xD5, 0x92, 0xFE);
DEFINE_GUID(CLSID_DoxNG, 0xE113C0B0, 0x288C, 0x4FE1, 0x8E, 0x97, 0x4C, 0xEF, 0x96, 0xD1, 0xBE, 0x40);

// *********************************************************************//
// Forward declaration of interfaces defined in Type Library            //
// *********************************************************************//
interface IDoxNG;

// *********************************************************************//
// Declaration of CoClasses defined in Type Library                     //
// (NOTE: Here we map each CoClass to it's Default Interface            //
// *********************************************************************//
typedef IDoxNG DoxNG;
// *********************************************************************//
// Interface: IDoxNG
// Flags:     (4416) Dual OleAutomation Dispatchable
// GUID:      {724B9527-477D-4BE1-93EA-775CD8D592FE}
// *********************************************************************//
interface IDoxNG : public IDispatch
{
public:
  virtual HRESULT STDMETHODCALLTYPE Convert(void) = 0; // [1]
  virtual HRESULT STDMETHODCALLTYPE SetInFileName(LPSTR FileName/*[in]*/) = 0; // [2]
  virtual HRESULT STDMETHODCALLTYPE SetOutFileName(LPSTR FileName/*[in]*/) = 0; // [3]
  virtual HRESULT STDMETHODCALLTYPE DebugOn(int Value/*[in]*/) = 0; // [4]
  virtual HRESULT STDMETHODCALLTYPE SetInFormat(LPSTR Extension/*[in]*/) = 0; // [5]
  virtual HRESULT STDMETHODCALLTYPE SetOutFormat(LPSTR Extension/*[in]*/) = 0; // [6]
  virtual HRESULT STDMETHODCALLTYPE UseFeature(LPSTR Feature/*[in]*/) = 0; // [7]
  virtual HRESULT STDMETHODCALLTYPE SetInString(LPSTR In/*[in]*/) = 0; // [8]
  virtual BSTR STDMETHODCALLTYPE StringConvert(void) = 0; // [9]
  virtual HRESULT STDMETHODCALLTYPE Done(void) = 0; // [10]
};

// *********************************************************************//
// SmartIntf: TCOMIDoxNG
// Interface: IDoxNG
// *********************************************************************//
class TCOMIDoxNG : public TComInterface<IDoxNG>
{
public:
  TCOMIDoxNG() {}
  TCOMIDoxNG(IDoxNG *intf, bool addRef = false) : TComInterface<IDoxNG>(intf, addRef) {}
};

// *********************************************************************//
// DispIntf:  IDoxNG
// Flags:     (4416) Dual OleAutomation Dispatchable
// GUID:      {724B9527-477D-4BE1-93EA-775CD8D592FE}
// *********************************************************************//
class IDoxNGDisp : public TAutoDriver<IDoxNG>
{
  typedef TDispId<IDoxNG> _TDispID;
public:

  IDoxNGDisp()
  {}

  IDoxNGDisp& operator=(IDoxNG *pintf)
  {
    TAutoDriver<IDoxNG>::Bind(pintf);
  }

  HRESULT BindDefault(/*Binds to CoClass DoxNG*/)
  {
    return OLECHECK(Bind(CLSID_DoxNG));
  }

  HRESULT /*[VT_HRESULT:0]*/  Convert()
  {
    static _TDispID _dispid(*this, OLETEXT("Convert"), DISPID(1));
    return OleFunction(_dispid);
  }

  HRESULT /*[VT_HRESULT:0]*/  SetInFileName(LPSTR FileName/*[in]*/)
  {
    static _TDispID _dispid(*this, OLETEXT("SetInFileName"), DISPID(2));
    TAutoArgs<1> _args;
    _args[1] = FileName /*[VT_LPSTR:0]*/;
    return OleFunction(_dispid, _args);
  }

  HRESULT /*[VT_HRESULT:0]*/  SetOutFileName(LPSTR FileName/*[in]*/)
  {
    static _TDispID _dispid(*this, OLETEXT("SetOutFileName"), DISPID(3));
    TAutoArgs<1> _args;
    _args[1] = FileName /*[VT_LPSTR:0]*/;
    return OleFunction(_dispid, _args);
  }

  HRESULT /*[VT_HRESULT:0]*/  DebugOn(int Value/*[in]*/)
  {
    static _TDispID _dispid(*this, OLETEXT("DebugOn"), DISPID(4));
    TAutoArgs<1> _args;
    _args[1] = Value /*[VT_INT:0]*/;
    return OleFunction(_dispid, _args);
  }

  HRESULT /*[VT_HRESULT:0]*/  SetInFormat(LPSTR Extension/*[in]*/)
  {
    static _TDispID _dispid(*this, OLETEXT("SetInFormat"), DISPID(5));
    TAutoArgs<1> _args;
    _args[1] = Extension /*[VT_LPSTR:0]*/;
    return OleFunction(_dispid, _args);
  }

  HRESULT /*[VT_HRESULT:0]*/  SetOutFormat(LPSTR Extension/*[in]*/)
  {
    static _TDispID _dispid(*this, OLETEXT("SetOutFormat"), DISPID(6));
    TAutoArgs<1> _args;
    _args[1] = Extension /*[VT_LPSTR:0]*/;
    return OleFunction(_dispid, _args);
  }

  HRESULT /*[VT_HRESULT:0]*/  UseFeature(LPSTR Feature/*[in]*/)
  {
    static _TDispID _dispid(*this, OLETEXT("UseFeature"), DISPID(7));
    TAutoArgs<1> _args;
    _args[1] = Feature /*[VT_LPSTR:0]*/;
    return OleFunction(_dispid, _args);
  }

  HRESULT /*[VT_HRESULT:0]*/  SetInString(LPSTR In/*[in]*/)
  {
    static _TDispID _dispid(*this, OLETEXT("SetInString"), DISPID(8));
    TAutoArgs<1> _args;
    _args[1] = In /*[VT_LPSTR:0]*/;
    return OleFunction(_dispid, _args);
  }

  BSTR /*[VT_BSTR:0]*/  StringConvert()
  {
    static _TDispID _dispid(*this, OLETEXT("StringConvert"), DISPID(9));
    TAutoArgs<0> _args;
    OleFunction(_dispid, _args);
    return _args.GetRetVariant();
  }

  HRESULT /*[VT_HRESULT:0]*/  Done()
  {
    static _TDispID _dispid(*this, OLETEXT("Done"), DISPID(10));
    return OleFunction(_dispid);
  }

};


// *********************************************************************//
// COCLASS DEFAULT INTERFACE CREATOR
// CoClass  : DoxNG
// Interface: TCOMIDoxNG
// *********************************************************************//
class CoDoxNG : public CoClassCreator
{
public:
  static TCOMIDoxNG Create(void);
  static TCOMIDoxNG CreateRemote(LPWSTR machineName);

  static HRESULT Create(TCOMIDoxNG& defIntfObj);
  static HRESULT CreateRemote(LPWSTR machineName, TCOMIDoxNG& defIntfObj);
};

};     // namespace Doxnew_tlb

#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using  namespace Doxnew_tlb;
#endif

#pragma option pop

#endif // __doxnew_TLB_h__
