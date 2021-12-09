//
// Created by gaydi on 08.12.2021.
//

#include "EnemyMoveUpDown.h"

bool isCambiar = true;

void EnemyMoveUpDown ::spawn(int x, int y)
{
//    setPos(x, y);
    setRect(x, y, sizeEnemy, sizeEnemy);
}

void EnemyMoveUpDown :: moveEnemy()
{

    int blockSize = 100;
    xEnemy = x();
    yEnemy = y();
    int step = 10;

    if(isCambiar)
    {
        if ((map->table[(yEnemy + step + sizeEnemy) / blockSize][xEnemy / blockSize])->type == EMPTY &&
            (yEnemy + step + sizeEnemy) < 570) {
            setPos(xEnemy, yEnemy + step);
        }
        else
        {
            isCambiar = false;
        }
    }
    if (!isCambiar)
    {
        if ((map->table[(yEnemy - step) / blockSize][xEnemy / blockSize])->type == EMPTY &&
            (yEnemy - step) > 0) {
            setPos(xEnemy, yEnemy - step);
        }
        else
        {
            isCambiar = true;
        }
    }

//    else
//    {
//        setPos(xEnemy, yEnemy-5);
//    }

}
