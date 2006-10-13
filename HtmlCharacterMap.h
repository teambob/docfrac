#ifndef __HTML_CHARACHTER_MAP_H__
#define __HTML_CHARACHTER_MAP_H__

#include <vector>
#include <string>
#include "UnicodeCharacter.h"

namespace DoxEngine
{
  class HtmlCharacterMap
  {
	private:
	  std::string id;
	  UnicodeCharacter character;
    public:
      HtmlCharacterMap(const std::string &newId,
        const UnicodeCharacter &newCharacter);

      void setMap(const std::string &newId,
        const UnicodeCharacter &newCharacter);

      ~HtmlCharacterMap();

      bool operator==(const std::string &rhs) const;
      bool operator!=(const std::string &rhs) const;

      UnicodeCharacter getCharacter(void);
  };


  class HtmlCharacterMaps : public std::vector<HtmlCharacterMap>
  {
  };

  class HtmlCharacterMapsFactory
  {
    public:
      static HtmlCharacterMapsFactory& instance(void);
      HtmlCharacterMaps getMaps(void);
  };


}
#endif


