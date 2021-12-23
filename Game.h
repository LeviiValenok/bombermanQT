#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QObject>
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QPointer>
#include <QTimer>

#include <GameIsWin.h>
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
    Q_OBJECT
public:
    int level;
    Game(int level, QWidget *parent = 0);
    QPointer<QGraphicsScene>  scene;
    QPointer<Map> map;
    QPointer<Player> player;
    QPointer<QTimer> timer;
    /*QSharedPointer <EnemyMoveUpDown> enemyUpDown;
    QSharedPointer <EnemyMoveLeftRight> enemyLeftRight;*/

    QPointer <EnemyMoveUpDown> enemyUpDown;
    QPointer <EnemyMoveLeftRight> enemyLeftRight;
//    EnemyMoveUpDown* enemyUpDown;
//    EnemyMoveLeftRight* enemyLeftRight;
    QPointer<Health> health;
    QPointer<GameIsWin> endGame;
    //    Background* background;
    void setUpGameLinks();
    void setBomb(qreal xBomb, qreal yBomb);
    void goToTheNextLevel();

public slots:
    void gameIsOver();

};

#endif
