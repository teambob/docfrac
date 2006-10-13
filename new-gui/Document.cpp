//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include <vector>
#include <string>
#include <map>
#include "Document.h"
#include "FilenameClass.h"
#include "FormatToExtensionMap.h"
#include "ExtensionToFormatMap.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

Document::Document()
{
  inFormat = FORMAT_UNKNOWN;
}

void Document::SetInputFilename(const AnsiString &newInFilename)
{
  inFilename = newInFilename;
  inFormat = FORMAT_UNKNOWN;

}



void Document::SetOutputManual(const AnsiString &newOutFilename)
{
  outPathname = newOutFilename;
  createOptions = NAME_MANUAL;
}




void Document::SetOutputAutomatic(const AnsiString &newPathname)
{
  outPathname = newPathname;
  if (outPathname[outPathname.Length()] != DIRECTORY_SEPARATOR)
    outPathname = outPathname + DIRECTORY_SEPARATOR;

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

AnsiString Document::GetInputPathname(void)
{
  return inFilename;
}

AnsiString Document::GetOutputPathname(void)
{
  FilenameClass pathname(inFilename.c_str());
  std::string outputPathname;
  DoxEngine::FormatToExtensionMap mapping;


  switch(createOptions)
  {
    case NAME_INPUT_DIR:
      outputPathname = pathname.GetDirectory()
        + pathname.GetBasename()
        + "."
        + mapping[outFormat];

    break;


    case NAME_OTHER_DIR:
      outputPathname = (std::string)outPathname.c_str()
        + pathname.GetBasename()
        + "."
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

AnsiString Document::GetDirectory(void)
{
  return outPathname;
}
