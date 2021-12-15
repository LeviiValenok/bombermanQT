#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QList>
#include <stdbool.h>

#include "Game.h"

class Player : public QObject, public QGraphicsRectItem
{
Q_OBJECT
public:
    int xPlayer;
    int yPlayer;
    int playerSize = 75;
    Game* game;

    Player(QGraphicsItem * parent=0);
    void keyPressEvent(QKeyEvent * event);
    void setGame(Game* game);
/*    void spawnEnemy();
    void setBomb(int xBomb, int yBomb, int bombSize);*/
};

#endif
