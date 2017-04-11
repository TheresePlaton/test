#include "gameover.h"
#include "ui_gameover.h"
#include "snakewindow.h"
#include "ui_snakewindow.h"

/**
 * @brief GameOver::GameOver
 * @param parent
 */
GameOver::GameOver(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GameOver)
{
    ui->setupUi(this);
}
/**
 * @brief GameOver::~GameOver
 */
GameOver::~GameOver()
{
    delete ui;
}
/**
 * @brief GameOver::on_retry_btn_clicked
 *
 * user can choose to start a new game, after gameover
 */
void GameOver::on_retry_btn_clicked()
{
    SnakeWindow *retryGame;
    retryGame = new SnakeWindow();
    this->hide();
    retryGame->show();
}
/**
 * @brief GameOver::on_exit_game_Btn_clicked
 * user can choose to exit the game
 */
void GameOver::on_exit_game_Btn_clicked()
{
    this->close();
}
