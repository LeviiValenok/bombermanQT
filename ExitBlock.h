#ifndef EXITBLOCK_H
#define EXITBLOCK_H
#include "MapCell.h"

class ExitBlock : public MapCell
{
public:
    ExitBlock(CellType type ):MapCell(type)
    {

    }
};

#endif // EXITBLOCK_H
