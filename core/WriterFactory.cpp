//---------------------------------------------------------------------------




#include "WriterFactory.h"
#include "RtfWriter.h"
#include "HtmlWriter.h"
#include "TextWriter.h"

//---------------------------------------------------------------------------



namespace DoxEngine
{
	template <class T> class WriterFactoryTemplate: public WriterFactory
	{
		virtual WriterInterface* Create(std::ostream &stream, DebugLog &log)
		{
      return new T(stream, log);
    }
  };

	WriterFactories& WriterFactoriesSingleton::GetWriterFactories()
	{
		// This function should only be called from the main thread
		static WriterFactories* writers = NULL;

		if (!writers)
		{
			writers = new WriterFactories;
			writers->insert(WriterFactories::value_type(FORMAT_RTF, WriterFactoryPtr(new WriterFactoryTemplate<RtfWriter>)));
			writers->insert(WriterFactories::value_type(FORMAT_HTML, WriterFactoryPtr(new WriterFactoryTemplate<HtmlWriter>)));
			writers->insert(WriterFactories::value_type(FORMAT_TEXT, WriterFactoryPtr(new WriterFactoryTemplate<TextWriter>)));
		}

		return *writers;

	}

}

