//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include <vector>
#include <map>
#include "Document.h"
#include "AddNewFiles.h"
#include "../core/ExtensionToFormatMap.h"
#include "TFilePropertiesForm.h"


//---------------------------------------------------------------------------
#pragma package(smart_init)

bool AddNewFiles(Documents &newDocuments)
{
  DoxEngine::ExtensionToFormatMap extensionMap;

  // Get the last saved settings here
  FilePropertiesForm->LoadOptions();

  if (newDocuments.size() > 1)
    FilePropertiesForm->SetMultiFile(true);
  else
    FilePropertiesForm->SetMultiFile(false);



  if (FilePropertiesForm->ShowModal() == mrOk)
  {
    FileFormat outFormat
      = extensionMap[FilePropertiesForm->OutputFormatSelect->Text.LowerCase().c_str()];

    Documents::iterator i;

    for (i=newDocuments.begin();i!=newDocuments.end();i++)
    {
      // Input pathname already set


      i->SetOutputFormat(outFormat);

      // There is probably a better object oriented way to do this but... oh well
      if (!FilePropertiesForm->AutomaticFilenameSelect->Checked)
      {
        // Manual filename
        i->SetOutputManual(FilePropertiesForm->OutputFilenameEdit->Text.c_str());

      }
      else // Automatic filename
      {
        if(FilePropertiesForm->InputDirectorySelect->Checked)
          i->SetOutputAutomatic();
        else if (FilePropertiesForm->OutputDirectorySelect->Checked)
          i->SetOutputAutomatic(FilePropertiesForm->OutputDirectoryEdit->Text);
      }
      // Save the last settings here
      FilePropertiesForm->SaveOptions();
    }
    return true;
  }
  else
  {
    newDocuments.clear();
    return false;
  }



} 
