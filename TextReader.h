#ifndef TextReaderH
#define TextReaderH

namespace DoxEngine
{
  class WriterInterface;

  class TextReader : public ReadInterface
  {
    private:
	    std::istream &stream;
	    WriterInterface &writer;


    public:
      TextReader(std::istream& newStream, WriterInterface& newWriter);

      virtual bool processData(void);
      virtual int getPercentComplete(void);

      virtual ~TextReader();
  };

}

//---------------------------------------------------------------------------
#endif


