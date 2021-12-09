#ifndef ENEMIES_H
#define ENEMIES_H

#include <iostream>
#include "Player.h"
#include "Map.h"

enum DirectionOfTravel
{
    UP_DOWN = 1,
    LEFT_TO_RIGHT = 2,
};


class Enemies: public QObject, public QGraphicsRectItem
{

public:
    Map* map;
    int xEnemy;
    int yEnemy;
    int sizeEnemy = 75;
    DirectionOfTravel direction;
    Enemies(Map& map, QGraphicsItem *parent = 0);
    Enemies(DirectionOfTravel setDirection, int x, int y,Map& map);
    ~Enemies();

    //movement

};


#endif  // ENEMIES_H
