#ifndef __RTFREADER_H__
#define __RTFREADER_H__

#include "ReaderInterface.h"
#include "RtfStyle.h"


namespace DoxEngine
{

  class WriterInterface;
  class RtfCommandElement;
  class RtfCommandVector;
  class UnicodeCharacter;
  class RtfStyle;
  class RtfStyleStack;



  class RtfReader : public ReadInterface
  {
    private:
      long fileLength;
      std::istream* stream;
      WriterInterface* writer;
			RtfCommandVector *elements;
			RtfStyleStack rtfStack;
			RtfStyle style;
      bool tableStarted, rowStarted, cellStarted;

      void readCommand(char inputCharacter);
      void handleCommand(std::string& inputString);
      void flushTable(void);


    public:
      RtfReader(std::istream& newStream, WriterInterface& newWriter);
      RtfReader(RtfReader &oldReader);
      ~RtfReader();
      virtual bool processData(void);
      virtual int getPercentComplete(void);

      void commandParagraphBreak(void);
      void commandLineBreak(void);
      void commandIgnoreDestinationKeyword(void);
      void commandColourTable(void);
      void commandCharacter(UnicodeCharacter& character);

      void commandParagraphDefault(void);

      void commandInTable(void);
      void commandEndCell(void);
      void commandEndRow(void);

			Style getStyle(void) const;
			void setStyle( const Style &style );

			RtfStyle getRtfStyle(void) const;
			void setRtfStyle( const RtfStyle &style );


  };

}

#endif

