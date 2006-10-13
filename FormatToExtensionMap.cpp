//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include <map>
#include <vector>
#include <string>
#include "Document.h"
#include "FormatToExtensionMap.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
namespace DoxEngine
{
  FormatToExtensionMap::FormatToExtensionMap()
  {
    (*this)[FORMAT_RTF] = std::string("rtf");
    (*this)[FORMAT_TEXT] = std::string("txt");
    (*this)[FORMAT_HTML] = std::string("html");

  }
}
