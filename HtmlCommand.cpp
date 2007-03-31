//---------------------------------------------------------------------------


#pragma hdrstop

#include "HtmlCommand.h"
#include "WriterInterface.h"
#include "HtmlReader.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)
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

// center

HtmlCommands::HtmlCommands():HtmlCommandMap()
{
  insert(HtmlCommands::value_type("br", HtmlCommandElement(new BrHandler())));
  insert(HtmlCommands::value_type("p", HtmlCommandElement(new PHandler())));
  insert(HtmlCommands::value_type("script", HtmlCommandElement(new ScriptHandler())));
  insert(HtmlCommands::value_type("iframe", HtmlCommandElement(new IframeHandler())));

  insert(HtmlCommands::value_type("b", HtmlCommandElement(new BHandler())));
  insert(HtmlCommands::value_type("i", HtmlCommandElement(new IHandler())));
  insert(HtmlCommands::value_type("u", HtmlCommandElement(new UHandler())));

}

}

