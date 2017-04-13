#ifndef POWERUP_H
#define POWERUP_H
#include <QObject>
#include <QGraphicsRectItem>
#include <QBrush>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QList>

class PowerUp : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    PowerUp(QGraphicsItem *parent=NULL);

    bool getConsumed() const;
    void setConsumed(bool value);

    int getX();
    int getY();
public slots:
    void animationCounter();

private:
    bool consumed = false;
    int randomX;
    int randomY;
    int restX;
    int restY;
    QTimer *pixMapTimer = new QTimer();
    QPixmap *powerUpPixMap;
    QList<QPixmap*> powerUpImageList;
    int animCounter=0;
    int increment = 0;

};

#endif // POWERUP_H
