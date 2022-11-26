#ifndef PELLET_H
#define PELLET_H

#include <QGraphicsPixmapItem>
#include <ctime>
#include <QDebug>

class Pellet : public QGraphicsPixmapItem
{
private:
    int board[15][15];
    int rows, columns;
public:
    Pellet(int boarddata[15][15]);
};

#endif
