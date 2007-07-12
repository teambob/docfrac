//---------------------------------------------------------------------------

#ifndef WriterFactoryH
#define WriterFactoryH
#include <map>
#include "WriterInterface.h"
#include "FileFormat.h"
#include "shared_ptr.h"
#include "DebugLog.h"
// This class uses an abstract factory to hide the details of
// the writer instantiation

//---------------------------------------------------------------------------
namespace DoxEngine
{

	class WriterFactory
	{
		public:
			virtual WriterInterface* Create(std::ostream &stream, DebugLog &log) = 0;
	};

  typedef shared_ptr<WriterFactory> WriterFactoryPtr;
	typedef std::map<const FileFormat,  WriterFactoryPtr> WriterFactories;

	class WriterFactoriesSingleton
	{
		public:
			// This function should only be called from the main thread
			static WriterFactories& GetWriterFactories();
	};
}

#endif
