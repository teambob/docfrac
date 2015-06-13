//---------------------------------------------------------------------------
#ifndef DocFracLibH
#define DocFracLibH
//---------------------------------------------------------------------------
#include "doxcom_TLB.h"

// The following define is utilized by the IDEs Code Manager to ensure that
// your controls Library Identifier is kept up-to-date.
// NOTE: Do not remove or modify this macro.
//
#define LIBID_DocFracLib LIBID_doxcom

class ATL_NO_VTABLE TDocFracLibImpl:
  AUTOOBJECT_IMPL(TDocFracLibImpl, DocFracLib, IDocFracLib)
{
public:

// The COM MAP entries declares the interfaces your object exposes (through
// QueryInterface). CComRootObjectEx::InternalQueryInterface only returns
// pointers for interfaces in the COM map. VCL controls exposed as OCXes
// have a minimum set of interfaces defined by the
// VCL_CONTROL_COM_INTERFACE_ENTRIES macro. Add other interfaces supported
// by your object with additional COM_INTERFACE_ENTRY[_xxx] macros.
//
BEGIN_COM_MAP(TDocFracLibImpl)
  AUTOOBJECT_COM_INTERFACE_ENTRIES(IDocFracLib)
END_COM_MAP()

// The following macro declares a 'static UpdateRegistry(..)' which is
// used by ATL to register this object.
//
DECLARE_TYPED_COMSERVER_REGISTRY("doxcom.DocFracLib")

  TDocFracLibImpl();
  ~TDocFracLibImpl();


protected:
  BSTR STDMETHODCALLTYPE StringConvert();
  STDMETHOD(Convert());
  STDMETHOD(SetInFileName(BSTR filename));
  STDMETHOD(SetInFormat(BSTR format));
  STDMETHOD(SetInString(BSTR inString));
  STDMETHOD(SetOutFileName(BSTR filename));
  STDMETHOD(SetOutFormat(BSTR format));
private:
    TDox *DoxCore;

};
#endif
