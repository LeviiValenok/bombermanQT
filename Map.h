//#pragma once
#ifndef MAP_H
#define MAP_H

#include <QGraphicsScene>
#include <QGraphicsPathItem>
#include <QGraphicsObject>
#include <QGraphicsItem>

#include "DestructibleBlock.h"
#include "EmptyBlock.h"




//add value exit

class Map : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT


    public:
        MapCell *table[6][8];
        Map(QGraphicsScene* scene, QGraphicsItem* parent = 0);
        void outputField(QGraphicsScene* scene);
        Map();

//        void setCellValue(int i, int j, int value);
//        void outputCTable();


};


#endif