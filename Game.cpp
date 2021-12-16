#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include <QBrush>
#include <QImage>
#include <QGraphicsRectItem>

#include "Game.h"

class EnemyMoveLeftRight;
class EnemyMoveUpDown;

Game::Game(QWidget* parent)
{
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);

    setBackgroundBrush(QBrush(QImage(":/pictures/bombermanPic/ground.png")));

    map = new Map(scene);

    health = new Health();
    health->setPos(health->x()+600,health->y()+25);
    scene->addItem(health);

    player = new Player();
    player->setPos(0, 0);
//    player->setRect(0, 0, 75, 75);
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

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
