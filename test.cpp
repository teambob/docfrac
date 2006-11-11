#include <iostream>
#include <fstream>
#include <stdlib.h>

#include "WriterFactory.h"
#include "ReaderFactory.h"
#include "ReaderInterface.h"
#include "WriterInterface.h"

int main(int argc, char* argv[])
{
  using namespace DoxEngine;
  using namespace std;

  try
  {
    if (argc != 4)
    {
      std::cout << "test <infile> <outfile> <repititions>\n";
      return 0;
    }

    int i;
    for (i=0;i<atoi(argv[3]);i++)
    {


      ifstream inputStream(argv[1], fstream::in);
      ofstream outputStream(argv[2], fstream::out);


	  DoxEngine::WriterFactories &writerFactories = DoxEngine::WriterFactoriesSingleton::GetWriterFactories();

	  DoxEngine::WriterFactories::iterator writerIterator = writerFactories.find(FORMAT_RTF);
	  if (writerIterator == writerFactories.end())
	  {
	    std::cerr << "Internal error initialising writer";
		break;
	  }
	  else
	  {
		// First type is the key (file format)
		// Second type is the value (factory instance)
		writer = writerIterator->second->Create(output);
	  }


      ReadInterface* reader = doxFactory->createRtfReader(inputStream, *writer);

      while(reader->processData());

      delete &reader;
      delete &writer;
    }


  }
  catch(...)
  {
    cout<<"Exception occured";
  }

}

