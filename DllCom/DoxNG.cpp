//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include <atl\atlvcl.h>

#include "DoxNG.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

TDoxNGImpl::TDoxNGImpl()
{
DoxCore = new TDox();
}

BSTR STDMETHODCALLTYPE TDoxNGImpl::StringConvert()
{
char *Temp;
int Size;
wchar_t *WTemp;
BSTR Result;

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
  if (!DoxCore)
    return S_OK;

  Temp = DoxCore->StringConvert();
/*
  for (count=0;count<3000;count++)
    Sample[count] = 'a';
  Sample[count] = 0;

  Temp = Sample;*/

/*
if (DoxCore->DebugOn)
    ShowMessage(Temp);
*/
  Size = MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, Temp, -1, NULL, 0);
/*
if (DoxCore->DebugOn)
    ShowMessage(Size);
*/
  if (!(WTemp = (wchar_t *)malloc(Size*sizeof(wchar_t))))
    OutputDebugString("Dox: Memory allocation failure.");
/*
 if (DoxCore->DebugOn)
    ShowMessage("Memory allocated.");
*/
  if (!MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, Temp, -1, WTemp, Size))
    OutputDebugString("Dox: Internal error");

  DoxCore->FreeMem();
  
/*
  if (DoxCore->DebugOn)
    ShowMessage("Dox: String Convert finished.");
*/
  Result = SysAllocString(WTemp);

  free(WTemp);

  return Result;
  }
  catch(Exception &e)
  {

    OutputDebugString("Dox Error: Internal protection fault.");

    Temp = "ERROR";

    Size = MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, Temp, -1, NULL, 0);

    if (!(WTemp = (wchar_t *)malloc(Size*sizeof(wchar_t))))
      OutputDebugString("Dox: Memory allocation failure.");

    MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, Temp, -1, WTemp, 1000);

  Result = SysAllocString(WTemp);

  free(WTemp);

  return Result;
  }

  catch(EAccessViolation &e)
  {

    OutputDebugString("Dox Error: Internal protection fault.");

    Temp = "ERROR";

    Size = MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, Temp, -1, NULL, 0);

    if (!(WTemp = (wchar_t *)malloc(Size*sizeof(wchar_t))))
      OutputDebugString("Dox: Memory allocation failure.");

    MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, Temp, -1, WTemp, 1000);

  Result = SysAllocString(WTemp);

  free(WTemp);

  return Result;
  }
  return S_OK;

};
//---------------------------------------------------------------------------

STDMETHODIMP TDoxNGImpl::Convert()
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
  if (!DoxCore)
    return S_OK;

  if (DoxCore->DebugOn)
    ShowMessage("Starting Dox COM system.");
  DoxCore->Convert();
  if (DoxCore->DebugOn)
    ShowMessage("Dox COM system finished.");

  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IDoxNG);
  }
  return S_OK;
};
//---------------------------------------------------------------------------

STDMETHODIMP TDoxNGImpl::DebugOn(int Value)
{
  try
  {
  if (!DoxCore)
    return S_OK;

  DoxCore->DebugOn = Value;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IDoxNG);
  }
  return S_OK;
};
//---------------------------------------------------------------------------

STDMETHODIMP TDoxNGImpl::Done()
{
  try
  {
  if (!DoxCore)
    return S_OK;
  CallbackMessage(DoxMessUser, "Freeing memory.");
  DoxCore->FreeMem();

  delete DoxCore;
  DoxCore = NULL;

  CallbackMessage(DoxMessUser, "Memory freed.");
  }
  catch(Exception &e)
  {
    CallbackMessage(DoxMessError, "Exception occurred.");
    return S_OK;
  }
  return S_OK;
};
//---------------------------------------------------------------------------

STDMETHODIMP TDoxNGImpl::SetInFileName(LPSTR FileName)
{
  try
  {
  if (!DoxCore)
    return S_OK;

  DoxCore->SetInFileName((char *)FileName);
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IDoxNG);
  }
  return S_OK;
};
//---------------------------------------------------------------------------

STDMETHODIMP TDoxNGImpl::SetInFormat(LPSTR Extension)
{
  try
  {
  if (!DoxCore)
    return S_OK;

  DoxCore->SetInFormat((char *)Extension);
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IDoxNG);
  }
  return S_OK;
};
//---------------------------------------------------------------------------

STDMETHODIMP TDoxNGImpl::SetInString(LPSTR In)
{
  try
  {
  if (!DoxCore)
    return S_OK;

  DoxCore->SetInString((char *)In);
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IDoxNG);
  }
  return S_OK;
};
//---------------------------------------------------------------------------

STDMETHODIMP TDoxNGImpl::SetOutFileName(LPSTR FileName)
{
  try
  {
  if (!DoxCore)
    return S_OK;

  DoxCore->SetOutFileName((char *)FileName);
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IDoxNG);
  }
  return S_OK;
};
//---------------------------------------------------------------------------

STDMETHODIMP TDoxNGImpl::SetOutFormat(LPSTR Extension)
{
  try
  {
  if (!DoxCore)
    return S_OK;

  DoxCore->SetOutFormat((char *)Extension);
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IDoxNG);
  }
  return S_OK;
};
//---------------------------------------------------------------------------

STDMETHODIMP TDoxNGImpl::UseFeature(LPSTR Feature)
{
  try
  {
  
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IDoxNG);
  }
  return S_OK;
};
//---------------------------------------------------------------------------


