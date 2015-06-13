//---------------------------------------------------------------------------

#ifndef ColourH
#define ColourH
//---------------------------------------------------------------------------

namespace DoxEngine
{
  class Colour
  {
  public:
    Colour();
    void SetDefault();

    void SetRed(int value);
    void SetGreen(int value);
    void SetBlue(int value);

    bool IsDefault() const;
    int GetRed() const;
    int GetGreen() const;
    int GetBlue() const;

    bool operator==( const Colour &rhs ) const;

  private:
    bool redDefault, greenDefault, blueDefault;
    int red, green, blue;

  };

}
#endif
