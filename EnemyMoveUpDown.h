#ifndef BOMBERMANQT_ENEMYMOVEUPDOWN_H
#define BOMBERMANQT_ENEMYMOVEUPDOWN_H

#include <QTimer>

#include "Enemy.h"
#include "Game.h"

class EnemyMoveUpDown: public Enemy
{
Q_OBJECT
public slots:
    void moveEnemyUpDown();
public:
    EnemyMoveUpDown(DirectionOfTravel direction, int xEnemy, int yEnemy, QGraphicsItem* parent = nullptr) : Enemy(direction, xEnemy, yEnemy, parent)
    {
        setPixmap(QPixmap(":/pictures/bombermanPic/enemy.png"));
        setPos(xEnemy, yEnemy);
//        setRect(0, 0, sizeEnemy, sizeEnemy);
        QTimer * timer = new QTimer(this);
        connect(timer,SIGNAL(timeout()),this,SLOT(moveEnemyUpDown()));
        // start the timer
        timer->start(100);
    }
    void spawn(int x, int y);
    void removeEnemyMoveUpDown();
};


#endif
