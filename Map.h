#ifndef MAP_H
#define MAP_H


#include <QGraphicsScene>
#include <QGraphicsPathItem>
#include <QGraphicsObject>
#include <QGraphicsItem>

#include "DestroyedBlock.h"

enum cellType
{
    EemptyPath = 0,
    EdestroyedBlock = 1,
    Eindestructible = 2,
    Ebomb = 3,
    Eplayer = 4,
    Eenemies = 5
};


//add value exit

class Map : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

    private:
        cellType type;
        int table[6][8] =
            {
                { 0, 0, 0, 0, 1, 1, 0, 1},
                { 0, 2, 0, 2, 0, 2, 0, 1},
                { 0, 0, 1, 0, 0, 0, 0, 0},
                { 0, 2, 0, 2, 0, 2, 0, 2},
                { 0, 0, 0, 0, 1, 1, 0, 2},
                { 0, 1, 1, 0, 0, 0, 0, 2},
            };
//        int iMap;
//        int jMap;
        public:

        friend class Player;
        friend class Bomb;
        friend class Enemies;

        Map(QGraphicsScene* scene, QGraphicsItem* parent = 0);
        void outputField(QGraphicsScene* scene);


        void setCellValue(int i, int j, int value);
//        void outputCTable();


};


#endif // MAP_H
