//---------------------------------------------------------------------------

#ifndef HtmlTagH
#define HtmlTagH
//---------------------------------------------------------------------------
#include <map>
#include <string>


namespace DoxEngine
{
  typedef std::map<std::string, std::string> HtmlTagParameters;

  class HtmlTag
  {
    private:
      std::string element;
      HtmlTagParameters parameters;
      bool beginning;
      bool end;
      bool comment;

      void ReadComment( std::istream &in );

    public:
      HtmlTag( std::istream &in );
      HtmlTag( std::ostream &out );

      std::string GetParameter( std::string &name );
      void SetParameter( std::string &name, std::string &value );

      std::string GetElement();
      void SetElement( std::string &value );

      bool IsBeginning();
      bool IsEnd();
      bool IsComment();

      void SetBeginning( bool value );
      void SetEnd( bool value );

      void ReadTag( std::istream &in );
      void WriteTag( std::ostream &out );
  };
}

#endif
