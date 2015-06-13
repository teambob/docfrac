//---------------------------------------------------------------------------
//#include <vcl.h>
#include <windows.h>
#pragma hdrstop
#include <fstream>
#include <string>
#include <sstream>
#include <io.h>
#include <stdio.h>
#include "tdox.h"


#define ALLOC_TRAD 1

#include "WriterInterface.h"
#include "ReaderInterface.h"
#include "debug.h"
#include "DoxFactory.h"
//#include "dox_defines.h"
//#include "dox.h"
#include "ExtensionToFormatMap.h"
// extern HANDLE DoxComSemaphore;


TDox::TDox():inFormat(-1),outFormat(-1)
{
}

TDox::~TDox()
{
}

/* Convert between files */
bool TDox::FileConvert()
{
  using namespace std;

  istream *input;

  if (UseInString)
    input = new istringstream(inBuffer);
  else
  {
    ifstream *inputStream = new ifstream(inBuffer.c_str());
    if ( !inputStream->good() || !inputStream->is_open())
      return false;

    input = inputStream;

  }



  ofstream *output = new ofstream(outBuffer.c_str());

  if ( !output->good() || !output->is_open())
    return false;


  DoxEngine::debugStream = &std::cout;
  DoxEngine::DoxFactory* factory = DoxEngine::DoxFactory::instance();
  DoxEngine::ReadInterface *reader;
  DoxEngine::WriterInterface *writer;
  DoxEngine::ExtensionToFormatMap map;


  if (outFormat == -1)
  {
    outFormat = map[outBuffer.c_str()];
    if (outFormat == FORMAT_UNKNOWN)
      outFormat = FORMAT_HTML;
  }


  switch(outFormat)
  {

    case FORMAT_HTML:
      writer = factory->createHtmlWriter(*output);
    break;

    case FORMAT_TEXT:
      writer = factory->createTextWriter(*output);
    break;

    case FORMAT_RTF:
    default:
      writer = factory->createRtfWriter(*output);
    break;

  }



  if (inFormat == -1)
  {
    inFormat = map[inBuffer.c_str()];
    if (inFormat == FORMAT_UNKNOWN)
      inFormat = FORMAT_HTML;
  }


  switch(inFormat)
  {
    case FORMAT_RTF:
      reader = factory->createRtfReader(*input, *writer);
    break;

    case FORMAT_HTML:
      reader = factory->createHtmlReader(*input, *writer);
    break;

    case FORMAT_TEXT:
      reader = factory->createTextReader(*input, *writer);
    break;

  }

  if ((reader == NULL)||(writer == NULL))
    return false;

  // test line
  while (reader->processData());
  //while (!Terminated);

  // Finsihed with the converter
  delete reader;
  delete writer;

  // Finished with the streams
  delete input;
  delete output;

  return true;

}

void TDox::SetInFileName(const std::string &Filename)
{
  inBuffer = Filename;
}

void TDox::SetOutFileName(const std::string &Filename)
{
  outBuffer = Filename;
}

void TDox::SetInFormat(const std::string &Extension)
{
  UseInString = false;
  inFormat = Ext2For(Extension.c_str());
}

void TDox::SetOutFormat(const std::string &Extension)
{
  outFormat = Ext2For(Extension.c_str());
}

int TDox::Ext2For(const char *Extension)
{
char Temp[255];

if (!Extension)
    return -1;

strcpy(Temp, Extension);
strlwr(Temp);

if (!strcmp(Extension, "rtf"))
    return FORMAT_RTF;
else if ((!strcmp(Extension, "htm"))||(!strcmp(Extension, "html")))
    return FORMAT_HTML;
else if (!strcmp(Extension, "txt"))
    return FORMAT_TEXT;
else return -1;
}

void TDox::SetInString(const std::string &In)
{
  inBuffer = In;
  UseInString = true;
}

std::string TDox::StringConvert(void)
{
  using namespace std;

  istream *input;
  string outString;

  if (UseInString)
    input = new istringstream(inBuffer);
  else
  {
    ifstream *inputStream = new ifstream(inBuffer.c_str());
    if ( !inputStream->good() || !inputStream->is_open())
      return "";

    input = inputStream;

  }

  ostringstream *output = new ostringstream;

  if (!output->good())
    return "";


  DoxEngine::debugStream = &std::cout;
  DoxEngine::DoxFactory* factory = DoxEngine::DoxFactory::instance();
  DoxEngine::ReadInterface *reader;
  DoxEngine::WriterInterface *writer;

  if (outFormat == -1)
    outFormat = FORMAT_RTF;

  switch(outFormat)
  {
    case FORMAT_HTML:
      writer = factory->createHtmlWriter(*output);
    break;

    case FORMAT_RTF:
      writer = factory->createRtfWriter(*output);
    break;

    case FORMAT_TEXT:
      writer = factory->createTextWriter(*output);
    break;



  }

  if (inFormat == -1)
    inFormat = FORMAT_RTF;

  switch(inFormat)
  {
    case FORMAT_RTF:
      reader = factory->createRtfReader(*input, *writer);
    break;

    case FORMAT_HTML:
      reader = factory->createHtmlReader(*input, *writer);
    break;

    case FORMAT_TEXT:
      reader = factory->createTextReader(*input, *writer);
    break;

  }

  if ((reader == NULL)||(writer == NULL))
    return "";

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


  return outString;

}

//---------------------------------------------------------------------------
#pragma package(smart_init)
