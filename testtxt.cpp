#include <fstream>
#include <iostream>
#include <stdlib.h>

#include "DoxFactory.h"
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
      std::cout << "testtxt <infile> <outfile> <repititions>\n";
      return 0;
    }

    int i;
    for (i=0;i<atoi(argv[3]);i++)
    {


      ifstream inputStream(argv[1], fstream::in);
      ofstream outputStream(argv[2], fstream::out);


      DoxFactory *doxFactory = DoxFactory::instance();

      WriterInterface* writer = doxFactory->createTextWriter(outputStream);
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

