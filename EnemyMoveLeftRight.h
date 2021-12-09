//
// Created by gaydi on 09.12.2021.
//

#ifndef BOMBERMANQT_ENEMYMOVELEFTRIGHT_H
#define BOMBERMANQT_ENEMYMOVELEFTRIGHT_H
#include "Enemies.h"
#include "Player.h"
#include "Health.h"
#include <QTimer>

class EnemyMoveLeftRight: public Enemies
{
Q_OBJECT
public slots:
    void moveEnemyLeftRight();
public:
    EnemyMoveLeftRight(DirectionOfTravel direction, int xEnemy, int yEnemy, Map& map, Player& player, QGraphicsItem* parent = nullptr) :
    Enemies(direction, xEnemy, yEnemy, map, player)
    {
        setPos(xEnemy, yEnemy);

        setRect(0, 0, sizeEnemy, sizeEnemy);
        ;
        QTimer * timer = new QTimer(this);
        connect(timer,SIGNAL(timeout()),this,SLOT(moveEnemyLeftRight()));
        // start the timer
        timer->start(100);
    }

    friend class Player;
//    void spawn(int x, int y);

};



#endif //BOMBERMANQT_ENEMYMOVELEFTRIGHT_H



