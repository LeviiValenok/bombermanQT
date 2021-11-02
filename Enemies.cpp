//
// Created by gaydi on 31.10.2021.
//

#include "Enemies.h"
#include "Player.h"

Enemies :: Enemies()
{
    enemiesCoordinate[0][0];
}
Enemies :: ~Enemies()
{

}

void Enemies :: collisionWithPlayer(Player player, Enemies enemy)
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
}
