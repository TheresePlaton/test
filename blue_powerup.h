#ifndef BLUE_POWERUP_H
#define BLUE_POWERUP_H


#include "Consumable.h"
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QList>
#include <QTime>
#include <QDebug>
#include <QtGlobal>

class Blue_powerup: public Consumable
{
    Q_OBJECT
public:
    Blue_powerup();
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

#endif // BLUE_POWERUP_H
