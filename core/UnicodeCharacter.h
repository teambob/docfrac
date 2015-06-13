//---------------------------------------------------------------------------
#ifndef UnicodeCharacterH
#define UnicodeCharacterH

namespace DoxEngine
{

  class UnicodeCharacter
  {
  private:
    long character;

  public:
    UnicodeCharacter(unsigned long initialCharacter);
    UnicodeCharacter(char initialCharacter);
    UnicodeCharacter();

    void setCharacter(long newCharacter);
    bool isASCII(void) const;
    char getASCII(void) const;
    long unicode(void) const;
  };

}
//---------------------------------------------------------------------------
#endif

