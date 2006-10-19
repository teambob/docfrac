//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include <vector>
#include <fstream>
#include <iostream>
#include <ios>

#include "Document.h"
#include "TEngineThread.h"
#include "ReaderInterface.h"
#include "WriterInterface.h"
#include "WriterFactory.h"
#include "ReaderFactory.h"
#include "debug.h"
#pragma package(smart_init)

class ThreadException
{
  private:
    std::string message;

  public:
    ThreadException(const std::string &newMessage);
    std::string GetMessage(void);
};

ThreadException::ThreadException(const std::string &newMessage):
  message(newMessage)
{
  // Empty initialiser
}

std::string ThreadException::GetMessage(void)
{
  return message;
}

class InputFileException : public ThreadException
{
  public:
    InputFileException(const std::string &newMessage);
};

InputFileException::InputFileException(const std::string &newMessage)
  : ThreadException(newMessage)
{
  // Empty initialiser
}

class OutputFileException : public ThreadException
{
  public:
    OutputFileException(const std::string &newMessage);
};

OutputFileException::OutputFileException(const std::string &newMessage)
  : ThreadException(newMessage)
{
  // Empty initialiser
}


//---------------------------------------------------------------------------
//   Important: Methods and properties of objects in VCL can only be
//   used in a method called using Synchronize, for example:
//
//      Synchronize(UpdateCaption);
//
//   where UpdateCaption could look like:
//
//      void __fastcall TEngineThread::UpdateCaption()
//      {
//        Form1->Caption = "Updated in a thread";
//      }
//---------------------------------------------------------------------------
__fastcall TEngineThread::TEngineThread(bool CreateSuspended,
  const Document &newDocument)
    : TThread(CreateSuspended),document(newDocument)
{
  onProgress = NULL;
  onFinished = NULL;
}

void TEngineThread::SetOnProgress(const TThreadProgressEvent newOnProgress)
{
  onProgress = newOnProgress;
}


void TEngineThread::SetOnFinished(const TNotifyEvent newOnFinished)
{
  onFinished = newOnFinished;
}

void __fastcall TEngineThread::UpdateProgress(void)
{
  if (onProgress)
    onProgress(this, percentage);
}

void __fastcall TEngineThread::Finished(void)
{
  if (onFinished)
    onFinished(this);
}

//---------------------------------------------------------------------------
void __fastcall TEngineThread::Execute()
{
  try
  {
    std::ifstream input(document.GetInputPathname().c_str());

    if ( !input.good() || !input.is_open())
	{
	  std::string message = "Could not open input file:";
	  message.append(document.GetInputPathname().c_str());
	  throw InputFileException(message);
    }

    std::ofstream output(document.GetOutputPathname().c_str());

    if (!output.good() || !output.is_open())
    {
	  std::string message("Could not open output file:");
	  message.append(document.GetOutputPathname().c_str());
	  throw OutputFileException(message);

    }


    DoxEngine::debugStream = &std::cout;
    DoxEngine::ReadInterface *reader = NULL;
    DoxEngine::WriterInterface *writer = NULL;

    // Get file size
	  input.seekg(0, std::ios_base::end); // Jump to end of file
		fileSize = input.tellg();     // Position indicates file size
		input.seekg(0, std::ios_base::beg); // Jump back to start of file

		DoxEngine::WriterFactories &writerFactories = DoxEngine::WriterFactoriesSingleton::GetWriterFactories();

		DoxEngine::WriterFactories::iterator writerIterator = writerFactories.find(document.GetOutputFormat());
		if (writerIterator == writerFactories.end())
		{
			throw ThreadException("Internal error initialising writer");
		}
		else
		{
			// First type is the key (file format)
			// Second type is the value (factory instance)
			writer = writerIterator->second.Create(output);
		}



		DoxEngine::ReaderFactories &readerFactories = DoxEngine::ReaderFactoriesSingleton::GetReaderFactories();

		DoxEngine::ReaderFactories::iterator readerIterator = readerFactories.find(document.GetInputFormat());
		if (readerIterator == readerFactories.end())
		{
			throw ThreadException("Internal error initialising reader");
		}
		else
		{
			// First type is the key (file format)
			// Second type is the value (factory instance)
			reader = readerIterator->second.Create(input, *writer);
		}

		input.exceptions(input.badbit);
		output.exceptions(output.badbit);
		
		while ((reader->processData())&&(!Terminated))
		{
			percentage = 100*input.tellg()/fileSize; // Calculate percentage
			Synchronize((TThreadMethod)&UpdateProgress);
		}

    delete reader;
    delete writer;

    error = false;

	TThread::Synchronize((TThreadMethod)&Finished);
  }
  catch(ThreadException &e)
  {
    error = true;
    errorMessage = e.GetMessage();
	Synchronize((TThreadMethod)&Finished);
  }
  catch(...)
  {
    error = true;
    errorMessage = "Unknown error";
    Synchronize((TThreadMethod)&Finished);
  }

}
//---------------------------------------------------------------------------

bool TEngineThread::GetError(void)
{
  return error;
}

std::string TEngineThread::GetErrorMessage(void)
{
  return errorMessage;
}
