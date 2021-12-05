//
// Created by gaydi on 05.12.2021.
//

#ifndef BOMBERMANQT_MAPCELL_H
#define BOMBERMANQT_MAPCELL_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsRectItem>

#include "constants.h"

class MapCell: public QObject, public QGraphicsRectItem
{
public:
    CellType type;
    int iIndex;
    int jIndex;
    MapCell(CellType cellType);
    MapCell& operator=(const MapCell* right)
    {
        type = right->type;
        iIndex = right->iIndex;
        jIndex = right->jIndex;
        return *this;
    }
    MapCell();
    void removeItem(MapCell* item);
};


#endif //BOMBERMANQT_MAPCELL_H
