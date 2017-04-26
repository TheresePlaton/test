#include "green_powerup.h"


Green_powerup::Green_powerup()
{
    Consumable();
    counterMax=11;
    setcolor(":/images/resourses/images/glowing_green/green0.png");
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



