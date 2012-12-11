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
    while(!cancel_ && reader_->processData());
}
