#ifndef PROGRESSDIALOG_H
#define PROGRESSDIALOG_H

#include <QDialog>

namespace Ui {
class ProgressDialog;
}

class ProgressDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit ProgressDialog(QWidget *parent=0);
    ~ProgressDialog();
  void setInputFilename(const std::string& inputFilename);
  void setOutputFilename(const std::string& outputFilename);

public slots:
    void onProgress(int percent);
    void onFinished();
    
private:
    Ui::ProgressDialog *ui;
};

#endif // PROGRESSDIALOG_H
