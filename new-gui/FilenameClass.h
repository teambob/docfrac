//---------------------------------------------------------------------------
#ifndef FilenameClassH
#define FilenameClassH
//---------------------------------------------------------------------------
const char DIRECTORY_SEPARATOR = '\\';

class FilenameClass : public std::string
{
  public:
    std::string GetDirectory(void);
    std::string GetFilename(void);
    std::string GetBasename(void);
    std::string GetExtension(void);

    FilenameClass();
    FilenameClass(const std::string &s);
    FilenameClass(const char* s);

};
#endif
 