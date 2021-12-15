//#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

#include "Map.h"
#include "Health.h"


#include <stdbool.h>


class Player : public QObject, public QGraphicsRectItem
{
    Q_OBJECT



public:
    int xPlayer;
    int yPlayer;
//    Player(QGraphicsItem * parent= 0);
    Player( Map& map, Health& health, QGraphicsItem * parent=0);

    int playerSize = 75;
    Map* map;
    Health* health;
    void keyPressEvent(QKeyEvent * event);
/*    void spawnEnemy();
    void setBomb(int xBomb, int yBomb, int bombSize);*/
    friend class Map;


};

#endif