//---------------------------------------------------------------------------
#ifndef DoxInterfaceH
#define DoxInterfaceH

namespace DoxEngine
{

  class Options;

  class DoxInterface
  {
  public:
    virtual void setOutStream(std::ostream& stream) = 0;
    virtual void setInStream(std::istream& stream) = 0;
    virtual void setOptions(Options& options) = 0;
    virtual void convert(void) = 0;
  };


}
//---------------------------------------------------------------------------
#endif
