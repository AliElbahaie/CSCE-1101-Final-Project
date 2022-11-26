#include "health.h"

Health::Health(QGraphicsPixmapItem* parent) : QGraphicsPixmapItem(parent)
{
    hp = 3;
    QPixmap hpfullIMG(":/Images/hearts3.jpg");
    hpfullIMG = hpfullIMG.scaledToWidth(150);
    hpfullIMG = hpfullIMG.scaledToHeight(50);
    setPixmap(QPixmap(hpfullIMG));
}

void Health::displayHealth(int lives)
{
    hp = lives;
    if (hp == 3)
    {
        QPixmap hpfullIMG(":/Images/hearts3.jpg");
        hpfullIMG = hpfullIMG.scaledToWidth(150);
        hpfullIMG = hpfullIMG.scaledToHeight(50);
        setPixmap(QPixmap(hpfullIMG));
    }
    else if (hp == 2)
    {
        QPixmap hpTwoIMG(":/Images/hearts2.jpg");
        hpTwoIMG = hpTwoIMG.scaledToWidth(150);
        hpTwoIMG = hpTwoIMG.scaledToHeight(50);
        setPixmap(QPixmap(hpTwoIMG));
    }
    else if (hp == 1)
    {
        QPixmap hpOneIMG(":/Images/hearts1.jpg");
        hpOneIMG = hpOneIMG.scaledToWidth(150);
        hpOneIMG = hpOneIMG.scaledToHeight(50);
        setPixmap(QPixmap(hpOneIMG));
    }
}

int Health::gethealth()
{
    return hp;
}
