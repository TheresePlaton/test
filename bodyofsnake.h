/**
 *This class is meant to create objects that can be used as snake body
*/
#ifndef BODYOFSNAKE_H
#define BODYOFSNAKE_H
#include <QGraphicsRectItem>
#include <QBrush>
#include <QGraphicsPixmapItem>


class BodyOfSnake : public QGraphicsPixmapItem
{

public:
    /**
     * @brief BodyOfSnake this constructor creates a body part
     * @param parent
     */
    BodyOfSnake(QGraphicsItem *parent = NULL);

    /**
     * @brief BodyOfSnake creates body part at x,y
     * @param x
     * @param y
     */
    BodyOfSnake(int x, int y);

    /**
     * @brief BodyOfSnake creates bodypart with custom pixmap
     * @param pixMapPath
     */
    BodyOfSnake(QString pixMapPath);

    /**
     * @brief testRect this creates a QRectF for collision purposes and is used
     * instead of native QT boundingRect(). boundingRect() always starts at 0,0
     * when created, which limits its use here.
     * @return
     */
    QRectF testRect() const;


private:
    QPixmap *bodyImage;
};

#endif // BODYOFSNAKE_H
