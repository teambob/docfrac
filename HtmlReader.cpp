#include <string>
#include <algorithm>
#include <vector>
#include <iostream>

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
    char character;

    stream.get(character);
    while(stream.good() && character != '>' )
    {
      line.append(1, character);
      if (line=="!--")  // '<' has been thrown away, comment
      {
        readComment();
        return;
      }

      stream.get(character);
    }

    std::string::iterator i;

    for(i=line.begin();i!=line.end();i++)
    {
      command += (char)toupper(*i); // Convert command to upper case
    }

    command = command.substr(0, command.find_first_of(" \n"));

#ifdef ENABLE_LOG_DEBUG
    log[LOG_DEBUG] << DEBUG_ID << "Line="<<line<<endl;
    log[LOG_DEBUG] << DEBUG_ID << "Command="<<command<<endl;
#endif

    if (!command.compare("BR"))
    {
      writer.writeBreak(LineBreak);

#ifdef ENABLE_LOG_DEBUG
      log[LOG_DEBUG] << DEBUG_ID << "Line break" << endl;
#endif
    }
    else if (!command.compare("P"))
    {
      writer.writeBreak(ParagraphBreak);
#ifdef ENABLE_LOG_DEBUG
      log[LOG_DEBUG] << DEBUG_ID << "Paragraph break" << endl;
#endif      
    }
    else if (!command.compare("SCRIPT"))
    {
      script = true;
    }
    else if (!command.compare("/SCRIPT"))
    {
      script = false;
    }
    else if (!command.compare("IFRAME"))
      iframe = true;
    else if (!command.compare("/IFRAME"))
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

  void HtmlReader::readComment(void)
  {
    using namespace std;
    string line, commentEnd="-->";

		for (unsigned i=0;stream.good()&&(i<commentEnd.length());i++)
      line.append(1, (char)stream.get());

	while(stream.good()&&(line!=commentEnd))
    {
      line = line.substr(1, line.npos);
      line.append(1, (char)stream.get());
    }
  }

}


