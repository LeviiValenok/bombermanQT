#ifndef MAP_H
#define MAP_H

#include <QGraphicsScene>
#include <QGraphicsPathItem>
#include <QGraphicsObject>
#include <QGraphicsItem>

#include "DestructibleBlock.h"
#include "EmptyBlock.h"
#include "ExitBlock.h"

class Game;
//add value exit

class Map : public QObject, public QGraphicsPixmapItem
{
Q_OBJECT


public:
    Game* game;
    MapCell *table[6][8];
    Map(QGraphicsScene* scene, QGraphicsItem* parent = 0);
    void outputField(QGraphicsScene* scene);
    void setGame(Game* game);
    Map();
    void setEmptyCell(int i, int j);
};

#endif
