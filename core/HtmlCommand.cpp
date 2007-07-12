//---------------------------------------------------------------------------


#pragma hdrstop

#include "HtmlCommand.h"
#include "WriterInterface.h"
#include "HtmlReader.h"

//---------------------------------------------------------------------------
#undef ENABLE_LOG_DEBUG
#pragma package(smart_init)

/* Notes for future refactoring:
  * Change HtmlBaseHandler so that the interface has three methods for
    handling commands: handleBeginningCommand(), handleEndCommand() and
    handleStandaloneCommand()
  * Should keep a stack of open tags, then pop automatically when required for example:
    - <p><font size="+3">this text is bigger</p>this text is normal
    - <p><font size="+3">this text is bigger<p>this text is normal
  * Change HtmlTag so it has three functions: IsBeginning(), IsEnd()
    and IsStandalone(). IsBeginning() and IsEnd() must be false when
    IsStandalone() is true
  * Need to separate styles into paragraph styles and character styles
    throughout
*/


namespace DoxEngine
{

class BrHandler:public HtmlBaseHandler
{
  virtual void handleCommand(DoxEngine::HtmlReader& parent,
			HtmlTag &tag)
  {
    WriterInterface &writer = parent.GetWriterReference();

      writer.writeBreak(LineBreak);

#ifdef ENABLE_LOG_DEBUG
      log[LOG_DEBUG] << DEBUG_ID << "Line break" << endl;
#endif


  }

};


class PHandler:public HtmlBaseHandler
{
  virtual void handleCommand(DoxEngine::HtmlReader& parent,
			HtmlTag &tag)
  {
    WriterInterface &writer = parent.GetWriterReference();

      if (tag.IsBeginning())
        writer.writeBreak(ParagraphBreak);
        
#ifdef ENABLE_LOG_DEBUG
      log[LOG_DEBUG] << DEBUG_ID << "Paragraph break" << endl;
#endif


  }

};


class ScriptHandler:public HtmlBaseHandler
{
  virtual void handleCommand(DoxEngine::HtmlReader& parent,
			HtmlTag &tag)
  {
    parent.SetScript(!tag.IsEnd());
  }

};


class IframeHandler:public HtmlBaseHandler
{
  virtual void handleCommand(DoxEngine::HtmlReader& parent,
			HtmlTag &tag)
  {
    parent.SetIframe(!tag.IsEnd());
  }

};



// Bold
class BHandler:public HtmlBaseHandler
{
  virtual void handleCommand(DoxEngine::HtmlReader& parent,
			HtmlTag &tag)
  {
    Style style = parent.GetStyle();

    style.setBold(!tag.IsEnd());

    parent.SetStyle(style);
  }

};

// Italic
class IHandler:public HtmlBaseHandler
{
  virtual void handleCommand(DoxEngine::HtmlReader& parent,
			HtmlTag &tag)
  {
    Style style = parent.GetStyle();

    style.setItalic(!tag.IsEnd());

    parent.SetStyle(style);
  }

};


// Underline

class UHandler:public HtmlBaseHandler
{
  virtual void handleCommand(DoxEngine::HtmlReader& parent,
			HtmlTag &tag)
  {
    Style style = parent.GetStyle();

    style.setUnderline(!tag.IsEnd());

    parent.SetStyle(style);
  }

};

// div
class DivHandler:public HtmlBaseHandler
{
  virtual void handleCommand(DoxEngine::HtmlReader& parent,
			HtmlTag &tag)
  {
    Style style = parent.GetStyle();

    if (!tag.IsEnd())
    {
      std::string align = tag.GetParameter("align");

      if (align == "center")
        style.setJustification(CentreJustified);
      else if (align == "right")
        style.setJustification(RightJustified);
      else if (align == "justify")
        style.setJustification(Justified);
      else if (align == "left")
        style.setJustification(LeftJustified);
    }
    else if (!tag.IsBeginning())
    {
      style.setJustification(DefaultJustified);
    }





    parent.SetStyle(style);
  }

};


// center
class CenterHandler:public HtmlBaseHandler
{
  virtual void handleCommand(DoxEngine::HtmlReader& parent,
			HtmlTag &tag)
  {
    Style style = parent.GetStyle();

    if (!tag.IsEnd())
    {
      style.setJustification(CentreJustified);
    }
    else if (!tag.IsBeginning())
    {
      style.setJustification(DefaultJustified);
    }





    parent.SetStyle(style);
  }

};

// ol, ul, li

class LiHandler:public HtmlBaseHandler
{
  virtual void handleCommand(DoxEngine::HtmlReader& parent,
			HtmlTag &tag)
  {
    if (!tag.IsEnd())
    {
      WriterInterface &writer = parent.GetWriterReference();
      writer.writeChar(UnicodeCharacter('*'));
    }
    else if (!tag.IsBeginning())
    {
      WriterInterface &writer = parent.GetWriterReference();

      writer.writeBreak(LineBreak);

    }

  }

};


// font

// table, tr, th, td
class TableHandler:public HtmlBaseHandler
{
  virtual void handleCommand(DoxEngine::HtmlReader& parent,
			HtmlTag &tag)
  {
    if (!tag.IsEnd())
    {
      WriterInterface &writer = parent.GetWriterReference();
      writer.writeTable(TableStart);
    }
    else if (!tag.IsBeginning())
    {
      WriterInterface &writer = parent.GetWriterReference();

      writer.writeTable(TableEnd);

    }

  }

};



class TrHandler:public HtmlBaseHandler
{
  virtual void handleCommand(DoxEngine::HtmlReader& parent,
			HtmlTag &tag)
  {
    if (!tag.IsEnd())
    {
      WriterInterface &writer = parent.GetWriterReference();
      writer.writeTable(TableRowStart);
    }
    else if (!tag.IsBeginning())
    {
      WriterInterface &writer = parent.GetWriterReference();

      writer.writeTable(TableRowEnd);

    }

  }

};

// Th and Td handler
class TdHandler:public HtmlBaseHandler
{
  virtual void handleCommand(DoxEngine::HtmlReader& parent,
			HtmlTag &tag)
  {
    if (!tag.IsEnd())
    {
      WriterInterface &writer = parent.GetWriterReference();
      writer.writeTable(TableCellStart);

    }
    else if (!tag.IsBeginning())
    {
      WriterInterface &writer = parent.GetWriterReference();

      writer.writeTable(TableCellEnd);

    }

  }

};





HtmlCommands::HtmlCommands():HtmlCommandMap()
{
  insert(HtmlCommands::value_type("br", HtmlCommandElement(new BrHandler())));
  insert(HtmlCommands::value_type("p", HtmlCommandElement(new PHandler())));
  insert(HtmlCommands::value_type("script", HtmlCommandElement(new ScriptHandler())));
  insert(HtmlCommands::value_type("iframe", HtmlCommandElement(new IframeHandler())));

  insert(HtmlCommands::value_type("b", HtmlCommandElement(new BHandler())));
  insert(HtmlCommands::value_type("i", HtmlCommandElement(new IHandler())));
  insert(HtmlCommands::value_type("u", HtmlCommandElement(new UHandler())));

  // the following items need more work: especially where tags are not closed correctly
  insert(HtmlCommands::value_type("div", HtmlCommandElement(new DivHandler())));
  insert(HtmlCommands::value_type("center", HtmlCommandElement(new CenterHandler())));
  insert(HtmlCommands::value_type("li", HtmlCommandElement(new LiHandler())));
  insert(HtmlCommands::value_type("table", HtmlCommandElement(new TableHandler())));
  insert(HtmlCommands::value_type("tr", HtmlCommandElement(new TrHandler())));
  insert(HtmlCommands::value_type("td", HtmlCommandElement(new TdHandler())));
  insert(HtmlCommands::value_type("th", HtmlCommandElement(new TdHandler())));


}

}

