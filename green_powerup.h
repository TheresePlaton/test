#ifndef GREEN_POWERUP_H
#define GREEN_POWERUP_H
#include "Consumable.h"


class Green_powerup: public Consumable
{
    Q_OBJECT
public:
    explicit Green_powerup();

private:
    QString color=":/images/resourses/images/glowing_green/green0.png";


};
#endif // GREEN_POWERUP_H

