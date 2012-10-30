#include "batchmodel.h"
#include <vector>
#include <string>


BatchModel::BatchModel(QObject *parent) :
    QAbstractTableModel(parent)
{
}

int BatchModel::rowCount(const QModelIndex &parent) const
{
    return 1;
}

int BatchModel::columnCount(const QModelIndex &parent) const
{
    return 4;
}

QVariant BatchModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole)
    {
        // fetch array element using index.row()
        std::vector<std::string> row;
        row.push_back("a.rtf");
        row.push_back("RTF");
        row.push_back("a.html");
        row.push_back("HTML");

        return QString(row.at(index.column()).c_str());
    }
    else
        return QVariant();
}

QVariant BatchModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole)
    {
        if (orientation == Qt::Horizontal)
        {
            switch (section)
            {
                case 0:
                    return QString("Input File");
                    break;

                case 1:
                    return QString("Input Format");
                    break;

                case 2:
                    return QString("Output File");
                    break;

                case 3:
                    return QString("Output Format");
                    break;
            }
        }
    }
    return QVariant();
}

