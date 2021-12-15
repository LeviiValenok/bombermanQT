#ifndef ENEMY_H
#define ENEMY_H

#include <iostream>
#include <QObject>
#include <QGraphicsRectItem>

enum DirectionOfTravel
{
    UP_DOWN = 1,
    LEFT_TO_RIGHT = 2,
};

class Game;

class Enemy: public QObject, public QGraphicsRectItem
{
public:
    Game* game;
    int xEnemy;
    int yEnemy;
    int sizeEnemy = 75;
    DirectionOfTravel direction;
    Enemy(DirectionOfTravel setDirection, int x, int y, QGraphicsItem *parent);
    ~Enemy();
    void setGame(Game* game);
};


#endif
