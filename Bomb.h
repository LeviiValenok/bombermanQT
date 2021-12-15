#ifndef BOMB_H
#define BOMB_H


#include <stdio.h>
#include "Player.h"
#include "Map.h"


#include <QGraphicsRectItem>
#include <QObject>
#include <QTimer>
#include <QGraphicsItem>
#include <QGraphicsScene>

class Bomb: public QObject, public QGraphicsRectItem
{
    Q_OBJECT
private:
    int xBomb;
    int yBomb;
    Map* map;
    QTimer* timer;
public slots:
    void destroyItem();
public:
    friend class Player;
    Bomb(qreal x, qreal y, Map& map);
    ~Bomb();
//    void setPosition(int x, int y);


//    void bombDetonation();


//public slots:
//    void detonation();

//    friend class Map;
//    friend class Enemies;
//    Bomb();
  //  void setBomb (Player player, Map& map);
//try destroy
   // void chooseATarget(Player& player, Enemies& enemyUpDown, Bomb bomb, int iBombCurrent, int jBombCurrent,
//                       Map& map, CellType type);
////check neighbors
//    void destroyObjects(Player& player, Enemies& enemyUpDown, Bomb bomb, Map& map, CellType type);

//    void destroyBlocks(Map& map);

//    void destroyEnemies(Enemies& enemyUpDown, Player& player, Map map);

//    void killPlayer(Player player, Map map);

};

#endif