/***************************************************************************
                          main.cpp  -  description
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
#include <cstdio>
#include <fstream>
#include <string.h>
#include "WriterFactory.h"
#include "ReaderFactory.h"
#include "WriterInterface.h"
#include "ReaderInterface.h"
#include "FileFormat.h"
#include "DebugLog.h"


static void ShowHelp(void);

int main(int argc, char *argv[])
{

  DoxEngine::FileFormat inFormat = DoxEngine::FORMAT_UNKNOWN, outFormat = DoxEngine::FORMAT_UNKNOWN;
  char *inFilename, *outFilename;
  int i;
  bool isOutfile = false;

  /* No debug by default */
  DoxEngine::DebugLog log;

  if (argc == 1)
  {
    ShowHelp();
    return 1;
  }


  for (i=1; i<argc; i++)
  {
    if (!strncmp(argv[i], "--", 2))
    {

      if (!strcmp(argv[i], "--from-html"))
        inFormat = DoxEngine::FORMAT_HTML;
      else if (!strcmp(argv[i], "--from-rtf"))
        inFormat = DoxEngine::FORMAT_RTF;
      else if (!strcmp(argv[i], "--from-text"))
        inFormat = DoxEngine::FORMAT_TEXT;

      else if (!strcmp(argv[i], "--to-html"))
        outFormat = DoxEngine::FORMAT_HTML;
      else if (!strcmp(argv[i], "--to-rtf"))
        outFormat = DoxEngine::FORMAT_RTF;
      else if (!strcmp(argv[i], "--to-text"))
        outFormat = DoxEngine::FORMAT_TEXT;

      else if (!strcmp(argv[i], "--debug"))
      {
#ifdef ENABLE_LOG_DEBUG
        log.SetStream(DoxEngine::LOG_DEBUG, std::cerr);
#else
        std::cerr << "Compile option ENABLE_DEBUG_LOG required" << std::endl;
#endif
      }

      else
      {
        ShowHelp();
        return 2;
      }




    }
    else
    {
      if (isOutfile)
      {
        outFilename = argv[i];
        std::ifstream input(inFilename);
        std::ofstream output(outFilename);
        DoxEngine::WriterInterface *writer;
        DoxEngine::ReadInterface *reader;

#ifdef ENABLE_LOG_DEBUG
        std::cerr << "HTML format: " << DoxEngine::FORMAT_HTML << std::endl;
        std::cerr << "Input format: " << inFormat << std::endl;
        std::cerr << "Output format: " << outFormat << std::endl;
#endif



        DoxEngine::WriterFactories &writerFactories = DoxEngine::WriterFactoriesSingleton::GetWriterFactories();

        DoxEngine::WriterFactories::iterator writerIterator = writerFactories.find(outFormat);
        if (writerIterator == writerFactories.end())
        {
          std::cerr << "Internal error initialising writer";
          break;
        }
        else
        {
          // First type is the key (file format)
          // Second type is the value (factory instance)
          writer = writerIterator->second->Create(output, log);
#ifdef ENABLE_LOG_DEBUG
          std::cerr << "Verify out format: "<< writerIterator->first << std::endl;
#endif
        }



        DoxEngine::ReaderFactories &readerFactories = DoxEngine::ReaderFactoriesSingleton::GetReaderFactories();

        DoxEngine::ReaderFactories::iterator readerIterator = readerFactories.find(inFormat);
        if (readerIterator == readerFactories.end())
        {
          std::cerr << "Internal error initialising reader";
          break;
        }
        else
        {
          // First type is the key (file format)
          // Second type is the value (factory instance)
          reader = readerIterator->second->Create(input, *writer, log);
#ifdef ENABLE_LOG_DEBUG
          std::cerr << "Verify in format: "<< readerIterator->first << std::endl;
#endif

        }


        printf("Converting %s to %s\n", inFilename, outFilename);

        while(reader->processData());

        delete reader;
        delete writer;

        isOutfile = false;

      }
      else
      {
        inFilename = argv[i];
        isOutfile = true;

      }
    }


  }

  return 0;
}




void ShowHelp(void)
{
  using namespace std;

  cout << "DocFrac Version 3.1.3" << endl;
  cout << "Copyright 2004-2006 Andrew Punch" << endl;
  cout << "Released under LGPL" << endl;
  cout << "Converts between RTF, HTML and text documents" << endl;
  cout << endl;

  cout << "Usage:" << endl;
  cout << "docfrac <from option> <from file> <to option> <to file>..." << endl;
  cout << endl;
  cout << "From options:" << endl;
  cout << "--from-rtf    From RTF" << endl;
  cout << "--from-html   From HTML" << endl;
  cout << "--from-text   From text" << endl;
  cout << endl;
  cout << "To options:" << endl;
  cout << "--to-rtf      To RTF" << endl;
  cout << "--to-html     To HTML" << endl;
  cout << "--to-text     To text" << endl;
  cout << endl;
  cout << "e.g. docfrac --from-rtf resume.rtf --to-html resume.html" << endl;





}

