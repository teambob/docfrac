//---------------------------------------------------------------------------
#ifndef FormatToExtensionMapH
#define FormatToExtensionMapH
//---------------------------------------------------------------------------
#include <map>
#include "FileFormat.h"
#include "tstring.h"

namespace DoxEngine
{
  // By default Compare is less<const FileFormat>
  // By default Alloc is alloc
  class FormatToExtensionMap :
    public std::map<const FileFormat, tstring>
  {
    public:
      FormatToExtensionMap();
  };
}
#endif
