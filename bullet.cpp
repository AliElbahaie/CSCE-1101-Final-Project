#include "bullet.h"

bullet::bullet( int boarddata[15][15],int r,int c)
{
    rows=r;
    columns=c;

    QPixmap image(":/Images/bullet image.png");
    image = image.scaledToWidth(50);
    image = image.scaledToHeight(50);
    setPixmap(image);


    setPos(50+50*columns,50+50*rows);

    for(int i=0;i<15;i++)
        for (int j=0;j<15;j++)
           board[i][j]=boarddata[i][j];

}


