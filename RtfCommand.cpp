#include <string>
#include <iostream>
#include <vector>

#include "RtfCommand.h"

#include "UnicodeCharacter.h"

#include "ReaderInterface.h"
#include "RtfReader.h"

#include "Style.h"
#include "RtfStyle.h"


namespace DoxEngine
{




  class ParHandler : public RtfBaseHandler
  {
    public:
      virtual ~ParHandler()
      {
      }
      
      virtual void handleCommand(DoxEngine::RtfReader* parent,
        int commandValue)
      {
        parent->commandLineBreak();
		}

	  virtual RtfBaseHandler* Clone() const
	  {
			return new ParHandler(*this);
		}
  };





	class DestinationHandler : public RtfBaseHandler
	{
	public:
		virtual void handleCommand(DoxEngine::RtfReader* parent,
			int commandValue)
		{
			parent->commandIgnoreDestinationKeyword();
		}

		virtual RtfBaseHandler* Clone() const
		{
			return new DestinationHandler(*this);
		}

	};

	class ColorTblHandler : public RtfBaseHandler
	{
	public:
		virtual void handleCommand(DoxEngine::RtfReader* parent,
			int commandValue)
		{
			parent->commandColourTable();
		}

		virtual RtfBaseHandler* Clone() const
		{
			return new ColorTblHandler(*this);
		}

	};

	class CfHandler : public RtfBaseHandler
	{
	public:
		virtual void handleCommand(DoxEngine::RtfReader* parent, int commandValue)
		{
			//cout << "Handling \\cf\n";
			RtfStyle style = parent->getRtfStyle();

			style.setForegroundColour(commandValue);

			parent->setRtfStyle(style);

		}

		virtual RtfBaseHandler* Clone() const
		{
			return new CfHandler(*this);
		}

	};



	class BackslashHandler : public RtfBaseHandler
	{
	public:
		virtual void handleCommand(DoxEngine::RtfReader* parent,
			int commandValue)
		{
			UnicodeCharacter character('\\');
			parent->commandCharacter(character);
		}

		virtual RtfBaseHandler* Clone() const
		{
			return new BackslashHandler(*this);
		}

	};


	class OpeningBraceHandler : public RtfBaseHandler
	{
	public:
		virtual void handleCommand(DoxEngine::RtfReader* parent,
			int commandValue)
		{
			UnicodeCharacter character('{');
			parent->commandCharacter(character);
		}

		virtual RtfBaseHandler* Clone() const
		{
			return new OpeningBraceHandler(*this);
		}


	};


	class ClosingBraceHandler : public RtfBaseHandler
	{
	public:
		virtual void handleCommand(DoxEngine::RtfReader* parent,
			int commandValue)
		{
			UnicodeCharacter character('}');
			parent->commandCharacter(character);
		}

		virtual RtfBaseHandler* Clone() const
		{
			return new ClosingBraceHandler(*this);
		}


	};


	class SemiColonHandler : public RtfBaseHandler
	{
	public:
		virtual void handleCommand(DoxEngine::RtfReader* parent,
			int commandValue)
		{
			UnicodeCharacter character(';');
			parent->commandCharacter(character);
		}

		virtual RtfBaseHandler* Clone() const
		{
			return new SemiColonHandler(*this);
		}


	};

	class LQuoteHandler : public RtfBaseHandler
	{
	public:
		virtual void handleCommand(DoxEngine::RtfReader* parent,
			int commandValue)
		{
			UnicodeCharacter character((unsigned long)0x91);
			parent->commandCharacter(character);
		}

		virtual RtfBaseHandler* Clone() const
		{
			return new LQuoteHandler(*this);
		}


	};


	class RQuoteHandler : public RtfBaseHandler
	{
	public:
		virtual void handleCommand(DoxEngine::RtfReader* parent,
			int commandValue)
		{
			UnicodeCharacter character((unsigned long)0x92);
			parent->commandCharacter(character);
		}

		virtual RtfBaseHandler* Clone() const
		{
			return new RQuoteHandler(*this);
		}
	};


  class LDblQuoteHandler : public RtfBaseHandler
  {
  public:
    virtual void handleCommand(DoxEngine::RtfReader* parent,
      int commandValue)
    {
      UnicodeCharacter character((unsigned long)0x93);
      parent->commandCharacter(character);
		}

		virtual RtfBaseHandler* Clone() const
		{
			return new LDblQuoteHandler(*this);
		}

  };

  class RDblQuoteHandler : public RtfBaseHandler
  {
  public:
    virtual void handleCommand(DoxEngine::RtfReader* parent,
      int commandValue)
    {
      UnicodeCharacter character((unsigned long)0x94);
      parent->commandCharacter(character);
		}

		virtual RtfBaseHandler* Clone() const
		{
			return new RDblQuoteHandler(*this);
		}


  };



  class BulletHandler : public RtfBaseHandler
  {
  public:
    virtual void handleCommand(DoxEngine::RtfReader* parent,
      int commandValue)
    {
      UnicodeCharacter character((unsigned long)0x95);
      parent->commandCharacter(character);
		}

		virtual RtfBaseHandler* Clone() const
		{
			return new BulletHandler(*this);
		}

  };

  class EnDashHandler : public RtfBaseHandler
  {
  public:
    virtual void handleCommand(DoxEngine::RtfReader* parent,
      int commandValue)
    {
      UnicodeCharacter character((unsigned long)0x96);
      parent->commandCharacter(character);
		}

		virtual RtfBaseHandler* Clone() const
		{
			return new EnDashHandler(*this);
		}

  };




  class EmDashHandler : public RtfBaseHandler
  {
  public:
    virtual void handleCommand(DoxEngine::RtfReader* parent,
      int commandValue)
    {
      UnicodeCharacter character((unsigned long)0x97);
      parent->commandCharacter(character);
		}

		virtual RtfBaseHandler* Clone() const
		{
			return new EmDashHandler(*this);
		}

  };




  class BoldHandler : public RtfBaseHandler
	{
  public:
    virtual void handleCommand(DoxEngine::RtfReader* parent,
      int commandValue)
    {
			Style style = parent->getStyle();
      if (commandValue)
        style.setBold(true);
      else
        style.setBold(false);

      parent->setStyle(style);
		}

		virtual RtfBaseHandler* Clone() const
		{
			return new BoldHandler(*this);
		}

	};

	class ItalicHandler : public RtfBaseHandler
	{
	public:
		virtual void handleCommand(DoxEngine::RtfReader* parent,
			int commandValue)
		{
			Style style = parent->getStyle();
			if (commandValue)
				style.setItalic(true);
			else
				style.setItalic(false);

			parent->setStyle(style);
		}

		virtual RtfBaseHandler* Clone() const
		{
			return new ItalicHandler(*this);
		}
	};


	class UnderlineHandler : public RtfBaseHandler
	{
	public:
		virtual void handleCommand(DoxEngine::RtfReader* parent,
			int commandValue)
		{
			Style style = parent->getStyle();
			if (commandValue)
				style.setUnderline(true);
			else
				style.setUnderline(false);

			parent->setStyle(style);
		}

		virtual RtfBaseHandler* Clone() const
		{
			return new UnderlineHandler(*this);
		}

	};


	class NoUnderlineHandler : public RtfBaseHandler
	{
	public:
		virtual void handleCommand(DoxEngine::RtfReader* parent,
			int commandValue)
		{
			Style style = parent->getStyle();
			style.setUnderline(false);

			parent->setStyle(style);
		}

		virtual RtfBaseHandler* Clone() const
		{
			return new NoUnderlineHandler(*this);
		}

  };


  class LeftJustifyHandler : public RtfBaseHandler
  {
  public:
    virtual void handleCommand(DoxEngine::RtfReader* parent,
      int commandValue)
    {
      Style style = parent->getStyle();
      if (commandValue)
        style.setJustification(LeftJustified);
      else
        style.setJustification(DefaultJustified);

      parent->setStyle(style);
		}

		virtual RtfBaseHandler* Clone() const
		{
			return new LeftJustifyHandler(*this);
		}

	};


	class CentreJustifyHandler : public RtfBaseHandler
	{
	public:
		virtual void handleCommand(DoxEngine::RtfReader* parent,
			int commandValue)
		{
			//cout << "Centre\n";
			Style style = parent->getStyle();
			if (commandValue)
			{
				style.setJustification(CentreJustified);
				//cout << "Centre set\n";
			}
			else
				style.setJustification(DefaultJustified);

			parent->setStyle(style);
		}

		virtual RtfBaseHandler* Clone() const
		{
			return new CentreJustifyHandler(*this);
		}

	};

	class RightJustifyHandler : public RtfBaseHandler
  {
  public:
    virtual void handleCommand(DoxEngine::RtfReader* parent,
      int commandValue)
    {
      Style style = parent->getStyle();
      if (commandValue)
        style.setJustification(RightJustified);
      else
        style.setJustification(DefaultJustified);

      parent->setStyle(style);
		}

		virtual RtfBaseHandler* Clone() const
		{
			return new RightJustifyHandler(*this);
		}


  };



	class PlainHandler : public RtfBaseHandler
  {
  public:
    virtual void handleCommand(DoxEngine::RtfReader* parent,
      int commandValue)
    {
      RtfStyle style = parent->getRtfStyle();

			style.setPlain();

      parent->setRtfStyle(style);
		}

		virtual RtfBaseHandler* Clone() const
		{
			return new PlainHandler(*this);
		}


  };


  class IntblHandler : public RtfBaseHandler
  {
  public:
    virtual void handleCommand(DoxEngine::RtfReader* parent,
      int commandValue)
    {
      parent->commandInTable();
		}

		virtual RtfBaseHandler* Clone() const
		{
			return new IntblHandler(*this);
		}


  };

  class RowHandler : public RtfBaseHandler
  {
  public:
    virtual void handleCommand(DoxEngine::RtfReader* parent,
      int commandValue)
    {
      //cout << "Table row\n";
      parent->commandEndRow();
		}

		virtual RtfBaseHandler* Clone() const
		{
			return new RowHandler(*this);
		}


  };


  class CellHandler : public RtfBaseHandler
  {
  public:
    virtual void handleCommand(DoxEngine::RtfReader* parent,
      int commandValue)
    {
      //cout << "Table cell\n";
      parent->commandEndCell();
		}

		virtual RtfBaseHandler* Clone() const
		{
			return new CellHandler(*this);
		}

  };



  class PardHandler : public RtfBaseHandler
  {
  public:
    virtual void handleCommand(DoxEngine::RtfReader* parent,
      int commandValue)
    {
      parent->commandParagraphDefault();
		}

		virtual RtfBaseHandler* Clone() const
		{
			return new PardHandler(*this);
		}


  };



  VectorFactory& VectorFactory::instance(void)
  {
    static VectorFactory singleton;
    return singleton;
  }

	RtfCommandVector VectorFactory::getCommandList(void)
	{
    RtfCommandVector newVector;


	newVector.push_back(RtfCommandElement("par", ParHandler()));
	newVector.push_back(RtfCommandElement("*", DestinationHandler()));
	newVector.push_back(RtfCommandElement("fonttbl", DestinationHandler()));
	newVector.push_back(RtfCommandElement("pict", DestinationHandler()));
	newVector.push_back(RtfCommandElement("colortbl", ColorTblHandler()));
	newVector.push_back(RtfCommandElement("stylesheet", DestinationHandler()));
	newVector.push_back(RtfCommandElement("info", DestinationHandler()));
	newVector.push_back(RtfCommandElement("xe", DestinationHandler()));
	newVector.push_back(RtfCommandElement("header", DestinationHandler()));
	newVector.push_back(RtfCommandElement("footer", DestinationHandler()));
	newVector.push_back(RtfCommandElement("tc", DestinationHandler()));
	newVector.push_back(RtfCommandElement("tcn", DestinationHandler()));
	newVector.push_back(RtfCommandElement("nonshppict", DestinationHandler()));


	//handler = new ColorTblHandler;
	//element = new RtfCommandElement("colortbl", handler);
	//newVector.push_back(*element);
	//delete element;











	newVector.push_back(RtfCommandElement("\\", BackslashHandler()));
	newVector.push_back(RtfCommandElement("{", OpeningBraceHandler()));
	newVector.push_back(RtfCommandElement("}", ClosingBraceHandler()));
	newVector.push_back(RtfCommandElement(";", SemiColonHandler()));
	newVector.push_back(RtfCommandElement("lquote", LQuoteHandler()));
	newVector.push_back(RtfCommandElement("rquote", RQuoteHandler()));
	newVector.push_back(RtfCommandElement("ldblquote", LDblQuoteHandler()));
	newVector.push_back(RtfCommandElement("rdblquote", RDblQuoteHandler()));
	newVector.push_back(RtfCommandElement("bullet", BulletHandler()));
	newVector.push_back(RtfCommandElement("endash", EnDashHandler()));
	newVector.push_back(RtfCommandElement("emdash", EmDashHandler()));
	newVector.push_back(RtfCommandElement("b", BoldHandler()));
	newVector.push_back(RtfCommandElement("i", ItalicHandler()));
	newVector.push_back(RtfCommandElement("ul", UnderlineHandler()));
	newVector.push_back(RtfCommandElement("ulnone", NoUnderlineHandler()));
	newVector.push_back(RtfCommandElement("plain", PlainHandler()));
	newVector.push_back(RtfCommandElement("ql", LeftJustifyHandler()));
	newVector.push_back(RtfCommandElement("qr", RightJustifyHandler()));
	newVector.push_back(RtfCommandElement("qc", CentreJustifyHandler()));
	newVector.push_back(RtfCommandElement("intbl", IntblHandler()));
	newVector.push_back(RtfCommandElement("row", RowHandler()));
	newVector.push_back(RtfCommandElement("cell", CellHandler()));
	newVector.push_back(RtfCommandElement("pard", PardHandler()));
	newVector.push_back(RtfCommandElement("cf", CfHandler()));

    return newVector;
  }


  RtfCommandElement::RtfCommandElement(
	const std::string &newCommand,
	const RtfBaseHandler& newHandler)
  {
	  command = newCommand;
    handler = newHandler.Clone();
  }

  RtfCommandElement::RtfCommandElement(const RtfCommandElement& element)
  {
		command = element.command;
		// Will this call the correct copy constructor?
		handler = element.handler->Clone(); // Houston we have a problem!!!
  }

  RtfCommandElement& RtfCommandElement::operator=(const RtfCommandElement& rhs)
  {
	if (&rhs == this)
	  return *this;

	command = rhs.command;
	handler = rhs.handler->Clone();

	return *this;
  }


  RtfCommandElement::~RtfCommandElement()
  {
    delete handler;
  }

  void RtfCommandElement::handleCommand(DoxEngine::RtfReader* parent,
    int commandValue)
  {
    handler->handleCommand(parent, commandValue);
  }

  bool RtfCommandElement::operator<(const DoxEngine::RtfCommandElement& rhs)
  {
	return command<rhs.command;
  }

  bool RtfCommandElement::operator<(const std::string& rhs)
  {
	  return command<rhs;
	}

	bool RtfCommandElement::operator==(const DoxEngine::RtfCommandElement& rhs)
	{
		return command==rhs.command;
  }



  bool RtfCommandElement::operator==(const std::string& rhs)
  {
	  return command==rhs;
  }


  bool RtfCommandElement::operator!=(const std::string rhs)
  {
	  return command!=rhs;
  }

}
