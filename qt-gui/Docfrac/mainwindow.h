#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class BatchModel;

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

private:
    Ui::MainWindow *ui;
    BatchModel *model;
};

#endif // MAINWINDOW_H
