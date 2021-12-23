#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QList>
#include <QPointer>
#include <stdbool.h>

#include "Game.h"

class Player : public QObject, public QGraphicsPixmapItem
{
Q_OBJECT
public:
    int xPlayer;
    int yPlayer;
    int playerSize = 75;
    QPointer<Game> game;

    Player(QGraphicsItem * parent=0);
    void keyPressEvent(QKeyEvent * event);
    void setGame(Game* game);
/*    void spawnEnemy();
    void setBomb(int xBomb, int yBomb, int bombSize);*/
};

#endif
