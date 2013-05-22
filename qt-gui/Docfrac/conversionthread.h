#ifndef CONVERSIONTHREAD_H
#define CONVERSIONTHREAD_H

#include <QThread>
#include "ReaderInterface.h"



class ConversionThread : public QThread
{
    Q_OBJECT
  public:
    explicit ConversionThread(QObject *parent, DoxEngine::ReadInterface* reader);
    void cancel();

    
  signals:
    void onProgress(int percent);
    
  public slots:

  protected:
    virtual void run();

  private:
    DoxEngine::ReadInterface* reader_;
    bool cancel_;
    
};

#endif // CONVERSIONTHREAD_H
