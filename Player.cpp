#include <stdio.h>
#include <stdbool.h>
#include <QList>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QSharedPointer>
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
           (((map->table[(yPlayer + playerSize) / blockSize][(xPlayer + step + playerSize) / blockSize]->type) == EMPTY
           &&(map->table[(yPlayer) / blockSize][(xPlayer + step + playerSize) / blockSize])->type == EMPTY)  ||
             ((map->table[(yPlayer + playerSize) / blockSize][(xPlayer + step+ playerSize) / blockSize]->type) == EXIT
            && (map->table[(yPlayer) / blockSize][(xPlayer+ step + playerSize) / blockSize])->type == EXIT)))
        {

            setPos(xPlayer+step,yPlayer);
            if (((map->table[(yPlayer + playerSize) / blockSize][(xPlayer+ playerSize) / blockSize]->type) == EXIT
                 && (map->table[(yPlayer) / blockSize][(xPlayer + playerSize) / blockSize])->type == EXIT))
            {
                game->goToTheNextLevel();
                return;
               /* game->close();
                SecondLevel level2;
                level2.show();*/

            }
        }


    }
    else if (event->key() == Qt::Key_W)
    {
        if(yPlayer - step >= 0 &&
           (map->table[(yPlayer - step) / blockSize][(xPlayer + playerSize) / blockSize]->type) == EMPTY
           &&(map->table[(yPlayer - step) / blockSize][(xPlayer) / blockSize]->type) == EMPTY)
        {
            setPos(xPlayer,yPlayer-step);
            /*if ((map->table[(yPlayer) / blockSize][(xPlayer + playerSize) / blockSize]->type) == EMPTY
                &&(map->table[(yPlayer) / blockSize][(xPlayer) / blockSize]->type) == EMPTY)
            {
                game->goToTheNextLevel();
            }*/
        }
    }
    else if (event->key() == Qt::Key_S)
    {

        if(yPlayer + playerSize + step <= 600 &&
           (map->table[(yPlayer + step + playerSize) / blockSize][(xPlayer + playerSize) / blockSize]->type == EMPTY)
           && (map->table[(yPlayer + step + playerSize) / blockSize][(xPlayer) / blockSize])->type == EMPTY)
        {
            setPos(xPlayer,yPlayer+step);
           /* if((map->table[(yPlayer + playerSize) / blockSize][(xPlayer + playerSize) / blockSize]->type == EMPTY)
               && (map->table[(yPlayer + playerSize) / blockSize][(xPlayer) / blockSize])->type == EMPTY)
            {
                game->goToTheNextLevel();
            }*/
        }
    }
    else if(event->key() == Qt::Key_Space)
    {
        this->game->setBomb(xPlayer, yPlayer);
    }

}

//сделать по границам клетки пермещение и коллизию так же
