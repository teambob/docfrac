//---------------------------------------------------------------------------
#ifndef DoxFactoryH
#define DoxFactoryH
//---------------------------------------------------------------------------


namespace DoxEngine
{

class WriterInterface;
class ReadInterface;


class DoxFactory
{

  public:
    static DoxFactory* instance(void);

    WriterInterface* createRtfWriter(std::ostream& stream);
    WriterInterface* createHtmlWriter(std::ostream& stream);
    WriterInterface* createTextWriter(std::ostream& stream);


    ReadInterface* createRtfReader(std::istream& stream,
      WriterInterface& writer);

    ReadInterface* createHtmlReader(std::istream& stream,
      WriterInterface& writer);

    ReadInterface* createTextReader(std::istream& stream,
      WriterInterface& writer);
};
}

#endif
