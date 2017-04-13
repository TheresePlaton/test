#ifndef SNAKE_H
#define SNAKE_H
#include <QBrush>
#include <QGraphicsRectItem>
#include <QGraphicsItem>
#include <QKeyEvent>
#include <QList>
#include <QPointF>
#include <QTimer>
#include <QMediaPlayer>
#include <QGraphicsPixmapItem>

/**
 * Snake class used to created the head of the snake as well as implement
 * movement methods.
 */

#include <QObject>
#include "bodyofsnake.h"
//#include "powerup.h"

class Snake : public QObject, public QGraphicsPixmapItem
{
Q_OBJECT

public:
    //enum for direction switching
    enum Direction{
        Up,
        Down,
        Left,
        Right,
        Stop
    };
    Snake(QGraphicsScene &scene, QObject *parent = 0);



    //direction setter
    void setDirection(Direction dir);

    //snake extension on power-up
    void extendSnake();
    /**
     * @brief appendBodies adds body object to the bodies QList
     * @param abody
     */
    void appendBodies(BodyOfSnake &abody);

    /**
     * @brief move move function that has neccessery commands to move the snake
     */
    void move();

    int getSnakeLength();

    void getDir();

    bool getHead_in_tail();

    int getGameScore();



private:
    //a variable that can stor an x,y coordiante for the object
    QPointF lastPosition;

    /**
     * @brief movingDirection property for the snake head
     */
    Direction movingDirection;
    /**
     * @brief bodies list to place snake parts in...
     */
    QList<BodyOfSnake*> bodies;
    QGraphicsScene &scene;
    bool head_in_tail = false;
    QMediaPlayer *powerUpSound;
    int gameScore=0;


    QPixmap *snakeHeadImage;


public slots:


};
#endif
