//---------------------------------------------------------------------------
#ifndef FormatToExtensionMapH
#define FormatToExtensionMapH
//---------------------------------------------------------------------------
#include <map>
#include <string>
#include "FileFormat.h"

namespace DoxEngine
{
  const std::map<FileFormat, std::string> getFormatToExtensionMap();
}
#endif
