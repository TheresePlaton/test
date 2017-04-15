#include "blue_powerup.h"
#include "snake.h"

Blue_powerup::Blue_powerup()
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


    powerUpImageList.append(new QPixmap(":/images/resourses/images/glowing_blue/blu0.png"));
    powerUpImageList.append(new QPixmap(":/images/resourses/images/glowing_blue/blu1.png"));
    powerUpImageList.append(new QPixmap(":/images/resourses/images/glowing_blue/blu2.png"));
    powerUpImageList.append(new QPixmap(":/images/resourses/images/glowing_blue/blu3.png"));
    powerUpImageList.append(new QPixmap(":/images/resourses/images/glowing_blue/blu4.png"));
    powerUpImageList.append(new QPixmap(":/images/resourses/images/glowing_blue/blu5.png"));
    powerUpImageList.append(new QPixmap(":/images/resourses/images/glowing_blue/blu6.png"));
    powerUpImageList.append(new QPixmap(":/images/resourses/images/glowing_blue/blu7.png"));
    powerUpImageList.append(new QPixmap(":/images/resourses/images/glowing_blue/blu8.png"));
    powerUpImageList.append(new QPixmap(":/images/resourses/images/glowing_blue/blu9.png"));
    powerUpImageList.append(new QPixmap(":/images/resourses/images/glowing_blue/blu10.png"));
    powerUpImageList.append(new QPixmap(":/images/resourses/images/glowing_blue/blu11.png"));

    connect(pixMapTimer, SIGNAL(timeout()), this, SLOT(animationCounter()));
    pixMapTimer->start(200);

    powerUpPixMap = powerUpImageList[0];
    setPixmap(*powerUpPixMap);
    setPos(restX,restY);
}

bool Blue_powerup::getConsumed() const
{
    return consumed;
}

void Blue_powerup::setConsumed(bool value)
{
    consumed = value;
}

void Blue_powerup::isEaten(Snake &snake)
{
    consumed=true;
    snake.extendSnake(":/images/resourses/images/glowing_blue/blu0.png");
}

int Blue_powerup::getX() const
{
    return restX;
}

int Blue_powerup::getY() const
{
    return restY;
}

void Blue_powerup::animationCounter()
{
    animCounter++;
    if(animCounter>=11)
    {
        animCounter=0;
    }

    powerUpPixMap = powerUpImageList[animCounter];
    setPixmap(*powerUpPixMap);
}
