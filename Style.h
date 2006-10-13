#ifndef __STYLE_H__
#define __STYLE_H__


namespace DoxEngine
{

  enum  Justification
  {
    DefaultJustified,
    LeftJustified,
    CentreJustified,
    RightJustified,
    Justified
  };

  class Style
  {
  private:
    DoxEngine::Justification justification;
    //int justification;
    bool bold;
    bool italic;
    bool underline;

    bool defaultColour;
    int red, green, blue;


  public:
	Style();
	virtual ~Style();

    Style& operator=(const Style &rhs);

    void setDefault( void );

    void setBold( bool value );
    void setItalic( bool value );
    void setUnderline( bool value );
    void setJustification( DoxEngine::Justification value );
    void setColour( void );
    void setColour( int redValue, int greenValue, int blueValue );

    bool getBold( void );
    bool getItalic( void );
    bool getUnderline( void );
    Justification getJustification( void );
    bool getDefaultColour( void );
    int getColourRed( void );
    int getColourBlue( void );
    int getColourGreen( void );

  };
}

#endif

