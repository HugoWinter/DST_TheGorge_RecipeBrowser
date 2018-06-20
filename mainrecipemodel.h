#ifndef MAINRECIPEMODEL_H
#define MAINRECIPEMODEL_H

#include <QtCore/QAbstractTableModel>

#define COLUMN_NUMBER 13

class MainRecipeModel : public QAbstractTableModel
{
public:

    enum ColumnNames
    {
        NUMBER =0,
        RECIPE_NAME,
        ING_1,
        ING_2,
        ING_3,
        ING_4,
        COOKING_TOOL,
        NORM_REWARD,
        PLATED_REWARD,
        CRAVING_TYPE_1,
        CRAVING_TYPE_2,
        CRAVING_TYPE_3,
        PLATING
    };

    MainRecipeModel();
    virtual ~MainRecipeModel();

    void load_data(QString filename);


    virtual int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    virtual int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    virtual QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    virtual QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

private :
    QColor compute_background_color(int row, int column) const;

private :
    QVector<QStringList> *data_core_;

};

#endif // MAINRECIPEMODEL_H
