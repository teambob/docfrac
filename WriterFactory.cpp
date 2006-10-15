//---------------------------------------------------------------------------


#pragma hdrstop

#include "WriterFactory.h"
#include "RtfWriter.h"
#include "HtmlWriter.h"
#include "TextWriter.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

namespace DoxEngine
{
	template <class T> class WriterFactoryTemplate: public WriterFactory
	{
		virtual WriterInterface* Create(std::ostream &stream)
		{
      return new T(stream);
    }
  };

	WriterFactories& WriterFactoriesSingleton::GetWriterFactories()
	{
		// This function should only be called from the main thread
		static WriterFactories* writers = NULL;

		if (!writers)
		{
			writers = new WriterFactories;
			writers->insert(WriterFactories::value_type(FORMAT_RTF, (WriterFactoryAdapter)(new WriterFactoryTemplate<RtfWriter>)));
			writers->insert(WriterFactories::value_type(FORMAT_HTML, (WriterFactoryAdapter)(new WriterFactoryTemplate<HtmlWriter>)));
			writers->insert(WriterFactories::value_type(FORMAT_TEXT, (WriterFactoryAdapter)(new WriterFactoryTemplate<TextWriter>)));
		}

		return *writers;

	}

	WriterFactoryAdapter::WriterFactoryAdapter(WriterFactory* newFactory)
	{
		factory = newFactory;
	}

	WriterFactoryAdapter::~WriterFactoryAdapter()
	{
    // Possible memory leak
		//delete factory;
	}

	WriterInterface* WriterFactoryAdapter::Create(std::ostream &stream)
	{
    return factory->Create(stream);
  }



}