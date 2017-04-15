#include "wall_brick.h"


Wall_brick::Wall_brick(QGraphicsItem *parent)
{
     setPixmap(QPixmap(":/images/resourses/images/brick.png"));
     setPos(50,50);
}

Wall_brick::Wall_brick(int x, int y)
{
    setPixmap(QPixmap(":/images/resourses/images/brick.png"));
    setPos(x,y);
}

QRectF Wall_brick::testRect() const
{
    int x=this->x();
    int y=this->y();
    int w=pixmap().width();
    int h=pixmap().height();

    return QRectF(x,y,w,h);
}
