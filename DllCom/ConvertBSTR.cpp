//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include <string>
#include "ConvertBSTR.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)

BSTR StringToBSTR(const std::string &inString)
{
  int Size;
  wchar_t *WTemp;
  BSTR Result;

  OutputDebugString(inString.c_str());
  Size = MultiByteToWideChar(
    CP_ACP,
    MB_PRECOMPOSED,
    inString.c_str(),
    -1,
    NULL,
    0
    );

  if (!Size)
    OutputDebugString("Dox: first call to MultiByteToWideChar failed");

  WTemp = (wchar_t *)malloc(Size*sizeof(wchar_t));
  if (WTemp == NULL)
    OutputDebugString("Dox: Memory allocation failure.");

  if (!MultiByteToWideChar(
    CP_ACP,
    MB_PRECOMPOSED,
    inString.c_str(),
    -1,
    WTemp,
    Size
    ))
  {
    OutputDebugString("Dox: Error in call to MultiByteToWideChar");
  }

  Result = SysAllocString(WTemp);

  if (Result == NULL)
    OutputDebugString("Dox: Error creating BSTR");

  free(WTemp);

  OutputDebugString("Dox: Finished StringToBSTR");
  return Result;
}





std::string BSTRToString(const BSTR inString)
{
  int Size;
  char *ASCIITemp;



  Size = SysStringLen(inString);

  ASCIITemp = (char*)malloc(Size+1);

  WideCharToMultiByte(
    CP_ACP, /* ANSI code page */
    0, /* no flags */
    inString, /* BSTR points to the first character as wchar_t */
    SysStringLen(inString),
    ASCIITemp,
    Size,
    NULL, /* Don't worry about other characters */
    NULL  /* Don't worry about other characters */
    );

  ASCIITemp[Size] = '\0';

  std::string StringTemp(ASCIITemp);

  free(ASCIITemp);

  return StringTemp;

}
