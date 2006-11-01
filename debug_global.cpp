/***************************************************************************
                          debug.cpp  -  description
                             -------------------
    begin                : Tue May 4 2004
    copyright            : (C) 2004 by Andrew Punch
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

#include <ostream>
#include <iostream>
#include <stdio.h>
#include "debug_global.h"

namespace DoxEngine
{
  std::ostream *debugStream = &(std::cerr);
};

