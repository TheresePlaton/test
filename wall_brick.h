#ifndef WALL_BRICK_H
#define WALL_BRICK_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QBrush>
#include <QDebug>


class Wall_brick:public QObject, public QGraphicsPixmapItem
{
public:
    Wall_brick(QGraphicsItem *parent=NULL);
    Wall_brick(int x, int y);
};

#endif // WALL_BRICK_H
