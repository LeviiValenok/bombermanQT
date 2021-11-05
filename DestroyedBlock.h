#ifndef DESTROYEDBLOCK_H
#define DESTROYEDBLOCK_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class DestroyedBlock: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    DestroyedBlock(qreal x, qreal y, QGraphicsItem* parent = 0);
};

#endif // DESTROYEDBLOCK_H
