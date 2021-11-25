#ifndef DESTROYEDBLOCK_H
#define DESTROYEDBLOCK_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsRectItem>
#include <QPaintEvent>
//, public QGraphicsPixmapItem
class DestroyedBlock: public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
//    DestroyedBlock(qreal x, qreal y, QGraphicsItem* parent = 0);
      DestroyedBlock(QGraphicsItem * parent=0);

};

#endif // DESTROYEDBLOCK_H
