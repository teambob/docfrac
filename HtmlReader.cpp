#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
#include <iterator>
#include <cctype>


#include "ReaderInterface.h"
#include "HtmlReader.h"

#include "WriterInterface.h"
#include "UnicodeCharacter.h"
#include "HtmlCharacterMap.h"


namespace DoxEngine
{



  HtmlReader::HtmlReader(std::istream& newStream, WriterInterface& newWriter, DebugLog &newLog)
	:stream(newStream), writer(newWriter), log(newLog)
  {
    lineEmpty = true;
    script = false;
    iframe = false;
  }



  bool HtmlReader::processData(void)
  {
    char character;

	  stream.get(character);

    if (!stream.good())
      return false;

    switch(character)
    {
      case '<':
        readCommand();
        lineEmpty = false;
      break;

      case '&':
        readCharacter();
        lineEmpty = false;
      break;

      case '\r':
      break;

      case '\n':
      {
        if ((!lineEmpty)&&(!script)&&(!iframe))
        {
          UnicodeCharacter unicodeCharacter(' ');
          writer.writeChar(unicodeCharacter);
        }
        lineEmpty = true;
      }
      break;

      default:
      {
        if ((!script)&&(!iframe))
        {
          writer.writeChar(UnicodeCharacter(character));
          lineEmpty = false;
        }
      }
      break;
    }

    return stream.good();

  }


  int HtmlReader::getPercentComplete(void)
  {
    return 0;
  }

  HtmlReader::~HtmlReader()
  {
  }


  void HtmlReader::readCommand(void)
  {
    using namespace std;
    string line, command;
    HtmlTag tag(stream);


    command = tag.GetElement();

    // Warning W8091: known bug in Borland 
    std::transform(
      command.begin(),
      command.end(),
      //std::back_inserter(commandLower),
      command.begin(),
      std::tolower);



#ifdef ENABLE_LOG_DEBUG
    log[LOG_DEBUG] << DEBUG_ID << "Line="<<line<<endl;
    log[LOG_DEBUG] << DEBUG_ID << "Command="<<command<<endl;
#endif

    if (!command.compare("br"))
    {
      writer.writeBreak(LineBreak);

#ifdef ENABLE_LOG_DEBUG
      log[LOG_DEBUG] << DEBUG_ID << "Line break" << endl;
#endif
    }
    else if (!command.compare("p"))
    {
      writer.writeBreak(ParagraphBreak);
#ifdef ENABLE_LOG_DEBUG
      log[LOG_DEBUG] << DEBUG_ID << "Paragraph break" << endl;
#endif      
    }
    else if (!command.compare("script"))
    {
      script = true;
    }
    else if (!command.compare("/script"))
    {
      script = false;
    }
    else if (!command.compare("iframe"))
      iframe = true;
    else if (!command.compare("/iframe"))
      iframe = false;



  }

  void HtmlReader::readCharacter(void)
  {
    using namespace std;
    string code("");
    char c;

    stream.get(c);

    while(stream.good() && c != ';')
    {

      // Handle entities missing a terminating semicolon
      if (isalnum(c) || c == '#')
      {
        code.append(1, c);
        stream.get(c);
      }
      else
      {
        stream.putback(c);
        break;
      }

    }


  if (stream.good())
  {
      if (code.find("#x") == 0 || code.find("#X") == 0)
      {
        // hex number
        // Chop off first two bytes (i.e. index 1)
        std::string numberString = code.substr(2);
        unsigned long number = strtoul(numberString.c_str(), NULL, 16);
        UnicodeCharacter character(number);
        writer.writeChar(character);


      }
      else if (code.find("#") == 0)
      {
        //decimal number
        // Chop off first two bytes (i.e. index 1)
        std::string numberString = code.substr(2);
        unsigned long number = strtoul(numberString.c_str(), NULL, 10);
        writer.writeChar(number);

      }
      else
      {
#ifdef ENABLE_LOG_DEBUG
        log[LOG_DEBUG] << DEBUG_ID << "Found escape code:" << code << std::endl;
#endif        
   	    HtmlCharacterMaps::iterator i = maps.find(code);
	      if ((i != maps.end())&&(!script)&&(!iframe))
	      {
		      writer.writeChar(i->second);
        }
      }
    }

  }


}


