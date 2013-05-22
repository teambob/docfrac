#ifndef __HTML_CHARACHTER_MAP_H__
#define __HTML_CHARACHTER_MAP_H__

#include <map>
#include <string>
#include "UnicodeCharacter.h"

namespace DoxEngine
{

  typedef std::map<std::string, UnicodeCharacter> HtmlCharacterMapsBase;

  class HtmlCharacterMaps: public HtmlCharacterMapsBase
  {
  public:
    HtmlCharacterMaps();
  };

}
#endif


