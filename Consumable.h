#ifndef CONSUMABLE_H
#define CONSUMABLE_H

#include <QObject>
#include <QGraphicsRectItem>
#include <QBrush>
#include <QTimer>
//#include "snake.h"
#include <QGraphicsPixmapItem>

class Snake;

/**
 * @brief The Consumable class is a super class for all consumable powerUps
 */
class Consumable : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Consumable(QGraphicsItem *parent=NULL);


    virtual bool getConsumed() const = 0;
    virtual void setConsumed(bool value);
    /**
     * @brief isEaten sets consumed to true
     * @param snake
     */
    virtual void isEaten(Snake &snake);

    /**
     * @brief getX, getY, getters for coordinates
     * @return
     */
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
