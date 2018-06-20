#ifndef SORTFILTERRECIPEMODEL_H
#define SORTFILTERRECIPEMODEL_H

#include <QtCore/QSortFilterProxyModel>

class SortFilterRecipeModel : public QSortFilterProxyModel
{
public:
    SortFilterRecipeModel();
    virtual ~SortFilterRecipeModel();

protected:
    virtual bool filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const override;
    virtual bool lessThan(const QModelIndex &left, const QModelIndex &right) const override;

public slots:
    void filterHasChanged(const QString &filter);
};


class SpecialisedSortFilterRecipeModel : public SortFilterRecipeModel
{
public:
    SpecialisedSortFilterRecipeModel();
    virtual ~SpecialisedSortFilterRecipeModel();

    void setOneTimeFilter(const QString &filter);

protected:
    virtual bool filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const override;
};

#endif // SORTFILTERRECIPEMODEL_H
