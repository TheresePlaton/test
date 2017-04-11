#include "powerup.h"
//#include <QGlobal.h>
#include <QtGlobal>
#include <QTime>
#include <QDebug>

PowerUp::PowerUp(QGraphicsItem *parent)
{
    QTime time = QTime::currentTime();
    qsrand((uint)time.msec());
    //setting random coordinates for new power up
    int width = 600;
    int height = 400;

    int NX = width / 20;
    int NY = height / 20;

    int _rx = qrand() % (NX + 1) * 20;
    int _ry = qrand() % (NY + 1) * 20;

    restX = _rx;
    restY = _ry;
    setRect(restX,restY, 20,20);
    //graphical properties of rect
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::red);
    setBrush(brush);
}

bool PowerUp::getConsumed() const
{
    return consumed;
}

void PowerUp::setConsumed(bool value)
{
    consumed = value;
}

int PowerUp::getX()
{
    return restX;
}

int PowerUp::getY()
{
    return restY;
}
