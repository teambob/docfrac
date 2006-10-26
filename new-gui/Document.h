//---------------------------------------------------------------------------
#ifndef DocumentH
#define DocumentH
//---------------------------------------------------------------------------
#include <vector>
#include "FileFormat.h"

  enum FilenameCreate
  {
    NAME_INPUT_DIR,
    NAME_OTHER_DIR,
    NAME_MANUAL
  };


  class Document
  {
    private:
      AnsiString inFilename;
      FileFormat inFormat;

      AnsiString outPathname; // May be directory path or file path
      FileFormat outFormat;
      FilenameCreate createOptions;

    public:
      Document();

      void SetInputFilename(const AnsiString &newInFilename);
      void SetOutputManual(const AnsiString &newOutFilename);
      void SetOutputAutomatic(const AnsiString &newPathname);
      void SetOutputAutomatic(void);
      void SetOutputFormat(FileFormat newOutFormat);

      bool IsAutomatic(void);
      bool IsOtherDirectory(void);
      AnsiString GetDirectory(void);

      AnsiString GetInputPathname(void);
      AnsiString GetOutputPathname(void);
      FileFormat GetInputFormat(void);
      FileFormat GetOutputFormat(void);

  };


  
  typedef std::vector<Document> Documents;



#endif
