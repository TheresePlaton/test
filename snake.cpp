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
    setPos(0,0);


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
    qDebug() << bodies.size()+1;
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

            //Consumes the consumable, if not trap -> grows. If trap, shrinks
            if(p->getConsumed() == false && p->getX()==this->x() &&p->getY()==this->y() ) {

                powerUpSound = new QMediaPlayer();
                powerUpSound->setMedia(QUrl("qrc:/sounds/resourses/sounds/157217__adamweeden__video-game-gain-xp-level-up.flac"));
                powerUpSound->play();
                qDebug()<<"Crash!";
                qDebug()<<p->getX();
                qDebug()<<p->getY();
                gameScore=gameScore+10;

                p->isEaten(*this);

                QTime time = QTime::currentTime();
                qsrand((uint)time.msec());
                int high = 2;
                int low = 1;
                int choice = qrand() % ((high + 1)-low)+low;
                qDebug()<<choice<<"is random choise of powerup";

                //sets random new power up
                Consumable *p = setPowerUp(choice);

                scene.addItem(p);
                continue;
            }

        }
        //tests whether or not head crashed in tail
        if(this->x()==list[i]->x()&&this->y()==list[i]->y())
        {
            head_in_tail=true;
            qDebug()<<"head crashed in tail";
            qDebug()<<head_in_tail;
        }


    }

}
