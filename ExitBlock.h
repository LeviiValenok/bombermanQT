#ifndef EXITBLOCK_H
#define EXITBLOCK_H
#include "MapCell.h"

class ExitBlock : public MapCell
{
public:
    ExitBlock(CellType type, QGraphicsItem* parent = nullptr ):MapCell(type)
    {
        setPixmap(QPixmap(":/pictures/bombermanPic/door.png"));
    }
};

#endif // EXITBLOCK_H
