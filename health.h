#ifndef HEALTH_H
#define HEALTH_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>

class Health : public QGraphicsPixmapItem
{
private:
    int hp;

public:
    Health(QGraphicsPixmapItem* parent = 0);
    void displayHealth(int lives);
    int gethealth();
};

#endif
