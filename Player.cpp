#include "Player.h"
#include "Map.h"
#include "Bomb.h"

#include <stdio.h>
#include <conio.h>
#include <stdbool.h>

#include <QList>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QGraphicsPixmapItem>

Player:: Player(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/pictures/bombermanPic/player.png"));
}

bool Player :: collidings()
{

    bool youCanMove = true;
    QList<QGraphicsItem *> collidingBlock = collidingItems();
    for (int i = 0, n = collidingBlock.size(); i < n; i++)
    {
       if (typeid(*(collidingBlock[i])) == typeid(DestroyedBlock))
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

void Player :: keyPressEvent(QKeyEvent *event)
{

    if (event->key() == Qt::Key_A)
    {
        if(pos().x()>0 && collidings())
         {
             setPos(x()-5,y());
         }
        else
        {
            action(x()+5, y());
        }


//        else
//        {
//            setPos(xPrevious, yPrevious);
//        }
    }
    else if (event->key() == Qt::Key_D)
        {
        if(pos().x() + 75 < 800 && collidings())
        {
            setPos(x()+5,y());
        }
        else
        {
            action(x()-5, y());
        }
//        else
//        {
//            setPos(xPrevious, yPrevious);
//        }
    }
    else if (event->key() == Qt::Key_W)
    {
        if(pos().y() > 0 && collidings())
        {
            setPos(x(),y()-5);
        }
        else
        {
            action(x(), y()+5);
        }
    }
    else if (event->key() == Qt::Key_S)
    {
        if(pos().y() + 100 < 600 && collidings())
        {
            setPos(x(),y()+5);
        }
        else
        {
            action(x(), y()-5);
        }
    }else if(event->key() == Qt::Key_Space)
    {
        Bomb *bomb = new Bomb(x(), y());
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
