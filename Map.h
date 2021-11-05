#ifndef MAP_H
#define MAP_H


#include <QGraphicsScene>
#include <QGraphicsPathItem>
#include <QGraphicsObject>
#include <QGraphicsItem>

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
        int table[8][9] =
            {
                {2, 2, 2, 2, 2, 2, 2, 2, 2},
                {2, 0, 0, 0, 0, 1, 1, 0, 2},
                {2, 0, 2, 0, 2, 0, 2, 0, 2},
                {2, 0, 0, 1, 0, 0, 0, 0, 2},
                {2, 0, 2, 0, 2, 0, 2, 0, 2},
                {2, 0, 0, 0, 0, 1, 1, 0, 2},
                {2, 0, 1, 1, 0, 0, 0, 0, 2},
                {2, 2, 2, 2, 2, 2, 2, 2, 2}
            };
//        int iMap;
//        int jMap;
        public:

        friend class Player;
        friend class Bomb;
        friend class Enemies;

        Map(QGraphicsItem* parent = 0);


        void setCellValue(int i, int j, int value);
        void outputCTable();


};


#endif // MAP_H
