#include <QFileDialog>
#include <QMessageBox>
#include <QClipboard>

#include <boost/scoped_ptr.hpp>
#include <fstream>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "about.h"
#include "propertiesdialog.h"
#include "progressdialog.h"
#include "batchmodel.h"
#include "batchentry.h"
#include "conversionthread.h"

#include "FileFormat.h"
#include "WriterFactory.h"
#include "ReaderFactory.h"
#include "ReaderInterface.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    progress_(this)
{
    ui->setupUi(this);
    model = new BatchModel(this);
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
    QStringList files = QFileDialog::getOpenFileNames(this,"Add Files to Batch", QString(), "All Known Formats (*.rtf *.html *.htm *.txt);;RTF (*.rtf);;HTML (*.html *.htm);;Text (*.txt)");
    if (files.size())
    {
        PropertiesDialog properties(this, (files.length()==1));
        if (properties.exec())
        {
            BatchEntry::OutputFilenameGeneration filenameGeneration;
            if (properties.useInputDirectory())
                filenameGeneration = BatchEntry::InputDirectory;
            else if (properties.useCustomDirectory())
                filenameGeneration = BatchEntry::CustomDirectory;
            else if (properties.useCustomFilename())
                filenameGeneration = BatchEntry::ManualFilename;
            else
                return; // TODO throw?

            for (QStringList::Iterator i=files.begin();i!=files.end();i++)
            {
              model->add(BatchEntry(i->toStdString(), filenameGeneration, properties.getOutputFormat(), properties.getPath()));
            }

        }
    }
}

void MainWindow::on_actionConvert_triggered()
{
    using namespace DoxEngine;
    using namespace std;
    vector<BatchEntry> entries = model->getEntries();
    WriterFactories writerFactories = WriterFactoriesSingleton::GetWriterFactories();
    ReaderFactories readerFactories = ReaderFactoriesSingleton::GetReaderFactories();


    for (vector<BatchEntry>::iterator i=entries.begin();i!=entries.end();i++)
    {
        DebugLog log;


        ofstream out(i->getOutputFilename().c_str());
        ifstream in(i->getInputFilename().c_str());

        boost::scoped_ptr<WriterInterface> writer(writerFactories[i->getOutputFormat()]->Create(out, log));
        boost::scoped_ptr<ReadInterface> reader(readerFactories[i->getInputFormat()]->Create(in, *writer, log));
        ConversionThread thread(this, reader.get());
        thread.start();
        QObject::connect(&thread,SIGNAL(finished()),this,SLOT(onThreadFinished()));
        if (!progress_.exec())
        {
            thread.cancel();
            thread.wait();
            return;
        }
        thread.wait();

    }

    model->clear();

    QMessageBox::information(this,"Finished","Conversion Finished",QMessageBox::Ok);






}

void MainWindow::on_actionRemove_triggered()
{

    QModelIndexList selectedRows = ui->batchList->selectionModel()->selectedRows(0);
    std::vector<int> toBeRemoved;

    for (QModelIndexList::iterator i = selectedRows.begin();i!=selectedRows.end();i++)
        toBeRemoved.push_back(i->row());

    // Go backwards otherwise we will mess up the indices
    for (std::vector<int>::reverse_iterator i=toBeRemoved.rbegin();i!=toBeRemoved.rend();i++)
        model->remove(*i);

    // FIXME: undo
}

void MainWindow::on_actionClear_All_Files_triggered()
{
    model->clear();
}

void MainWindow::onThreadFinished()
{
    progress_.accept();
}

void MainWindow::on_actionExit_triggered()
{
    close();
}

void MainWindow::on_actionSelect_All_triggered()
{
    ui->batchList->selectAll();
}

void MainWindow::on_actionPaste_triggered()
{

}
