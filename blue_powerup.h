#ifndef BLUE_POWERUP_H
#define BLUE_POWERUP_H
#include "Consumable.h"


class Blue_powerup: public Consumable
{
    Q_OBJECT
public:
    explicit Blue_powerup();

private:
    QString color=":/images/resourses/images/glowing_green/green0.png";


};

#endif // BLUE_POWERUP_H
