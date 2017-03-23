#include "bodyofsnake.h"

/**
 * @brief BodyOfSnake::BodyOfSnake just a rec drawing to be used as body part
 * @param parent
 */
BodyOfSnake::BodyOfSnake(QGraphicsItem *parent)
{
    //x,y, heigth, width
    setRect(0,0,20,20);

    //graphical properties of rect
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::blue);
    setBrush(brush);

}

BodyOfSnake::BodyOfSnake(int x, int y)
{
    setRect(x,y,20,20);

    //graphical properties of rect
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::blue);
    setBrush(brush);
}
