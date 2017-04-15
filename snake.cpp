#include "snake.h"
#include "snakewindow.h"
#include <QTimer>
#include <QDebug>
#include <QObject>
#include <typeinfo>
#include "gameover.h"
#include "ui_gameover.h"
#include <QMediaPlayer>
#include <QPainter>
#include "Green_powerup.h"
#include <QGraphicsItem>



extern SnakeWindow *snakeWindow;



Snake::Snake(QGraphicsScene &scene, QObject *parent) :
    QObject(parent),
    scene(scene)
{
    snakeHeadImage = new QPixmap(":/images/resourses/images/head.png");
    setPixmap(*snakeHeadImage);
    setPos(60,40);

    //set snake head rect focusable
    setFlag(QGraphicsItem::ItemIsFocusable, true);

    //sets default direction
    movingDirection = Stop;

}

Consumable* Snake::setPowerUp(int choice)
{
    Consumable *consumablePowerUp;
    if(choice==1)
    {
        consumablePowerUp = new Green_Powerup();
    }
    if(choice==2)
    {
        consumablePowerUp = new Red_powerup();
    }
    return consumablePowerUp;

}


QRectF Snake::testRect() const
{
    int x=this->x();
    int y=this->y();
    int w=pixmap().width();
    int h=pixmap().height();

    return QRectF(x,y,w,h);
}

bool Snake::collidesWithPwrUp(Consumable *p)
{

    for(int i=0; i<bodies.length(); i++)
    {
        if(bodies[i]->testRect().intersects(p->testRect()))
        {
            return true;
        }
    }

    if(this->testRect().intersects(p->testRect()))
    {
        return true;
    }
    return false;
}

/**
     * @brief Snake::setDirection direction check and set according to basic snake rools
     * @param dir
     */
void Snake::setDirection(Direction dir)
{
    switch (dir) {
    case Up:
        if(movingDirection!=Up && movingDirection!=Down)
        {
            movingDirection=Up;
            snakeHeadImage = new QPixmap(":/images/resourses/images/headUp.png");
            this->setPixmap(*snakeHeadImage);
        }
        break;
    case Down:
        if(movingDirection!=Down && movingDirection!=Up)
        {
            movingDirection=Down;
            snakeHeadImage = new QPixmap(":/images/resourses/images/headDown.png");
            this->setPixmap(*snakeHeadImage);
        }
        break;
    case Left:
        if(movingDirection!=Left && movingDirection!=Right)
        {
            movingDirection=Left;
            snakeHeadImage = new QPixmap(":/images/resourses/images/headLeft.png");
            this->setPixmap(*snakeHeadImage);
        }
        break;
    case Right:
        if(movingDirection!=Right && movingDirection!=Left)
        {
            movingDirection=Right;
            snakeHeadImage = new QPixmap(":/images/resourses/images/head.png");
            this->setPixmap(*snakeHeadImage);
        }
        break;
    default: break;

    }
}

void Snake::extendSnake(QString pathToBodyImage)
{
    BodyOfSnake *ext = new BodyOfSnake(pathToBodyImage);
    bodies.prepend(ext);
    ext->setPos(this->x(),this->y());
    scene.addItem(ext);
}

void Snake::appendBodies(BodyOfSnake &abody)
{
    bodies.append(&abody);
}


int Snake::getSnakeLength()
{
    //qDebug() << bodies.size()+1;
    return bodies.size()+1;
}

void Snake::getDir()
{
    qDebug()<<movingDirection;
}

bool Snake::getHead_in_tail()
{
    return head_in_tail;
}

int Snake::getGameScore()
{
    return gameScore;
}

/**
     * @brief Snake::move
     */
void Snake::move()
{


    //updates last position of head to pass to tail
    lastPosition = pos();
    //qDebug()<<lastPosition;
    //dx, dy to move snake object by n pixels in needed direction
    int dx, dy;

    //NB 0,0 location is upper left corner
    switch(movingDirection){
    case Up: dx=0, dy=-20; break;
    case Down: dx=0, dy=20; break;
    case Right: dx=20, dy=0; break;
    case Left: dx=-20, dy=0; break;
    case Stop: dx=0, dy=0; break;
    }


    if(movingDirection!=Stop)
    {
        //sets new position of the sneak head.
        setPos(x()+dx, y()+dy);
    }

    //moves bodies inside of the array
    for (int i = 0, n = bodies.size()-1; i < n; ++i){
        bodies[i]->setPos(bodies[i+1]->pos());
    }



    // move front body part to previous position of head
    if(this->movingDirection!=Stop){
        bodies.last()->setPos(lastPosition);
    }

    //Implements collision test.
    QList<QGraphicsItem*> list = collidingItems();
    //qDebug()<<"Type of snake: "<<typeid(*this).name();
    for(int i=0, n =list.size(); i<n; i++)
    {
        qDebug() << typeid(list[i]).name();


        /** Will return nullptr if cannot cast to consumable*
             * Otherwise ptr to the consumable
             * Allows for the if test below
             * */
        Consumable* p =  dynamic_cast<Consumable*>(list[i]);

        if(p)
        {
            /**
                 * @brief checks whether snake collides with power up
                 * and removes power up if collision occures.
                 * Removal only occurs when consumed sets to true due
                 * to first collison.
                 */

            if(p->getConsumed() == false && p->boundingRect().intersects(this->boundingRect()))
            {
                powerUpSound = new QMediaPlayer();
                powerUpSound->setMedia(QUrl("qrc:/sounds/resourses/sounds/157217__adamweeden__video-game-gain-xp-level-up.flac"));
                powerUpSound->play();
                qDebug()<<"Crash!";
                qDebug()<<p->getX();
                qDebug()<<p->getY();
                gameScore=gameScore+10;

                scene.removeItem(p);
                p->isEaten(*this);
                qDebug()<<(int*)p;

                continue;
            }
        }

        if(this->boundingRect().intersects(list[i]->boundingRect()))
        {
            head_in_tail=true;
            qDebug()<<"head crashed in tail";
            qDebug()<<head_in_tail;
        }


    }

}
