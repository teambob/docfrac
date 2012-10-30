#ifndef FILELISTMODEL_H
#define FILELISTMODEL_H

#include <QAbstractTableModel>

class BatchModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit BatchModel(QObject *parent = 0);
    int rowCount(const QModelIndex &parent = QModelIndex()) const ;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
signals:
    
public slots:
    
};

#endif // FILELISTMODEL_H
