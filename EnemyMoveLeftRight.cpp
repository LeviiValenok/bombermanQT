//
// Created by gaydi on 09.12.2021.
//

#include "EnemyMoveLeftRight.h"

bool isSelectorLeftRight = true;


void EnemyMoveLeftRight :: moveEnemyLeftRight() {

    int blockSize = 100;
    xEnemy = x();
    yEnemy = y();
    int step = 10;

    if (isSelectorLeftRight) {
        if ((map->table[(yEnemy) / blockSize][(xEnemy+step+blockSize) / blockSize])->type == EMPTY &&
            (xEnemy + step + sizeEnemy) < 770)
        {
            setPos(xEnemy+step, yEnemy);
            if ((player->map->table[(player->yPlayer)/blockSize][(player->xPlayer + player->playerSize) / blockSize] ==
                 map->table[yEnemy/blockSize][xEnemy/blockSize]) ||
                (player->map->table[(player->yPlayer)/blockSize][(player->xPlayer) / blockSize] ==
                 map->table[yEnemy/blockSize][(xEnemy + sizeEnemy)/blockSize]) ||
                (player->map->table[(player->yPlayer + player->playerSize)/blockSize][(player->xPlayer) / blockSize] ==
                 map->table[yEnemy/blockSize][xEnemy/blockSize]) ||
                (player->map->table[(player->yPlayer)/blockSize][(player->xPlayer) / blockSize] ==
                 map->table[yEnemy/blockSize][(xEnemy+sizeEnemy)/blockSize]))
            {
                player->health->decrease();
                player->setPos(0, 0);
            }
        }
        else
        {
            isSelectorLeftRight = false;

        }
    }
    if (!isSelectorLeftRight) {
        if ((map->table[yEnemy/ blockSize][(xEnemy-step) / blockSize])->type == EMPTY &&
            (xEnemy - step) > 0)
        {
            setPos(xEnemy- step, yEnemy );
            if ((player->map->table[(player->yPlayer)/blockSize][(player->xPlayer + player->playerSize) / blockSize] ==
                 map->table[yEnemy/blockSize][xEnemy/blockSize]) ||
                (player->map->table[(player->yPlayer)/blockSize][(player->xPlayer) / blockSize] ==
                 map->table[yEnemy/blockSize][(xEnemy + sizeEnemy)/blockSize]) ||
                (player->map->table[(player->yPlayer + player->playerSize)/blockSize][(player->xPlayer) / blockSize] ==
                 map->table[yEnemy/blockSize][xEnemy/blockSize]) ||
                (player->map->table[(player->yPlayer)/blockSize][(player->xPlayer) / blockSize] ==
                 map->table[yEnemy/blockSize][(xEnemy+sizeEnemy)/blockSize]))
            {
                player->health->decrease();
                player->setPos(0, 0);
            }
        } else
        {
            isSelectorLeftRight = true;
        }
    }
}