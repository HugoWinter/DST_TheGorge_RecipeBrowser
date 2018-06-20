#include "sortfilterrecipemodel.h"

#include "mainrecipemodel.h" // for Enum

SortFilterRecipeModel::SortFilterRecipeModel()
{

}

SortFilterRecipeModel::~SortFilterRecipeModel()
{

}

bool SortFilterRecipeModel::filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const
{
    for (int i = 0; i < sourceModel()->columnCount(); i++)
    {
        QModelIndex index = sourceModel()->index(sourceRow, i, sourceParent);

        if (sourceModel()->data(index).toString().contains(this->filterRegExp())){
            return true;
        }
    }
    return false;
}

bool SortFilterRecipeModel::lessThan(const QModelIndex &left, const QModelIndex &right) const
{
    QVariant leftData = sourceModel()->data(left);
    QVariant rightData = sourceModel()->data(right);

    if(left.column() == MainRecipeModel::NUMBER)
    {
        return leftData.toInt() > rightData.toInt();
    }

    return QString::localeAwareCompare(leftData.toString(), rightData.toString()) > 0;
}


void SortFilterRecipeModel::filterHasChanged(const QString &filter)
{
    QRegExp regExp(filter, Qt::CaseInsensitive); //TODO : fix case insensitivity not working
    this->setFilterRegExp(regExp);
    this->invalidateFilter();
}

//***********************************************************************************************


SpecialisedSortFilterRecipeModel::SpecialisedSortFilterRecipeModel()
{

}

SpecialisedSortFilterRecipeModel::~SpecialisedSortFilterRecipeModel()
{

}

void SpecialisedSortFilterRecipeModel::setOneTimeFilter(const QString &filter)
{
    QRegExp regExp(filter, Qt::CaseInsensitive); //TODO : fix case insensitivity not working
    this->setFilterRegExp(regExp);
    this->invalidateFilter();
}

bool SpecialisedSortFilterRecipeModel::filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const
{
    QModelIndex index = sourceModel()->index(sourceRow, MainRecipeModel::COOKING_TOOL, sourceParent);
    if (sourceModel()->data(index).toString().contains(this->filterRegExp())){
        return true;
    }
    return false;
}
