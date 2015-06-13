/***************************************************************************
                          RtfWriter.h  -  description
                             -------------------
    begin                : Tue Feb 15 2003
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

#ifndef __RTF_WRITER_H__
#define __RTF_WRITER_H__

#include "DebugLog.h"
#include "Style.h"

namespace DoxEngine
{

  class RtfWriter : public WriterInterface
  {
  private:
    std::ostream* outputStream;
    DebugLog& log;
    Style style;

  public:
    RtfWriter(std::ostream& stream, DebugLog& newLog);
    virtual void writeChar(const UnicodeCharacter& character);
    virtual void writeTable(TableType table);
    virtual ~RtfWriter();
    virtual void writeBreak(BreakType type);
    virtual void setStyle( const Style &newStyle );
  };

}


#endif
