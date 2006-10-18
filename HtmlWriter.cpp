#include <string>
#include <iostream>
#include <ctype.h>

#include "UnicodeCharacter.h"
#include "WriterInterface.h"
#include "HtmlWriter.h"
#include "Style.h"
#include "debug.h"

namespace DoxEngine
{

  char HexToChar(int value)
  {
    if (value<10)
      return (char)('0' + value);
    else
      return (char)('A' + value - 10);
  }

  std::string HexToString(int value)
  {
    using namespace std;

    string temp;

    //temp.clear();

    temp = HexToChar((value>>4)&0x0f);
    temp += HexToChar(value&0x0f);

    return temp;
  }



  HtmlWriter::HtmlWriter(std::ostream& stream)
	:outputStream(stream)
  {
	outputStream << "<HTML>\r\n";
    outputStream << "<BODY>\r\n";

    styleChanged = false;
    whiteSpaces = 0;

  }



  HtmlWriter::~HtmlWriter()
  {
    clearStyles();

	outputStream << "</BODY>\r\n";
	outputStream << "</HTML>\r\n";

  }


  void HtmlWriter::writeChar(const UnicodeCharacter& character)
  {
    if (styleChanged)
    {
      //clearStyles();
      outputStyles();
      styleChanged = false;
    }



    if (character.isASCII())
    {
      if (isspace(character.getASCII()))
      {
        if (whiteSpaces)
          outputStream << "&nbsp;";
        else
	        outputStream << character.getASCII();
          
        whiteSpaces++;
      }
      else
      {
        whiteSpaces = 0;
	      outputStream << character.getASCII();
      }
    }
	  else
    {
      whiteSpaces = 0;
      outputStream << "&#" << character.unicode() << ";";
    }

  }

  void HtmlWriter::writeTable(TableType table)
  {
    switch(table)
    {
      case TableStart:
        tableStopStyle();
		outputStream << "<table>";
	  break;

	  case TableRowStart:
		outputStream << "<tr>";
	  break;

	  case TableRowEnd:
		outputStream << "</tr>\r\n";
	  break;

	  case TableCellStart:
		outputStream << "<td>";
		tableRestartStyle();
	  break;

	  case TableCellEnd:
		tableStopStyle();
		outputStream << "</td>";
	  break;

	  case TableEnd:
		outputStream << "</table>\r\n";
		tableRestartStyle();
	  break;
	}
  }


  void HtmlWriter::writeBreak(BreakType type)
  {
    if (type == LineBreak)
      outputStream << "\r\n<br>";

  }


	void HtmlWriter::setStyle( const Style &newStyle )
  {

    if (!styleChanged)
	  oldStyle = style;

	styleChanged = true;
    style = newStyle;

  }





  void HtmlWriter::outputStyles( void )
  {

	if ((!style.getBold())&&oldStyle.getBold())
	  outputStream << "</b>";

	if ((!style.getItalic())&&oldStyle.getItalic())
	  outputStream << "</i>";

	if ((!style.getUnderline())&&oldStyle.getUnderline())
	  outputStream << "</u>";


	if ((oldStyle.getJustification() != style.getJustification())&&
	  (oldStyle.getJustification() != DefaultJustified))
	  outputStream << "</div>";

	if ((!oldStyle.getDefaultColour())&&
	  (
	  (style.getDefaultColour())||
	  (oldStyle.getColourRed()!=style.getColourRed())||
	  (oldStyle.getColourGreen()!=style.getColourGreen())||
	  (oldStyle.getColourBlue()!=style.getColourBlue())
	  )
	  )
	{
	  *debugStream<<"Clearing colour\n";
	  outputStream << "</font>";
	}


	if (!style.getDefaultColour())
	{
	  *debugStream << "Not default colour\n";

	  if ((oldStyle.getColourRed()!=style.getColourRed())||
	  (oldStyle.getColourGreen()!=style.getColourGreen())||
	  (oldStyle.getColourBlue()!=style.getColourBlue()))
	  {
		*debugStream << "Colour has changed\n";

		outputStream << "<font color=";
		outputStream << HexToString(style.getColourRed());
		outputStream << HexToString(style.getColourGreen());
		outputStream << HexToString(style.getColourBlue());
		outputStream << ">";
	  }
	  else if (oldStyle.getDefaultColour())
	  {
		*debugStream << "Colour is now non-default\n";
		outputStream << "<font color=";
		outputStream << HexToString(style.getColourRed());
		outputStream << HexToString(style.getColourGreen());
		outputStream << HexToString(style.getColourBlue());
		outputStream << ">";
	  }

	  //std::cout << "Finished setting colour\n";
	}




	if ((!oldStyle.getBold())&&style.getBold())
	  outputStream << "<b>";

	if ((!oldStyle.getItalic())&&style.getItalic())
	  outputStream << "<i>";

	if ((!oldStyle.getUnderline())&&style.getUnderline())
	  outputStream << "<u>";


	if (oldStyle.getJustification() != style.getJustification())
	{
	  //std::cout << "Justification changed\n";
	  //if (style->getJustification() == DefaultJustified)
	  //  std::cout << "No Justification\n";
	  if (style.getJustification() == LeftJustified)
		outputStream << "<div align=left>";
	  else if (style.getJustification() == RightJustified)
		outputStream << "<div align=right>";
	  else if (style.getJustification() == CentreJustified)
	  {
		//std::cout << "Writing centre\n";
		outputStream << "<div align=center>";
	  }
	  else if (style.getJustification() == Justified)
		outputStream << "<div align=justify>";
	}


	styleChanged = false;
  }


  void HtmlWriter::clearStyles( void )
  {
	oldStyle = style;

	style.setDefault();
	outputStyles();
  }


  void HtmlWriter::tableStopStyle( void )
  {
	Style tempStyle(style);

	oldStyle = style;

	style.setDefault();
	outputStyles();

	style = tempStyle;

  }



  void HtmlWriter::tableRestartStyle( void )
  {
	oldStyle.setDefault();
	outputStyles();
  }

}














