#include "enemy.h"
#include <QtCore>
#include <QTimer>
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QBrush>
#include <QFile>
#include <QTextStream>
#include <QGraphicsPixmapItem>

enemy::enemy(int dataitem[15][15], int r, int c)
{
    row = r;
    column = c;

    QPixmap e(":/Images/police enemy.png");
    e = e.scaledToWidth(50);
    e = e.scaledToHeight(50);
    setPixmap(e);
    setPos(50 + 50 * column, 50 + 50 * row);
    for (int i = 0; i < 15; i++)
        for (int j = 0; j < 15; j++)
            data[i][j] = dataitem[i][j];
    MyTimer();
}



void enemy::MyTimer()
{
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(MySlot()));
    if (health > 0)
    {
        timer->start(300);
    }

    col = new QTimer(this);
    connect(col, SIGNAL(timeout()), this, SLOT(collision()));
    if (health > 0) {
        col->start(100);
    }

}

void enemy::move()
{
    qDebug() << "up val: " << data[row - 1][column];
    if (data[row - 1][column] == -1)
    {
        up = false;
    }
    if (data[row + 1][column] == -1)
    {
        down = false;
    }
    if (data[row][column - 1] == -1)
    {
        left = false;
    }
    if (data[row][column + 1] == -1)
    {
        right = false;
    }
    if (!right && !left && !up && !down)
    {
        direction = wasd[rand() % 4];
        if (((direction == 'w' && !(data[row - 1][column] == -1)) || (direction == 's' && !(data[row + 1][column] == -1)) || (direction == 'a' && !(data[row][column - 1] == -1)) || (direction == 'd' && !((data[row][column + 1] == -1)))))
        {
            switch (direction)
            {
            case 'w':
                up = true;
                break;
            case 'a':
                left = true;
                break;
            case 's':
                down = true;
                break;
            case 'd':
                right = true;
                break;
            }
        }
    }
    if (up)
    {
        row--;
    }
    if (down)
    {
        row++;
    }
    if (left)
    {
        column--;
    }
    if (right)
    {
        column++;
    }
    setPos(50 + 50 * column, 50 + 50 * row);
}
void enemy::MySlot()
{
    if (health > 0)
    {
        direction = wasd[rand() % 4];
        if (direction == 'w' && data[row - 1][column] != -1 && data[row - 1][column] != -77 && data[row - 1][column] != -10 && data[row - 1][column] != -11 && data[row - 1][column] != -8 && data[row - 1][column] != -9)
        {
            row--;
        }
        if (direction == 's' && data[row + 1][column] != -1 && data[row + 1][column] != -10 && data[row + 1][column] != -11 && data[row + 1][column] != -8 && data[row + 1][column] != -9)
        {
            row++;
        }
        if (direction == 'a' && data[row][column - 1] != -1 && data[row][column - 1] != -77 && data[row][column - 1] != -10 && data[row][column - 1] != -11 && data[row][column - 1] != -4 && data[row][column - 1] != -9 && data[row][column - 1] != -8)
        {
            column--;
        }
        if (direction == 'd' && data[row][column + 1] != -1 && data[row][column + 1] != -11 && data[row][column + 1] != -10 && data[row][column + 1] != -2 && data[row][column + 1] != -4 && data[row][column + 1] != -8 && data[row][column + 1] != -9)
        {
            column++;
        }
        setPos(50 + 50 * column, 50 + 50 * row);
    }
}

int enemy::getHealth()
{
    return health;
}

void enemy::setHealt(int h)
{
    health = h;
}

