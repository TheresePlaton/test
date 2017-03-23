#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<snakewindow.h>
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_name_field_returnPressed();

    void on_Name_Ok_Btn_clicked();

    void on_exit_application_Btn_clicked();


private:
    Ui::MainWindow *ui;
    QString name;
    SnakeWindow *snakeWindow;

};

#endif // MAINWINDOW_H
