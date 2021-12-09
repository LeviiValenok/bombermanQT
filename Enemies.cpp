//
// Created by gaydi on 31.10.2021.
//

#include "Enemies.h"
#include "Player.h"


Enemies :: Enemies(DirectionOfTravel setDirection, int x, int y, Map& map): map(&map)
{
    direction =  setDirection;
    xEnemy = x;
    yEnemy = y;

}

Enemies :: ~Enemies()
{

}
Enemies ::Enemies(Map& map, QGraphicsItem *parent): QGraphicsRectItem(parent), map(&map)
{

}

/*

void Enemies :: addItems()
{
    Enemies *enemyUP = new Enemies(UP_DOWN);
    int blockSize = 100;
    int enemySize = 75;
    if (enemyUP->map->table[])
    if ((mtable[iEnemy/blockSize][jEnemy/blockSize])->type == EMPTY)
    {
        Enemies *enemy = new Enemies();
        enemy->setRect(jEnemy, iEnemy, enemySize, enemySize);
        scene->addItem(enemy);
    }
}
*/


//void Enemies :: move(Map& map, Enemies& enemy)
//{
//    int blockSize = 100;
//    int enemySize = 75;
//    int step = 10;
//    while ((map.table[(iEnemy+enemySize)/blockSize][jEnemy/blockSize])->type == EMPTY)
//    {
//        setPos(jEnemy, iEnemy+step);
//        iEnemy=+step;
//    }
//    }


/*void Enemies :: collisionWithPlayer(Player player, Enemies enemy)
{
    int iPlayer = player.iPlayer;
    int jPlayer = player.jPlayer;
    if (enemy.enemiesCoordinate[iEnemy][jEnemy] == player.playerCoordinate[iPlayer][jPlayer])
    {
        player.health--;
        if (player.health == 0)
        {
            std::cout << "Game is over :( " << std::endl;
        }
    }
}*/
