#ifndef RED_POWERUP_H
#define RED_POWERUP_H

#include "Consumable.h"
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QList>
#include <QTime>
#include <QDebug>
#include <QtGlobal>

/**
 * @brief The Red_powerup class is subclass of consumable class
 */
class Red_powerup: public Consumable
{
    Q_OBJECT
public:
    Red_powerup();
    //gets the value of consumed bool for collistion testing purposes

    bool getConsumed() const;
    //set the value of consumed bool for collision testing purposes
    void setConsumed(bool value);

    //set value of consumed. extends snake with powerup pixmap. deletes
    //current power-up
    void isEaten(Snake &snake);

    //position getters
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
