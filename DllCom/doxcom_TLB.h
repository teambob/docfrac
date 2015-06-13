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
#ifndef   __doxcom_TLB_h__
#define   __doxcom_TLB_h__

#pragma option push -b


#include <sysdefs.h>
#include <utilcls.h>
#include <stdvcl.hpp>
#include <ocxproxy.h>

namespace Doxcom_tlb
{

// *********************************************************************//
// HelpString: Dox COM/ActiveX Programming Kit
// Version:    1.0
// *********************************************************************//


// *********************************************************************//
// GUIDS declared in the TypeLibrary. Following prefixes are used:      //
//   Type Libraries     : LIBID_xxxx                                    //
//   CoClasses          : CLSID_xxxx                                    //
//   DISPInterfaces     : DIID_xxxx                                     //
//   Non-DISP interfaces: IID_xxxx                                      //
// *********************************************************************//
DEFINE_GUID(LIBID_doxcom, 0x984AF200, 0x1620, 0x11D4, 0xAD, 0x01, 0x00, 0xC0, 0xDF, 0xE6, 0x0B, 0xB5);
DEFINE_GUID(IID_IDoxLib, 0x984AF201, 0x1620, 0x11D4, 0xAD, 0x01, 0x00, 0xC0, 0xDF, 0xE6, 0x0B, 0xB5);
DEFINE_GUID(CLSID_DoxLib, 0x984AF203, 0x1620, 0x11D4, 0xAD, 0x01, 0x00, 0xC0, 0xDF, 0xE6, 0x0B, 0xB5);
DEFINE_GUID(IID_IDocFracLib, 0x87657306, 0xE15B, 0x45CA, 0x94, 0x43, 0xAA, 0x97, 0x46, 0x52, 0x68, 0x01);
DEFINE_GUID(CLSID_DocFracLib, 0xFD70E1F4, 0x00C7, 0x47B4, 0xB7, 0x39, 0xB9, 0xA2, 0x90, 0xAD, 0x51, 0x85);

// *********************************************************************//
// Forward declaration of interfaces defined in Type Library            //
// *********************************************************************//
interface IDoxLib;
interface IDocFracLib;

// *********************************************************************//
// Declaration of CoClasses defined in Type Library                     //
// (NOTE: Here we map each CoClass to it's Default Interface            //
// *********************************************************************//
typedef IDoxLib DoxLib;
typedef IDocFracLib DocFracLib;
// *********************************************************************//
// Interface: IDoxLib
// Flags:     (4416) Dual OleAutomation Dispatchable
// GUID:      {984AF201-1620-11D4-AD01-00C0DFE60BB5}
// *********************************************************************//
interface IDoxLib : public IDispatch
{
public:
  virtual HRESULT STDMETHODCALLTYPE Convert(void) = 0; // [1]
  virtual HRESULT STDMETHODCALLTYPE SetInFileName(LPSTR FileName/*[in]*/) = 0; // [2]
  virtual HRESULT STDMETHODCALLTYPE SetOutFileName(LPSTR FileName/*[in]*/) = 0; // [3]
  virtual HRESULT STDMETHODCALLTYPE DebugOn(void) = 0; // [4]
  virtual HRESULT STDMETHODCALLTYPE SetInFormat(LPSTR Extension/*[in]*/) = 0; // [5]
  virtual HRESULT STDMETHODCALLTYPE SetOutFormat(LPSTR Extension/*[in]*/) = 0; // [6]
  virtual HRESULT STDMETHODCALLTYPE UseExtractPict(int Use/*[in]*/) = 0; // [7]
  virtual HRESULT STDMETHODCALLTYPE SetInString(LPSTR In/*[in]*/) = 0; // [8]
  virtual BSTR STDMETHODCALLTYPE StringConvert(void) = 0; // [9]
};

// *********************************************************************//
// SmartIntf: TCOMIDoxLib
// Interface: IDoxLib
// *********************************************************************//
class TCOMIDoxLib : public TComInterface<IDoxLib>
{
public:
  TCOMIDoxLib() {}
  TCOMIDoxLib(IDoxLib *intf, bool addRef = false) : TComInterface<IDoxLib>(intf, addRef) {}
};

// *********************************************************************//
// DispIntf:  IDoxLib
// Flags:     (4416) Dual OleAutomation Dispatchable
// GUID:      {984AF201-1620-11D4-AD01-00C0DFE60BB5}
// *********************************************************************//
class IDoxLibDisp : public TAutoDriver<IDoxLib>
{
  typedef TDispId<IDoxLib> _TDispID;
public:

  IDoxLibDisp()
  {}

  IDoxLibDisp& operator=(IDoxLib *pintf)
  {
    TAutoDriver<IDoxLib>::Bind(pintf);
  }

  HRESULT BindDefault(/*Binds to CoClass DoxLib*/)
  {
    return OLECHECK(Bind(CLSID_DoxLib));
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

  HRESULT /*[VT_HRESULT:0]*/  DebugOn()
  {
    static _TDispID _dispid(*this, OLETEXT("DebugOn"), DISPID(4));
    return OleFunction(_dispid);
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

  HRESULT /*[VT_HRESULT:0]*/  UseExtractPict(int Use/*[in]*/)
  {
    static _TDispID _dispid(*this, OLETEXT("UseExtractPict"), DISPID(7));
    TAutoArgs<1> _args;
    _args[1] = Use /*[VT_INT:0]*/;
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

};

// *********************************************************************//
// Interface: IDocFracLib
// Flags:     (4416) Dual OleAutomation Dispatchable
// GUID:      {87657306-E15B-45CA-9443-AA9746526801}
// *********************************************************************//
interface IDocFracLib : public IDispatch
{
public:
  virtual HRESULT STDMETHODCALLTYPE SetInFileName(BSTR FileName/*[in]*/) = 0; // [1]
  virtual HRESULT STDMETHODCALLTYPE SetOutFileName(BSTR FileName/*[in]*/) = 0; // [3]
  virtual HRESULT STDMETHODCALLTYPE SetInFormat(BSTR format/*[in]*/) = 0; // [4]
  virtual HRESULT STDMETHODCALLTYPE SetOutFormat(BSTR format/*[in]*/) = 0; // [5]
  virtual HRESULT STDMETHODCALLTYPE Convert(void) = 0; // [6]
  virtual HRESULT STDMETHODCALLTYPE SetInString(BSTR inString/*[in]*/) = 0; // [7]
  virtual BSTR STDMETHODCALLTYPE StringConvert(void) = 0; // [8]
};

// *********************************************************************//
// SmartIntf: TCOMIDocFracLib
// Interface: IDocFracLib
// *********************************************************************//
class TCOMIDocFracLib : public TComInterface<IDocFracLib>
{
public:
  TCOMIDocFracLib() {}
  TCOMIDocFracLib(IDocFracLib *intf, bool addRef = false) : TComInterface<IDocFracLib>(intf, addRef) {}
};

// *********************************************************************//
// DispIntf:  IDocFracLib
// Flags:     (4416) Dual OleAutomation Dispatchable
// GUID:      {87657306-E15B-45CA-9443-AA9746526801}
// *********************************************************************//
class IDocFracLibDisp : public TAutoDriver<IDocFracLib>
{
  typedef TDispId<IDocFracLib> _TDispID;
public:

  IDocFracLibDisp()
  {}

  IDocFracLibDisp& operator=(IDocFracLib *pintf)
  {
    TAutoDriver<IDocFracLib>::Bind(pintf);
  }

  HRESULT BindDefault(/*Binds to CoClass DocFracLib*/)
  {
    return OLECHECK(Bind(CLSID_DocFracLib));
  }

  HRESULT /*[VT_HRESULT:0]*/  SetInFileName(BSTR FileName/*[in]*/)
  {
    static _TDispID _dispid(*this, OLETEXT("SetInFileName"), DISPID(1));
    TAutoArgs<1> _args;
    _args[1] = FileName /*[VT_BSTR:0]*/;
    return OleFunction(_dispid, _args);
  }

  HRESULT /*[VT_HRESULT:0]*/  SetOutFileName(BSTR FileName/*[in]*/)
  {
    static _TDispID _dispid(*this, OLETEXT("SetOutFileName"), DISPID(3));
    TAutoArgs<1> _args;
    _args[1] = FileName /*[VT_BSTR:0]*/;
    return OleFunction(_dispid, _args);
  }

  HRESULT /*[VT_HRESULT:0]*/  SetInFormat(BSTR format/*[in]*/)
  {
    static _TDispID _dispid(*this, OLETEXT("SetInFormat"), DISPID(4));
    TAutoArgs<1> _args;
    _args[1] = format /*[VT_BSTR:0]*/;
    return OleFunction(_dispid, _args);
  }

  HRESULT /*[VT_HRESULT:0]*/  SetOutFormat(BSTR format/*[in]*/)
  {
    static _TDispID _dispid(*this, OLETEXT("SetOutFormat"), DISPID(5));
    TAutoArgs<1> _args;
    _args[1] = format /*[VT_BSTR:0]*/;
    return OleFunction(_dispid, _args);
  }

  HRESULT /*[VT_HRESULT:0]*/  Convert()
  {
    static _TDispID _dispid(*this, OLETEXT("Convert"), DISPID(6));
    return OleFunction(_dispid);
  }

  HRESULT /*[VT_HRESULT:0]*/  SetInString(BSTR inString/*[in]*/)
  {
    static _TDispID _dispid(*this, OLETEXT("SetInString"), DISPID(7));
    TAutoArgs<1> _args;
    _args[1] = inString /*[VT_BSTR:0]*/;
    return OleFunction(_dispid, _args);
  }

  BSTR /*[VT_BSTR:0]*/  StringConvert()
  {
    static _TDispID _dispid(*this, OLETEXT("StringConvert"), DISPID(8));
    TAutoArgs<0> _args;
    OleFunction(_dispid, _args);
    return _args.GetRetVariant();
  }

};


// *********************************************************************//
// COCLASS DEFAULT INTERFACE CREATOR
// CoClass  : DoxLib
// Interface: TCOMIDoxLib
// *********************************************************************//
class CoDoxLib : public CoClassCreator
{
public:
  static TCOMIDoxLib Create(void);
  static TCOMIDoxLib CreateRemote(LPWSTR machineName);

  static HRESULT Create(TCOMIDoxLib& defIntfObj);
  static HRESULT CreateRemote(LPWSTR machineName, TCOMIDoxLib& defIntfObj);
};


// *********************************************************************//
// COCLASS DEFAULT INTERFACE CREATOR
// CoClass  : DocFracLib
// Interface: TCOMIDocFracLib
// *********************************************************************//
class CoDocFracLib : public CoClassCreator
{
public:
  static TCOMIDocFracLib Create(void);
  static TCOMIDocFracLib CreateRemote(LPWSTR machineName);

  static HRESULT Create(TCOMIDocFracLib& defIntfObj);
  static HRESULT CreateRemote(LPWSTR machineName, TCOMIDocFracLib& defIntfObj);
};

};     // namespace Doxcom_tlb

#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using  namespace Doxcom_tlb;
#endif

#pragma option pop

#endif // __doxcom_TLB_h__
