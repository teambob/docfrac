//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include <string>
#include "FilenameClass.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)


FilenameClass::FilenameClass() : std::string()
{

}


FilenameClass::FilenameClass(const std::string &s)
  : std::string(s)
{

}

FilenameClass::FilenameClass(const char* s) : std::string(s)
{

}



std::string FilenameClass::GetDirectory(void)
{
  return substr(0, rfind(DIRECTORY_SEPARATOR)+1);
}


std::string FilenameClass::GetFilename(void)
{
  size_type position = rfind(DIRECTORY_SEPARATOR);

  if (position == length())
  {
    // Not found
    return "";
  }
  else
  {
    // Found
    return substr(position+1);
  }

}

std::string FilenameClass::GetExtension(void)
{
  std::string filename(GetFilename());
  std::string::size_type position = filename.rfind(".");


  if (position == filename.length())
  {
    // Not found
    return "";
  }
  else
  {
    // Found
    return filename.substr(position+1);
  }


}



std::string FilenameClass::GetBasename(void)
{
  std::string filename(GetFilename());
  size_type position = filename.rfind(".");

  if (position == length())
  {
    // Not found
    return "";
  }
  else
  {
    // Found
    return filename.substr(0, position);
  }

}
