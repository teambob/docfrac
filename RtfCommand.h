#include <string>
#include <map>

namespace DoxEngine
{
  class RtfReader;

  class RtfBaseHandler
  {
  public:
		virtual ~RtfBaseHandler() { }
		virtual void handleCommand(DoxEngine::RtfReader* parent,
			int commandValue) = 0;
		virtual RtfBaseHandler* Clone() const = 0;
	};


  class RtfCommandElement
  {
  private:
    RtfBaseHandler* handler;

  public:
    RtfCommandElement(const RtfBaseHandler& newHandler);
    RtfCommandElement(const RtfCommandElement& element);
    RtfCommandElement& operator=(const RtfCommandElement& element);
    ~RtfCommandElement();
    void handleCommand(DoxEngine::RtfReader* parent, int commandValue);


  };


	class RtfCommands : public std::map<std::string, DoxEngine::RtfCommandElement>
  {
  };




  class RtfCommandFactory
  {
  public:
    static RtfCommandFactory& instance(void);

    DoxEngine::RtfCommands getCommandList(void);
  };

}

