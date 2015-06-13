#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QItemSelection>
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


    void on_actionExit_triggered();

    void on_actionSelect_All_triggered();

    void on_actionPaste_triggered();

    void on_actionText_triggered();

    void on_actionRTF_triggered();

    void on_actionHTML_triggered();

    void on_actionInputDirectory_triggered();

    void on_actionCustomDirectory_triggered();

    void on_actionCustomFilename_triggered();

    void onSelectionChanged( const QItemSelection & selected, const QItemSelection & deselected );

    void on_actionDonate_triggered();

    void on_batchList_customContextMenuRequested(const QPoint &pos);

  private:
    Ui::MainWindow *ui;
    BatchModel *model;
    ProgressDialog progress_;

  protected:
    virtual void dragEnterEvent(QDragEnterEvent *event);
    virtual void dropEvent(QDropEvent *event);
    virtual void showEvent ( QShowEvent * event );
};

#endif // MAINWINDOW_H
