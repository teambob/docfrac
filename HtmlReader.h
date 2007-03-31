#ifndef HtmlReaderH
#define HtmlReaderH

#include <istream>

#include "HtmlCharacterMap.h"
#include "HtmlTag.h"
#include "DebugLog.h"
#include "Style.h"
#include "ReaderInterface.h"
#include "HtmlCommand.h"

namespace DoxEngine
{
  class WriterInterface;

  class HtmlReader : public ReadInterface
  {
    private:
	  std::istream *stream;
	  WriterInterface &writer;
    HtmlCommands commands;
    DebugLog &log;
    Style style;
    bool startOfFile;
    
      HtmlCharacterMaps maps;
      bool lineEmpty;
      bool script, iframe;

      void readCommand(void);
      void readCharacter(void);

    static const char BYTE_ORDER_MARK_UTF8_BYTE1 = 0xEF;
    static const char BYTE_ORDER_MARK_UTF8_BYTE2 = 0xBB;
    static const char BYTE_ORDER_MARK_UTF8_BYTE3 = 0xBF;




    public:
      HtmlReader(std::istream& newStream, WriterInterface& newWriter, DebugLog &newLog);

      virtual bool processData(void);
      virtual int getPercentComplete(void);

      virtual ~HtmlReader();

      Style GetStyle();
      void SetStyle( const Style &value );
      void SetScript( bool value );
      void SetIframe( bool value );
      WriterInterface& HtmlReader::GetWriterReference();

  };

}

//---------------------------------------------------------------------------
#endif


