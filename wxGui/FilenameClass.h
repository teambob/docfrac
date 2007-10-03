//---------------------------------------------------------------------------
#ifndef FilenameClassH
#define FilenameClassH
//---------------------------------------------------------------------------
#include "tstring.h"

const wxChar DIRECTORY_SEPARATOR = wxT('\\');

class FilenameClass : public tstring
{
  public:
    tstring GetDirectory(void);
    tstring GetFilename(void);
    tstring GetBasename(void);
    tstring GetExtension(void);

    FilenameClass();
    FilenameClass(const tstring &s);
    FilenameClass(const wxChar* s);

};
#endif
 
