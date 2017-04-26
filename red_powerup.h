#ifndef RED_POWERUP_H
#define RED_POWERUP_H
#include "Consumable.h"


class Red_powerup: public Consumable
{
    Q_OBJECT
public:
    explicit Red_powerup();
private:
    QString color=":/images/resourses/images/glowing_red/rp1.png";

};
#endif // RED_POWERUP_H
