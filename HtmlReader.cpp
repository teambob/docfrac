#include <string>
#include <algorithm>
#include <vector>
#include <iostream>

#include "ReaderInterface.h"
#include "HtmlReader.h"

#include "WriterInterface.h"
#include "UnicodeCharacter.h"
#include "HtmlCharacterMap.h"

#include "debug.h"

namespace DoxEngine
{



  HtmlReader::HtmlReader(std::istream& newStream, WriterInterface& newWriter)
	:stream(newStream), writer(newWriter)
  {
    maps = HtmlCharacterMapsFactory::instance().getMaps();

    lineEmpty = true;
    script = false;
    iframe = false;
  }



  bool HtmlReader::processData(void)
  {
    int character;

	character = stream.get();

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

      case EOF:
      break;

      default:
      {
        if ((!script)&&(!iframe))
        {
          writer.writeChar(UnicodeCharacter((char)character));
          lineEmpty = false;
        }
      }
      break;
    }

    return (!stream.eof());

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
    int character;

    character = stream.get();
    while((!stream.eof())&&(character!='>'))
    {
      line += (char)character;
      if (line=="!--")  // '<' has been thrown away, comment
      {
        readComment();
        return;
      }

      character = stream.get();
    }

    std::string::iterator i;

    for(i=line.begin();i!=line.end();i++)
    {
      command += (char)toupper(*i); // Convert command to upper case
    }

    command = command.substr(0, command.find_first_of(" \n"));
    
    *debugStream << "Line="<<line<<endl;
    *debugStream << "Command="<<command<<endl;
    if (!command.compare("BR"))
    {
      writer.writeBreak(LineBreak);
      *debugStream << "Line break" << endl;
    }
    else if (!command.compare("P"))
    {
      writer.writeBreak(ParagraphBreak);
      *debugStream << "Paragraph break" << endl;
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
    int c;

    c = stream.get();
    
    while((!stream.eof())&&(c!=';'))
    {
      code += (char)c;

      c = stream.get();
    }

    
    if (c == ';')
    {
      *debugStream << "Found escape code:" << code << std::endl;
	  HtmlCharacterMaps::iterator i = find(maps.begin(), maps.end(), code);
	  if ((i != maps.end())&&(!script)&&(!iframe))
	  {

		writer.writeChar(i->getCharacter());
      }

    }

  }

  void HtmlReader::readComment(void)
  {
    using namespace std;
    string line, commentEnd="-->";

		for (unsigned i=0;(!stream.eof())&&(i<commentEnd.length());i++)
      line += (char)stream.get();

	while((!stream.eof())&&(line!=commentEnd))
    {
      line = line.substr(1, line.npos);
      line += (char)stream.get();
    }
  }

}


