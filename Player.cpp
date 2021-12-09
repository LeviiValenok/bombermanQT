#include "Player.h"
#include "EnemyMoveUpDown.h"
#include "Bomb.h"
#include "Map.h"
#include <stdio.h>
#include <conio.h>
#include <stdbool.h>

#include <QList>
#include <QGraphicsScene>
#include <QKeyEvent>
//#include <QGraphicsPixmapItem>
#include <QGraphicsRectItem>
#include <QtDebug>

//Player:: Player(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
//{
//    setPixmap(QPixmap(":/pictures/bombermanPic/player.png"));
//}

Player::Player(Map &map, Health& health,  QGraphicsItem *parent): QGraphicsRectItem(parent), map(&map), health(&health)
{

}


void Player :: keyPressEvent(QKeyEvent *event)
{
    xPlayer = x();
    yPlayer = y();
    int blockSize = 100;
    int playerSize = 75;
    int step = 10;



   // QGraphicsScene *scene;


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
    }else if(event->key() == Qt::Key_Space)
    {
        int xBomb = xPlayer;
        int yBomb = yPlayer;
        int bombSize = playerSize;
        Bomb* bomb = new Bomb(xBomb, yBomb);
        scene()->addItem(bomb);
        bomb->destroyItem(xBomb, yBomb, bomb, *map);


    }

}

//void Player :: spawnEnemy()
//{
//    EnemyMoveUpDown* enemyUpDown = new EnemyMoveUpDown(UP_DOWN);
//    scene()->addItem(enemyUpDown);
//}

//сделать по границам клетки пермещение и коллизию так же
