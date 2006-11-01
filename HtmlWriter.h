#ifndef __HTML_WRITER_H__
#define __HTML_WRITER_H__

#include "Style.h"
#include "DebugLog.h"

namespace DoxEngine
{
  class Style;

  class HtmlWriter : public WriterInterface
  {
	private:
	  std::ostream& outputStream;
    DebugLog& log;
	  Style style, oldStyle;
	  bool styleChanged;
    int whiteSpaces;


	  void outputStyles( void );
	  void clearStyles( void );

	  void tableStopStyle( void );
	  void tableRestartStyle( void );


	public:
	  HtmlWriter(std::ostream& stream, DebugLog &newLog);
	  virtual void writeChar(const UnicodeCharacter& character);
	  virtual void writeTable(TableType table);
      virtual ~HtmlWriter();
      virtual void writeBreak(BreakType type);
      virtual void setStyle( const Style &newStyle );
  };

}


#endif

