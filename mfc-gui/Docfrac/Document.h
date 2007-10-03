//---------------------------------------------------------------------------
#ifndef DocumentH
#define DocumentH
//---------------------------------------------------------------------------
#include <vector>
#include "FileFormat.h"
#include "tstring.h"

  enum FilenameCreate
  {
    NAME_INPUT_DIR,
    NAME_OTHER_DIR,
    NAME_MANUAL
  };


  class Document
  {
    private:
      tstring inFilename;
      FileFormat inFormat;

      tstring outPathname; // May be directory path or file path
      FileFormat outFormat;
      FilenameCreate createOptions;

    public:
      Document();

      void SetInputFilename(const tstring &newInFilename);
      void SetOutputManual(const tstring &newOutFilename);
      void SetOutputAutomatic(const tstring &newPathname);
      void SetOutputAutomatic(void);
      void SetOutputFormat(FileFormat newOutFormat);

      bool IsAutomatic(void);
      bool IsOtherDirectory(void);
      tstring GetDirectory(void);

      tstring GetInputPathname(void);
      tstring GetOutputPathname(void);
      FileFormat GetInputFormat(void);
      FileFormat GetOutputFormat(void);

  };


  
  typedef std::vector<Document> Documents;



#endif
