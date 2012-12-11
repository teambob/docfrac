#include <vector>
#include <string>
#include <boost/algorithm/string.hpp>
#include "batchmodel.h"
#include "batchentry.h"
#include "FormatToExtensionMap.h"

BatchModel::BatchModel(QObject *parent) :
    QAbstractTableModel(parent)
{
}

int BatchModel::rowCount(const QModelIndex &parent) const
{
    return entries_.size();
}

int BatchModel::columnCount(const QModelIndex &parent) const
{
    return 4;
}

QVariant BatchModel::data(const QModelIndex &index, int role) const
{
    using namespace std;
    if (role == Qt::DisplayRole)
    {

        switch( index.column() )
        {
            case 0:
            return QString(entries_[index.row()].getInputFilename().c_str());

            case 1:
            {
                DoxEngine::FileFormat format = entries_[index.row()].getInputFormat();
                map<DoxEngine::FileFormat, string> mapping = DoxEngine::getFormatToExtensionMap();
                map<DoxEngine::FileFormat, string>::const_iterator i = mapping.find(format);
                if (i!=mapping.end())
                    return QString(boost::to_upper_copy(i->second).c_str());
                else
                    return QString("Error");
            }

            case 2:
            return QString(entries_[index.row()].getOutputFilename().c_str());

            case 3:
            {
                DoxEngine::FileFormat format = entries_[index.row()].getOutputFormat();
                map<DoxEngine::FileFormat, string> mapping = DoxEngine::getFormatToExtensionMap();
                map<DoxEngine::FileFormat, string>::const_iterator i = mapping.find(format);
                if (i!=mapping.end())
                    return QString(boost::to_upper_copy(i->second).c_str());
                else
                    return QString("Error");
            }


            default:
            return QVariant();

        }

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
                    return QString("Input Filename");
                    break;

                case 1:
                    return QString("Input Format");
                    break;

                case 2:
                    return QString("Output Filename");
                    break;

                case 3:
                    return QString("Output Format");
                    break;
            }
        }
    }
    return QVariant();
}

void BatchModel::add(const BatchEntry &entry)
{
    int row = entries_.size();
    beginInsertRows(QModelIndex(), row, row);
    entries_.push_back(entry);
    endInsertRows();

}

void BatchModel::remove(int index)
{
    beginRemoveRows(QModelIndex(), index, index);
    entries_.erase(entries_.begin()+index);
    endRemoveRows();
}

void BatchModel::clear()
{
    for (int i=entries_.size();i>0;i--)
        remove(i-1);
}

std::vector<BatchEntry> BatchModel::getEntries()
{
    return entries_;
}
