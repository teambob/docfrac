//---------------------------------------------------------------------------
#ifndef DoxLibH
#define DoxLibH
//---------------------------------------------------------------------------
#include "doxcom_TLB.h"

// The following define is utilized by the IDEs Code Manager to ensure that
// your controls Library Identifier is kept up-to-date.
// NOTE: Do not remove or modify this macro.
//
#define LIBID_DoxLib LIBID_doxcom

class ATL_NO_VTABLE TDoxLibImpl:
  AUTOOBJECT_IMPL(TDoxLibImpl, DoxLib, IDoxLib)
{
public:

// The COM MAP entries declares the interfaces your object exposes (through
// QueryInterface). CComRootObjectEx::InternalQueryInterface only returns
// pointers for interfaces in the COM map. VCL controls exposed as OCXes
// have a minimum set of interfaces defined by the
// VCL_CONTROL_COM_INTERFACE_ENTRIES macro. Add other interfaces supported
// by your object with additional COM_INTERFACE_ENTRY[_xxx] macros.
//
BEGIN_COM_MAP(TDoxLibImpl)
  AUTOOBJECT_COM_INTERFACE_ENTRIES(IDoxLib)
END_COM_MAP()

// The following macro declares a 'static UpdateRegistry(..)' which is
// used by ATL to register this object.
//
DECLARE_TYPED_COMSERVER_REGISTRY("doxcom.DoxLib")
    TDoxLibImpl();
    ~TDoxLibImpl();
protected: 
  STDMETHOD(Convert());
  STDMETHOD(DebugOn());
  STDMETHOD(SetInFileName(LPSTR FileName));
  STDMETHOD(SetInFormat(LPSTR Extension));
  STDMETHOD(SetOutFileName(LPSTR FileName));
  STDMETHOD(SetOutFormat(LPSTR Extension));
  STDMETHOD(UseExtractPict(int Use)); 
  BSTR STDMETHODCALLTYPE StringConvert();
  STDMETHOD(SetInString(LPSTR In));
private:
    TDox *DoxCore;
};
#endif
