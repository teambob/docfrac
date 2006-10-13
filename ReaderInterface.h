//---------------------------------------------------------------------------
#ifndef ReaderInterfaceH
#define ReaderInterfaceH

namespace DoxEngine
{
  class ReadInterface
  {
    public:
      virtual bool processData(void) = 0;
      virtual int getPercentComplete(void) = 0;

      virtual ~ReadInterface();
  };

}

//---------------------------------------------------------------------------
#endif
