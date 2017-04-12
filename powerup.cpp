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

    setPixmap(QPixmap(":/images/resourses/images/smiley-face-png-003.png"));
    setPos(restX, restY);

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
