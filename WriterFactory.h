//---------------------------------------------------------------------------

#ifndef WriterFactoryH
#define WriterFactoryH
#include <map>
#include "WriterInterface.h"
#include "FileFormat.h"
// This class uses an abstract factory to hide the details of
// the writer instantiation

//---------------------------------------------------------------------------
namespace DoxEngine
{

	class WriterFactory
	{
		public:
			virtual WriterInterface* Create(std::ostream &stream) = 0;
	};


	// Slicing = Stroustrup incompetence
	class WriterFactoryAdapter
	{
		private:
			WriterFactory *factory;

		public:
			WriterFactoryAdapter(WriterFactory* newFactory);
			~WriterFactoryAdapter();
			WriterInterface* Create(std::ostream &stream);
	};

	typedef std::map<const FileFormat, WriterFactoryAdapter> WriterFactories;

	class WriterFactoriesSingleton
	{
		public:
			// This function should only be called from the main thread
			static WriterFactories& GetWriterFactories();
	};
}

#endif
