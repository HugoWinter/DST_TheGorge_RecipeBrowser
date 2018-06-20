#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "mainrecipemodel.h"
#include "sortfilterrecipemodel.h"

#include <QtWidgets/QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setWindowTitle("DST The Gorge Recipe Browser");
    this->init_ui();

    connect(ui->import_action, &QAction::triggered, this, &MainWindow::on_import_file_clicked);

    main_model_ = new MainRecipeModel;

    SortFilterRecipeModel *sort_filter_model = new SortFilterRecipeModel;
    sort_filter_model->setSourceModel(main_model_);

    SpecialisedSortFilterRecipeModel *crockpot_model = new SpecialisedSortFilterRecipeModel;
    SpecialisedSortFilterRecipeModel *oven_model = new SpecialisedSortFilterRecipeModel;
    SpecialisedSortFilterRecipeModel *grill_model = new SpecialisedSortFilterRecipeModel;
    crockpot_model->setSourceModel(sort_filter_model);
    oven_model->setSourceModel(sort_filter_model);
    grill_model->setSourceModel(sort_filter_model);
    crockpot_model->setOneTimeFilter("crockpot");
    oven_model->setOneTimeFilter("oven");
    grill_model->setOneTimeFilter("grill");


    ui->main_view->setModel(sort_filter_model);
    ui->crockpot_view->setModel(crockpot_model);
    ui->oven_view->setModel(oven_model);
    ui->grill_view->setModel(grill_model);


    connect(ui->filter_edit, &QLineEdit::textChanged, sort_filter_model, &SortFilterRecipeModel::filterHasChanged);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_import_file_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("Choose the recipe file to import"),QString(),"*.csv");

    if(!filename.isNull())
    {
        main_model_->load_data(filename);
    }
}

void MainWindow::init_ui()
{
    connect(ui->meat_button, &QPushButton::clicked, [this]{this->ui->filter_edit->setText("Meat");});
    connect(ui->soup_button, &QPushButton::clicked, [this]{this->ui->filter_edit->setText("Soup");});
    connect(ui->dessert_button, &QPushButton::clicked, [this]{this->ui->filter_edit->setText("Dessert");});
    connect(ui->cheese_button, &QPushButton::clicked, [this]{this->ui->filter_edit->setText("Cheese");});
    connect(ui->pasta_button, &QPushButton::clicked, [this]{this->ui->filter_edit->setText("Pasta");});
    connect(ui->bread_button, &QPushButton::clicked, [this]{this->ui->filter_edit->setText("Bread");});
    connect(ui->fish_button, &QPushButton::clicked, [this]{this->ui->filter_edit->setText("Fish");});
    connect(ui->snack_button, &QPushButton::clicked, [this]{this->ui->filter_edit->setText("Snack");});
    connect(ui->vegetable_button, &QPushButton::clicked, [this]{this->ui->filter_edit->setText("Veggie");});
}
