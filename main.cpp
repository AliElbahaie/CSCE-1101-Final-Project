#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QFile>
#include <QTextStream>
#include <QGraphicsPixmapItem>
#include <QGraphicsRectItem>
#include "pellet.h"
#include "player.h"
#include "health.h"

int main(int argc, char* argv[])
{
    srand(time(NULL));
    QApplication a(argc, argv);
    QGraphicsView view;
    QGraphicsScene scene;

    view.setFixedSize(820, 820);
    view.setWindowTitle("GTA");
    QBrush brush(Qt::darkBlue);
    view.setBackgroundBrush(brush);

    QFile file(":/Board/mapofgame.txt");
    file.open(QIODevice::ReadOnly);
    QTextStream stream(&file);

    int MapData[15][15];

    QString temp;
    for (int i = 0; i < 15; i++)
        for (int j = 0; j < 15; j++)
        {
            stream >> temp;
            MapData[i][j] = temp.toInt();
        }

    QPixmap stonesImage(":/Images/ground0003.jpg");
    stonesImage = stonesImage.scaledToWidth(50);
    stonesImage = stonesImage.scaledToHeight(50);

    QPixmap lavaImage(":/Images/lava0001.png");
    lavaImage = lavaImage.scaledToWidth(50);
    lavaImage = lavaImage.scaledToHeight(50);

    QPixmap home(":/Images/Home.jpg");
    home = home.scaledToWidth(50);
    home = home.scaledToHeight(50);

    QGraphicsPixmapItem Maparray[15][15];
    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 15; j++)
        {
            if (i == 7 && j == 7)
            {
                Maparray[i][j].setPixmap(home);
            }
            else if (MapData[i][j] == -1)
            {
                Maparray[i][j].setPixmap(lavaImage);
            }
            else
            {
                Maparray[i][j].setPixmap(stonesImage);
            }

            Maparray[i][j].setPos(50 + j * 50, 50 + i * 50);

            scene.addItem(&Maparray[i][j]);
        }
    }

    Health health = new Health();
    scene.addItem(&health);

    Player Franklin(MapData, &a, &health);
    scene.addItem(&Franklin);

    Pellet armor1(MapData);
    scene.addItem(&armor1);
    Pellet armor2(MapData);
    scene.addItem(&armor2);

    enemy enemy1(MapData, 13, 5);
    scene.addItem(&enemy1);
    enemy enemy2(MapData, 13, 9);
    scene.addItem(&enemy2);

    bullet bullet1(MapData, 1, 1);
    scene.addItem(&bullet1);
    bullet bullet2(MapData, 13, 1);
    scene.addItem(&bullet2);
    bullet bullet3(MapData, 1, 13);
    scene.addItem(&bullet3);
    bullet bullet4(MapData, 13, 13);
    scene.addItem(&bullet4);

    Franklin.setFlag(QGraphicsItem::ItemIsFocusable);
    Franklin.setFocus();

    view.setScene(&scene);
    view.show();
    return a.exec();
}
