#include <string>

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
 	  std::string command;
    RtfBaseHandler* handler;

  public:
    RtfCommandElement(const std::string &newCommand, const RtfBaseHandler& newHandler);
    RtfCommandElement(const RtfCommandElement& element);
    RtfCommandElement& operator=(const RtfCommandElement& element);
    ~RtfCommandElement();
    void handleCommand(DoxEngine::RtfReader* parent, int commandValue);


    bool operator<(const DoxEngine::RtfCommandElement& rhs);
    bool operator<(const std::string& rhs);
    bool operator==(const DoxEngine::RtfCommandElement& rhs);
    bool operator==(const std::string& rhs);
    bool operator!=(const std::string rhs);
  };


	class RtfCommandVector : public std::vector<DoxEngine::RtfCommandElement>
  {
  };




  class VectorFactory
  {
  public:
    static VectorFactory& instance(void);

    DoxEngine::RtfCommandVector getCommandList(void);
  };

}

