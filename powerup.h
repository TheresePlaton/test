#ifndef POWERUP_H
#define POWERUP_H
#include <QObject>
#include <QGraphicsRectItem>
#include <QBrush>
#include <QGraphicsPixmapItem>
#include <QTimer>

class PowerUp : public QGraphicsPixmapItem
{
public:
    PowerUp(QGraphicsItem *parent=NULL);

    bool getConsumed() const;
    void setConsumed(bool value);

    int getX();
    int getY();

private:
    bool consumed = false;
    int randomX;
    int randomY;
    int restX;
    int restY;
    QTimer *pixMapTimer;

};

#endif // POWERUP_H
