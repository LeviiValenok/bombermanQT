#ifndef DESTRUCTIBLEBLOCK_H
#define DESTRUCTIBLEBLOCK_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsRectItem>
#include <QPaintEvent>

#include "MapCell.h"

//#include "Block.h"
//, public QGraphicsPixmapItem

class DestructibleBlock:  public MapCell
{
Q_OBJECT
public:
    DestructibleBlock(int x, int y, CellType type, QGraphicsItem* parent = nullptr) : MapCell(type) {}
    void removeBlock(DestructibleBlock& block);
    friend class Bomb;
};

#endif
