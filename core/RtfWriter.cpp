/***************************************************************************
                          RtfWriter.cpp  -  description
                             -------------------
    begin                : Tue Oct 28 2003
    copyright            : (C) 2003 by Andrew Punch
    email                : andrewpunch@bigfoot.com
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/
#include <iostream>

#include "WriterInterface.h"
#include "RtfWriter.h"
#include "UnicodeCharacter.h"



namespace DoxEngine
{


  RtfWriter::RtfWriter(std::ostream& stream, DebugLog& newLog):
    log(newLog),WriterInterface()
  {
    outputStream = &stream;

    *outputStream << "{\\rtf\\ansi{";
  }


  void RtfWriter::writeChar(const UnicodeCharacter& character)
  {
    if (character.isASCII())
      *outputStream << character.getASCII();
  }


  void RtfWriter::writeTable(TableType table)
  {
    // RTF table out requires further investiagtion
    switch(table)
    {
    case TableStart:
      break;

    case TableEnd:
      break;

    case TableRowStart:
      break;

    case TableRowEnd:
      break;

    case TableCellStart:
      break;

    case TableCellEnd:
      break;
    }
  }

  RtfWriter::~RtfWriter()
  {
    *outputStream << "}}";
  }


  void RtfWriter::writeBreak(BreakType type)
  {
    if (type == LineBreak)
      *outputStream << "\\par\r\n";
    else if (type == ParagraphBreak)
      *outputStream << "\\par\r\n\\par\r\n";

  }

  void RtfWriter::setStyle( const Style &newStyle )
  {
    if (newStyle != style)
    {
      *outputStream << "}{";

      // Write out character styles
      if (newStyle.getBold())
      {
        *outputStream << "\\b ";
      }

      if (newStyle.getItalic())
      {
        *outputStream << "\\i ";
      }

      if (newStyle.getUnderline())
      {
        *outputStream << "\\ul ";
      }

    }


  }

}

