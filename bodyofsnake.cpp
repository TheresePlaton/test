#include "bodyofsnake.h"

/**
 * @brief BodyOfSnake::BodyOfSnake just a rec drawing to be used as body part
 * @param parent
 */
BodyOfSnake::BodyOfSnake(QGraphicsItem *parent)
{
    bodyImage = new QPixmap(":/images/resourses/images/body_ball.png");
    setPixmap(*bodyImage);
    setPos(0,0);
    Q_UNUSED(parent);

}

BodyOfSnake::BodyOfSnake(int x, int y)
{
    bodyImage = new QPixmap(":/images/resourses/images/body_ball.png");
    setPixmap(*bodyImage);
    setPos(x,y);

//    setRect(x,y,20,20);

//    //graphical properties of rect
//    QBrush brush;
//    brush.setStyle(Qt::SolidPattern);
//    brush.setColor(Qt::blue);
//    setBrush(brush);
}
