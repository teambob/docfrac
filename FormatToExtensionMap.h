//---------------------------------------------------------------------------
#ifndef FormatToExtensionMapH
#define FormatToExtensionMapH
//---------------------------------------------------------------------------
namespace DoxEngine
{
  // By default Compare is less<const FileFormat>
  // By default Alloc is alloc
  class FormatToExtensionMap :
    public std::map<const FileFormat, std::string>
  {
    public:
      FormatToExtensionMap();
  };
}
#endif
