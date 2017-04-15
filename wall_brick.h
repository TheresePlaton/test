#ifndef WALL_BRICK_H
#define WALL_BRICK_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QBrush>
#include <QDebug>

/**
 * @brief The Wall_brick class creates a wall object that is a
 * 40x40 QGraphicsPixmapItem
 */
class Wall_brick:public QObject, public QGraphicsPixmapItem
{
public:
    Wall_brick(QGraphicsItem *parent=NULL);
    Wall_brick(int x, int y);

    /**
     * @brief testRect substitution for the native boundingRect() functionality
     * @return
     */
    QRectF testRect() const;

};

#endif // WALL_BRICK_H
