#ifndef HtmlReaderH
#define HtmlReaderH

#include "HtmlCharacterMap.h"

namespace DoxEngine
{
  class WriterInterface;
  class HtmlCharacterMaps;

  class HtmlReader : public ReadInterface
  {
    private:
	  std::istream &stream;
	  WriterInterface &writer;
      HtmlCharacterMaps maps;
      bool lineEmpty;
      bool script, iframe;

      void readCommand(void);
      void readCharacter(void);
      void readComment(void);


    public:
      HtmlReader(std::istream& newStream, WriterInterface& newWriter);

      virtual bool processData(void);
      virtual int getPercentComplete(void);

      virtual ~HtmlReader();
  };

}

//---------------------------------------------------------------------------
#endif


