//---------------------------------------------------------------------------
#ifndef DoxNGH
#define DoxNGH
//---------------------------------------------------------------------------
#include "doxnew_TLB.h"
#include "TDox.h"
// The following define is utilized by the IDEs Code Manager to ensure that
// your controls Library Identifier is kept up-to-date.
// NOTE: Do not remove or modify this macro.
//
#define LIBID_DoxNG LIBID_doxnew

class ATL_NO_VTABLE TDoxNGImpl:
  AUTOOBJECT_IMPL(TDoxNGImpl, DoxNG, IDoxNG)
{
public:

// The COM MAP entries declares the interfaces your object exposes (through
// QueryInterface). CComRootObjectEx::InternalQueryInterface only returns
// pointers for interfaces in the COM map. VCL controls exposed as OCXes
// have a minimum set of interfaces defined by the
// VCL_CONTROL_COM_INTERFACE_ENTRIES macro. Add other interfaces supported
// by your object with additional COM_INTERFACE_ENTRY[_xxx] macros.
//
BEGIN_COM_MAP(TDoxNGImpl)
  AUTOOBJECT_COM_INTERFACE_ENTRIES(IDoxNG)
END_COM_MAP()

// The following macro declares a 'static UpdateRegistry(..)' which is
// used by ATL to register this object.
//
DECLARE_TYPED_COMSERVER_REGISTRY("doxnew.DoxNG")

    TDoxNGImpl();

protected:
  BSTR STDMETHODCALLTYPE StringConvert();
  STDMETHOD(Convert());
  STDMETHOD(DebugOn(int Value));
  STDMETHOD(Done());
  STDMETHOD(SetInFileName(LPSTR FileName));
  STDMETHOD(SetInFormat(LPSTR Extension));
  STDMETHOD(SetInString(LPSTR In));
  STDMETHOD(SetOutFileName(LPSTR FileName));
  STDMETHOD(SetOutFormat(LPSTR Extension));
  STDMETHOD(UseFeature(LPSTR Feature));

private:
    TDox *DoxCore;

};
#endif
