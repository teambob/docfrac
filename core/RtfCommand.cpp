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

  };





	class DestinationHandler : public RtfBaseHandler
	{
	public:
		virtual void handleCommand(DoxEngine::RtfReader* parent,
			int commandValue)
		{
			parent->commandIgnoreDestinationKeyword();
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

	};

	class CfHandler : public RtfBaseHandler
	{
	public:
		virtual void handleCommand(DoxEngine::RtfReader* parent, int commandValue)
		{
			RtfStyle style = parent->getRtfStyle();

			style.setForegroundColour(commandValue);

			parent->setRtfStyle(style);

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

	};


	class CentreJustifyHandler : public RtfBaseHandler
	{
	public:
		virtual void handleCommand(DoxEngine::RtfReader* parent,
			int commandValue)
		{
			Style style = parent->getStyle();
			if (commandValue)
			{
				style.setJustification(CentreJustified);
			}
			else
				style.setJustification(DefaultJustified);

			parent->setStyle(style);
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
		}

  };

  class RowHandler : public RtfBaseHandler
  {
  public:
    virtual void handleCommand(DoxEngine::RtfReader* parent,
      int commandValue)
    {
      parent->commandEndRow();
		}

  };


  class CellHandler : public RtfBaseHandler
  {
  public:
    virtual void handleCommand(DoxEngine::RtfReader* parent,
      int commandValue)
    {
      parent->commandEndCell();
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

  };


  class PardHandler : public RtfBaseHandler
  {
  public:
    virtual void handleCommand(DoxEngine::RtfReader* parent,
      int commandValue)
    {
      parent->commandParagraphDefault();
		}

  };




	RtfCommands::RtfCommands():RtfCommandMap()
	{

	insert(RtfCommands::value_type("par", RtfCommandElement(new ParHandler())));
	insert(RtfCommands::value_type("*", RtfCommandElement(new DestinationHandler())));
	insert(RtfCommands::value_type("fonttbl", RtfCommandElement(new DestinationHandler())));
	insert(RtfCommands::value_type("pict", RtfCommandElement(new DestinationHandler())));
	insert(RtfCommands::value_type("colortbl", RtfCommandElement(new ColorTblHandler())));
	insert(RtfCommands::value_type("stylesheet", RtfCommandElement(new DestinationHandler())));
	insert(RtfCommands::value_type("info", RtfCommandElement(new DestinationHandler())));
	insert(RtfCommands::value_type("xe", RtfCommandElement(new DestinationHandler())));
	insert(RtfCommands::value_type("header", RtfCommandElement(new DestinationHandler())));
	insert(RtfCommands::value_type("footer", RtfCommandElement(new DestinationHandler())));
	insert(RtfCommands::value_type("tc", RtfCommandElement(new DestinationHandler())));
	insert(RtfCommands::value_type("tcn", RtfCommandElement(new DestinationHandler())));
	insert(RtfCommands::value_type("nonshppict", RtfCommandElement(new DestinationHandler())));

  // Section handling code
  insert(RtfCommands::value_type("sbknone", RtfCommandElement(new SbknoneHandler())));
  insert(RtfCommands::value_type("cols", RtfCommandElement(new ColsHandler())));
  insert(RtfCommands::value_type("sbkcol", RtfCommandElement(new CellHandler())));


	insert(RtfCommands::value_type("\\", RtfCommandElement(new BackslashHandler())));
	insert(RtfCommands::value_type("{", RtfCommandElement(new OpeningBraceHandler())));
	insert(RtfCommands::value_type("}", RtfCommandElement(new ClosingBraceHandler())));
	insert(RtfCommands::value_type(";", RtfCommandElement(new SemiColonHandler())));
	insert(RtfCommands::value_type("lquote", RtfCommandElement(new LQuoteHandler())));
	insert(RtfCommands::value_type("rquote", RtfCommandElement(new RQuoteHandler())));
	insert(RtfCommands::value_type("ldblquote", RtfCommandElement(new LDblQuoteHandler())));
	insert(RtfCommands::value_type("rdblquote", RtfCommandElement(new RDblQuoteHandler())));
	insert(RtfCommands::value_type("bullet", RtfCommandElement(new BulletHandler())));
	insert(RtfCommands::value_type("endash", RtfCommandElement(new EnDashHandler())));
	insert(RtfCommands::value_type("emdash", RtfCommandElement(new EmDashHandler())));
	insert(RtfCommands::value_type("b", RtfCommandElement(new BoldHandler())));
	insert(RtfCommands::value_type("i", RtfCommandElement(new ItalicHandler())));
	insert(RtfCommands::value_type("ul", RtfCommandElement(new UnderlineHandler())));
	insert(RtfCommands::value_type("ulnone", RtfCommandElement(new NoUnderlineHandler())));
	insert(RtfCommands::value_type("plain", RtfCommandElement(new PlainHandler())));
	insert(RtfCommands::value_type("ql", RtfCommandElement(new LeftJustifyHandler())));
	insert(RtfCommands::value_type("qr", RtfCommandElement(new RightJustifyHandler())));
	insert(RtfCommands::value_type("qc", RtfCommandElement(new CentreJustifyHandler())));
	insert(RtfCommands::value_type("intbl", RtfCommandElement(new IntblHandler())));
	insert(RtfCommands::value_type("row", RtfCommandElement(new RowHandler())));
	insert(RtfCommands::value_type("cell", RtfCommandElement(new CellHandler())));
	insert(RtfCommands::value_type("pard", RtfCommandElement(new PardHandler())));
	insert(RtfCommands::value_type("cf", RtfCommandElement(new CfHandler())));

  }





}
