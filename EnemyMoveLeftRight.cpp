#include "EnemyMoveLeftRight.h"

class Enemy;

bool isSelectorLeftRight = true;

void EnemyMoveLeftRight :: moveEnemyLeftRight() {

    int blockSize = 100;
    xEnemy = x();
    yEnemy = y();
    int step = 10;

    Player* player = this->game->player;
    Map* map = this->game->map;
    if (isSelectorLeftRight) {
        if ((map->table[(yEnemy) / blockSize][(xEnemy+step+blockSize) / blockSize])->type == EMPTY &&
            (xEnemy + step + sizeEnemy) < 770)
        {
            setPos(xEnemy+step, yEnemy);

            if ((map->table[(player->yPlayer)/blockSize][(player->xPlayer + player->playerSize) / blockSize] ==
                 map->table[yEnemy/blockSize][xEnemy/blockSize]) ||
                (map->table[(player->yPlayer+ player->playerSize)/blockSize][(player->xPlayer + player->playerSize)/blockSize] ==
                 map->table[(yEnemy+sizeEnemy)/blockSize][xEnemy/blockSize])||
                ((map->table[(player->yPlayer + player->playerSize)/blockSize][(player->xPlayer + player->playerSize)/blockSize] ==
                  map->table[yEnemy/blockSize][(xEnemy + sizeEnemy)/blockSize] ||
                  (map->table[(player->yPlayer + player->playerSize)/blockSize][(player->xPlayer)/blockSize] ==
                   map->table[yEnemy/blockSize][xEnemy/blockSize]) ||
                  (map->table[(player->yPlayer)/blockSize][(player->xPlayer)/blockSize] ==
                   map->table[yEnemy/blockSize][(xEnemy + sizeEnemy)/blockSize]) ||
                  (map->table[(player->yPlayer + player->playerSize)/blockSize][(player->xPlayer)/blockSize] ==
                   map->table[(yEnemy + sizeEnemy)/blockSize][(xEnemy + sizeEnemy)/blockSize]) ||
                  (map->table[(player->yPlayer)/blockSize][(player->xPlayer)/blockSize] ==
                   map->table[(yEnemy + sizeEnemy)/blockSize][(xEnemy)/blockSize]) ||
                  (map->table[(player->yPlayer)/blockSize][(player->xPlayer + player->playerSize)/blockSize] ==
                   map->table[(yEnemy + sizeEnemy)/blockSize][(xEnemy + sizeEnemy)/blockSize]))))
            {
                player->setPos(0, 0);
                player->yPlayer = 0;
                player->xPlayer = 0;
                this->game->health->decrease();
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

            if ((map->table[(player->yPlayer)/blockSize][(player->xPlayer + player->playerSize) / blockSize] ==
                 map->table[yEnemy/blockSize][xEnemy/blockSize]) ||
                (map->table[(player->yPlayer+ player->playerSize)/blockSize][(player->xPlayer + player->playerSize)/blockSize] ==
                 map->table[(yEnemy+sizeEnemy)/blockSize][xEnemy/blockSize])||
                ((map->table[(player->yPlayer + player->playerSize)/blockSize][(player->xPlayer + player->playerSize)/blockSize] ==
                  map->table[yEnemy/blockSize][(xEnemy + sizeEnemy)/blockSize] ||
                  (map->table[(player->yPlayer + player->playerSize)/blockSize][(player->xPlayer)/blockSize] ==
                   map->table[yEnemy/blockSize][xEnemy/blockSize]) ||
                  (map->table[(player->yPlayer)/blockSize][(player->xPlayer)/blockSize] ==
                   map->table[yEnemy/blockSize][(xEnemy + sizeEnemy)/blockSize]) ||
                  (map->table[(player->yPlayer + player->playerSize)/blockSize][(player->xPlayer)/blockSize] ==
                   map->table[(yEnemy + sizeEnemy)/blockSize][(xEnemy + sizeEnemy)/blockSize]) ||
                  (map->table[(player->yPlayer)/blockSize][(player->xPlayer)/blockSize] ==
                   map->table[(yEnemy + sizeEnemy)/blockSize][(xEnemy)/blockSize]) ||
                  (map->table[(player->yPlayer)/blockSize][(player->xPlayer + player->playerSize)/blockSize] ==
                   map->table[(yEnemy + sizeEnemy)/blockSize][(xEnemy + sizeEnemy)/blockSize]))))
            {
                player->setPos(0, 0);
                player->yPlayer = 0;
                player->xPlayer = 0;
                this->game->health->decrease();
            }
        } else
        {
            isSelectorLeftRight = true;
        }
    }
}
