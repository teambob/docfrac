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



    bool Style::getBold( void )
    {
      return bold;
    }

    bool Style::getItalic( void )
    {
      return italic;
    }

    bool Style::getUnderline( void )
    {
      return underline;
    }

    Justification Style::getJustification( void )
    {
#ifdef ENABLE_LOG_DEBUG
      log[LOG_DEBUG] << DEBUG_ID << "Returning justification of " << justification << "\n";
#endif
      return justification;
    }

    int Style::getColourRed( void )
    {
      return colour.GetRed();
    }

    int Style::getColourBlue( void )
    {
      return colour.GetBlue();
    }

    int Style::getColourGreen( void )
    {
      return colour.GetGreen();
    }


    bool Style::getDefaultColour( void )
    {
      return colour.IsDefault();
    }
}


