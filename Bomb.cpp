//
// Created by gaydi on 25.10.2021.
//

#include "Bomb.h"
#include "Player.h"
#include "Map.h"



#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <QGraphicsItem>
#include <stdbool.h>
#include <QDebug>




//void Bomb::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
//{
//    QPolygon polygon;
//    polygon << QPoint(300,200) << QPoint(225,300) << QPoint(300,300)
//            << QPoint(300, 400) << QPoint(375, 400) << QPoint(375, 300) << QPoint(450, 300)
//            <<  QPoint(450, 200) << QPoint(375, 200) << QPoint(375, 100) << QPoint(300, 100);
//    painter->setBrush(Qt::black);
//    painter->drawPolygon(polygon);
//    Q_UNUSED(option);
//    Q_UNUSED(widget);
//}


Bomb::Bomb(qreal x, qreal y): QObject(), QGraphicsRectItem()
{
    int bombSize = 75;
    setRect(x, y, bombSize, bombSize);

}

void Bomb :: destroyItem(qreal x, qreal y, Bomb* bomb, Map &map) {
    int blockSize = 100;
    int xBomb = x;
    int yBomb = y;
    int bombSize = 75;
    bool bombIsExploded = false;

    if ((yBomb - bombSize) > 0 && ((map.table[(yBomb - bombSize) / blockSize][(xBomb + bombSize) / blockSize])->type == DESTRUCTIBLE_BLOCK ||
        ((map.table[(yBomb - bombSize) / blockSize][(xBomb) / blockSize])->type == DESTRUCTIBLE_BLOCK)))
    {
       map.table[(yBomb - bombSize) / blockSize][xBomb / blockSize]->
       removeItem(map.table[(yBomb - bombSize) / blockSize][xBomb / blockSize]);
        map.table[(yBomb - bombSize) / blockSize][xBomb / blockSize]->type = EMPTY;
        bombIsExploded = true;
    }

    if(yBomb < 500 && ((map.table[(yBomb + 2* bombSize)/blockSize][(xBomb)/blockSize])->type == DESTRUCTIBLE_BLOCK ||
    ((map.table[(yBomb + 2*bombSize)/blockSize][(xBomb+bombSize)/blockSize])->type == DESTRUCTIBLE_BLOCK)))
    {
        map.table[(yBomb + 2*bombSize)/blockSize][(xBomb+bombSize)/blockSize]->
        removeItem(map.table[(yBomb + 2*bombSize)/blockSize][(xBomb+bombSize)/blockSize]);
        map.table[(yBomb + 2*bombSize)/blockSize][(xBomb+bombSize)/blockSize]->type = EMPTY;
        bombIsExploded = true;
    }
    if ((xBomb - bombSize) > 0 && ((map.table[yBomb/blockSize][xBomb/blockSize])->type == DESTRUCTIBLE_BLOCK ||
            (map.table[yBomb/blockSize][(xBomb - bombSize)/blockSize])->type == DESTRUCTIBLE_BLOCK))
    {
        map.table[yBomb/blockSize][(xBomb - bombSize)/blockSize]->
        removeItem(map.table[yBomb/blockSize][(xBomb - bombSize)/blockSize]);
        map.table[yBomb/blockSize][(xBomb - bombSize)/blockSize]->type = EMPTY;
        bombIsExploded = true;
    }

    if ((xBomb + bombSize) < 700 && ((map.table[yBomb/blockSize][(xBomb+bombSize)/blockSize])->type == DESTRUCTIBLE_BLOCK ||
    (map.table[yBomb/blockSize][(xBomb + 2*bombSize)/blockSize])->type == DESTRUCTIBLE_BLOCK))
    {
        map.table[yBomb/blockSize][(xBomb + 2*bombSize)/blockSize]->
        removeItem(map.table[yBomb/blockSize][(xBomb + 2*bombSize)/blockSize]);
        map.table[yBomb/blockSize][(xBomb + 2*bombSize)/blockSize]->type = EMPTY;
        bombIsExploded = true;
    }

    if (bombIsExploded)
    {
        scene()->removeItem(bomb);
    }

}


void Bomb:: setPosition(int x, int y)
{


    setPos(x, y);
}


//Bomb::Bomb(QGraphicsItem *parent): QGraphicsRectItem(parent)
//{

//}



//void Bomb::bombDetonation()
//{
//    QList<QGraphicsItem*> collisionWithItems = collidingItems();
//    for (int i = 0, n = collisionWithItems.size(); i < n; i++)
//    {
//       if (typeid(*(collisionWithItems[i])) == typeid(DestructibleBlock))
//       {
//           scene()->removeItem(collisionWithItems[i]);
//                      scene()->removeItem(this);
//                      // delete them both
//                      delete collisionWithItems[i];
//                      delete this;
//                      return;
//       }

//    }
//}




//#include "Map.h"
//#include "Enemies.h"


//Bomb::Bomb(): QObject(), QGraphicsRectItem()
//{
//   setRect(0, 0, 30, 30);
//}

/*
void Bomb :: setBomb (Player player, Map& map)
{
    iBomb = player.getIPosition();
    jBomb = player.getJPosition();
    map.setCellValue(iBomb, jBomb, Ebomb);

}


void Bomb :: destroyEnemies(Enemies& enemyUpDown, Player& player, Map map)
{
    //TODO: timer???
    //TODO: Change enemyUpDown's coordinate to current enemyUpDown coordinate
    //TODO: Get current enemyUpDown coordinate
    int iEnemyCurrent = enemyUpDown.iEnemy;
    int jEnemyCurrent = enemyUpDown.jEnemy;
    int enemyCurrentLocation = enemyUpDown.enemiesCoordinate[iEnemyCurrent][jEnemyCurrent];
    if (bombCoordinate[iBomb][jBomb] == enemyCurrentLocation ||
        bombCoordinate[iBomb + 1][jBomb] == enemyCurrentLocation ||
        bombCoordinate[iBomb - 1][jBomb] == enemyCurrentLocation ||
        bombCoordinate[iBomb][jBomb + 1] == enemyCurrentLocation ||
        bombCoordinate[iBomb][jBomb - 1] == enemyCurrentLocation)
    {
        //destroy an enemyUpDown
        player.score++;
    }
}


void Bomb :: killPlayer(Player player, Map map)
{
    int iPlayerCurrent = player.iPlayer;
    int jPlayerCurrent = player.jPlayer;
    int playerCurrenLocation = player.playerCoordinate[iPlayerCurrent][jPlayerCurrent];
    if (bombCoordinate[iBomb][jBomb] == playerCurrenLocation ||
        bombCoordinate[iBomb + 1][jBomb] == playerCurrenLocation ||
        bombCoordinate[iBomb - 1][jBomb] == playerCurrenLocation ||
        bombCoordinate[iBomb][jBomb + 1] == playerCurrenLocation ||
        bombCoordinate[iBomb][jBomb - 1] == playerCurrenLocation)
    {
        player.health--;
    }

}

//try destroy
void  Bomb :: chooseATarget(Player& player, Enemies& enemyUpDown, Bomb bomb, int iBombCurrent, int jBombCurrent, Map& map, CellType type)
{
    switch (bomb.bombCoordinate[iBombCurrent][jBombCurrent])
    {
        case DESTRUCTIBLE_BLOCK:
        {
            map.initializationsTable[iBombCurrent][jBombCurrent] = EMPTY;
            break;
        }
        case Eenemies:
        {
            //destroy enemyUpDown;
            break;
        }
        case Eplayer:
        {
            player.health--;
            if (player.health == 0) {
                std::cout << "Game is over :( " << std::endl;
            }
            break;
        }
    }
}
//check neighbors
void Bomb :: destroyObjects(Player& player, Enemies& enemyUpDown, Bomb bomb, Map& map, CellType type)
{
    int iPlayerCurrent = player.iPlayer;
    int jPlayerCurrent = player.jPlayer;
    int iEnemyCurrent = enemyUpDown.iEnemy;
    int jEnemyCurrent = enemyUpDown.jEnemy;

    if (bomb.bombCoordinate[iBomb][jBomb] == DESTRUCTIBLE_BLOCK ||
        bomb.bombCoordinate[iBomb][jBomb] == Eenemies || bomb.bombCoordinate[iBomb][jBomb] == Eplayer)
    {
        chooseATarget(player, enemyUpDown, bomb, iBomb, jBomb, map, type);
    }
    if (bomb.bombCoordinate[iBomb + 1][jBomb] == DESTRUCTIBLE_BLOCK ||
        bomb.bombCoordinate[iBomb + 1][jBomb] == Eenemies || bomb.bombCoordinate[iBomb + 1][jBomb] == Eplayer)
    {
        chooseATarget(player, enemyUpDown, bomb, iBomb + 1, jBomb, map, type);
    }
    if (bomb.bombCoordinate[iBomb - 1][jBomb] == DESTRUCTIBLE_BLOCK ||
        bomb.bombCoordinate[iBomb - 1][jBomb] == Eenemies || bomb.bombCoordinate[iBomb - 1][jBomb] == Eplayer)
    {
        chooseATarget(player, enemyUpDown, bomb, iBomb - 1, jBomb, map, type);
    }
    if (bomb.bombCoordinate[iBomb][jBomb + 1] == DESTRUCTIBLE_BLOCK ||
        bomb.bombCoordinate[iBomb][jBomb + 1] == Eenemies || bomb.bombCoordinate[iBomb][jBomb + 1] == Eplayer)
    {
        chooseATarget(player, enemyUpDown, bomb, iBomb, jBomb + 1, map, type);
    }
    if (bomb.bombCoordinate[iBomb][jBomb - 1] == DESTRUCTIBLE_BLOCK ||
        bomb.bombCoordinate[iBomb][jBomb - 1] == Eenemies || bomb.bombCoordinate[iBomb][jBomb - 1] == Eplayer)
    {
        chooseATarget(player, enemyUpDown, bomb, iBomb, jBomb - 1, map, type);
    }
}

void Bomb :: destroyBlocks(Map& map)
{
    if (bombCoordinate[iBomb][jBomb] == 1)
    {
        map.initializationsTable[iBomb][jBomb] = 0;
    }
    else if (bombCoordinate[iBomb + 1][jBomb] == 1)
    {
        map.initializationsTable[iBomb + 1][jBomb] = 0;
    }
    else if (bombCoordinate[iBomb - 1][jBomb] == 1)
    {
        map.initializationsTable[iBomb - 1][jBomb] = 0;
    } else if (bombCoordinate[iBomb][jBomb + 1] == 1)
    {
        map.initializationsTable[iBomb][jBomb + 1] = 0;
    } else if (bombCoordinate[iBomb][jBomb - 1] == 1)
    {
        map.initializationsTable[iBomb][jBomb - 1] =0;
    }
}
*/

