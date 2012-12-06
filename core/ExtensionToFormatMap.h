//---------------------------------------------------------------------------
#ifndef ExtensionToFormatMapH
#define ExtensionToFormatMapH
//---------------------------------------------------------------------------
#include <map>
#include <string>

#include "FileFormat.h"

namespace DoxEngine
{
  const std::map<std::string, FileFormat> getExtensionToFormatMap();
}



#endif
