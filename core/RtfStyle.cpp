#include "Style.h"
#include "RtfStyle.h"
#include <vector>

namespace DoxEngine
{

  RtfStyle::RtfStyle()
  {
    setPlain();
    setSectionPlain();
  }

  RtfStyle::RtfStyle(DebugLog &newLog):log(newLog)
  {
    setPlain();
    setSectionPlain();
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
#ifdef ENABLE_LOG_DEBUG
    log[LOG_DEBUG] << DEBUG_ID << "Setting red to " << value << "\n";
#endif

	currentColour.SetRed(value);
  }

  void RtfStyle::setGreen( int value )
  {
#ifdef ENABLE_LOG_DEBUG
    log[LOG_DEBUG] << DEBUG_ID << "Setting green to " << value << "\n";
#endif
	currentColour.SetGreen(value);
  }

  void RtfStyle::setBlue( int value )
  {
#ifdef ENABLE_LOG_DEBUG
    log[LOG_DEBUG] << DEBUG_ID << "Setting blue to " << value << "\n";
#endif

    currentColour.SetBlue(value);
  }

  void RtfStyle::colourTerminate( void )
  {
#ifdef ENABLE_LOG_DEBUG
    log[LOG_DEBUG] << DEBUG_ID << "Saving colour table entry\n";
#endif

	  colour.push_back(currentColour);
  }

  void RtfStyle::setForegroundColour( int index )
  {
    // Colour index is based on 1
#ifdef ENABLE_LOG_DEBUG
		log[LOG_DEBUG] << DEBUG_ID << "Setting foreground colour\n";
#endif

		if (index < 0)
		{
			// integer index can't be compared to unsigned size if negative
      log[LOG_WARNING] << DEBUG_ID << "Index cannot be negative\n";
		}
		else if (unsigned(index) >= colour.size()) // cast to unsigned
		{
			log[LOG_WARNING] << DEBUG_ID << index << "is beyond bounds (" << colour.size() << "\n";
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

