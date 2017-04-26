#include "red_powerup.h"


Red_powerup::Red_powerup()
{
    Consumable();
    setcolor(":/images/resourses/images/glowing_red/rp1.png");
    counterMax=7;
    powerUpImageList.append(new QPixmap(":/images/resourses/images/glowing_red/rp1.png"));
    powerUpImageList.append(new QPixmap(":/images/resourses/images/glowing_red/rp2.png"));
    powerUpImageList.append(new QPixmap(":/images/resourses/images/glowing_red/rp3.png"));
    powerUpImageList.append(new QPixmap(":/images/resourses/images/glowing_red/rp4.png"));
    powerUpImageList.append(new QPixmap(":/images/resourses/images/glowing_red/rp5.png"));
    powerUpImageList.append(new QPixmap(":/images/resourses/images/glowing_red/rp6.png"));
    powerUpImageList.append(new QPixmap(":/images/resourses/images/glowing_red/rp7.png"));
    powerUpImageList.append(new QPixmap(":/images/resourses/images/glowing_red/rp8.png"));

    connect(pixMapTimer, SIGNAL(timeout()), this, SLOT(animationCounter()));
    pixMapTimer->start(200);

    powerUpPixMap = powerUpImageList[0];
    setPixmap(*powerUpPixMap);
    setPos(restX,restY);

}


