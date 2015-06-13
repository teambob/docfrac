#include "progressdialog.h"
#include "ui_progressdialog.h"

ProgressDialog::ProgressDialog(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::ProgressDialog)
{
  ui->setupUi(this);
}

ProgressDialog::~ProgressDialog()
{
  delete ui;
}

void ProgressDialog::setInputFilename(const std::string &inputFilename)
{
  ui->inputFileLabel->setText(inputFilename.c_str());
}

void ProgressDialog::setOutputFilename(const std::string &outputFilename)
{
  ui->outputFileLabel->setText(outputFilename.c_str());
}

void ProgressDialog::onProgress(int percent)
{
  ui->progressBar->setValue(percent);
}

void ProgressDialog::onFinished()
{
  accept();
}
