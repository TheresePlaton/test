#include "Consumable.h"
#include <QDebug>



Consumable::Consumable()
{
    QTime time = QTime::currentTime();
    qsrand((uint)time.msec());
    //setting random coordinates for new power up
    int width = 520;
    int height = 320;

    int NX = width / 20;
    int NY = height / 20;

    int _rx = ((NX+qrand()) % (NX)) * 20;
    int _ry = ((NY+qrand()) % (NY)) * 20;

    restX = _rx;
    restY = _ry;
}

bool Consumable::getConsumed() const
{
    return consumed;
}

void Consumable::setConsumed(bool value)
{
    consumed = value;
}

int Consumable::getX() const
{
    return restX;
}

int Consumable::getY() const
{
    return restY;
}

void Consumable::animationCounter()
{
    animCounter++;
    if(animCounter>=counterMax)
    {
        animCounter=0;
    }

    powerUpPixMap = powerUpImageList[animCounter];
    setPixmap(*powerUpPixMap);
}

QRectF Consumable::testRect() const
{
     int x=getX();
     int y=getY();
     int w=pixmap().width();
     int h=pixmap().height();

     return QRectF(x,y,w,h);
}
void Consumable::isEaten()
{
    consumed=true;


}
QString Consumable::getcolor(){
    return color;
}
void Consumable::setcolor(QString c){
    color=c;
}
