#ifndef BOMB_H
#define BOMB_H

#include <stdio.h>
#include "Player.h"
#include "Map.h"
#include "Enemies.h"

#include <QGraphicsRectItem>
#include <QObject>


class Bomb
{

private:
    int **bombCoordinate;
    int iBomb;
    int jBomb;
public:
    friend class Player;
//    friend class Map;
//    friend class Enemies;
//    Bomb();
  //  void setBomb (Player player, Map& map);
//try destroy
   // void chooseATarget(Player& player, Enemies& enemy, Bomb bomb, int iBombCurrent, int jBombCurrent,
//                       Map& map, cellType type);
////check neighbors
//    void destroyObjects(Player& player, Enemies& enemy, Bomb bomb, Map& map, cellType type);

//    void destroyBlocks(Map& map);

//    void destroyEnemies(Enemies& enemy, Player& player, Map map);

//    void killPlayer(Player player, Map map);

};

#endif // BOMB_H
