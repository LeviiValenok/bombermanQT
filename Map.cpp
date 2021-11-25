
#include "DestroyedBlock.h"
#include "Indestructible.h"
#include "Map.h"
#include <iostream>

#include <QGraphicsScene>
#include <QDebug>

Map :: Map(QGraphicsScene* scene, QGraphicsItem* parent):QGraphicsPixmapItem(parent)
{

    outputField(scene);
//    setPixmap(QPixmap(":/pictures/bombermanPic/ground.png"));

}


Map :: Map()
{

}

void Map::outputField(QGraphicsScene *scene)
{

//        system("cls");
//        QPainter painter(this);
        for (int i = 0; i < 6; i++)
            {
                for (int j = 0; j < 8; j++)
                {
                   if(table[i][j] == EdestroyedBlock)
                    {
//                       qDebug() << "table [i][j] " << table[i][j];
//                       qDebug() << "i "<<i;
//                       qDebug() << "j "<<j;
                       DestroyedBlock* destroyedBlock = new DestroyedBlock();
                       destroyedBlock->setRect(j*100, i*100, 100, 100);
                       scene->addItem(destroyedBlock);
                       qDebug() << "Destroyed block is created i " << i << "j " << j;
                    }
                   if(table[i][j] == Eindestructible)
                   {
                       Indestructible* indestrictableBlock = new Indestructible();
                       indestrictableBlock->setRect(j*100, i*100, 100, 100);
                       scene->addItem(indestrictableBlock);
                       qDebug() << "Indestructable block is created i " << i << "j " << j;
                   }
                }
            }
}




//void Map :: setCellValue(int i, int j, int value)
//{
//    table[i][j] = value;
//}



//void Map :: outputCTable()
//{
//    system("cls");
//    for (int i = 0; i < 9; i++)
//        {
//            for (int j = 0; j < 9; j++)
//            {
//                if (table[i][j] == Eindestructible)
//                {
//                    std::cout << "#";
//                }else if(table[i][j] == EdestroyedBlock)
//                {
//                    std::cout << "0";
//                }else if(table[i][j] == EemptyPath)
//                {
//                    std::cout << ' ';
//                }else if(table[i][j] == Eplayer)
//                {
//                    std::cout << '4';
//                }else if(table[i][j] == Eenemies)
//                {
//                    std::cout << '5';
//                }
//            }
//         std::cout << "\n";
//        }
//}


//для доступа к блокам надо их куда-то записывать
//создать переменную класса map которая будет хранить созданные объекты
