#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>
#include "batchentry.h"
#include "batchmodel.h"
#include "progressdialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    
private slots:
    void on_actionAbout_triggered();

    void on_actionConversion_Properties_triggered();

    void on_actionAdd_triggered();

    void on_actionConvert_triggered();

    void on_actionRemove_triggered();

    void on_actionClear_All_Files_triggered();
    void onThreadFinished();

    void on_actionExit_triggered();

    void on_actionSelect_All_triggered();

private:
    Ui::MainWindow *ui;
    BatchModel *model;
    ProgressDialog progress_;
};

#endif // MAINWINDOW_H
