//---------------------------------------------------------------------------

#include <vector>
#include <map>
#include "Document.h"
#include "FilenameClass.h"

#include "FormatToExtensionMap.h"
#include "ExtensionToFormatMap.h"
#include "tstring.h"


//---------------------------------------------------------------------------


Document::Document()
{
  inFormat = FORMAT_UNKNOWN;
}

void Document::SetInputFilename(const tstring &newInFilename)
{
  inFilename = newInFilename;
  inFormat = FORMAT_UNKNOWN;

}



void Document::SetOutputManual(const tstring &newOutFilename)
{
  outPathname = newOutFilename;
  createOptions = NAME_MANUAL;
}




void Document::SetOutputAutomatic(const tstring &newPathname)
{
  outPathname = newPathname;
  if (outPathname.substr(outPathname.size()-1) != DIRECTORY_SEPARATOR)
    outPathname.append(DIRECTORY_SEPARATOR);

  createOptions = NAME_OTHER_DIR;
}




void Document::SetOutputAutomatic(void)
{
  createOptions = NAME_INPUT_DIR;
}


void Document::SetOutputFormat(FileFormat newOutFormat)
{
  outFormat = newOutFormat;
}

tstring Document::GetInputPathname(void)
{
  return inFilename;
}

tstring Document::GetOutputPathname(void)
{
  FilenameClass pathname(inFilename.c_str());
  tstring outputPathname;
  
  DoxEngine::FormatToExtensionMap mapping;


  switch(createOptions)
  {
    case NAME_INPUT_DIR:
      outputPathname = pathname.GetDirectory()
        + pathname.GetBasename()
        + TEXT(".")
		+ mapping[outFormat];

    break;


    case NAME_OTHER_DIR:
      outputPathname = (tstring)outPathname.c_str()
        + pathname.GetBasename()
        + TEXT(".")
		+ mapping[outFormat];
    break;


    case NAME_MANUAL:
      outputPathname = outPathname.c_str();
    break;
  }
  return outputPathname.c_str();
}

FileFormat Document::GetInputFormat(void)
{
  FilenameClass pathname(inFilename.c_str());
  DoxEngine::ExtensionToFormatMap mapping;


  if (inFormat != FORMAT_UNKNOWN)
    return inFormat;
  else
    return mapping[pathname.GetExtension()];
}

FileFormat Document::GetOutputFormat(void)
{
  return outFormat;

}

bool Document::IsAutomatic(void)
{
  return (createOptions != NAME_MANUAL);
}

bool Document::IsOtherDirectory(void)
{
  return (createOptions == NAME_OTHER_DIR);
}

tstring Document::GetDirectory(void)
{
  return outPathname;
}
