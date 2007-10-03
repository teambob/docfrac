//---------------------------------------------------------------------------


#include <map>
#include <string>
#include "ExtensionToFormatMap.h"

//---------------------------------------------------------------------------


namespace DoxEngine
{
  ExtensionToFormatMap::ExtensionToFormatMap()
   :std::map<const tstring, FileFormat>()
  {
    (*this)[TEXT("rtf")] = FORMAT_RTF;
    (*this)[TEXT("txt")] = FORMAT_TEXT;
    (*this)[TEXT("text")] = FORMAT_TEXT;
    (*this)[TEXT("html")] = FORMAT_HTML;
    (*this)[TEXT("htm")] = FORMAT_HTML;
  }
}
