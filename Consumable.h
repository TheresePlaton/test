#ifndef CONSUMABLE_H
#define CONSUMABLE_H
#include <QObject>
#include <QBrush>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QList>
#include <QTime>
#include <QDebug>
#include <QtGlobal>

/**
 * @brief The Consumable class is a super class for all consumable powerUps
 */
class Consumable :public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Consumable();
    QTimer *pixMapTimer = new QTimer();
    QPixmap *powerUpPixMap;
    QList<QPixmap*> powerUpImageList;
    int animCounter=0;
    int increment = 0;
    int getX() const;
    int getY() const;
    QRectF testRect() const;
    void isEaten();
    QString getcolor();
    void setcolor(QString);
    
protected:
    bool consumed = false;
    int randomX;
    int randomY;
    int restX;
    int restY;
    int counterMax;
private:
    QString color;

public slots:
    void animationCounter();
    bool getConsumed() const;
    void setConsumed(bool value);

};

#endif // CONSUMABLE_H
