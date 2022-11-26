#ifndef PLAYER_H
#define PLAYER_H

#include <QApplication>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QList>
#include <QTimer>
#include "pellet.h"
#include "enemy.h"
#include "bullet.h"
#include "Health.h"
#include <QDebug>

class Player : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    int lives, rows, columns;
    int data[15][15];
    bool invincible;
    QApplication* b;
    Health* h1;

public:
    Player(int board[15][15], QApplication* c, Health* h2);

public slots:
    void keyPressEvent(QKeyEvent* event);

private slots:
    void timeout_evet();
};

#endif
