#include "blue_powerup.h"

Blue_powerup::Blue_powerup()
{
     Consumable();
     counterMax=11;
     setcolor(":/images/resourses/images/glowing_blue/blu0.png");
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


