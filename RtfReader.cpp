#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <iostream>
#include <stdlib.h>
#include <ctype.h>

#include "ReaderInterface.h"
#include "RtfReader.h"
#include "WriterInterface.h"
#include "UnicodeCharacter.h"
#include "RtfCommand.h"
#include "Style.h"
#include "RtfStyle.h"

namespace DoxEngine
{


  unsigned hexToInt(char character)
  {
    if ((character >= '0')&&(character <= '9'))
      return character - '0';
    else if ((character >= 'a')&&(character <= 'z'))
      return character - 'a' + 10;
    else if ((character >= 'A')&&(character <= 'Z'))
      return character - 'A' + 10;
    else return 0;

  }


  RtfReader::RtfReader(std::istream& newStream, WriterInterface& newWriter, DebugLog& newLog):
    log(newLog),style(newLog)
  {
    writer = &newWriter;
    stream = &newStream;
    tableStarted = false;

  }

  RtfReader::~RtfReader()
  {
  }

  bool RtfReader::processData(void)
  {
    char character;
    stream->get(character);

    if (stream->good())
    {

      switch(character)
      {
        case '{':
          // push
#ifdef ENABLE_LOG_DEBUG
          log[LOG_DEBUG] << DEBUG_ID << "rtf push" << std::endl;
#endif          
          rtfStack.push(style);
          break;

        case '}':
          // pop
#ifdef ENABLE_LOG_DEBUG
          log[LOG_DEBUG] << DEBUG_ID << "rtf pop" << std::endl;
#endif          
					style = rtfStack.top();
					if (rtfStack.size())
					{
						rtfStack.pop();
						writer->setStyle(style.getStyle());
					}
					else
					{
							// Mismatched closing brackets
              log[LOG_WARNING] << DEBUG_ID << "Mismatched closing brackets" << std::endl;
					}
				break;

				case '\\':
					// command
#ifdef ENABLE_LOG_DEBUG
          log[LOG_DEBUG] << DEBUG_ID << "command" << std::endl;
#endif
          readCommand(character);
          break;


        case '\n':
        case '\r':
        break;

        default:
          // character
#ifdef ENABLE_LOG_DEBUG
          log[LOG_DEBUG] << "Writing character" << character << std::endl;
#endif          
          flushTable();
          if (character >= 32)
          {
            UnicodeCharacter unicodeCharacter(character);
            writer->writeChar(unicodeCharacter);
          }
          break;
      }

      return true;

    }
    else  // End of file
      return false;

  }


  int RtfReader::getPercentComplete(void)
  {
    return 0;
	}



	void RtfReader::readCommand(char inputCharacter)
	{
		std::string inputString;
		char character;

		// need to check for \{ \} \\
		inputString.append(1, inputCharacter);

 	  stream->get(character);
		while (stream->good())
		{

      if (isdigit(character))
      {
        // this is the parameter for the command
        while (isdigit(character) && stream->good())
        {
          inputString.append(1, character);
          stream->get(character);
        }

        if (!isspace(character))
          stream->putback(character);
          
        handleCommand(inputString);
        return;
      }

      
			switch(character)
			{
				case '\'':
				{
					// Numeric representation of a character
					inputString.append(1, character);
					stream->get(character);
					inputString.append(1, character);
					stream->get(character);
					inputString.append(1, character);
					handleCommand(inputString);
					return;
				}


				case '\\':
				{
					stream->putback(character);
					handleCommand(inputString);
					return;
				}


				case '{':
				case '}':
				case ';':
				{
					stream->putback(character);
					handleCommand(inputString);
					return;
				}

				case ' ':
				case '\r':
				case '\n':
				{
					handleCommand(inputString);
					return;
				}

				default:
					inputString.append(1, character);
				break;



      }

      stream->get(character);
    }


  }





  void RtfReader::handleCommand(std::string& inputString)
  {
  using namespace std;

#ifdef ENABLE_LOG_DEBUG
  log[LOG_DEBUG] << DEBUG_ID << "Handling command: " << inputString << "\n";
#endif  

  if (inputString[1] == '\'')
  {
    unsigned long value =
     (hexToInt(inputString[2])<<4)+hexToInt(inputString[3]);

    UnicodeCharacter character(value);

    commandCharacter(character);

    return;

  }

  string::size_type digitIndex = inputString.find_first_of("-0123456789", 0);
  string commandString;

  if (digitIndex>0)
    commandString = inputString.substr(1, digitIndex-1);
  else
    commandString = inputString.substr(1);

#ifdef ENABLE_LOG_DEBUG
  log[LOG_DEBUG] << DEBUG_ID << "digitIndex = " << digitIndex << "\n";
#endif

  int value;
  if (digitIndex >= inputString.length())
    value = 1;
  else
  {
    string valueString(inputString, digitIndex);
    value = atoi(valueString.c_str());
  }


  RtfCommands::iterator found = elements.find(commandString);

  if (found != elements.end())
    found->second->handleCommand(this, value);
  else
    log[LOG_INFO] << DEBUG_ID << "Command " << commandString << " not found\n";


  }


  void RtfReader::commandIgnoreDestinationKeyword(void)
  {
    int level;
		char character;


		for (level=1;level!=0 && stream->good();)
		{
      stream->get(character);

      if (character == '{')
        level++;
      else if (character == '}')
        level--;

    }


  }






  void RtfReader::commandParagraphBreak(void)
  {
    writer->writeBreak(ParagraphBreak);
  }

  void RtfReader::commandLineBreak(void)
  {
    writer->writeBreak(LineBreak);
  }



  void RtfReader::commandCharacter(UnicodeCharacter& character)
  {
    writer->writeChar(character);
  }


  void RtfReader::commandParagraphDefault(void)
  {
		style.setInTable( false );
		Style standardStyle = style.getStyle();
		standardStyle.setJustification( DefaultJustified );
		style.setStyle(standardStyle);
    writer->setStyle( standardStyle );
  }

  void RtfReader::commandInTable(void)
  {
    // Note: RTF does not allow nested tables
		style.setInTable( true );

	}

	void RtfReader::flushTable(void)
	{
		if (style.getInTable() || style.getSectionColumns())
		{
  		if (!tableStarted)
	  	{
		  	// Beginning of table
			  writer->writeTable(TableStart);
  			tableStarted = true;

	  		writer->writeTable(TableRowStart);
		  	rowStarted = true;

			  writer->writeTable(TableCellStart);
  			cellStarted = true;
	  	}


			if (!rowStarted)
			{
				writer->writeTable(TableRowStart);
				rowStarted = true;
			}

			if (!cellStarted)
			{
				writer->writeTable(TableCellStart);
        cellStarted = true;
      }


    }
    else if (tableStarted)
    {
      writer->writeTable(TableEnd);
      tableStarted = false;
    }
  }

  void RtfReader::commandEndCell(void)
  {
    if (cellStarted)
      writer->writeTable(TableCellEnd);

    cellStarted = false;
	}

  void RtfReader::commandEndRow(void)
  {
    commandEndCell();

    if (rowStarted)
      writer->writeTable(TableRowEnd);

    rowStarted = false;
  }


	Style RtfReader::getStyle(void) const
	{
		return style.getStyle();
	}

	void RtfReader::setStyle( const Style &value )
	{
#ifdef ENABLE_DEBUG_LOG
		log[LOG_DEBUG] << DEBUG_ID << "Setting style\n";
#endif    
		style.setStyle(value);
		writer->setStyle( value );
	}

	void RtfReader::commandColourTable(void)
	{
		int brackets = 1;
		char character;
		std::string inputString;

    stream->get(character);

		while (brackets && stream->good())
		{
#ifdef ENABLE_LOG_DEBUG
			log[LOG_DEBUG] << DEBUG_ID << "Colour character = " << character;
#endif

			if (inputString.length() > 0)
			{
				switch(character)
        {
          case '\\':
          case '{':
          case '}':
          case ';':
          {
            stream->putback(character);
            // handle the colour commands
            std::string::size_type digitIndex = inputString.find_first_of("-0123456789", 0);
            std::string commandString(inputString, 1, digitIndex-1);

#ifdef ENABLE_LOG_DEBUG
            log[LOG_DEBUG] << DEBUG_ID << "inputString.length() = " << inputString.length() << "\n";
            log[LOG_DEBUG] << DEBUG_ID << "digitIndex = " << digitIndex << "\n";
						log[LOG_DEBUG] << DEBUG_ID << "inputString = " << inputString << "\n";
#endif

						int value;

            if (digitIndex >= inputString.length())
              value = 1;
            else
            {
              std::string valueString(inputString, digitIndex);
              value = atoi(valueString.c_str());
#ifdef ENABLE_LOG_DEBUG
              log[LOG_DEBUG] << DEBUG_ID << "value = " << value << "\n";
#endif
            }

#ifdef ENABLE_LOG_DEBUG
            log[LOG_DEBUG] << DEBUG_ID << "commandString = \"" << commandString << "\"\n";
            log[LOG_DEBUG] << DEBUG_ID << "commandString.length() = " << commandString.length() << "\n";
#endif

						if (commandString == "red")
						{
#ifdef ENABLE_LOG_DEBUG
							log[LOG_DEBUG] << DEBUG_ID << "red\n";
#endif
							style.setRed(value);
            }
            else if (commandString == "green")
            {
#ifdef ENABLE_LOG_DEBUG
              log[LOG_DEBUG] << DEBUG_ID << "green\n";
#endif
							style.setGreen(value);
            }
            else if (commandString == "blue")
            {
#ifdef ENABLE_LOG_DEBUG
              log[LOG_DEBUG] << DEBUG_ID << "blue\n";
#endif
              style.setBlue(value);
            }
            else
						  log[LOG_WARNING] << DEBUG_ID << "Not recognised\n";

						inputString.assign("");
          }
          break;

          default:
            inputString.append(1, (char)character);
#ifdef ENABLE_LOG_DEBUG
            log[LOG_DEBUG] << DEBUG_ID << "character = " << character << "\n";
            log[LOG_DEBUG] << DEBUG_ID << "inputString = " << inputString << "\n";
#endif
          break;
        }
      }
      else
      {
#ifdef ENABLE_LOG_DEBUG
        log[LOG_DEBUG] << DEBUG_ID << "Contol character: " << character;
#endif

				switch(character)
				{
					case '{':
            brackets++;
          break;

          case '}':
            brackets--;
          break;

          case ';':
            style.colourTerminate();
          break;

          case '\\':
            inputString.append(1, (char)character);
					break;
				}
			}

      if (brackets)
        stream->get(character);
		}

	}

	RtfStyle RtfReader::getRtfStyle(void) const
	{
		return style;
	}

	void RtfReader::setRtfStyle( const RtfStyle &value )
	{
		style = value;
		writer->setStyle( value.getStyle() );
	}


}



