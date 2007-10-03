//---------------------------------------------------------------------------
#include <map>
#include <vector>
#include <string>
#include "FormatToExtensionMap.h"
#include "tstring.h"

//---------------------------------------------------------------------------
namespace DoxEngine
{
  FormatToExtensionMap::FormatToExtensionMap()
  {
    (*this)[FORMAT_RTF] = tstring(TEXT("rtf"));
    (*this)[FORMAT_TEXT] = tstring(TEXT("txt"));
    (*this)[FORMAT_HTML] = tstring(TEXT("html"));

  }
}
