//---------------------------------------------------------------------------
#ifndef TEngineThreadH
#define TEngineThreadH
//---------------------------------------------------------------------------
#include <Classes.hpp>
//---------------------------------------------------------------------------

typedef void __fastcall (__closure *TThreadProgressEvent)(System::TObject *Sender,
  int percent);

class TEngineThread : public TThread
{
private:
  bool error;
  std::string errorMessage;

  Document document;
  TThreadProgressEvent onProgress;
  TNotifyEvent onFinished;
  long fileSize;
  int percentage;

  void __fastcall UpdateProgress(void);
  void __fastcall Finished(void);


protected:
    void __fastcall Execute();
public:
    __fastcall TEngineThread(bool CreateSuspended, const Document &newDocument);
    void SetOnProgress(const TThreadProgressEvent newOnProgress);
    void SetOnFinished(const TNotifyEvent newOnFinished);
    bool GetError(void);
    std::string GetErrorMessage(void);
};
//---------------------------------------------------------------------------
#endif
