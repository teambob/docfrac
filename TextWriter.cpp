#include <iostream>

#include "UnicodeCharacter.h"
#include "WriterInterface.h"
#include "TextWriter.h"


//---------------------------------------------------------------------------

namespace DoxEngine
{

  TextWriter::TextWriter(std::ostream& stream, DebugLog& newLog): log(newLog)
  {
    outputStream = &stream;
    inTable = false;
  }

  void TextWriter::writeChar(const UnicodeCharacter& character)
  {
    using namespace std;

    if (character.isASCII())
      outputStream->put(character.getASCII());

    //character.getASCII();

  }


  void TextWriter::writeTable(TableType table)
  {
    switch(table)
    {
      case TableStart:
        *outputStream << "\r\n";
        //*outputStream << "===================================\r\n";
        inTable = true;
      break;

      case TableRowStart:
        *outputStream << "-----------------------------------\r\n";
      break;

      case TableRowEnd:
        *outputStream << "|\r\n";
      break;

      case TableCellStart:
        *outputStream << "| ";
      break;

      case TableCellEnd:
        *outputStream << " ";
      break;

      case TableEnd:
        *outputStream << "-----------------------------------\r\n";
        inTable = false;
      break;
    }

  }

  TextWriter::~TextWriter()
  {

  }

  void TextWriter::writeBreak(BreakType type)
  {
    if (!inTable)
    {
      if (type == LineBreak)
        outputStream->put('\n');
      else if (type == ParagraphBreak)
      {
        outputStream->put('\n');
        outputStream->put('\n');
      }
    }
  }

  void TextWriter::setStyle( const Style &newStyle )
  {

  }

}
