//---------------------------------------------------------------------------
#ifndef WriterInterfaceH
#define WriterInterfaceH


namespace DoxEngine
{
  class UnicodeCharacter;
  class Style;

  typedef enum
  {
    LineBreak,
    ParagraphBreak,
    PageBreak
  } BreakType;

  typedef enum
  {
    TableStart,
    TableCellStart,
    TableCellEnd,
    TableRowStart,
    TableRowEnd,
    TableEnd
  } TableType;

  class WriterInterface
  {
  public:
    //virtual void setOutStream(ostream& stream) = 0;
    virtual void writeChar(const UnicodeCharacter& character) = 0;
    virtual void writeBreak(BreakType type) = 0;
    virtual void writeTable(TableType table) = 0;
    virtual void setStyle( const Style &newStyle ) = 0;
    virtual ~WriterInterface();
    //virtual void writePicture() = 0;
  };

}


//---------------------------------------------------------------------------
#endif
