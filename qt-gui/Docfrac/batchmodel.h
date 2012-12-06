#ifndef FILELISTMODEL_H
#define FILELISTMODEL_H

#include <QAbstractTableModel>
#include <vector>
#include "batchentry.h"


class BatchModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit BatchModel(QObject *parent , const std::vector<BatchEntry> &entries);
    int rowCount(const QModelIndex &parent = QModelIndex()) const ;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
signals:
    
public slots:

private:
    const std::vector<BatchEntry> &entries_;
    
};

#endif // FILELISTMODEL_H
