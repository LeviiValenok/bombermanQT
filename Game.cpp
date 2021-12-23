
#include <QGraphicsTextItem>
#include <QBrush>
#include <QImage>
#include <QGraphicsRectItem>
#include <iostream>
#include "Game.h"
#include <cstdlib>

class EnemyMoveLeftRight;
class EnemyMoveUpDown;

void Game::gameIsOver() {

    std::exit(0);
}



Game::Game(int level, QWidget* parent) : level(1)
{

    scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, 800, 600);
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800, 600);

    setBackgroundBrush(QBrush(QImage(":/pictures/bombermanPic/ground.png")));

    map = new Map(level, scene);

    health = new Health();
    health->setPos(health->x() + 600, health->y() + 25);
    scene->addItem(health);

    player = new Player();
    player->setPos(0, 0);
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

//    std::unique_ptr<EnemyMoveUpDown> enemyUpDown (new EnemyMoveUpDown(UP_DOWN, 410, 110));
    enemyUpDown = new EnemyMoveUpDown(UP_DOWN, 410, 110);
    enemyLeftRight = new EnemyMoveLeftRight(LEFT_TO_RIGHT, 100, 400);

    scene->addItem(enemyUpDown);
    scene->addItem(enemyLeftRight);
    scene->addItem(player);

    show();

}

void Game::setUpGameLinks()
{
    map->setGame(this);
    player->setGame(this);
    enemyUpDown->setGame(this);
    enemyLeftRight->setGame(this);

}

void Game::setBomb(qreal xBomb, qreal yBomb)
{
   Bomb* bomb = new Bomb(xBomb, yBomb, this);

    this->scene->addItem(bomb);
}

void Game ::goToTheNextLevel()
{
    level++;
//    connect(this, SIGNAL(this->level > 2),this,SLOT(gameIsOver()));
    if (level > 2)
    {
        endGame = new GameIsWin();
        endGame->setPos(endGame->x() + 180, endGame->y() + 240);
        scene->addItem(endGame);
        timer = new QTimer(this);
        connect(timer,SIGNAL(timeout()),this,SLOT(gameIsOver()));
        timer->start(3000);

        return;
    }

    clearFocus();

    delete scene;

    scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, 800, 600);
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800, 600);

    setBackgroundBrush(QBrush(QImage(":/pictures/bombermanPic/groundLevel2.png")));
    if (!enemyLeftRight.isNull())
    {
        scene->removeItem(enemyLeftRight);
        delete enemyLeftRight;
    }
    if (!enemyUpDown.isNull())
    {
        scene->removeItem(enemyUpDown);
        delete enemyUpDown;
    }


    enemyUpDown = new EnemyMoveUpDown(UP_DOWN, 410, 110);
    enemyLeftRight = new EnemyMoveLeftRight(LEFT_TO_RIGHT, 100, 400);

    scene->addItem(enemyLeftRight);
    scene->addItem(enemyUpDown);

    scene->removeItem(map);
    delete map;
    map = new Map(level, scene);
    scene->addItem(map);

    scene->removeItem(health);
    delete health;
    health = new Health();
    health->setPos(health->x() + 600, health->y() + 25);
    scene->addItem(health);

    delete player;
    player = new Player();

    player->setPos(0, 0);
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    scene->addItem(player);

    this->setUpGameLinks();
    show();
}
