//---------------------------------------------------------------------------
#include <vcl.h>
//#include <stdio.h>
//#include <io.h>
#pragma hdrstop

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

#include "WriterInterface.h"
#include "ReaderInterface.h"
#include "DoxFactory.h"
#include "debug.h"

//#include "dox.h"
#include "doxface.h"


long _export _cdecl DoxConvert(char *InFile, char *OutFile, long Options)
{
  using namespace std;

  ifstream *input;
  long outLength;

  input = new ifstream(InFile);


  if ( !input->good() || !input->is_open() )
    return 0;

  ofstream *output = new ofstream(OutFile);

  if ( !output->good() || !output->is_open() )
    return 0;

  //DoxEngine::debugStream = &std::cout;
  DoxEngine::debugStream = new ofstream("c:\\dox.log");
  DoxEngine::DoxFactory* factory = DoxEngine::DoxFactory::instance();
  DoxEngine::ReadInterface *reader;
  DoxEngine::WriterInterface *writer;

  switch((Options>>4)-1)
  {
    case doc_rtf:
      writer = factory->createRtfWriter(*output);
    break;

    case doc_html:
      writer = factory->createHtmlWriter(*output);
    break;

    case doc_text:
      writer = factory->createTextWriter(*output);
    break;

    default:
      return 0;

  }



  switch((Options&0x0f)-1)
  {
    case doc_rtf:
      reader = factory->createRtfReader(*input, *writer);
    break;

    case doc_html:
      reader = factory->createHtmlReader(*input, *writer);
    break;

    case doc_text:
      reader = factory->createTextReader(*input, *writer);
    break;

    default:
      return 0;

  }

  if ((reader == NULL)||(writer == NULL))
    return 0;

  // test line
  while (reader->processData());
  //while (!Terminated);

  // Finsihed with the converter
  delete reader;
  delete writer;

  output->seekp(0, ios_base::end);
  outLength = output->tellp();

  (*DoxEngine::debugStream) << "OutLength = " << outLength << endl;

  // Finished with the streams
  delete input;
  delete output;


  delete DoxEngine::debugStream;

  return outLength;
}



long _export _cdecl DoxStringConvert(char *InBuffer, long InLength, char *OutBuffer,
    long OutLength, long Options)
{
  using namespace std;

  istream *input;
  string inString;
  string outString;


  input = new istringstream(InBuffer, InLength);


  if (!input->good())
    return false;

  ostringstream *output = new ostringstream;

  if (!output->good())
    return false;


  DoxEngine::debugStream = &std::cout;
  DoxEngine::DoxFactory* factory = DoxEngine::DoxFactory::instance();
  DoxEngine::ReadInterface *reader;
  DoxEngine::WriterInterface *writer;

  switch((Options>>4)-1)
  {
    case doc_rtf:
      writer = factory->createRtfWriter(*output);
    break;

    case doc_html:
      writer = factory->createHtmlWriter(*output);
    break;

    case doc_text:
      writer = factory->createTextWriter(*output);
    break;

    default:
      return 0;

  }



  switch((Options&0x0f)-1)
  {
    case doc_rtf:
      reader = factory->createRtfReader(*input, *writer);
    break;

    case doc_html:
      reader = factory->createHtmlReader(*input, *writer);
    break;

    case doc_text:
      reader = factory->createTextReader(*input, *writer);
    break;

    default:
      return 0;

  }

  if ((reader == NULL)||(writer == NULL))
    return 0;

  // test line
  while (reader->processData());
  //while (!Terminated);

  // Finsihed with the converter
  delete reader;
  delete writer;

  outString = output->str();

  // Finished with the streams
  delete input;
  delete output;

  // Copy at most OutLength bytes into OutBuffer
  outString.copy(OutBuffer, OutLength);
  if (outString.length()<OutLength)
    return outString.length();   /* Enought buffer space */
  else
    return -(long)outString.length();  /* Not enough buffer space */
}


//---------------------------------------------------------------------------
#pragma package(smart_init)
