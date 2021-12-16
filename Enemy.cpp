#include "Enemy.h"


Enemy::Enemy(DirectionOfTravel setDirection, int x, int y, QGraphicsItem *parent)
{
    direction =  setDirection;
    xEnemy = x;
    yEnemy = y;
}

Enemy:: ~Enemy(){}

void Enemy::setGame(Game* game)
{
    this->game = game;
}
/*

void Enemy :: addItems()
{
    Enemy *enemyUP = new Enemy(UP_DOWN);
    int blockSize = 100;
    int enemySize = 75;
    if (enemyUP->map->table[])
    if ((mtable[iEnemy/blockSize][jEnemy/blockSize])->type == EMPTY)
    {
        Enemy *enemyUpDown = new Enemy();
        enemyUpDown->setRect(jEnemy, iEnemy, enemySize, enemySize);
        scene->addItem(enemyUpDown);
    }
}
*/


//void Enemy :: move(Map& map, Enemy& enemyUpDown)
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


/*void Enemy :: collisionWithPlayer(Player player, Enemy enemyUpDown)
{
    int iPlayer = player.iPlayer;
    int jPlayer = player.jPlayer;
    if (enemyUpDown.enemiesCoordinate[iEnemy][jEnemy] == player.playerCoordinate[iPlayer][jPlayer])
    {
        player.health--;
        if (player.health == 0)
        {
            std::cout << "Game is over :( " << std::endl;
        }
    }
}*/
