//---------------------------------------------------------------------------
#ifndef FilenameClassH
#define FilenameClassH
//---------------------------------------------------------------------------
#include <windows.h>
#include "tstring.h"
const TCHAR DIRECTORY_SEPARATOR[] = TEXT("\\");

class FilenameClass : public tstring
{
  public:
    tstring GetDirectory(void);
    tstring GetFilename(void);
    tstring GetBasename(void);
    tstring GetExtension(void);

    FilenameClass();
    FilenameClass(const tstring &s);
    FilenameClass(const TCHAR* s);

};
#endif
 