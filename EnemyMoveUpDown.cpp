#include "EnemyMoveUpDown.h"

class Enemy;

bool isSelectorUpDown = true;

void EnemyMoveUpDown ::spawn(int x, int y)
{
//    setPos(x, y);
//    setRect(x, y, sizeEnemy, sizeEnemy);
}

void EnemyMoveUpDown :: moveEnemyUpDown()
{

    int blockSize = 100;
    xEnemy = x();
    yEnemy = y();
    int step = 10;

    Player* player = this->game->player;
    Map* map = this->game->map;

    if(isSelectorUpDown)
    {
        if ((map->table[(yEnemy + step + sizeEnemy) / blockSize][xEnemy / blockSize])->type == EMPTY &&
            (yEnemy + step + sizeEnemy) < 570)
        {
            setPos(xEnemy, yEnemy + step);

            if ((map->table[(player->yPlayer)/blockSize][(player->xPlayer + player->playerSize)/blockSize] ==
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
            isSelectorUpDown = false;
        }
    }
    if (!isSelectorUpDown)
    {
        if ((map->table[(yEnemy - step) / blockSize][xEnemy / blockSize])->type == EMPTY &&
            (yEnemy - step) > 0)
        {
            setPos(xEnemy, yEnemy - step);

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
            isSelectorUpDown = true;
        }
    }

}


void EnemyMoveUpDown ::removeEnemyMoveUpDown()
{
    scene()->removeItem(this);
//    delete this;
}
