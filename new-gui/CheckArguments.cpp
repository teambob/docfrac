//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include <vector>
#include "Document.h"
#include "CheckArguments.h"
#include "AddNewFiles.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
#include "CheckArguments.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)

Documents CheckArguments(int argc, char *argv[])
{
  int i;
  Documents newDocuments;

  for (i=1;i<argc;i++)
  {
    Document newDocument;

    newDocument.SetInputFilename(argv[i]);
    newDocuments.push_back(newDocument);
  }

  if (newDocuments.size())
  {
    if (!AddNewFiles(newDocuments))
      newDocuments.clear();
  }


  return newDocuments;


}