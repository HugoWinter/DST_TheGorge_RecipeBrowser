#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class MainRecipeModel;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void on_import_file_clicked();
private :
    void init_ui();

private:
    Ui::MainWindow *ui;
    MainRecipeModel *main_model_;
};

#endif // MAINWINDOW_H
