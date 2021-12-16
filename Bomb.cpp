#include "Bomb.h"
#include "Player.h"
#include "Map.h"

#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <QGraphicsItem>
#include <stdbool.h>

bool isEnemyLeftRightExist = true;
bool isEnemyUpDownExist = true;
//void Bomb::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
//{
//    QPolygon polygon;
//    polygon << QPoint(300,200) << QPoint(225,300) << QPoint(300,300)
//            << QPoint(300, 400) << QPoint(375, 400) << QPoint(375, 300) << QPoint(450, 300)
//            <<  QPoint(450, 200) << QPoint(375, 200) << QPoint(375, 100) << QPoint(300, 100);
//    painter->setBrush(Qt::black);
//    painter->drawPolygon(polygon);
//    Q_UNUSED(option);
//    Q_UNUSED(widget);
//}

Bomb::Bomb(qreal x, qreal y, Game* game, QGraphicsItem* parent): QObject(), QGraphicsPixmapItem(parent)
{
    this->game = game;
    int bombSize = 75;
    setPixmap(QPixmap(":/pictures/bombermanPic/bomb.png"));
    setPos(x*100, y*100);
    xBomb = x;
    yBomb = y;
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(destroyItem()));
    timer->start(3000);


}

void Bomb :: destroyItem() {
    int blockSize = 100;
    int bombSize = 75;

    Map* map = this->game->map;
    Player* player = this->game->player;
    EnemyMoveLeftRight* enemyLeftRight = this->game->enemyLeftRight;
    EnemyMoveUpDown* enemyMoveUpDown = this->game->enemyUpDown;
    int playerSize = player->playerSize;
    int enemySize = enemyLeftRight->sizeEnemy;
    QGraphicsScene* scene = game->scene;
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
//for destroy enemy left right

    if (isEnemyLeftRightExist) {
        if ((yBomb - bombSize) > 0 &&
            (map->table[(yBomb - bombSize) / blockSize][(xBomb + bombSize) / blockSize] ==
             map->table[(enemyLeftRight->yEnemy + enemySize) / blockSize][(enemyLeftRight->xEnemy) / blockSize]) ||
            (map->table[(yBomb - bombSize) / blockSize][(xBomb) / blockSize] ==
             map->table[(enemyLeftRight->yEnemy + enemySize) / blockSize][(enemyLeftRight->xEnemy + enemySize) /
                                                                          blockSize])) {
//        enemyLeftRight->removeEnemyLeftRight();
            scene->removeItem(enemyLeftRight);
            isEnemyLeftRightExist = false;
            delete enemyLeftRight;
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
            isEnemyLeftRightExist = false;
            delete enemyLeftRight;

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
            isEnemyLeftRightExist = false;
            delete enemyLeftRight;
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
            isEnemyLeftRightExist = false;
            delete enemyLeftRight;
            scene->removeItem(this);
            delete timer;
            return;
        }
    }
//for destroy enemy move up down
    if (isEnemyUpDownExist) {
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
