#ifndef RED_POWERUP_H
#define RED_POWERUP_H

#include "Consumable.h"
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QList>
#include <QTime>
#include <QDebug>
#include <QtGlobal>

class Red_powerup: public Consumable
{
    Q_OBJECT
public:
    Red_powerup();
    bool getConsumed() const;
    void setConsumed(bool value);
    void isEaten(Snake &snake);


    int getX() const override;
    int getY() const override;
private:
    QTimer *pixMapTimer = new QTimer();
    QPixmap *powerUpPixMap;
    QList<QPixmap*> powerUpImageList;
    int animCounter=0;
    int increment = 0;
public slots:
    void animationCounter();

};

#endif // RED_POWERUP_H
