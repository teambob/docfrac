//---------------------------------------------------------------------------

#ifndef WriterFactoryH
#define WriterFactoryH
#include <map>
#include <istream>
#include "ReaderInterface.h"
#include "WriterInterface.h"
#include "FileFormat.h"
// This class uses an abstract factory to hide the details of
// the writer instantiation

//---------------------------------------------------------------------------
namespace DoxEngine
{

	class ReaderFactory
	{
		public:
			virtual ReadInterface* Create(std::istream &stream, WriterInterface &writer) = 0;
	};


	// Slicing = Stroustrup incompetence
	class ReaderFactoryAdapter
	{
		private:
			ReaderFactory *factory;

		public:
			ReaderFactoryAdapter(ReaderFactory* newFactory);
			~ReaderFactoryAdapter();
			ReadInterface* Create(std::istream &stream, WriterInterface &writer);
	};

	typedef std::map<const FileFormat, ReaderFactoryAdapter> ReaderFactories;

	class ReaderFactoriesSingleton
	{
		public:
			// This function should only be called from the main thread
			static ReaderFactories& GetReaderFactories();
	};
}

#endif
