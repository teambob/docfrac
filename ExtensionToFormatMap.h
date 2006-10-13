//---------------------------------------------------------------------------
#ifndef ExtensionToFormatMapH
#define ExtensionToFormatMapH
//---------------------------------------------------------------------------
#include <map>
#include <string>

#include "FileFormat.h"

namespace DoxEngine
{
  // By default Compare is less<const std::string>
  // By default Alloc is alloc
  class ExtensionToFormatMap :
    public std::map<const std::string, FileFormat>
  {
    public:
      ExtensionToFormatMap();


  };
}



#endif
 