#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QList>


#include "Map.h"
#include "DestroyedBlock.h"

#include <stdbool.h>

class Player : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:
        int **playerCoordinate;
        qreal xPos = x();
        qreal yPos = y();

public:
    Player(QGraphicsItem * parent= 0);
    int health = 3;
    int score = 0;

//    Player(int i, int j, Map& map);
//    int getIPosition();
//    int getJPosition();
//    friend class Bomb;
//    friend class Enemies;
//    friend class Map;

//    void  movement(Player& player, Map& map, bool& isQuite);
//    bool youCanMoveUp(Map map);
//    bool youCanMoveDown(Map map);
//    bool youCanMoveRight(Map map);
//    bool youCanMoveLeft(Map map);

    void keyPressEvent(QKeyEvent * event);


    bool collidings();
    void action(qreal xPrevious, qreal yPrevious);

};

#endif // PLAYER_H
