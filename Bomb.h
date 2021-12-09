#ifndef BOMB_H
#define BOMB_H

#include <stdio.h>
#include "Player.h"
#include "Map.h"


#include <QGraphicsRectItem>
#include <QObject>
#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene>

class Bomb: public QObject, public QGraphicsRectItem
{
    Q_OBJECT
private:
    int **bombCoordinate;
    int iBomb;
    int jBomb;
public:
    friend class Player;
//    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
//    Bomb(QGraphicsItem * parent=0);
    Bomb(qreal x, qreal y);
    void destroyItem(qreal x, qreal y, Bomb* bomb, Map& map);
    void setPosition(int x, int y);


//    void bombDetonation();


//public slots:
//    void detonation();

//    friend class Map;
//    friend class Enemies;
//    Bomb();
  //  void setBomb (Player player, Map& map);
//try destroy
   // void chooseATarget(Player& player, Enemies& enemy, Bomb bomb, int iBombCurrent, int jBombCurrent,
//                       Map& map, CellType type);
////check neighbors
//    void destroyObjects(Player& player, Enemies& enemy, Bomb bomb, Map& map, CellType type);

//    void destroyBlocks(Map& map);

//    void destroyEnemies(Enemies& enemy, Player& player, Map map);

//    void killPlayer(Player player, Map map);

};

#endif // BOMB_H
