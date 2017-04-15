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


    powerUpImageList.append(new QPixmap(":/images/resourses/images/glowing_green/green0.png"));
    powerUpImageList.append(new QPixmap(":/images/resourses/images/glowing_green/green1.png"));
    powerUpImageList.append(new QPixmap(":/images/resourses/images/glowing_green/green2.png"));
    powerUpImageList.append(new QPixmap(":/images/resourses/images/glowing_green/green3.png"));
    powerUpImageList.append(new QPixmap(":/images/resourses/images/glowing_green/green4.png"));
    powerUpImageList.append(new QPixmap(":/images/resourses/images/glowing_green/green5.png"));
    powerUpImageList.append(new QPixmap(":/images/resourses/images/glowing_green/green6.png"));
    powerUpImageList.append(new QPixmap(":/images/resourses/images/glowing_green/green7.png"));
    powerUpImageList.append(new QPixmap(":/images/resourses/images/glowing_green/green8.png"));
    powerUpImageList.append(new QPixmap(":/images/resourses/images/glowing_green/green9.png"));
    powerUpImageList.append(new QPixmap(":/images/resourses/images/glowing_green/green10.png"));
    powerUpImageList.append(new QPixmap(":/images/resourses/images/glowing_green/green11.png"));

    connect(pixMapTimer, SIGNAL(timeout()), this, SLOT(animationCounter()));
    pixMapTimer->start(200);

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
    snake.extendSnake(":/images/resourses/images/glowing_green/green0.png");

}

void Green_Powerup::animationCounter()
{
    animCounter++;
    if(animCounter>=11)
    {
        animCounter=0;
    }

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
