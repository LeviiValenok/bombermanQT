#ifndef BOMBERMAN_H
#define BOMBERMAN_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>

#include "Player.h"
class Bomberman : public QGraphicsView
{
public:
    Bomberman(QWidget *parent = 0);
    QGraphicsScene * scene;
    Player * player;
};

#endif // BOMBERMAN_H
