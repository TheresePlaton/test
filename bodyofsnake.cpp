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

}

BodyOfSnake::BodyOfSnake(QString pixMapPath)
{
    bodyImage = new QPixmap(pixMapPath);
    setPixmap(*bodyImage);
    setPos(0,0);
}

QRectF BodyOfSnake::testRect() const
{
    int x=this->x();
    int y=this->y();
    int w=pixmap().width();
    int h=pixmap().height();

    return QRectF(x,y,w,h);
}
