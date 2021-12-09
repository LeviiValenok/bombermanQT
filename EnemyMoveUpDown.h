//
// Created by gaydi on 08.12.2021.
//

#ifndef BOMBERMANQT_ENEMYMOVEUPDOWN_H
#define BOMBERMANQT_ENEMYMOVEUPDOWN_H
#include "Enemies.h"
#include <QTimer>

class EnemyMoveUpDown: public Enemies
{
Q_OBJECT
public slots:
    void moveEnemy();
public:
    EnemyMoveUpDown(DirectionOfTravel direction, int xEnemy, int yEnemy, Map& map, QGraphicsItem* parent = nullptr) :
    Enemies(direction, xEnemy, yEnemy, map)
    {
        setPos(xEnemy, yEnemy);

        setRect(0, 0, sizeEnemy, sizeEnemy);
;
        QTimer * timer = new QTimer(this);
        connect(timer,SIGNAL(timeout()),this,SLOT(moveEnemy()));
        // start the timer
        timer->start(100);
    }
    void spawn(int x, int y);

};


#endif //BOMBERMANQT_ENEMYMOVEUPDOWN_H
