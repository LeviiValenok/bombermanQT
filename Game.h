#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>

#include "Map.h"
#include "Player.h"
#include "Enemy.h"
#include "EnemyMoveLeftRight.h"
#include "EnemyMoveUpDown.h"
#include "Health.h"
#include "Bomb.h"
//#include "Background.h"

class Player;
class Map;
class EnemyMoveUpDown;
class EnemyMoveLeftRight;

class Game : public QGraphicsView
{
public:
    Game(QWidget *parent = 0);
    QGraphicsScene * scene;
    Map* map;
    Player* player;
    EnemyMoveUpDown* enemyUpDown;
    EnemyMoveLeftRight* enemyLeftRight;
    Health* health;
    //    Background* background;
    void setUpGameLinks();
    void setBomb(qreal xBomb, qreal yBomb);
};

#endif
