#ifndef SNAKEWINDOW_H
#define SNAKEWINDOW_H
#include <QObject>
#include <QColor>
#include <QKeyEvent>
#include <QMainWindow>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QTimer>
#include <QBrush>
#include <QtGlobal>
#include <QTime>
#include "map.h"
#include <QtCore>
#include <QtGui>
#include <QEvent>
#include <QString>
#include <QMediaPlayer>
#include <QImage>
#include <QMediaPlaylist>
#include <QMessageBox>
#include "green_powerup.h"
#include "Consumable.h"
#include "wall_brick.h"
#include "snake.h"
#include "gameover.h"


class QGraphicsScene;
class Snake;
class QKeyEvent;

namespace Ui {
class SnakeWindow;
}
/**
 * @brief The SnakeWindow class is main game class that creates game scene and
 * draws all objects of the game on it.
 */
class SnakeWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SnakeWindow(QWidget *parent = 0);
    ~SnakeWindow();
    void gameOver();
    bool powerUpIntersects(Consumable *cons, Map *map);
    void startNewLevel();


public slots:
    /**
     * @brief gameLoop runs logic of the snake.cpp class and creates new power ups
     * when existing is eaten
     */
    void gameLoop();
    /**
     * @brief getCrashed returns true if snake crashes, is used for game over logic
     * @return
     */
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
    bool isDead = false;
    QMediaPlayer * music;
    bool gameIsPaused=false;
    bool gameIsStarted=false;
    Consumable *pUp;
    Map level;
    int lvl=0;
    int totalScore=0;
    void pause();
    void start();
};

#endif // SNAKEWINDOW_H
