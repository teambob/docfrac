#include "Style.h"
#include "RtfStyle.h"
#include <vector>

namespace DoxEngine
{

  RtfStyle::RtfStyle()
  {
  }


  RtfStyle::~RtfStyle()
  {
  }

	void RtfStyle::setPlain( void )
  {
		style.setBold( false );
		style.setItalic( false );
		style.setUnderline( false );

    style.setColour();
    inTable = false;
  }

  void RtfStyle::setInTable( bool insideTable)
  {
    inTable = insideTable;
  }


  bool RtfStyle::getInTable()
  {
    return inTable;
  }

  void RtfStyle::setRed( int value )
  {
    //cout << "Setting red to " << value << "\n";
	currentColour.SetRed(value);
  }

  void RtfStyle::setGreen( int value )
  {
    //cout << "Setting green to " << value << "\n";
	currentColour.SetGreen(value);
  }

  void RtfStyle::setBlue( int value )
  {
    //cout << "Setting blue to " << value << "\n";
    currentColour.SetBlue(value);
  }

  void RtfStyle::colourTerminate( void )
  {
    //cout << "Saving colour table entry\n";
    //cout << "red = " << redColour << "\n";
    //cout << "green = " << greenColour << "\n";
    //cout << "blue = " << blueColour << "\n";
	colour.push_back(currentColour);
  }

  void RtfStyle::setForegroundColour( int index )
  {
    //cout << "Setting foreground colour\n";
    if (index >= colour.size());
      //cout << index << "is beyond bounds (" << redTable->size() << "\n";
    else
    {
      if (colour[index].IsDefault())
				style.setColour();
			else
        style.setColour(colour[index].GetRed(), colour[index].GetGreen(),colour[index].GetBlue());

    }
  }

	Style RtfStyle::getStyle() const
	{
		return style;
	}

	void RtfStyle::setStyle(const Style &newStyle)
	{
		style = newStyle;
  }

}

