
#include "DestroyedBlock.h"
#include "Map.h"
#include <iostream>

#include <QGraphicsScene>

Map :: Map(QGraphicsItem* parent):QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/pictures/bombermanPic/ground.png"));
}



void Map :: setCellValue(int i, int j, int value)
{
    table[i][j] = value;
}

void Map :: outputCTable()
{
    system("cls");
    for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (table[i][j] == Eindestructible)
                {
                    std::cout << "#";
                }else if(table[i][j] == EdestroyedBlock)
                {
                    std::cout << "0";
                }else if(table[i][j] == EemptyPath)
                {
                    std::cout << ' ';
                }else if(table[i][j] == Eplayer)
                {
                    std::cout << '4';
                }else if(table[i][j] == Eenemies)
                {
                    std::cout << '5';
                }
            }
         std::cout << "\n";
        }
}

