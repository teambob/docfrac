//---------------------------------------------------------------------------


#include <map>
#include <string>
#include "ExtensionToFormatMap.h"

//---------------------------------------------------------------------------


namespace DoxEngine
{
  std::map<std::string, FileFormat> getExtensionToFormatMap()
  {
    std::map<std::string, FileFormat> results;    
    results["rtf"] = FORMAT_RTF;
    results["txt"] = FORMAT_TEXT;
    results["text"] = FORMAT_TEXT;
    results["html"] = FORMAT_HTML;
    results["htm"] = FORMAT_HTML;
    return results;
  }
}
