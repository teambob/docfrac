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

  void RtfStyle::setSectionPlain( void )
  {
    sectionColumns = 0;
  }
  
  void RtfStyle::setSectionColumns( int columns )
  {
    sectionColumns = columns;
  }

  int RtfStyle::getSectionColumns( void )
  {
    return sectionColumns;
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
    // Colour index is based on 1
		//cout << "Setting foreground colour\n";
		if (index < 0)
		{
			// integer index can't be compared to unsigned size if negative
		}
		else if (unsigned(index) >= colour.size()) // cast to unsigned
		{
			//cout << index << "is beyond bounds (" << redTable->size() << "\n";
		}
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

