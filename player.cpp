#include "player.h"

Player::Player(int board[15][15], QApplication* c, Health* h2)
{
    QPixmap image(":/Images/gangsta.png");
    image = image.scaledToWidth(50);
    image = image.scaledToHeight(50);
    setPixmap(image);

    b = c;
    h1 = h2;

    rows = 7;
    columns = 7;
    setPos(51 + columns * 51, 50 + rows * 50);
    lives = 3;
    invincible = false;

    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 15; j++)
        {
            data[i][j] = board[i][j];
        }
    }
}

void Player::keyPressEvent(QKeyEvent* event)
{
    if (event->key() == Qt::Key_Up && data[rows - 1][columns] >= 0)
    {
        rows--;
    }
    else if (event->key() == Qt::Key_Down && data[rows + 1][columns] >= 0)
    {
        rows++;
    }
    else if (event->key() == Qt::Key_Right && data[rows][columns + 1] >= 0)
    {
        columns++;
    }
    else if (event->key() == Qt::Key_Left && data[rows][columns - 1] >= 0)
    {
        columns--;
    }
    setPos(51 + columns * 51, 50 + rows * 50);

    QList<QGraphicsItem*> items = collidingItems();
    for (int i = 0; i < items.size(); i++)
    {
        if (typeid(*items[i]) == typeid(Pellet))
        {
            if (invincible != true)
            {
                scene()->removeItem(items[i]);
                invincible = true;
                QTimer::singleShot(10000, this, SLOT(timeout_evet()));
            }
        }
        if (typeid(*items[i]) == typeid(bullet))
        {
            scene()->removeItem(items[i]);

        }
        if (typeid(*items[i]) == typeid(enemy))
        {
            if (invincible != true)
            {
                rows = 7;
                columns = 7;
                setPos(50 + columns * 50, 50 + rows * 50);
                lives--;
                h1->displayHealth(lives);
                if (lives == 0)
                {
                    b->exit();
                }
            }
        }
    }
}

void Player::timeout_evet()
{
    invincible = false;
}

