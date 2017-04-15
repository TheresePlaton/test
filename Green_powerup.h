#ifndef GREEN_POWERUP_H
#define GREEN_POWERUP_H

#include "Consumable.h"
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QList>
#include <QTime>
#include <QDebug>
#include <QtGlobal>

/**
 * @brief The Green_Powerup class subclass of Consumable
 */
class Green_Powerup: public Consumable
{
    Q_OBJECT
public:
    Green_Powerup();
    //gets the value of consumed bool for collistion testing purposes
    bool getConsumed() const;

    //sets the value of consumed bool for collistion testing purposes
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

#endif // GREEN_POWERUP_H
