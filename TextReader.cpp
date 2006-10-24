#include <string>
#include <algorithm>
#include <vector>
#include <iostream>

#include "ReaderInterface.h"
#include "TextReader.h"

#include "WriterInterface.h"
#include "UnicodeCharacter.h"
#include "HtmlCharacterMap.h"

#include "debug.h"


namespace DoxEngine
{



  TextReader::TextReader(std::istream& newStream, WriterInterface& newWriter)
	:stream(newStream), writer(newWriter)
  {
  }



  bool TextReader::processData(void)
  {
    char character;

	  stream.get(character);

    if (!stream.good())
      return false;

    switch(character)
    {
      case '\r':
        // Ignore
      break;

      case '\n':
        writer.writeBreak(LineBreak);
      break;

      default:
        writer.writeChar(UnicodeCharacter(character));
      break;
    }

    return stream.good();

  }


  int TextReader::getPercentComplete(void)
  {
    return 0;
  }

  TextReader::~TextReader()
  {
  }




}


