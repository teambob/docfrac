//---------------------------------------------------------------------------
#ifndef TEngineThreadH
#define TEngineThreadH
//---------------------------------------------------------------------------
#include <wx/thread.h>
//---------------------------------------------------------------------------

#include "tstring.h"
#include "ProgressForm.h"

/*typedef void __fastcall (__closure *TThreadProgressEvent)(System::TObject *Sender,
  int percent);*/

class TEngineThread : public wxThread
{
private:
  bool error;
  bool terminate;  
    
  tstring errorMessage;

  Document document;
  long fileSize;
  int percentage;

  void UpdateProgress(void);
  void Finished(void);
  ProgressForm *progressForm;


protected:
    virtual void* Entry();
public:
    TEngineThread(const Document &newDocument);
    bool GetError(void);
    tstring GetErrorMessage(void);
	void SetProgressForm(ProgressForm *form);
	void Terminate();
 
};
//---------------------------------------------------------------------------
#endif
