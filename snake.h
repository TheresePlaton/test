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
#include <QTime>
#include <QtGlobal>
#include "Green_powerup.h"
#include "red_powerup.h"

/**
 * Snake class used to created the head of the snake as well as implement
 * movement methods and other snake related logic
 */

#include <QObject>
#include "bodyofsnake.h"

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
    /**
     * @brief testRect replacement lofic for native boundingRect()
     * for collision testing
     * @return
     */
    QRectF testRect() const;

    /**
     * @brief collidesWithPwrUp test whether or not new power up collides with
     * either head or body of snake on creation. If true, tries to create a new
     * power up that is not located on existing snake parts.
     * @param p
     * @return
     */
    bool collidesWithPwrUp(Consumable *p);


    Snake(QGraphicsScene &scene, QObject *parent = 0);

    /**
     * @brief setPowerUp "rolls" for new power up
     * @param choice
     * @return
     */
    Consumable* setPowerUp(int choice);

    //direction setter
    void setDirection(Direction dir);

    //snake extension on power-up
    void extendSnake(QString pathToBodyImage);
    /**
     * @brief appendBodies adds body object to the bodies QList
     * @param abody
     */
    void appendBodies(BodyOfSnake &abody);

    /**
     * @brief move move function that has neccessery commands to move the snake
     */
    void move();

    /**
     * @brief getSnakeLength returns snake length based on number of body parts
     * @return
     */
    int getSnakeLength();

    /**
     * @brief getDir direction getter for snake
     */
    void getDir();

    /**
     * @brief getHead_in_tail sets true if snake head crashes in it's tail
     * @return
     */
    bool getHead_in_tail();

    /**
     * @brief getGameScore returns game score based on number of collected power ups
     * @return
     */
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
    Consumable* p;

    QPixmap *snakeHeadImage;


public slots:


};
#endif
