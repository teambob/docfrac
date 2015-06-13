#include "donatedialog.h"
#include "ui_donatedialog.h"

DonateDialog::DonateDialog(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::DonateDialog)
{
  ui->setupUi(this);
}

DonateDialog::~DonateDialog()
{
  delete ui;
}
