

#include "IndestructibleBlock.h"
#include <iostream>
#include <stdlib.h>
#include <QGraphicsScene>

#include "Map.h"

Map :: Map(QGraphicsScene* scene, QGraphicsItem* parent): QGraphicsPixmapItem(parent)
{
    outputField(scene);
}


Map :: Map() {}

void Map::setGame(Game* game)
{
    this->game = game;
}

void Map::outputField(QGraphicsScene *scene)
{

    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if(initializationsTable[i][j] == DESTRUCTIBLE_BLOCK)
            {
                DestructibleBlock* destroyedBlock = new DestructibleBlock(j, i, DESTRUCTIBLE_BLOCK);
                destroyedBlock->setRect(j*100, i*100, 100, 100);
                scene->addItem(destroyedBlock);
                table[i][j] = destroyedBlock;
            } else
            {
                EmptyBlock* emptyBlock = new EmptyBlock(EMPTY);
                table[i][j] = emptyBlock;
            }
            if(initializationsTable[i][j] == INDESTRUCTIBLE_BLOCK)
            {
                IndestructibleBlock* indestrictableBlock = new IndestructibleBlock(j, i, INDESTRUCTIBLE_BLOCK);
                indestrictableBlock->setRect(j*100, i*100, 100, 100);
                scene->addItem(indestrictableBlock);
                table[i][j] = indestrictableBlock;
            }
        }
    }
//    EnemyMoveUpDown* enemyUpDown = new EnemyMoveUpDown(UP_DOWN);
//        scene->addItem(enemyUpDown);
}

void Map::setEmptyCell(int i, int j)
{
    this->table[i][j]->type = EMPTY;
}



//void Map :: setCellValue(int i, int j, int value)
//{
//    initializationsTable[i][j] = value;
//}



//void Map :: outputCTable()
//{
//    system("cls");
//    for (int i = 0; i < 9; i++)
//        {
//            for (int j = 0; j < 9; j++)
//            {
//                if (initializationsTable[i][j] == INDESTRUCTIBLE_BLOCK)
//                {
//                    std::cout << "#";
//                }else if(initializationsTable[i][j] == DESTRUCTIBLE_BLOCK)
//                {
//                    std::cout << "0";
//                }else if(initializationsTable[i][j] == EMPTY)
//                {
//                    std::cout << ' ';
//                }else if(initializationsTable[i][j] == Eplayer)
//                {
//                    std::cout << '4';
//                }else if(initializationsTable[i][j] == Eenemies)
//                {
//                    std::cout << '5';
//                }
//            }
//         std::cout << "\n";
//        }
//}


//для доступа к блокам надо их куда-то записывать
//создать переменную класса map которая будет хранить созданные объекты
