#ifndef GAMEOVER_H
#define GAMEOVER_H

#include <QDialog>

namespace Ui {
class GameOver;
}

class GameOver : public QDialog
{
    Q_OBJECT

public:
    explicit GameOver(QWidget *parent = 0);
    ~GameOver();

private slots:
    void on_retry_btn_clicked();

    void on_exit_game_Btn_clicked();

private:
    Ui::GameOver *ui;
};

#endif // GAMEOVER_H
