#ifndef CONSUMABLE_H
#define CONSUMABLE_H

#include <QObject>
#include <QGraphicsRectItem>
#include <QBrush>
#include <QTimer>
//#include "snake.h"
#include <QGraphicsPixmapItem>

class Snake;

class Consumable : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Consumable(QGraphicsItem *parent=NULL);

    virtual bool getConsumed() const = 0;
    virtual void setConsumed(bool value);
    virtual void isEaten(Snake &snake);

    virtual int getX() const = 0;
    virtual int getY() const = 0;

    QRectF testRect() const;

protected:
    bool consumed = false;
    int randomX;
    int randomY;
    int restX;
    int restY;

};

#endif // CONSUMABLE_H
