/**
 *This class is meant to create objects that can be used as snake body
*/
#ifndef BODYOFSNAKE_H
#define BODYOFSNAKE_H
#include <QGraphicsRectItem>
#include <QBrush>


class BodyOfSnake : public QGraphicsRectItem
{

public:
    /**
     * @brief BodyOfSnake this constructor creates a rectangle that can be used as a body part/parts
     * @param parent
     */
    BodyOfSnake(QGraphicsItem *parent = NULL);

    BodyOfSnake(int x, int y);
};

#endif // BODYOFSNAKE_H
