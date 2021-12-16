#ifndef DESTRUCTIBLEBLOCK_H
#define DESTRUCTIBLEBLOCK_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsRectItem>
#include <QPaintEvent>

#include "MapCell.h"

//#include "Block.h"
//

class DestructibleBlock:  virtual public MapCell
{

public:
    DestructibleBlock(int x, int y, CellType type, QGraphicsItem* parent = nullptr) : MapCell(type)
    {
        setPixmap(QPixmap(":/pictures/bombermanPic/broken.png"));
    }
    void removeBlock(DestructibleBlock& block);
    friend class Bomb;
};

#endif
