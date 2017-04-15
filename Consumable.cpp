#include "Consumable.h"
#include <QDebug>



Consumable::Consumable(QGraphicsItem *parent)
{

}

void Consumable::setConsumed(bool value)
{

}

void Consumable::isEaten(Snake &snake)
{

}

QRectF Consumable::testRect() const
{
     int x=getX();
     int y=getY();
     int w=pixmap().width();
     int h=pixmap().height();

     return QRectF(x,y,w,h);
}

