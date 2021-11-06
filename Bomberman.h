#ifndef BOMBERMAN_H
#define BOMBERMAN_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>

#include "Map.h"
#include "DestroyedBlock.h"
#include "Player.h"
//#include "Background.h"

class Bomberman : public QGraphicsView
{
public:
    Bomberman(QWidget *parent = 0);
    QGraphicsScene * scene;
    Map* map;
    Player* player;
//    Background* background;
};

#endif // BOMBERMAN_H
