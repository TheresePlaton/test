#include "Green_powerup.h"
#include "snake.h"

Green_Powerup::Green_Powerup()
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


    powerUpImageList.append(new QPixmap(":/images/resourses/images/glowing_green/gg1.png"));
    powerUpImageList.append(new QPixmap(":/images/resourses/images/glowing_green/gg2.png"));
    powerUpImageList.append(new QPixmap(":/images/resourses/images/glowing_green/gg3.png"));
    powerUpImageList.append(new QPixmap(":/images/resourses/images/glowing_green/gg4.png"));

    connect(pixMapTimer, SIGNAL(timeout()), this, SLOT(animationCounter()));
    pixMapTimer->start(250);

    powerUpPixMap = powerUpImageList[0];
    setPixmap(*powerUpPixMap);
    setPos(restX,restY);


}

bool Green_Powerup::getConsumed() const
{
    return consumed;
}

void Green_Powerup::setConsumed(bool value)
{
    consumed = value;
}

void Green_Powerup::isEaten(Snake &snake)
{
    consumed=true;
    snake.extendSnake(":/images/resourses/images/glowing_green/gg1.png");

}

void Green_Powerup::animationCounter()
{
    if(animCounter>=3) increment = -1;
        if(animCounter ==0) increment = 1;
        //qDebug()<<animCounter<<"is current counter";
        animCounter+=increment;
        powerUpPixMap = powerUpImageList[animCounter];
        setPixmap(*powerUpPixMap);
}

int Green_Powerup::getX() const
{
 return restX;
}

int Green_Powerup::getY() const
{
    return restY;
}
