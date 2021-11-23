#ifndef INDESTRUCTIBLE_H
#define INDESTRUCTIBLE_H


#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsRectItem>
//public QGraphicsPixmapItem
class Indestructible: public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    Indestructible(qreal x, qreal y, QGraphicsItem* parent = 0);
};

#endif // INDESTRUCTIBLE_H
