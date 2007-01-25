#include <string>
#include <iostream>
#include <ostream>
#include <ctype.h>

#include "UnicodeCharacter.h"
#include "WriterInterface.h"
#include "HtmlWriter.h"
#include "Style.h"

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



  HtmlWriter::HtmlWriter(std::ostream& stream, DebugLog &newLog)
	:outputStream(stream), log(newLog)
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
      char ASCIICharacter = character.getASCII();

      if (isspace(ASCIICharacter))
      {
        if (whiteSpaces)
          outputStream << "&nbsp;";
        else
	        outputStream << ASCIICharacter;

        whiteSpaces++;
      }
      else
      {
        whiteSpaces = 0;
        switch (ASCIICharacter)
        {
          case '&':
            outputStream << "&amp;";
          break;

          case '<':
            outputStream << "&lt;";
          break;

          case '>':
            outputStream << "&gt;";
          break;

          default:
            outputStream << ASCIICharacter;
          break;
        }

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


	if (oldStyle.getJustification() != style.getJustification() &&
	    oldStyle.getJustification() != DefaultJustified &&
      oldStyle.getJustification() != LeftJustified)
	  outputStream << "</div>";

	if ( !oldStyle.getDefaultColour() &&
	  (
	    style.getDefaultColour() ||
	    (oldStyle.getColourRed()!=style.getColourRed()) ||
	    (oldStyle.getColourGreen()!=style.getColourGreen()) ||
	    (oldStyle.getColourBlue()!=style.getColourBlue())
	  ) )
	{
#ifdef ENABLE_LOG_DEBUG
	  log[LOG_DEBUG] << DEBUG_ID << "Clearing colour\n";
#endif
	  outputStream << "</font>";
	}


	if (!style.getDefaultColour())
	{
#ifdef ENABLE_LOG_DEBUG
	  log[LOG_DEBUG] << DEBUG_ID << "Not default colour\n";
#endif

    if (oldStyle.getDefaultColour())
	  {
#ifdef ENABLE_LOG_DEBUG
		log[LOG_DEBUG] << DEBUG_ID << "Colour is now non-default\n";
#endif
		outputStream << "<font color=";
		outputStream << HexToString(style.getColourRed());
		outputStream << HexToString(style.getColourGreen());
		outputStream << HexToString(style.getColourBlue());
		outputStream << ">";
	  }
    else if ( (oldStyle.getColourRed()!=style.getColourRed())||
	    (oldStyle.getColourGreen()!=style.getColourGreen())||
	    (oldStyle.getColourBlue()!=style.getColourBlue()))
	  {
#ifdef ENABLE_LOG_DEBUG
		log[LOG_DEBUG] << DEBUG_ID << "Colour has changed\n";
#endif

		outputStream << "<font color=";
		outputStream << HexToString(style.getColourRed());
		outputStream << HexToString(style.getColourGreen());
		outputStream << HexToString(style.getColourBlue());
		outputStream << ">";
	  }


#ifdef ENABLE_LOG_DEBUG
	  log[LOG_DEBUG] << DEBUG_ID << "Finished setting colour\n";
#endif    
	}




	if ((!oldStyle.getBold())&&style.getBold())
	  outputStream << "<b>";

	if ((!oldStyle.getItalic())&&style.getItalic())
	  outputStream << "<i>";

	if ((!oldStyle.getUnderline())&&style.getUnderline())
	  outputStream << "<u>";



  Justification oldJustification = oldStyle.getJustification();
  Justification newJustification = style.getJustification();

  if (oldJustification == DefaultJustified)
    oldJustification = LeftJustified;

  if (newJustification == DefaultJustified)
    newJustification = LeftJustified;


	if (oldJustification != newJustification)
	{
#ifdef ENABLE_LOG_DEBUG
	  log[LOG_DEBUG] << DEBUG_ID << "Justification changed\n";
#endif

	  if (style.getJustification() == DefaultJustified ||
	    style.getJustification() == LeftJustified)
    {

    }
	  else if (style.getJustification() == RightJustified)
		  outputStream << "<div align=right>";
	  else if (style.getJustification() == CentreJustified)
	  {
#ifdef ENABLE_LOG_DEBUG
		  log[LOG_DEBUG] << DEBUG_ID << "Writing centre\n";
#endif
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














