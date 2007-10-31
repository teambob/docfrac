//---------------------------------------------------------------------------
#include <wx/thread.h>

#include <fstream>
#include <iostream>
#include <ios>

#include <stdio.h>
#include <ext/stdio_filebuf.h.>

#include "Document.h"
#include "TEngineThread.h"
#include "ReaderInterface.h"
#include "WriterInterface.h"
#include "WriterFactory.h"
#include "ReaderFactory.h"
#include "tstring.h"


class ThreadException
{
  private:
    tstring message;

  public:
    ThreadException(const tstring &newMessage);
    tstring GetMessage(void);
};

ThreadException::ThreadException(const tstring &newMessage):
  message(newMessage)
{
  // Empty initialiser
}

tstring ThreadException::GetMessage(void)
{
  return message;
}

class InputFileException : public ThreadException
{
  public:
    InputFileException(const tstring &newMessage);
};

InputFileException::InputFileException(const tstring &newMessage)
  : ThreadException(newMessage)
{
  // Empty initialiser
}

class OutputFileException : public ThreadException
{
  public:
    OutputFileException(const tstring &newMessage);
};

OutputFileException::OutputFileException(const tstring &newMessage)
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
TEngineThread::TEngineThread(const Document &newDocument)
    : wxThread(wxTHREAD_JOINABLE ),document(newDocument)
{
  progressForm = NULL;
  //onFinished = NULL;
  terminate = false;
  Create();
}

void TEngineThread::SetProgressForm(ProgressForm *form)
{
  progressForm = form;
}


void TEngineThread::UpdateProgress(void)
{
    wxMutexGuiEnter();
    if (progressForm)
        progressForm->OnProgress(percentage);
    wxMutexGuiLeave();
}

void TEngineThread::Finished(void)
{
    wxMutexGuiEnter();
    if (progressForm)
        progressForm->OnFinished();
    wxMutexGuiLeave();
}

//---------------------------------------------------------------------------
void* TEngineThread::Entry()
{
    FILE *inputFptr = _wfopen(document.GetInputPathname().c_str(), L"rb");
    
    // need to test inputFptr
    if ( !inputFptr )
    {
      tstring message = wxT("Could not open input file:");
      message.append(document.GetInputPathname().c_str());
      throw InputFileException(message);
    }
    
    FILE *outputFptr = _wfopen(document.GetOutputPathname().c_str(), L"wb");
    
    
    // need to test outputFptr
    if ( !outputFptr )
    {
      tstring message = wxT("Could not open output file:");
      message.append(document.GetOutputPathname().c_str());
      throw InputFileException(message);
    }



  try
  {
    


    __gnu_cxx::stdio_filebuf<char> inputBuf(inputFptr, std::ios_base::in);    
    std::istream input(&inputBuf);
    

    

    if ( !input.good() )
	{
	  tstring message = wxT("Could not open input file:");
	  message.append(document.GetInputPathname().c_str());
	  throw InputFileException(message);
    }



    


    __gnu_cxx::stdio_filebuf<char> outputBuf(outputFptr, std::ios_base::out);
    std::ostream output(&outputBuf);




    if (!output.good())
    {
	  tstring message(wxT("Could not open output file:"));
	  message.append(document.GetOutputPathname().c_str());
	  throw OutputFileException(message);

    }

    DoxEngine::DebugLog log;
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
			throw ThreadException(wxT("Internal error initialising writer"));
		}
		else
		{
			// First type is the key (file format)
			// Second type is the value (factory instance)
			writer = writerIterator->second->Create(output, log);
		}



		DoxEngine::ReaderFactories &readerFactories = DoxEngine::ReaderFactoriesSingleton::GetReaderFactories();

		DoxEngine::ReaderFactories::iterator readerIterator = readerFactories.find(document.GetInputFormat());
		if (readerIterator == readerFactories.end())
		{
			throw ThreadException(wxT("Internal error initialising reader"));
		}
		else
		{
			// First type is the key (file format)
			// Second type is the value (factory instance)
			reader = readerIterator->second->Create(input, *writer, log);
		}

		input.exceptions(input.badbit);
		output.exceptions(output.badbit);


		while (reader->processData()    // Data to process
            &&!terminate            // wxThread still running
            && input.good())            // No problems reading data
		{
			percentage = 100*input.tellg()/fileSize; // Calculate percentage
			UpdateProgress();
		}

    delete reader;
    delete writer;

    error = false;

	Finished();


  }
  catch(ThreadException &e)
  {
    error = true;
    /*errorMessage = e.GetMessage();*/
	/*Synchronize((TThreadMethod)&Finished);*/
  }
  catch(...)
  {
    error = true;
    errorMessage = wxT("Unknown error");
    /*Synchronize((TThreadMethod)&Finished);*/
  }
  
  // need to do this *after* deleting c++ streams
  fclose(inputFptr);
  fclose(outputFptr);

}
//---------------------------------------------------------------------------

bool TEngineThread::GetError(void)
{
  return error;
}

tstring TEngineThread::GetErrorMessage(void)
{
  return errorMessage;
}


void TEngineThread::Terminate()
{
    terminate = true;    
}
