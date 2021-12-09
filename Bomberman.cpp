#include "Bomberman.h"


#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include <QBrush>
#include <QImage>
#include <QGraphicsRectItem>

Bomberman::Bomberman(QWidget* parent)
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
    health->setPos(health->x(),health->y()+25);
    scene->addItem(health);

    player = new Player(*map, *health);

    enemyUpDown = new EnemyMoveUpDown(UP_DOWN, 410, 110, *map, *player);
    enemyLeftRight = new EnemyMoveLeftRight(LEFT_TO_RIGHT, 100, 400, *map, *player);

    player->setRect(0, 0, 75, 75);
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();


    scene->addItem(enemyUpDown);
    scene->addItem(enemyLeftRight);
    scene->addItem(player);



    show();
//    enemyUpDown->moveEnemyUpDown();
}
