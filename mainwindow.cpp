#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
/**
 * @brief MainWindow::on_name_field_returnPressed
 */
void MainWindow::on_name_field_returnPressed()
{

}
/**
 * @brief MainWindow::on_Name_Ok_Btn_clicked
 *
 * Opens the snakeGameWindow
 */
void MainWindow::on_Name_Ok_Btn_clicked()
{
    snakeWindow= new SnakeWindow();
    this->hide();
    snakeWindow->show();
}
/**
 * @brief MainWindow::on_exit_application_Btn_clicked
 */
void MainWindow::on_exit_application_Btn_clicked()
{
    this->close();
}
