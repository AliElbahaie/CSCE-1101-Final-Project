#include "pellet.h"

Pellet::Pellet(int boarddata[15][15])
{
    QPixmap image(":/Images/Sheild.png");
    image = image.scaledToWidth(50);
    image = image.scaledToHeight(50);
    setPixmap(image);

    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 15; j++)
        {
            board[i][j] = boarddata[i][j];
        }
    }

    rows = rand() % 15;
    columns = rand() % 15;

    while (board[rows][columns] == -1)
    {
        rows = rand() % 15;
        columns = rand() % 15;
    }

    //qDebug()<<"rows: "<<rows<<"columns: "<<columns;

    setPos(50 + rows * 50, 50 + columns * 50);
}
