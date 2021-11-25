#include "Player.h"
#include "Map.h"
#include "Bomb.h"

#include <stdio.h>
#include <conio.h>
#include <stdbool.h>

#include <QList>
#include <QGraphicsScene>
#include <QKeyEvent>
//#include <QGraphicsPixmapItem>
#include <QGraphicsRectItem>
#include <QtDebug>

//Player:: Player(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
//{
//    setPixmap(QPixmap(":/pictures/bombermanPic/player.png"));
//}

Player::Player(QGraphicsItem *parent): QGraphicsRectItem(parent)
{

}

bool Player :: collidings()
{

    bool youCanMove = true;
    QList<QGraphicsItem *> collidingBlock = collidingItems();
    for (int i = 0, n = collidingBlock.size(); i < n; i++)
    {
       if ((typeid(*(collidingBlock[i])) == typeid(DestroyedBlock))
               || (typeid(*(collidingBlock[i])) == typeid(Indestructible)))
       {
         youCanMove = false;
       }

    }
    return youCanMove;
}


void Player :: action(qreal xPrevious, qreal yPrevious)
{
     if (collidings() == false)
     {
         setPos(xPrevious, yPrevious);
     }
}
//I replaced x() and y() coordinates with iPlayer and jPlayer
// and pos().x() with iPlayer and pos().y() with jPlayer
//void Player :: keyPressEvent(QKeyEvent *event)
//{
//    iPlayer = x();
//    jPlayer = y();
//    Map* map = new Map();

//    if (event->key() == Qt::Key_A)
//    {
////         if(iPlayer>0 && collidings())
//        if(iPlayer>0 && iPlayer )
//         {
//             setPos(iPlayer-5,jPlayer);
//         }
//        else
//        {
//            action(iPlayer+13, jPlayer);

//            return;
//        }

//    }
//    else if (event->key() == Qt::Key_D)
//        {
//        if(iPlayer + 75 < 800 && collidings())
//        {
//            setPos(iPlayer+5,jPlayer);
//        }
//        else
//        {
//            action(iPlayer-13, jPlayer);
//            return;
//        }
//    }
//    else if (event->key() == Qt::Key_W)
//    {
//        if(jPlayer > 0 && collidings())
//        {
//            setPos(iPlayer,jPlayer-5);
//        }
//        else
//        {
//            action(iPlayer, jPlayer+13);
//            return;

//        }
//    }
//    else if (event->key() == Qt::Key_S)
//    {
//        if(jPlayer + 75 < 600 && collidings())
//        {
//            setPos(iPlayer,jPlayer+5);
//        }
//        else
//        {
//            action(iPlayer, jPlayer-13);
//            return;
//        }
//    }else if(event->key() == Qt::Key_Space)
//    {
//        Bomb* bomb = new Bomb();
//        scene()->addItem(bomb);
//    }
//}

void Player :: keyPressEvent(QKeyEvent *event)
{
    xPlayer = x();
    yPlayer = y();
    int blockSize = 100;
    int playerSize = 75;
    int step = 10;

    Map* map = new Map();


    if (event->key() == Qt::Key_A)
    {

//        qDebug() << "x player >> " << xPlayer << " y player >> " << yPlayer;
//        qDebug() << "iMap >> " << yPlayer/blockSize << "jMap >> " << (xPlayer-step)/blockSize
//                 << map->table[(yPlayer)/blockSize][(xPlayer-step)/blockSize];
//        qDebug() << "iMap >> " << (yPlayer+playerSize)/blockSize << "jMap >> " << (xPlayer-step)/blockSize
//                 << map->table[(yPlayer+playerSize)/blockSize][(xPlayer-step)/blockSize];

        if(xPlayer - step >= 0 &&
        (map->table[(yPlayer+playerSize)/blockSize][(xPlayer-step)/blockSize] == EemptyPath)
        && (map->table[(yPlayer)/blockSize][(xPlayer-step)/blockSize] == EemptyPath))
         {

            setPos(xPlayer-step,yPlayer);
         }


    }
    else if (event->key() == Qt::Key_D)
        {

        if(xPlayer + playerSize + step <= 800 &&
            (map->table[(yPlayer+playerSize)/blockSize][(xPlayer+step+playerSize)/blockSize] == EemptyPath)
            && (map->table[(yPlayer)/blockSize][(xPlayer+step+playerSize)/blockSize] == EemptyPath))
        {

            setPos(xPlayer+step,yPlayer);
        }
    }
    else if (event->key() == Qt::Key_W)
    {
        if(yPlayer - step >= 0 &&
                (map->table[(yPlayer-step)/blockSize][(xPlayer+playerSize)/blockSize] == EemptyPath)
                && (map->table[(yPlayer-step)/blockSize][(xPlayer)/blockSize] == EemptyPath))
        {
            setPos(xPlayer,yPlayer-step);
        }
    }
    else if (event->key() == Qt::Key_S)
    {
     if(yPlayer + playerSize + step <= 600 &&
             (map->table[(yPlayer+step+playerSize)/blockSize][(xPlayer+playerSize)/blockSize] == EemptyPath)
             && (map->table[(yPlayer+step+playerSize)/blockSize][(xPlayer)/blockSize] == EemptyPath))
        {

            setPos(xPlayer,yPlayer+step);
        }
    }else if(event->key() == Qt::Key_Space)
    {
        Bomb* bomb = new Bomb();
        scene()->addItem(bomb);
    }
}


/*
Player :: Player(int i, int j, Map& map)
{
    iPlayer = i;
    jPlayer = j;
    map.setCellValue(iPlayer, jPlayer, 4);
}

int Player :: getIPosition()
{
    return iPlayer;
}
int Player :: getJPosition()
{
    return jPlayer;
}

bool Player:: youCanMoveUp(Map map)
{
    if (map.table[iPlayer - 1][jPlayer] == EemptyPath && (iPlayer - 1) >= 0)
    {
    return true;
    }
    else
    {
    return false;
    }
}

bool Player :: youCanMoveDown(Map map)
{
    if (map.table[iPlayer + 1][jPlayer] == EemptyPath && (iPlayer + 1) < 8)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool Player :: youCanMoveRight(Map map)
{
    if (map.table[iPlayer][jPlayer + 1] == EemptyPath && (jPlayer + 1) < 9)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Player :: youCanMoveLeft(Map map)
{
    if (map.table[iPlayer][jPlayer - 1] == EemptyPath && (jPlayer - 1) >= 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void Player :: movement(Player& player, Map& map, bool& isQuite)
{
    int iTemp = iPlayer;
    int jTemp = jPlayer;
    rewind(stdin);
    if(kbhit())
    {
        switch (getch())
        {


            case 'a':
            {
                if(youCanMoveLeft(map))
                {
                    map.setCellValue(iPlayer, --jPlayer, Eplayer);
                    iTemp = iPlayer;
                    jTemp = jPlayer;
                    map.setCellValue(iTemp, ++jTemp, EemptyPath);
                }
                break;
            }
            case 'd':
            {
                if(youCanMoveRight(map))
                {

                    map.setCellValue(iPlayer, ++jPlayer, Eplayer);
                    iTemp = iPlayer;
                    jTemp = jPlayer;
                    map.setCellValue(iTemp, --jTemp, EemptyPath);
                }
                break;
            }
            case 'w':
            {
                if(youCanMoveUp(map))
                {
                    map.setCellValue(--iPlayer, jPlayer, Eplayer);
                    iTemp = iPlayer;
                    jTemp = jPlayer;
                    map.setCellValue(++iTemp, jTemp, EemptyPath);
                }
                break;
            }
            case 's':
            {
                if(youCanMoveDown(map))
                {
                    map.setCellValue(++iPlayer, jPlayer, Eplayer);
                    iTemp = iPlayer;
                    jTemp = jPlayer;
                    map.setCellValue(--iTemp, jTemp, EemptyPath);
                }
                break;
            }
            case 'x':
            {
                isQuite = false;
                break;
            }
        }
    }
}
*/

//сделать по границам клетки пермещение и коллизию так же
