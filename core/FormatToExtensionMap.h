//---------------------------------------------------------------------------
#ifndef FormatToExtensionMapH
#define FormatToExtensionMapH
//---------------------------------------------------------------------------
#include <map>
#include <string>
#include "FileFormat.h"

namespace DoxEngine
{
  std::map<FileFormat, std::string> getFormatToExtensionMap();
}
#endif
