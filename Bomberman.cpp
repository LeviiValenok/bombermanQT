#include "Bomberman.h"


#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
Bomberman::Bomberman(QWidget* parent)
{
    // create the scene
     // make the scene 800x600 instead of infinity by infinity (default)

    // make the newly created scene the scene to visualize (since Game is a QGraphicsView Widget,
    // it can be used to visualize scenes)
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);

    map = new Map();
    player = new Player();



    player->setPos(400,500);
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    scene ->addItem(map);
    scene->addItem(player);


    scene->addItem(new DestroyedBlock(200, 0));
    scene->addItem(new DestroyedBlock(200, 150));
    scene->addItem(new DestroyedBlock(300, 150));
    scene->addItem(new DestroyedBlock(400, 150));

    // add the player, map and blocks to the scene


    show();
}
