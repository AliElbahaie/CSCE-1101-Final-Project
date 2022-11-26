#ifndef BULLET_H
#define BULLET_H

#include <QMainWindow>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <time.h>
#include <QtCore>
#include <QTimer>
#include "enemy.h"

class bullet:public QObject, public QGraphicsPixmapItem
{
private:

    int board[15][15];
    int rows, columns;
public:

    bullet(int boarddata[15][15], int,int);



};

#endif // HEART_H
