#include "Bomb.h"
#include "Player.h"
#include "Map.h"

#include <QTimer>
#include <QGraphicsScene>
#include <QPointer>
#include <QList>
#include <QGraphicsItem>
#include <stdbool.h>

bool isEnemyLeftRightExist = true;
bool isEnemyUpDownExist = true;

Bomb::Bomb(qreal x, qreal y, Game* game, QGraphicsItem* parent): QObject(), QGraphicsPixmapItem(parent)
{
    this->game = game;
    int bombSize = 75;
    setPixmap(QPixmap(":/pictures/bombermanPic/bomb.png"));
    setPos(x, y);
    xBomb = x;
    yBomb = y;
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(destroyItem()));
    timer->start(3000);


}

void Bomb :: destroyItem() {
    int blockSize = 100;
    int bombSize = 75;
    int enemySize = 75;
    QPointer<Map> map = this->game->map;
    QPointer<Player> player = this->game->player;
//    QSharedPointer<EnemyMoveLeftRight> enemyLeftRight = this->game->enemyLeftRight;
    QPointer<EnemyMoveLeftRight> enemyLeftRight = this->game->enemyLeftRight;
//    QSharedPointer<EnemyMoveUpDown> enemyMoveUpDown = this->game->enemyUpDown;
    QPointer<EnemyMoveUpDown> enemyMoveUpDown = this->game->enemyUpDown;

    int playerSize = player->playerSize;
    QPointer<QGraphicsScene> scene = game->scene;
//for destroy block
    if ((yBomb - bombSize) > 0 && ((map->table[(yBomb - bombSize) / blockSize][(xBomb + bombSize) / blockSize])->type == DESTRUCTIBLE_BLOCK ||
                                   ((map->table[(yBomb - bombSize) / blockSize][(xBomb) / blockSize])->type == DESTRUCTIBLE_BLOCK)))
    {
        map->table[(yBomb - bombSize) / blockSize][xBomb / blockSize]->removeItem(map->table[(yBomb - bombSize) / blockSize][xBomb / blockSize]);
        map->setEmptyCell((yBomb - bombSize) / blockSize, xBomb / blockSize);
    }

    if(yBomb < 500 && ((map->table[(yBomb + 2* bombSize)/blockSize][(xBomb)/blockSize])->type == DESTRUCTIBLE_BLOCK ||
                       ((map->table[(yBomb + 2*bombSize)/blockSize][(xBomb+bombSize)/blockSize])->type == DESTRUCTIBLE_BLOCK)))
    {
        map->table[(yBomb + 2*bombSize)/blockSize][(xBomb+bombSize)/blockSize]->removeItem(map->table[(yBomb + 2*bombSize)/blockSize][(xBomb+bombSize)/blockSize]);
        map->setEmptyCell((yBomb + 2*bombSize)/blockSize, (xBomb+bombSize)/blockSize);
    }
    if ((xBomb - bombSize) > 0 && ((map->table[yBomb/blockSize][xBomb/blockSize])->type == DESTRUCTIBLE_BLOCK ||
                                   (map->table[yBomb/blockSize][(xBomb - bombSize)/blockSize])->type == DESTRUCTIBLE_BLOCK))
    {
        map->table[yBomb/blockSize][(xBomb - bombSize)/blockSize]->removeItem(map->table[yBomb/blockSize][(xBomb - bombSize)/blockSize]);
        map->setEmptyCell(yBomb/blockSize, (xBomb - bombSize)/blockSize);
    }

    if ((xBomb + bombSize) < 700 && ((map->table[yBomb/blockSize][(xBomb+bombSize)/blockSize])->type == DESTRUCTIBLE_BLOCK ||
                                     (map->table[yBomb/blockSize][(xBomb + 2*bombSize)/blockSize])->type == DESTRUCTIBLE_BLOCK))
    {
        map->table[yBomb/blockSize][(xBomb + 2*bombSize)/blockSize]->removeItem(map->table[yBomb/blockSize][(xBomb + 2*bombSize)/blockSize]);
        map->setEmptyCell(yBomb/blockSize, (xBomb + 2*bombSize)/blockSize);
    }
//for destroy player

    if ((yBomb - bombSize) > 0 && (map->table[(yBomb - bombSize) / blockSize][(xBomb + bombSize) / blockSize] == map->table[(player->yPlayer + playerSize)/blockSize][(player->xPlayer)/blockSize]) ||
        (map->table[(yBomb - bombSize) / blockSize][(xBomb) / blockSize] == map->table[(player->yPlayer + playerSize)/blockSize][(player->xPlayer + playerSize)/blockSize]))
    {
        player->setPos(0, 0);
        player->yPlayer = 0;
        player->xPlayer = 0;
        this->game->health->decrease();
    }

    if (yBomb < 500 &&
    ((map->table[(yBomb + 2* bombSize)/blockSize][(xBomb)/blockSize] == map->table[(player->yPlayer)/blockSize][(player->xPlayer)/blockSize] ||
    (map->table[(yBomb + 2*bombSize)/blockSize][(xBomb+bombSize)/blockSize]== map->table[(player->yPlayer)/blockSize][(player->xPlayer + playerSize)/blockSize]))))
    {
        player->setPos(0, 0);
        player->yPlayer = 0;
        player->xPlayer = 0;
        this->game->health->decrease();
    }

    if((xBomb - bombSize) > 0 &&
    (((map->table[yBomb/blockSize][xBomb/blockSize]) == map->table[(player->yPlayer)/blockSize][(player->xPlayer + playerSize)/blockSize] ||
      (map->table[yBomb/blockSize][(xBomb - bombSize)/blockSize]) == map->table[(player->yPlayer + playerSize)/blockSize][(player->xPlayer + playerSize)/blockSize])))
    {
        player->setPos(0, 0);
        player->yPlayer = 0;
        player->xPlayer = 0;
        this->game->health->decrease();
    }

/*    ((map->table[yBomb/blockSize][(xBomb+bombSize)/blockSize])->type == DESTRUCTIBLE_BLOCK ||
     (map->table[yBomb/blockSize][(xBomb + 2*bombSize)/blockSize])->type == DESTRUCTIBLE_BLOCK))*/

    if ((xBomb + bombSize) < 700 &&
    (((map->table[yBomb/blockSize][(xBomb+bombSize)/blockSize]) == map->table[(player->yPlayer)/blockSize][(player->xPlayer)/blockSize] ||
    (map->table[yBomb/blockSize][(xBomb + 2*bombSize)/blockSize]) == map->table[(player->yPlayer)/blockSize][(player->xPlayer + playerSize)/blockSize])))
    {
        player->setPos(0, 0);
        player->yPlayer = 0;
        player->xPlayer = 0;
        this->game->health->decrease();
    }
//for destroy enemy left right

    if (!enemyLeftRight.isNull()) {
        if ((yBomb - bombSize) > 0 &&
            (map->table[(yBomb - bombSize) / blockSize][(xBomb + bombSize) / blockSize] ==
             map->table[(enemyLeftRight->yEnemy + enemySize) / blockSize][(enemyLeftRight->xEnemy) / blockSize]) ||
            (map->table[(yBomb - bombSize) / blockSize][(xBomb) / blockSize] ==
             map->table[(enemyLeftRight->yEnemy + enemySize) / blockSize][(enemyLeftRight->xEnemy + enemySize) /
                                                                          blockSize])) {
//            enemyLeftRight->removeEnemyLeftRight();
            scene->removeItem(enemyLeftRight);
            delete enemyLeftRight;
            isEnemyLeftRightExist = false;
            scene->removeItem(this);
            delete timer;
            return;

        }

        if (yBomb < 500 &&
            ((map->table[(yBomb + 2 * bombSize) / blockSize][(xBomb) / blockSize] ==
              map->table[(enemyLeftRight->yEnemy) / blockSize][(enemyLeftRight->xEnemy) / blockSize] ||
              (map->table[(yBomb + 2 * bombSize) / blockSize][(xBomb + bombSize) / blockSize] ==
               map->table[(enemyLeftRight->yEnemy) / blockSize][(enemyLeftRight->xEnemy + enemySize) / blockSize])))) {
//        enemyLeftRight->removeEnemyLeftRight();
            scene->removeItem(enemyLeftRight);
            delete enemyLeftRight;;
            isEnemyLeftRightExist = false;
            scene->removeItem(this);
            delete timer;
            return;
        }

        if ((xBomb - bombSize) > 0 &&
            (((map->table[yBomb / blockSize][xBomb / blockSize]) ==
              map->table[(enemyLeftRight->yEnemy) / blockSize][(enemyLeftRight->xEnemy + enemySize) / blockSize] ||
              (map->table[yBomb / blockSize][(xBomb - bombSize) / blockSize]) ==
              map->table[(enemyLeftRight->yEnemy + enemySize) / blockSize][(enemyLeftRight->xEnemy + enemySize) /
                                                                           blockSize]))) {
//        enemyLeftRight->removeEnemyLeftRight();
            scene->removeItem(enemyLeftRight);
            delete enemyLeftRight;
            isEnemyLeftRightExist = false;
            scene->removeItem(this);
            delete timer;
            return;
        }

        if ((xBomb + bombSize) < 700 &&
            ((map->table[yBomb / blockSize][(xBomb + bombSize) / blockSize]) ==
             map->table[(enemyLeftRight->yEnemy) / blockSize][(enemyLeftRight->xEnemy) / blockSize] ||
             (map->table[yBomb / blockSize][(xBomb + 2 * bombSize) / blockSize]) ==
             map->table[(enemyLeftRight->yEnemy + enemySize) / blockSize][enemyLeftRight->xEnemy / blockSize])) {
//        enemyLeftRight->removeEnemyLeftRight();
            scene->removeItem(enemyLeftRight);
            delete enemyLeftRight;
            isEnemyLeftRightExist = false;
            scene->removeItem(this);
            delete timer;
            return;
        }
    }
//for destroy enemy move up down
    if (!enemyMoveUpDown.isNull()) {
        if ((yBomb - bombSize) > 0 &&
            (map->table[(yBomb - bombSize) / blockSize][(xBomb + bombSize) / blockSize] ==
             map->table[(enemyMoveUpDown->yEnemy + enemySize) / blockSize][(enemyMoveUpDown->xEnemy) / blockSize]) ||
            (map->table[(yBomb - bombSize) / blockSize][(xBomb) / blockSize] ==
             map->table[(enemyMoveUpDown->yEnemy + enemySize) / blockSize][(enemyMoveUpDown->xEnemy + enemySize) /blockSize])) {
            scene->removeItem(enemyMoveUpDown);
            isEnemyUpDownExist = false;
            delete enemyMoveUpDown;
            scene->removeItem(this);
            delete timer;
            return;
        }

        if (yBomb < 500 &&
            ((map->table[(yBomb + 2 * bombSize) / blockSize][(xBomb) / blockSize] ==
              map->table[(enemyMoveUpDown->yEnemy) / blockSize][(enemyMoveUpDown->xEnemy) / blockSize] ||
              (map->table[(yBomb + 2 * bombSize) / blockSize][(xBomb + bombSize) / blockSize] ==
               map->table[(enemyMoveUpDown->yEnemy) / blockSize][(enemyMoveUpDown->xEnemy + enemySize) /blockSize])))) {
            scene->removeItem(enemyMoveUpDown);
            isEnemyUpDownExist = false;
            delete enemyMoveUpDown;
            scene->removeItem(this);
            delete timer;
            return;
        }

        if ((xBomb - bombSize) > 0 &&
            (((map->table[yBomb / blockSize][xBomb / blockSize]) ==
              map->table[(enemyMoveUpDown->yEnemy) / blockSize][(enemyMoveUpDown->xEnemy + enemySize) / blockSize] ||
              (map->table[yBomb / blockSize][(xBomb - bombSize) / blockSize]) ==
              map->table[(enemyMoveUpDown->yEnemy + enemySize) / blockSize][(enemyMoveUpDown->xEnemy + enemySize) /
                                                                            blockSize]))) {
            scene->removeItem(enemyMoveUpDown);
            isEnemyUpDownExist = false;
            delete enemyMoveUpDown;
            scene->removeItem(this);
            delete timer;
            return;
        }

        if ((xBomb + bombSize) < 700 &&
            ((map->table[yBomb / blockSize][(xBomb + bombSize) / blockSize]) ==
             map->table[(enemyMoveUpDown->yEnemy) / blockSize][(enemyMoveUpDown->xEnemy) / blockSize] ||
             (map->table[yBomb / blockSize][(xBomb + 2 * bombSize) / blockSize]) ==
             map->table[(enemyMoveUpDown->yEnemy + enemySize) / blockSize][enemyMoveUpDown->xEnemy / blockSize])) {
            scene->removeItem(enemyMoveUpDown);
            isEnemyUpDownExist = false;
            delete enemyMoveUpDown;
            scene->removeItem(this);
            delete timer;
            return;

        }
    }
    scene->removeItem(this);
    delete timer;
    return;
}


/*
(map->table[(player->yPlayer)/blockSize][(player->xPlayer + player->playerSize)/blockSize] ==
map->table[yBomb/blockSize][xBomb/blockSize]) ||
(map->table[(player->yPlayer+ player->playerSize)/blockSize][(player->xPlayer + player->playerSize)/blockSize] ==
map->table[(yBomb+bombSize)/blockSize][xBomb/blockSize])||
((map->table[(player->yPlayer + player->playerSize)/blockSize][(player->xPlayer + player->playerSize)/blockSize] ==
map->table[yBomb/blockSize][(xBomb + bombSize)/blockSize] ||
(map->table[(player->yPlayer + player->playerSize)/blockSize][(player->xPlayer)/blockSize] ==
map->table[yBomb/blockSize][xBomb/blockSize]) ||
(map->table[(player->yPlayer)/blockSize][(player->xPlayer)/blockSize] ==
map->table[yBomb/blockSize][(xBomb + bombSize)/blockSize]) ||
(map->table[(player->yPlayer + player->playerSize)/blockSize][(player->xPlayer)/blockSize] ==
map->table[(yBomb + bombSize)/blockSize][(xBomb + bombSize)/blockSize]) ||
(map->table[(player->yPlayer)/blockSize][(player->xPlayer)/blockSize] ==
map->table[(yBomb + bombSize)/blockSize][(xBomb)/blockSize]) ||
(map->table[(player->yPlayer)/blockSize][(player->xPlayer + player->playerSize)/blockSize] ==
map->table[(yBomb + bombSize)/blockSize][(xBomb + bombSize)/blockSize]))))*/
