#ifndef __RTF_COMMAND_H__
#define __RTF_COMMAND_H__

#include <string>
#include <map>
#include "shared_ptr.h"

namespace DoxEngine
{
  class RtfReader;

  class RtfBaseHandler
  {
  public:
		virtual ~RtfBaseHandler() { }
		virtual void handleCommand(DoxEngine::RtfReader* parent,
			int commandValue) = 0;
	};


  typedef shared_ptr<RtfBaseHandler> RtfCommandElement;

  typedef std::map<std::string, DoxEngine::RtfCommandElement> RtfCommandMap;
	class RtfCommands : public RtfCommandMap
  {
    public:
      RtfCommands();
  };

}

#endif
