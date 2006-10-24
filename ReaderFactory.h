//---------------------------------------------------------------------------

#ifndef ReaderFactoryH
#define ReaderFactoryH
#include <map>
#include <istream>
#include "ReaderInterface.h"
#include "WriterInterface.h"
#include "FileFormat.h"
#include "shared_ptr.h"
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


  typedef shared_ptr<ReaderFactory> ReaderFactoryPtr;
	typedef std::map<const FileFormat, ReaderFactoryPtr> ReaderFactories;

	class ReaderFactoriesSingleton
	{
		public:
			// This function should only be called from the main thread
			static ReaderFactories& GetReaderFactories();
      
	};
}

#endif
