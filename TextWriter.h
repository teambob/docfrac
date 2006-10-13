//---------------------------------------------------------------------------
#ifndef TextWriterH
#define TextWriterH


namespace DoxEngine
{

  class TextWriter : public WriterInterface
  {
    private:
      std::ostream* outputStream;
      bool inTable;

    public:
      TextWriter(std::ostream& stream);
      virtual void writeChar(const UnicodeCharacter& character);
      virtual ~TextWriter();
      virtual void writeBreak(BreakType type);
      virtual void setStyle( const Style &newStyle );
      virtual void writeTable(TableType table);
  };
}

//---------------------------------------------------------------------------
#endif
