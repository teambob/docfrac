//---------------------------------------------------------------------------

#ifndef HtmlCommandH
#define HtmlCommandH

#include <string>
#include <map>
#include "shared_ptr.h"
#include "HtmlTag.h"


namespace DoxEngine
{
  class HtmlReader;
  
  class HtmlBaseHandler
  {
  public:
		virtual ~HtmlBaseHandler() { }
		virtual void handleCommand(HtmlReader& parent,
			HtmlTag &tag) = 0;
	};

  typedef shared_ptr<HtmlBaseHandler> HtmlCommandElement;

  typedef std::map<std::string, DoxEngine::HtmlCommandElement> HtmlCommandMap;
	class HtmlCommands : public HtmlCommandMap
  {
    public:
      HtmlCommands();
  };

}
//---------------------------------------------------------------------------
#endif
