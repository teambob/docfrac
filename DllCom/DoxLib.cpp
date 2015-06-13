//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include <atl\atlvcl.h>
#include <winnls.h>
#include <string>
#include "ConvertBSTR.h"
#include "TDox.h"
#include "DoxLib.h"


#if defined(DoxCOMTrial)
int TestTrial(void);
#endif

//---------------------------------------------------------------------------
#pragma package(smart_init)
TDoxLibImpl::TDoxLibImpl()
{
  DoxCore = new TDox;
}

TDoxLibImpl::~TDoxLibImpl()
{
  delete DoxCore;
}

STDMETHODIMP TDoxLibImpl::Convert()
{
  try
  {
  #if defined(DoxCOMTrial)
            if (!TestTrial())
                {
                ShowMessage("Trial period over or code invalid.\n"
                "Try running trial.exe or"
                " visit http://users.hunterlink.net.au/~mabatp/");
                return S_OK;
                }
  #endif
  
  if (DoxCore->DebugOn)
    ShowMessage("Starting Dox COM system.");
  DoxCore->FileConvert();
  if (DoxCore->DebugOn)
    ShowMessage("Dox COM system finished.");
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IDoxLib);
  }
  return S_OK;
};
//---------------------------------------------------------------------------

STDMETHODIMP TDoxLibImpl::DebugOn()
{
  try
  {
    DoxCore->DebugOn = true;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IDoxLib);
  }
  return S_OK;
};
//---------------------------------------------------------------------------

STDMETHODIMP TDoxLibImpl::SetInFileName(LPSTR FileName)
{
  try
  {
    DoxCore->SetInFileName((char *)FileName);
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IDoxLib);
  }
  return S_OK;
};
//---------------------------------------------------------------------------

STDMETHODIMP TDoxLibImpl::SetInFormat(LPSTR Extension)
{
  try
  {
    DoxCore->SetInFormat((char *)Extension);
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IDoxLib);
  }
  return S_OK;
};
//---------------------------------------------------------------------------

STDMETHODIMP TDoxLibImpl::SetOutFileName(LPSTR FileName)
{
  try
  {
    DoxCore->SetOutFileName((char *)FileName);
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IDoxLib);
  }
  return S_OK;
};
//---------------------------------------------------------------------------

STDMETHODIMP TDoxLibImpl::SetOutFormat(LPSTR Extension)
{
  try
  {
    DoxCore->SetOutFormat((char *)Extension);
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IDoxLib);
  }
  return S_OK;
};
//---------------------------------------------------------------------------

STDMETHODIMP TDoxLibImpl::UseExtractPict(int Use)
{
  try
  {
  
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IDoxLib);
  }
  return S_OK;
};
//---------------------------------------------------------------------------



BSTR STDMETHODCALLTYPE TDoxLibImpl::StringConvert()
{

  try
  {
    /*int count;*/
    std::string Temp;

  #if defined(DoxCOMTrial)
            if (!TestTrial())
                {
                ShowMessage("Trial period over or code invalid.\n"
                "Try running trial.exe or"
                " visit http://users.hunterlink.net.au/~mabatp/");
                return S_OK;
                }
  #endif

    Temp = DoxCore->StringConvert();
    return StringToBSTR(Temp);
  }
  catch(Exception &e)
  {

    OutputDebugString("Dox Error: Internal protection fault.");


    return StringToBSTR("ERROR");
  }

  catch(EAccessViolation &e)
  {

    OutputDebugString("Dox Error: Internal protection fault.");

    return StringToBSTR("ERROR");
  }
  //return S_OK;
};
//---------------------------------------------------------------------------

STDMETHODIMP TDoxLibImpl::SetInString(LPSTR In)
{
  try
  {
  DoxCore->SetInString((char *)In);
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IDoxLib);
  }
  return S_OK;
};
//---------------------------------------------------------------------------


