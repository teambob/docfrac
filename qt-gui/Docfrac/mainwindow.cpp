#include <QFileDialog>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "about.h"
#include "propertiesdialog.h"
#include "progressdialog.h"
#include "batchmodel.h"
#include "FileFormat.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    model = new BatchModel(this, entries_);
    entries_.push_back(BatchEntry("test.rtf", BatchEntry::ManualFilename, DoxEngine::FORMAT_HTML, "test.html"));
    ui->batchList->setModel(model);
    ui->batchList->resizeColumnsToContents();

}

MainWindow::~MainWindow()
{
    delete ui;
    delete model;
}


void MainWindow::on_actionAbout_triggered()
{
    About aboutBox(this);
    aboutBox.exec();
}

void MainWindow::on_actionConversion_Properties_triggered()
{
    PropertiesDialog properties(this);

    properties.exec();
}

void MainWindow::on_actionAdd_triggered()
{
    QStringList files = QFileDialog::getOpenFileNames(this,"Add Files to Batch","","All Known Formats (*.rtf *.html *.htm *.txt);;RTF (*.rtf);;HTML (*.html *.htm);;Text (*.txt)");
    if (files.length())
    {
        PropertiesDialog properties(this, (files.length()==1));
        if (properties.exec() == QFileDialog::Accept)
        {
            for (QStringList::Iterator i=files.begin();i!=files.end();i++);
        }
    }
}

void MainWindow::on_actionConvert_triggered()
{
    ProgressDialog progress(this);
    progress.exec();
}
