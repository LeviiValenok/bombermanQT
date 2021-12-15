#include "DestructibleBlock.h"

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>

#include <QPainterPath>

//DestructibleBlock::DestructibleBlock(qreal x, qreal y, QGraphicsItem *parent): QGraphicsPixmapItem(parent)
//{
//    setPixmap(QPixmap(":/pictures/bombermanPic/broken.png"));
//    setPos(x, y);
//}


//DestructibleBlock ::
//    DestructibleBlock(int x, int y, CellType type, QGraphicsItem *parent): MapCell(type)
//{
//
//}
//DestructibleBlock :: DestructibleBlock(QGraphicsItem *parent): QGraphicsRectItem(parent)
//{
//
//}

void DestructibleBlock :: removeBlock(DestructibleBlock &block)
{
    scene()->removeItem(this);
}


