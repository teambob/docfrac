//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include <atl\atlvcl.h>

#include <string>
#include "TDox.h"
#include "DocFracLib.h"
#include "ConvertBSTR.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

TDocFracLibImpl::TDocFracLibImpl()
{
  DoxCore = new TDox;  
}

TDocFracLibImpl::~TDocFracLibImpl()
{
  delete DoxCore;
}

BSTR STDMETHODCALLTYPE TDocFracLibImpl::StringConvert()
{
  std::string Temp;
  BSTR Result;

  try
  {
    Temp = DoxCore->StringConvert();
    Result = StringToBSTR(Temp);
    return Result;

  }
  catch(Exception &e)
  {
    return StringToBSTR("Error");
  }
};
//---------------------------------------------------------------------------

STDMETHODIMP TDocFracLibImpl::Convert()
{
  try
  {
    if (DoxCore->DebugOn)
      ShowMessage("Starting Dox COM system.");


    DoxCore->FileConvert();


    if (DoxCore->DebugOn)
      ShowMessage("Dox COM system finished.");

  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IDocFracLib);
  }
  return S_OK;
};
//---------------------------------------------------------------------------

STDMETHODIMP TDocFracLibImpl::SetInFileName(BSTR filename)
{
  try
  {
    DoxCore->SetInFileName(BSTRToString(filename));
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IDocFracLib);
  }
  return S_OK;
};
//---------------------------------------------------------------------------

STDMETHODIMP TDocFracLibImpl::SetInFormat(BSTR format)
{
  try
  {
    DoxCore->SetInFormat(BSTRToString(format));
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IDocFracLib);
  }
  return S_OK;
};
//---------------------------------------------------------------------------

STDMETHODIMP TDocFracLibImpl::SetInString(BSTR inString)
{
  try
  {
    DoxCore->SetInString(BSTRToString(inString));
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IDocFracLib);
  }
  return S_OK;
};
//---------------------------------------------------------------------------

STDMETHODIMP TDocFracLibImpl::SetOutFileName(BSTR filename)
{
  try
  {
    DoxCore->SetOutFileName(BSTRToString(filename));
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IDocFracLib);
  }
  return S_OK;
};
//---------------------------------------------------------------------------

STDMETHODIMP TDocFracLibImpl::SetOutFormat(BSTR format)
{
  try
  {
    DoxCore->SetOutFormat(BSTRToString(format));
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IDocFracLib);
  }
  return S_OK;
};
//---------------------------------------------------------------------------

