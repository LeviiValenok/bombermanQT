//
// Created by gaydi on 05.12.2021.
//

#include "MapCell.h"
#include <QGraphicsScene>

MapCell::MapCell(CellType cellType)
{
    type = cellType;
}

void MapCell::removeItem(MapCell *item)
{
    scene()->removeItem(this);
}

MapCell::MapCell()
{

}