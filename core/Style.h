#ifndef __STYLE_H__
#define __STYLE_H__
#include "DebugLog.h"
#include "Colour.h"
namespace DoxEngine
{

  enum  Justification
  {
    DefaultJustified,
    LeftJustified,
    CentreJustified,
    RightJustified,
    Justified
  };

  class Style
  {
  private:
    Justification justification;
    bool bold;
    bool italic;
    bool underline;

    bool defaultColour;
    Colour colour;
    DebugLog log;


  public:
    Style();
    Style(DebugLog &newLog);
    Style(const Style &style);
    ~Style();
    Style& operator=(const Style& rhs);
    bool operator==(const Style& rhs) const;
    bool operator!=(const Style& rhs) const;

    void setDefault( void );

    void setBold( bool value );
    void setItalic( bool value );
    void setUnderline( bool value );
    void setJustification( DoxEngine::Justification value );
    void setColour( void );
    void setColour( int redValue, int greenValue, int blueValue );

    bool getBold( void ) const;
    bool getItalic( void ) const;
    bool getUnderline( void ) const;
    Justification getJustification( void ) const;
    bool getDefaultColour( void ) const;
    int getColourRed( void ) const;
    int getColourBlue( void ) const;
    int getColourGreen( void ) const;

  };
}

#endif

