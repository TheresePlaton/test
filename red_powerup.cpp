#include "red_powerup.h"
#include "snake.h"

Red_powerup::Red_powerup()
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


    powerUpImageList.append(new QPixmap(":/images/resourses/images/glowing_red/rp1.png"));
    powerUpImageList.append(new QPixmap(":/images/resourses/images/glowing_red/rp2.png"));
    powerUpImageList.append(new QPixmap(":/images/resourses/images/glowing_red/rp3.png"));
    powerUpImageList.append(new QPixmap(":/images/resourses/images/glowing_red/rp4.png"));
    powerUpImageList.append(new QPixmap(":/images/resourses/images/glowing_red/rp5.png"));
    powerUpImageList.append(new QPixmap(":/images/resourses/images/glowing_red/rp6.png"));
    powerUpImageList.append(new QPixmap(":/images/resourses/images/glowing_red/rp7.png"));
    powerUpImageList.append(new QPixmap(":/images/resourses/images/glowing_red/rp8.png"));

    connect(pixMapTimer, SIGNAL(timeout()), this, SLOT(animationCounter()));
    pixMapTimer->start(150);

    powerUpPixMap = powerUpImageList[0];
    setPixmap(*powerUpPixMap);
    setPos(restX,restY);

}

bool Red_powerup::getConsumed() const
{
    return consumed;
}

void Red_powerup::setConsumed(bool value)
{
    consumed = value;
}

void Red_powerup::isEaten(Snake &snake)
{
    consumed=true;
    snake.extendSnake(":/images/resourses/images/glowing_red/rp1.png");
    delete this;
}

int Red_powerup::getX() const
{
    return restX;
}

int Red_powerup::getY() const
{
    return restY;
}

void Red_powerup::animationCounter()
{
    animCounter++;
    if(animCounter>=7)
    {
        animCounter=0;
    }

    powerUpPixMap = powerUpImageList[animCounter];
    setPixmap(*powerUpPixMap);
}
