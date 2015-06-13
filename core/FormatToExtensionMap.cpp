//---------------------------------------------------------------------------
#include <map>
#include <vector>
#include <string>
#include "FormatToExtensionMap.h"

//---------------------------------------------------------------------------
namespace DoxEngine
{
  std::map<FileFormat, std::string> getFormatToExtensionMap()
  {
    std::map<FileFormat, std::string> results;


    results[FORMAT_RTF] = "rtf";
    results[FORMAT_TEXT] = "txt";
    results[FORMAT_HTML] = "html";

    return results;

  }
}
