#ifndef PROPERTIESDIALOG_H
#define PROPERTIESDIALOG_H

#include <QDialog>
#include "FileFormat.h"

namespace Ui {
class PropertiesDialog;
}

class PropertiesDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit PropertiesDialog(QWidget *parent = 0, bool customFilenameEnabled = true);
    ~PropertiesDialog();

    bool useInputDirectory();
    bool useCustomDirectory();
    bool useCustomFilename();

    std::string getPath();
    DoxEngine::FileFormat getOutputFormat();
    
private slots:
    void on_customDirectorySelect_toggled(bool checked);

    void on_customFilenameSelect_toggled(bool checked);

    void on_browseOutputDirectory_clicked();

    void on_outputFilenameBrowse_clicked();

private:
    Ui::PropertiesDialog *ui;
};

#endif // PROPERTIESDIALOG_H
