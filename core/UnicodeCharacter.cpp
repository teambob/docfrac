#include "UnicodeCharacter.h"

namespace DoxEngine
{

  UnicodeCharacter::UnicodeCharacter(unsigned long initialCharacter)
  {
    character = initialCharacter;
  }


  UnicodeCharacter::UnicodeCharacter(char initialCharacter)
  {
    character = initialCharacter;
  }


  bool UnicodeCharacter::isASCII(void) const
  {
    if (character < 0x80)
      return true;
    else
      return false;
  }


  char UnicodeCharacter::getASCII(void) const
  {
    return (char)character;
  }


  long UnicodeCharacter::unicode(void) const
  {
    return character;

  }

  UnicodeCharacter::UnicodeCharacter()
  {
    character = 0;
  }

}

