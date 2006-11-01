#ifndef HtmlReaderH
#define HtmlReaderH

#include "HtmlCharacterMap.h"
#include "DebugLog.h"

namespace DoxEngine
{
  class WriterInterface;

  class HtmlReader : public ReadInterface
  {
    private:
	  std::istream &stream;
	  WriterInterface &writer;
    DebugLog &log;
    
      HtmlCharacterMaps maps;
      bool lineEmpty;
      bool script, iframe;

      void readCommand(void);
      void readCharacter(void);
      void readComment(void);


    public:
      HtmlReader(std::istream& newStream, WriterInterface& newWriter, DebugLog &newLog);

      virtual bool processData(void);
      virtual int getPercentComplete(void);

      virtual ~HtmlReader();
  };

}

//---------------------------------------------------------------------------
#endif


