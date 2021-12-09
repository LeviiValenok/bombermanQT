#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QList>


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

//    Player(int i, int j, Map& map);
//    int getIPosition();
//    int getJPosition();
//    friend class Bomb;
//    friend class Enemies;


//    void  movement(Player& player, Map& map, bool& isQuite);
//    bool youCanMoveUp(Map map);
//    bool youCanMoveDown(Map map);
//    bool youCanMoveRight(Map map);
//    bool youCanMoveLeft(Map map);
//, Map &map
    void keyPressEvent(QKeyEvent * event);
    void spawnEnemy();
    void setBomb(int xBomb, int yBomb, int bombSize);
    friend class Map;

};

#endif // PLAYER_H
