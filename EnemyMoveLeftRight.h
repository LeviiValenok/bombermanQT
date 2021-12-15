#ifndef BOMBERMANQT_ENEMYMOVELEFTRIGHT_H
#define BOMBERMANQT_ENEMYMOVELEFTRIGHT_H

#include <QTimer>

#include "Enemy.h"
#include "Game.h"

class EnemyMoveLeftRight: public Enemy
{
Q_OBJECT
public slots:
    void moveEnemyLeftRight();
public:
    EnemyMoveLeftRight(DirectionOfTravel direction, int xEnemy, int yEnemy, QGraphicsItem* parent = nullptr) : Enemy(direction, xEnemy, yEnemy, parent)
    {
        setPos(xEnemy, yEnemy);
        setRect(0, 0, sizeEnemy, sizeEnemy);
        QTimer * timer = new QTimer(this);
        connect(timer,SIGNAL(timeout()),this,SLOT(moveEnemyLeftRight()));
        // start the timer
        timer->start(100);
    }
//    void spawn(int x, int y);
};


#endif



