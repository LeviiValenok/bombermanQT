#ifndef INDESTRUCTIBLE_H
#define INDESTRUCTIBLE_H


#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsRectItem>


//public QGraphicsPixmapItem
class IndestructibleBlock: public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    IndestructibleBlock(QGraphicsItem* parent = 0);
};

#endif // INDESTRUCTIBLE_H
