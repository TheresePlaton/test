#ifndef SNAKEWINDOW_H
#define SNAKEWINDOW_H
#include <QKeyEvent>
#include <QMainWindow>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QObject>
#include <QTimer>
#include <QColor>
#include <QBrush>
#include "snake.h"
#include "powerup.h"
#include "ui_gameover.h"
#include "gameover.h"

class QGraphicsScene;
class Snake;
class QKeyEvent;

namespace Ui {
class SnakeWindow;
}

class SnakeWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SnakeWindow(QWidget *parent = 0);
    ~SnakeWindow();
    void gameOver();


public slots:
    void gameLoop();
    bool getCrashed();

private slots:
    void on_exit_Game_Btn_clicked();

    void on_pause_Game_Btn_clicked();

    void on_start_Game_Btn_clicked();

    void handleKeyPressed(QKeyEvent *event);
protected:
     bool eventFilter(QObject *object, QEvent *event);


private:
    Ui::SnakeWindow *ui;
    QGraphicsScene *scene;
    Snake *shead;
    BodyOfSnake *body;
    QTimer *gameStart = new QTimer();
    GameOver *gameOverWindow;
    bool isDead = false;
};

#endif // SNAKEWINDOW_H
