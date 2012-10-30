#include <QFileDialog>
#include "propertiesdialog.h"
#include "ui_propertiesdialog.h"

PropertiesDialog::PropertiesDialog(QWidget *parent, bool customFilenameEnabled) :
    QDialog(parent),
    ui(new Ui::PropertiesDialog)
{
    ui->setupUi(this);
    ui->customFilenameSelect->setEnabled(customFilenameEnabled);
}

PropertiesDialog::~PropertiesDialog()
{
    delete ui;
}

bool PropertiesDialog::useInputDirectory()
{
    return ui->inputDirectorySelect->isChecked();
}

bool PropertiesDialog::useCustomDirectory()
{
    return ui->customDirectorySelect->isChecked();
}

bool PropertiesDialog::useCustomFilename()
{
    return ui->customFilenameSelect->isChecked();
}

std::string PropertiesDialog::getPath()
{
    if (ui->customDirectorySelect->isChecked())
        return ui->outputDirectory->text().toStdString();
    else if (ui->customFilenameSelect->isChecked())
        return ui->outputFilename->text().toStdString();
    else
        return "";
}

std::string PropertiesDialog::getOutputFormat()
{
    return ui->outputFormatSelect->currentText().toStdString();
}



void PropertiesDialog::on_customDirectorySelect_toggled(bool checked)
{
    ui->browseOutputDirectory->setEnabled(checked);
    ui->outputDirectory->setEnabled(checked);

}


void PropertiesDialog::on_customFilenameSelect_toggled(bool checked)
{
    ui->outputFilenameBrowse->setEnabled(checked);
    ui->outputFilename->setEnabled(checked);
}

void PropertiesDialog::on_browseOutputDirectory_clicked()
{
    QString directory = QFileDialog::getExistingDirectory(this, "Output Directory");
    if (directory.size())
        ui->outputDirectory->setText(directory);
}

void PropertiesDialog::on_outputFilenameBrowse_clicked()
{
    QString filename = QFileDialog::getSaveFileName(this, "Output File","","All Known Formats (*.rtf *.html *.htm *.txt);;RTF (*.rtf);;HTML (*.html *.htm);;Text (*.txt)");
    if (filename.size())
        ui->outputFilename->setText(filename);
}
