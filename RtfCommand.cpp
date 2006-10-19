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
      RtfStyle rtfStyle = parent->getRtfStyle();
      rtfStyle.setInTable( commandValue );
      parent->setRtfStyle(rtfStyle);
      if (!commandValue)
       parent->flushTable();
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

  class SbknoneHandler : public RtfBaseHandler
  {
    public:
      virtual void handleCommand(DoxEngine::RtfReader* parent,
      int commandValue)
      {
        if (parent->getRtfStyle().getSectionColumns())
          parent->commandEndRow();
        else
          parent->commandLineBreak();

      }

		virtual RtfBaseHandler* Clone() const
		{
			return new SbknoneHandler(*this);
		}

  };

  class ColsHandler : public RtfBaseHandler
  {
  public:
    virtual void handleCommand(DoxEngine::RtfReader* parent,
      int commandValue)
    {
      RtfStyle rtfStyle = parent->getRtfStyle();
      rtfStyle.setSectionColumns(commandValue);
      parent->setRtfStyle(rtfStyle);

		}

		virtual RtfBaseHandler* Clone() const
		{
			return new ColsHandler(*this);
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



  RtfCommandFactory& RtfCommandFactory::instance(void)
  {
    static RtfCommandFactory singleton;
    return singleton;
  }

	RtfCommands RtfCommandFactory::getCommandList(void)
	{
    RtfCommands newVector;


	newVector.insert(RtfCommands::value_type("par", RtfCommandElement(ParHandler())));
	newVector.insert(RtfCommands::value_type("*", RtfCommandElement(DestinationHandler())));
	newVector.insert(RtfCommands::value_type("fonttbl", RtfCommandElement(DestinationHandler())));
	newVector.insert(RtfCommands::value_type("pict", RtfCommandElement(DestinationHandler())));
	newVector.insert(RtfCommands::value_type("colortbl", RtfCommandElement(ColorTblHandler())));
	newVector.insert(RtfCommands::value_type("stylesheet", RtfCommandElement(DestinationHandler())));
	newVector.insert(RtfCommands::value_type("info", RtfCommandElement(DestinationHandler())));
	newVector.insert(RtfCommands::value_type("xe", RtfCommandElement(DestinationHandler())));
	newVector.insert(RtfCommands::value_type("header", RtfCommandElement(DestinationHandler())));
	newVector.insert(RtfCommands::value_type("footer", RtfCommandElement(DestinationHandler())));
	newVector.insert(RtfCommands::value_type("tc", RtfCommandElement(DestinationHandler())));
	newVector.insert(RtfCommands::value_type("tcn", RtfCommandElement(DestinationHandler())));
	newVector.insert(RtfCommands::value_type("nonshppict", RtfCommandElement(DestinationHandler())));

  // Section handling code
  newVector.insert(RtfCommands::value_type("sbknone", RtfCommandElement(SbknoneHandler())));
  newVector.insert(RtfCommands::value_type("cols", RtfCommandElement(ColsHandler())));
  newVector.insert(RtfCommands::value_type("sbkcol", RtfCommandElement(CellHandler())));


	newVector.insert(RtfCommands::value_type("\\", RtfCommandElement(BackslashHandler())));
	newVector.insert(RtfCommands::value_type("{", RtfCommandElement(OpeningBraceHandler())));
	newVector.insert(RtfCommands::value_type("}", RtfCommandElement(ClosingBraceHandler())));
	newVector.insert(RtfCommands::value_type(";", RtfCommandElement(SemiColonHandler())));
	newVector.insert(RtfCommands::value_type("lquote", RtfCommandElement(LQuoteHandler())));
	newVector.insert(RtfCommands::value_type("rquote", RtfCommandElement(RQuoteHandler())));
	newVector.insert(RtfCommands::value_type("ldblquote", RtfCommandElement(LDblQuoteHandler())));
	newVector.insert(RtfCommands::value_type("rdblquote", RtfCommandElement(RDblQuoteHandler())));
	newVector.insert(RtfCommands::value_type("bullet", RtfCommandElement(BulletHandler())));
	newVector.insert(RtfCommands::value_type("endash", RtfCommandElement(EnDashHandler())));
	newVector.insert(RtfCommands::value_type("emdash", RtfCommandElement(EmDashHandler())));
	newVector.insert(RtfCommands::value_type("b", RtfCommandElement(BoldHandler())));
	newVector.insert(RtfCommands::value_type("i", RtfCommandElement(ItalicHandler())));
	newVector.insert(RtfCommands::value_type("ul", RtfCommandElement(UnderlineHandler())));
	newVector.insert(RtfCommands::value_type("ulnone", RtfCommandElement(NoUnderlineHandler())));
	newVector.insert(RtfCommands::value_type("plain", RtfCommandElement(PlainHandler())));
	newVector.insert(RtfCommands::value_type("ql", RtfCommandElement(LeftJustifyHandler())));
	newVector.insert(RtfCommands::value_type("qr", RtfCommandElement(RightJustifyHandler())));
	newVector.insert(RtfCommands::value_type("qc", RtfCommandElement(CentreJustifyHandler())));
	newVector.insert(RtfCommands::value_type("intbl", RtfCommandElement(IntblHandler())));
	newVector.insert(RtfCommands::value_type("intbl", RtfCommandElement(RowHandler())));
	newVector.insert(RtfCommands::value_type("cell", RtfCommandElement(CellHandler())));
	newVector.insert(RtfCommands::value_type("pard", RtfCommandElement(PardHandler())));
	newVector.insert(RtfCommands::value_type("cf", RtfCommandElement(CfHandler())));

    return newVector;
  }


  RtfCommandElement::RtfCommandElement(	const RtfBaseHandler& newHandler)
  {
    handler = newHandler.Clone();
  }

	RtfCommandElement::RtfCommandElement(const RtfCommandElement& element)
  {
		// Will this call the correct copy constructor?
		handler = element.handler->Clone(); // Houston we have a problem!!!
  }

  RtfCommandElement& RtfCommandElement::operator=(const RtfCommandElement& rhs)
  {
	if (&rhs == this)
	  return *this;

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



}
