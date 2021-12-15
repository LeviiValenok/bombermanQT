#ifndef DESTRUCTIBLEBLOCK_H
#define DESTRUCTIBLEBLOCK_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsRectItem>
#include <QPaintEvent>

#include "MapCell.h"



class DestructibleBlock:  public MapCell
{
    Q_OBJECT
public:

//    DestructibleBlock(QGraphicsItem * parent=0);
    DestructibleBlock(int x, int y, CellType type, QGraphicsItem* parent = nullptr) : MapCell(type)
    {

    }


    void removeBlock(DestructibleBlock& block);
//      DestructibleBlock(QGraphicsItem * parent=0);
    friend class Bomb;

};

#endif