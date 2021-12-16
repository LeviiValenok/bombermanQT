#include <stdio.h>
#include <stdbool.h>
#include <QList>
#include <QGraphicsScene>
#include <QKeyEvent>
//#include <QGraphicsPixmapItem>
#include <QGraphicsRectItem>
#include <QtDebug>

#include "Player.h"
#include "constants.h"

Player::Player(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{
    xPlayer = 0;
    yPlayer = 0;
    setPixmap(QPixmap(":/pictures/bombermanPic/player.png"));
}

void Player :: setGame(Game* game)
{
    this->game = game;
}

void Player :: keyPressEvent(QKeyEvent *event)
{
    xPlayer = x();
    yPlayer = y();
    int blockSize = 100;
    int playerSize = 75;
    int step = 10;

    Map* map = this->game->map;

    if (event->key() == Qt::Key_A)
    {
        if(xPlayer - step >= 0 &&
           (map->table[(yPlayer + playerSize) / blockSize][(xPlayer - step) / blockSize]->type) == EMPTY
           && (map->table[(yPlayer) / blockSize][(xPlayer - step) / blockSize]->type) == EMPTY)
        {
            setPos(xPlayer-step,yPlayer);
        }
    }
    else if (event->key() == Qt::Key_D)
    {

        if(xPlayer + playerSize + step <= 800 &&
           (map->table[(yPlayer + playerSize) / blockSize][(xPlayer + step + playerSize) / blockSize]->type) == EMPTY
           &&(map->table[(yPlayer) / blockSize][(xPlayer + step + playerSize) / blockSize])->type == EMPTY)
        {

            setPos(xPlayer+step,yPlayer);
        }
    }
    else if (event->key() == Qt::Key_W)
    {
        if(yPlayer - step >= 0 &&
           (map->table[(yPlayer - step) / blockSize][(xPlayer + playerSize) / blockSize]->type) == EMPTY
           &&(map->table[(yPlayer - step) / blockSize][(xPlayer) / blockSize]->type) == EMPTY)
        {
            setPos(xPlayer,yPlayer-step);
        }
    }
    else if (event->key() == Qt::Key_S)
    {

        if(yPlayer + playerSize + step <= 600 &&
           (map->table[(yPlayer + step + playerSize) / blockSize][(xPlayer + playerSize) / blockSize]->type == EMPTY)
           && (map->table[(yPlayer + step + playerSize) / blockSize][(xPlayer) / blockSize])->type == EMPTY)
        {
            setPos(xPlayer,yPlayer+step);
        }
    }
    else if(event->key() == Qt::Key_Space)
    {
        this->game->setBomb(xPlayer, yPlayer);
    }

}

//void Player :: spawnEnemy()
//{
//    EnemyMoveUpDown* enemyUpDown = new EnemyMoveUpDown(UP_DOWN);
//    scene()->addItem(enemyUpDown);
//}

//сделать по границам клетки пермещение и коллизию так же
