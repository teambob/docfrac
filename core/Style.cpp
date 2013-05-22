#include <iostream>
#include <fstream>
#include "Style.h"


namespace DoxEngine
{

  Style::Style():log()
  {
    setDefault();
  }

  Style::Style(DebugLog &newLog):log(newLog)
  {
    setDefault();
  }

  Style::Style(const Style &rhs)
  {
    justification = rhs.justification;
    bold = rhs.bold;
    italic = rhs.italic;
    underline = rhs.underline;

    colour = rhs.colour;
    log = rhs.log;
  }


  Style::~Style()
  {

  }

  Style& Style::operator=(const Style& rhs)
  {
    if (this == &rhs)
      return *this;


    justification = rhs.justification;
    bold = rhs.bold;
    italic = rhs.italic;
    underline = rhs.underline;

    colour = rhs.colour;
    log = rhs.log;

    return *this;

  }



  void Style::setDefault( void )
  {
    bold = false;
    italic = false;
    underline = false;
    justification = DefaultJustified;
    colour.SetDefault();

  }


  void Style::setBold( bool value )
  {
    bold = value;
  }

  void Style::setItalic( bool value )
  {
    italic = value;
  }

  void Style::setUnderline( bool value )
  {
    underline = value;
  }

  void Style::setJustification( Justification value )
  {
#ifdef ENABLE_LOG_DEBUG
    log[LOG_DEBUG] << DEBUG_ID << "Justification being set to " << value << "\n";
#endif

    justification = value;
  }

  void Style::setColour( void )
  {
    colour.SetDefault();

#ifdef ENABLE_LOG_DEBUG
    log[LOG_DEBUG] << DEBUG_ID <<"Setting default colour\n";
#endif
  }



  void Style::setColour( int redValue, int greenValue, int blueValue )
  {
#ifdef ENABLE_LOG_DEBUG
    log[LOG_DEBUG] << DEBUG_ID << "Setting colour to " << redValue << "," << greenValue << "," << blueValue << "\n";
#endif

    colour.SetRed(redValue);
    colour.SetGreen(greenValue);
    colour.SetBlue(blueValue);
  }



  bool Style::getBold( void ) const
  {
    return bold;
  }

  bool Style::getItalic( void ) const
  {
    return italic;
  }

  bool Style::getUnderline( void ) const
  {
    return underline;
  }

  Justification Style::getJustification( void ) const
  {
#ifdef ENABLE_LOG_DEBUG
    //log[LOG_DEBUG] << DEBUG_ID << "Returning justification of " << justification << "\n";
#endif
    return justification;
  }

  int Style::getColourRed( void ) const
  {
    return colour.GetRed();
  }

  int Style::getColourBlue( void ) const
  {
    return colour.GetBlue();
  }

  int Style::getColourGreen( void ) const
  {
    return colour.GetGreen();
  }


  bool Style::getDefaultColour( void ) const
  {
    return colour.IsDefault();
  }

  bool Style::operator==(const Style& rhs) const
  {
    return
      justification == rhs.justification
      && bold == rhs.bold
      && italic == rhs.italic
      && underline == rhs.underline
      && defaultColour == rhs.defaultColour
      && ( defaultColour || colour == rhs.colour );
  }

  bool Style::operator!=(const Style& rhs) const
  {
    return !( *this == rhs );
  }
}


