#include "conversionthread.h"
#include "ReaderInterface.h"

ConversionThread::ConversionThread(QObject *parent, DoxEngine::ReadInterface* reader) :
  QThread(parent),reader_(reader),cancel_(false)
{
}

void ConversionThread::cancel()
{
  cancel_ = true;
}

void ConversionThread::run()
{
  int lastPercent = 0;

  while(!cancel_ && reader_->processData())
  {
    int percent = reader_->getPercentComplete();
    if (percent!=lastPercent)
    {
      emit onProgress(percent);
      lastPercent = percent;
    }
  }
}
