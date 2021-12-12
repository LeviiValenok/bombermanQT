//
// Created by gaydi on 05.12.2021.
//

#ifndef BOMBERMANQT_CONSTANTS_H
#define BOMBERMANQT_CONSTANTS_H

#endif
#include <stdbool.h>


enum CellType
{
    EMPTY = 0,
    DESTRUCTIBLE_BLOCK = 1,
    INDESTRUCTIBLE_BLOCK = 2,
    BOMB = 3,
};

const int initializationsTable[6][8] =
    {
        { 0, 0, 0, 0, 1, 1, 0, 1},
        { 0, 2, 0, 2, 0, 2, 0, 1},
        { 0, 0, 1, 0, 0, 0, 0, 0},
        { 0, 2, 0, 2, 0, 2, 0, 2},
        { 0, 0, 0, 0, 1, 1, 0, 2},
        { 0, 1, 1, 0, 0, 0, 0, 2},
    };

