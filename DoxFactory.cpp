#include <iostream>
#include <istream>
#include <ostream>

#include "DoxFactory.h"
#include "ReaderInterface.h"
#include "WriterInterface.h"

#include "RtfWriter.h"
#include "TextWriter.h"
#include "HtmlWriter.h"

#include "RtfReader.h"
#include "HtmlReader.h"

//---------------------------------------------------------------------------

using namespace std;

namespace DoxEngine
{

DoxFactory* DoxFactory::instance(void)
{
  static DoxFactory doxFactory;

  return &doxFactory;
}

WriterInterface* DoxFactory::createRtfWriter(std::ostream& stream)
{
  return new RtfWriter(stream);
}

WriterInterface* DoxFactory::createHtmlWriter(std::ostream& stream)
{
  return new HtmlWriter(stream);
}

WriterInterface* DoxFactory::createTextWriter(std::ostream& stream)
{
  return new TextWriter(stream);
}

ReadInterface* DoxFactory::createRtfReader(std::istream& stream,
WriterInterface& writer)
{
  return new RtfReader(stream, writer);
}

ReadInterface* DoxFactory::createHtmlReader(std::istream& stream,
WriterInterface& writer)
{
  return new HtmlReader(stream, writer);
}


ReadInterface* DoxFactory::createTextReader(std::istream& stream,
WriterInterface& writer)
{
  printf("Text reader not available\n");
  return (ReadInterface*)NULL;
}


}

