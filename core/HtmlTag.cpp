//---------------------------------------------------------------------------



#include <istream>
#include "HtmlTag.h"

//---------------------------------------------------------------------------



namespace DoxEngine
{

  HtmlTag::HtmlTag( std::istream &in )
  {
    ReadTag( in );
  }

  HtmlTag::HtmlTag( std::ostream &out )
  {
    WriteTag( out );
  }

  std::string HtmlTag::GetParameter( const std::string &name )
  {
    HtmlTagParameters::iterator i = parameters.find( name );
    return i->second;
  }

  void HtmlTag::SetParameter( const std::string &name, const std::string &value )
  {
    parameters.insert( HtmlTagParameters::value_type(name, value) );
  }

  std::string HtmlTag::GetElement()
  {
    return element;
  }

  void HtmlTag::SetElement( const std::string &value )
  {
    element = value;
  }

  bool HtmlTag::IsBeginning()
  {
    return beginning;
  }

  bool HtmlTag::IsEnd()
  {
    return end;
  }

  void HtmlTag::SetBeginning( bool value )
  {
    beginning = value;
  }

  void HtmlTag::SetEnd( bool value )
  {
    end = value;
  }

  void HtmlTag::ReadTag( std::istream &in )
  {
    std::string line;
    char character;

    in.get(character);
    while(in.good() && character != '>' )
    {
      line.append(1, character);
      if (line=="!--")  // '<' has been thrown away, comment
      {
        ReadComment( in );
        return;
      }

      in.get(character);
    }


    // Tag: <[/]element [parameter] ... [/]>

    // First '/' indicates end tag, final '/' indicates self-contained tag


    // Process element and start/end indication

    if (line.at(0) == '/')

    {

      element = line.substr(1, line.find_first_of(" \n"));
      beginning = false;
      end = true;
    }

    else

    {

      element = line.substr(0, line.find_first_of(" \n"));
      if (line.at( line.size() - 1 ) == '/')
      {
        beginning = true;
        end = true;
      }
      else
      {
        beginning = true;
        end = false;
      }
    }

    //  Process parameters



  }

  void HtmlTag::WriteTag( std::ostream &out )
  {

  }


  void HtmlTag::ReadComment( std::istream &in )
  {
    using namespace std;
    string line, commentEnd="-->";

    for (unsigned i=0; in.good()&&(i<commentEnd.length()); i++)
      line.append(1, (char)in.get());

    while(in.good()&&(line!=commentEnd))
    {
      line = line.substr(1, line.npos);
      line.append(1, (char)in.get());
    }
  }


}
