#ifndef FILELISTMODEL_H
#define FILELISTMODEL_H

#include <QAbstractTableModel>
#include <vector>
#include "batchentry.h"


class BatchModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit BatchModel(QObject *parent);
    int rowCount(const QModelIndex &parent = QModelIndex()) const ;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    void add(const BatchEntry &entry);
    void remove(int index);
    void clear();
    std::vector<BatchEntry> getEntries();
    BatchEntry& at(int index);
signals:
    
public slots:

private:
    std::vector<BatchEntry> entries_;
    
};

#endif // FILELISTMODEL_H
