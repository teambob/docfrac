//---------------------------------------------------------------------------
#include <string>
#include "FilenameClass.h"

//---------------------------------------------------------------------------


FilenameClass::FilenameClass() : tstring()
{

}


FilenameClass::FilenameClass(const tstring &s)
  : tstring(s)
{

}

FilenameClass::FilenameClass(const wxChar* s) : tstring(s)
{

}



tstring FilenameClass::GetDirectory(void)
{
  return substr(0, rfind(DIRECTORY_SEPARATOR)+1);
}


tstring FilenameClass::GetFilename(void)
{
  size_type position = rfind(DIRECTORY_SEPARATOR);

  if (position == length())
  {
    // Not found
    return wxT("");
  }
  else
  {
    // Found
    return substr(position+1);
  }

}

tstring FilenameClass::GetExtension(void)
{
  tstring filename(GetFilename());
  tstring::size_type position = filename.rfind(wxT("."));


  if (position == filename.length())
  {
    // Not found
    return wxT("");
  }
  else
  {
    // Found
    return filename.substr(position+1);
  }


}



tstring FilenameClass::GetBasename(void)
{
  tstring filename(GetFilename());
  size_type position = filename.rfind(wxT("."));

  if (position == length())
  {
    // Not found
    return wxT("");
  }
  else
  {
    // Found
    return filename.substr(0, position);
  }

}
