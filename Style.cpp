#include <iostream>
#include <fstream>
#include "Style.h"
#include "debug.h"

namespace DoxEngine
{

	Style::Style()
	{
		setDefault();
	}

	Style::~Style()
	{

  }

	Style& Style::operator=(const Style &rhs)
    {
      if (&rhs == this)
        return *this;

      bold = rhs.bold;
      italic = rhs.italic;
      underline = rhs.underline;
      justification = rhs.justification;
      defaultColour = rhs.defaultColour;
      red = rhs.red;
      green = rhs.green;
      blue = rhs.blue;

      return *this;
    }


    void Style::setDefault( void )
    {
      bold = false;
      italic = false;
      underline = false;
      justification = DefaultJustified;
      defaultColour = true;

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
      //std::cout << "Justification being set to " << value << "\n";
      justification = value;
    }

    void Style::setColour( void )
    {
      defaultColour = true;
      *debugStream<<"Setting default colour\n";
    }

    void Style::setColour( int redValue, int greenValue, int blueValue )
    {
      defaultColour = false;

      *debugStream << "Setting colour to " << redValue << "," << greenValue << "," << blueValue << "\n";
      red = redValue;
      green = greenValue;
      blue = blueValue;
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
      //std::cout << "Returning justification of " << justification << "\n";
      return justification;
    }

    int Style::getColourRed( void )
    {
      return red;
    }

    int Style::getColourBlue( void )
    {
      return blue;
    }

    int Style::getColourGreen( void )
    {
      return green;
    }


    bool Style::getDefaultColour( void )
    {
      return defaultColour;
    }
}


