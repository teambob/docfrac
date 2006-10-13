//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include <map>
#include <string>
#include "ExtensionToFormatMap.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)

namespace DoxEngine
{
  ExtensionToFormatMap::ExtensionToFormatMap()
   :std::map<const std::string, FileFormat>()
  {
    (*this)["rtf"] = FORMAT_RTF;
    (*this)["txt"] = FORMAT_TEXT;
    (*this)["text"] = FORMAT_TEXT;
    (*this)["html"] = FORMAT_HTML;
    (*this)["htm"] = FORMAT_HTML;
  }
}