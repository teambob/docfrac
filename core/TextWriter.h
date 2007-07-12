//---------------------------------------------------------------------------
#ifndef TextWriterH
#define TextWriterH

#include "DebugLog.h"

namespace DoxEngine
{

  class TextWriter : public WriterInterface
  {
    private:
      std::ostream* outputStream;
      DebugLog& log;
      bool inTable;

    public:
      TextWriter(std::ostream& stream, DebugLog& newLog);
      virtual void writeChar(const UnicodeCharacter& character);
      virtual ~TextWriter();
      virtual void writeBreak(BreakType type);
      virtual void setStyle( const Style &newStyle );
      virtual void writeTable(TableType table);
  };
}

//---------------------------------------------------------------------------
#endif
