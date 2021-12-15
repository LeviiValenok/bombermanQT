#ifndef BOMB_H
#define BOMB_H

#include <stdio.h>
#include <QGraphicsRectItem>
#include <QObject>
#include <QTimer>
#include <QGraphicsItem>
#include <QGraphicsScene>

#include "Map.h"

class Bomb: public QObject, public QGraphicsRectItem
{
Q_OBJECT
private:
    int xBomb;
    int yBomb;
    QTimer* timer;
public slots:
    void destroyItem();
public:
    Game* game;
    Bomb(qreal x, qreal y, Game* game);
};

#endif
