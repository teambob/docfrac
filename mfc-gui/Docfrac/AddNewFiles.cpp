//---------------------------------------------------------------------------
#include "stdafx.h"
#include "winmgr.h"


#include <vector>
#include <map>
#include "Document.h"
#include "AddNewFiles.h"
#include "ExtensionToFormatMap.h"
#include "FilePropertiesDlg.h"


//---------------------------------------------------------------------------

bool AddNewFiles(Documents &newDocuments)
{
  DoxEngine::ExtensionToFormatMap extensionMap;
  FilePropertiesDlg dialog;

  // Get the last saved settings here
  /* TODO
  FilePropertiesForm->LoadOptions();

  if (newDocuments.size() > 1)
    FilePropertiesForm->SetMultiFile(true);
  else
    FilePropertiesForm->SetMultiFile(false);*/



  if (dialog.DoModal() == IDOK)
  {
    FileFormat outFormat
		= extensionMap[dialog.m_OutputFormatSelect.GetString()];

    Documents::iterator i;

    for (i=newDocuments.begin();i!=newDocuments.end();i++)
    {
      // Input pathname already set


      i->SetOutputFormat(outFormat);

      // There is probably a better object oriented way to do this but... oh well
	  if (!dialog.m_AutomaticFilenameSelect)
      {
        // Manual filename
		  i->SetOutputManual(dialog.m_OutputFilenameEdit.GetString());

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
