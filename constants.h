#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <stdbool.h>

enum CellType
{
    EMPTY = 0,
    DESTRUCTIBLE_BLOCK = 1,
    INDESTRUCTIBLE_BLOCK = 2,
    BOMB = 3,
    EXIT = 4,
};

const int initializationsTable[6][8] =
        {
                { 0, 0, 0, 0, 1, 1, 0, 1},
                { 0, 2, 0, 2, 0, 2, 0, 1},
                { 0, 0, 1, 0, 0, 0, 0, 4},
                { 0, 2, 0, 2, 0, 2, 0, 2},
                { 0, 0, 0, 0, 1, 1, 0, 2},
                { 0, 1, 1, 0, 0, 0, 0, 2},
        };

#endif
