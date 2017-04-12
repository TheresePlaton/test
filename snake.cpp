#include "snake.h"
#include "snakewindow.h"
#include <QTimer>
#include <QDebug>
#include <QObject>
#include <typeinfo>
#include <powerup.h>
#include "gameover.h"
#include "ui_gameover.h"
#include <QMediaPlayer>



extern SnakeWindow *snakeWindow;


Snake::Snake(QGraphicsScene &scene, QObject *parent) :
    QObject(parent),
    scene(scene)
{

//  setPixmap(QPixmap(":/images/resourses/images/head.png"));
//  setPos(0,0);
    setRect(0,0,20,20);
    QBrush brush;
    //sets color and solid for head of snake
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::green);
    setBrush(brush);

    //set snake head rect focusable
    setFlag(QGraphicsItem::ItemIsFocusable, true);

    //sets default direction
    movingDirection = Stop;

}



/**
 * @brief Snake::setDirection direction check and set according to basic snake rools
 * @param dir
 */
void Snake::setDirection(Direction dir)
{
    switch (dir) {
    case Up:
        if(movingDirection!=Up && movingDirection!=Down) movingDirection=Up;
        break;
    case Down:
        if(movingDirection!=Down && movingDirection!=Up) movingDirection=Down;
        break;
    case Left:
        if(movingDirection!=Left && movingDirection!=Right) movingDirection=Left;
        break;
    case Right:
        if(movingDirection!=Right && movingDirection!=Left) movingDirection=Right;
        break;
    default: break;

    }
}

void Snake::extendSnake()
{
    BodyOfSnake *ext = new BodyOfSnake();
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
        //qDebug() << typeid(*list[i]).name();
        if(typeid(*list[i])==typeid(PowerUp))
        {
            /**
             * @brief checks whether snake collides with power up
             * and removes power up if collision occures.
             * Removal only occurs when consumed sets to true due
             * to first collison.
             */
            PowerUp* p = (PowerUp*) list[i];
            if(p->getConsumed() == false && p->getX()==this->x() &&p->getY()==this->y() ) {

                powerUpSound = new QMediaPlayer();
                powerUpSound->setMedia(QUrl("qrc:/sounds/resourses/sounds/157217__adamweeden__video-game-gain-xp-level-up.flac"));
                powerUpSound->play();
                qDebug()<<"Crash!";
                qDebug()<<p->getX();
                qDebug()<<p->getY();
                gameScore=gameScore+10;

                p->setConsumed(true);
                extendSnake();
                delete p;
                PowerUp *p = new PowerUp();
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
