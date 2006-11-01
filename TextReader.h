#ifndef TextReaderH
#define TextReaderH

#include "DebugLog.h"

namespace DoxEngine
{
  class WriterInterface;

  class TextReader : public ReadInterface
  {
    private:
	    std::istream &stream;
	    WriterInterface &writer;
      DebugLog &log;


    public:
      TextReader(std::istream& newStream, WriterInterface& newWriter, DebugLog& newLog);

      virtual bool processData(void);
      virtual int getPercentComplete(void);

      virtual ~TextReader();
  };

}

//---------------------------------------------------------------------------
#endif


