#include "mainrecipemodel.h"

#include <QtCore/QFile>
#include <QtCore/QTextStream>
#include <QColor>

MainRecipeModel::MainRecipeModel()
{
    data_core_ = new QVector<QStringList>;
}


MainRecipeModel::~MainRecipeModel()
{
    delete data_core_;
}


void MainRecipeModel::load_data(QString filename)
{
    Q_UNUSED(filename)

    beginResetModel();

    QFile file(filename);
    if(!file.open(QIODevice::ReadOnly)){
        return;
    }

    data_core_->clear();

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList cells = line.split(",");
        if(!cells.at(NUMBER).isEmpty() && !cells.at(NUMBER).startsWith("N"))
            data_core_->append(cells);
    }

    endResetModel();
}


int MainRecipeModel::rowCount(const QModelIndex &parent /*= QModelIndex()*/) const
{
    Q_UNUSED(parent)
    return data_core_->count();
}

int MainRecipeModel::columnCount(const QModelIndex &parent /*= QModelIndex()*/) const
{
    Q_UNUSED(parent)
    return COLUMN_NUMBER;
}

QVariant MainRecipeModel::data(const QModelIndex &index, int role /*= Qt::DisplayRole*/) const
{

    if(role != Qt::DisplayRole && role != Qt::BackgroundColorRole){
        return QVariant();
    }

    if(role == Qt::BackgroundColorRole)
    {
        if(data_core_->at(index.row()).at(RECIPE_NAME).isEmpty())
        {
            QColor magenta = QColor("#ff00ff");//Qt::magenta;
            magenta.setAlpha(30);
            return magenta;
        }

        return compute_background_color(index.row(), index.column());
    }

    return data_core_->at(index.row()).at(index.column());
}


QVariant MainRecipeModel::headerData(int section, Qt::Orientation orientation, int role /*= Qt::DisplayRole*/) const
{
    if(orientation == Qt::Horizontal && role == Qt::BackgroundColorRole)
    {
        QColor color;
        color.setNamedColor("gray");
        return color;
    }

    if(role != Qt::DisplayRole || orientation != Qt::Horizontal){
        return QVariant();
    }

    switch(section)
    {
    case NUMBER :
        return tr("N°");
        break;
    case RECIPE_NAME :
        return tr("Recipe Name");
        break;
    case ING_1 :
        return tr("Ingredient 1");
        break;
    case ING_2 :
        return tr("Ingredient 2");
        break;
    case ING_3 :
        return tr("Ingredient 3");
        break;
    case ING_4 :
        return tr("Ingredient 4");
        break;
    case COOKING_TOOL :
        return tr("Tool");
        break;
    case NORM_REWARD :
        return tr("Normal Reward");
        break;
    case PLATED_REWARD :
        return tr("Plated Reward");
        break;
    case CRAVING_TYPE_1 :
        return tr("Craving Type 1");
        break;
    case CRAVING_TYPE_2 :
        return tr("Craving Type 2");
        break;
    case CRAVING_TYPE_3 :
        return tr("Craving Type 3");
        break;
    case PLATING :
        return tr("Plating");
        break;
    default:
        break;

    }
    return QVariant();
}

QColor MainRecipeModel::compute_background_color(int row, int column) const
{
    if(column == COOKING_TOOL)
    {
        QString cooking_tool = data_core_->at(row).at(column);
        if(cooking_tool == "Grill & Oven")
            return QColor("#008000");//Qt::darkGreen
        if(cooking_tool.contains("CrockPot"))
            return QColor("#808000");//Qt::darkYellow
        if(cooking_tool.contains("Oven"))
            return QColor("#ffff00");//Qt::yellow
        if(cooking_tool.contains("Grill"))
        {
            QColor blue = QColor("#0000ff");
            blue.setAlpha(50);
            return blue; //Qt::blue
        }
    }

    if(column == NORM_REWARD || column == PLATED_REWARD)
    {
        QString reward = data_core_->at(row).at(column);
        if(reward.contains("G"))
            return QColor("#008000");//Qt::darkGreen
        if(reward.contains("R"))
            return QColor("#800000");//Qt::darkRed
        if(reward.contains("B"))
            return QColor("#008080");//Qt::darkCyan


    }

    return Qt::white;
}

