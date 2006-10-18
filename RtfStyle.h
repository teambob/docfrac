#ifndef __RTFSTYLE_H__
#define __RTFSTYLE_H__

#include <stack>
#include <vector>
#include "Colour.h"
#include "Style.h"

namespace DoxEngine
{
  class RtfStyle
  {
  private:
	bool inTable;
	std::vector<Colour> colour;
	Colour currentColour;
	Style style;
  int sectionColumns;

  public:
    RtfStyle();
	virtual ~RtfStyle();

    void setPlain( void );
    void setInTable( bool insideTable);
    bool getInTable();

    void setSectionPlain( void );
    void setSectionColumns( int columns );
    int getSectionColumns( void );


    void setRed( int value );
    void setGreen( int value );
    void setBlue( int value );
    void colourTerminate( void );

		void setForegroundColour( int index );

		Style getStyle() const;
		void setStyle(const Style &style);

  };

  class RtfStyleStack : public std::stack<RtfStyle>
	{
	};

}


#endif

