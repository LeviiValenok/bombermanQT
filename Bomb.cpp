#include "Bomb.h"
#include "Player.h"
#include "Map.h"

#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <QGraphicsItem>
#include <stdbool.h>

//void Bomb::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
//{
//    QPolygon polygon;
//    polygon << QPoint(300,200) << QPoint(225,300) << QPoint(300,300)
//            << QPoint(300, 400) << QPoint(375, 400) << QPoint(375, 300) << QPoint(450, 300)
//            <<  QPoint(450, 200) << QPoint(375, 200) << QPoint(375, 100) << QPoint(300, 100);
//    painter->setBrush(Qt::black);
//    painter->drawPolygon(polygon);
//    Q_UNUSED(option);
//    Q_UNUSED(widget);
//}

Bomb::Bomb(qreal x, qreal y, Game* game): QObject(), QGraphicsRectItem()
{
    this->game = game;
    int bombSize = 75;
    setRect(x, y, bombSize, bombSize);
    xBomb = x;
    yBomb = y;
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(destroyItem()));
    timer->start(3000);


}

void Bomb :: destroyItem() {
    int blockSize = 100;
    int bombSize = 75;

    Map* map = this->game->map;

    if ((yBomb - bombSize) > 0 && ((map->table[(yBomb - bombSize) / blockSize][(xBomb + bombSize) / blockSize])->type == DESTRUCTIBLE_BLOCK ||
                                   ((map->table[(yBomb - bombSize) / blockSize][(xBomb) / blockSize])->type == DESTRUCTIBLE_BLOCK)))
    {
        map->table[(yBomb - bombSize) / blockSize][xBomb / blockSize]->removeItem(map->table[(yBomb - bombSize) / blockSize][xBomb / blockSize]);
        map->setEmptyCell((yBomb - bombSize) / blockSize, xBomb / blockSize);
    }

    if(yBomb < 500 && ((map->table[(yBomb + 2* bombSize)/blockSize][(xBomb)/blockSize])->type == DESTRUCTIBLE_BLOCK ||
                       ((map->table[(yBomb + 2*bombSize)/blockSize][(xBomb+bombSize)/blockSize])->type == DESTRUCTIBLE_BLOCK)))
    {
        map->table[(yBomb + 2*bombSize)/blockSize][(xBomb+bombSize)/blockSize]->removeItem(map->table[(yBomb + 2*bombSize)/blockSize][(xBomb+bombSize)/blockSize]);
        map->setEmptyCell((yBomb + 2*bombSize)/blockSize, (xBomb+bombSize)/blockSize);
    }
    if ((xBomb - bombSize) > 0 && ((map->table[yBomb/blockSize][xBomb/blockSize])->type == DESTRUCTIBLE_BLOCK ||
                                   (map->table[yBomb/blockSize][(xBomb - bombSize)/blockSize])->type == DESTRUCTIBLE_BLOCK))
    {
        map->table[yBomb/blockSize][(xBomb - bombSize)/blockSize]->removeItem(map->table[yBomb/blockSize][(xBomb - bombSize)/blockSize]);
        map->setEmptyCell(yBomb/blockSize, (xBomb - bombSize)/blockSize);
    }

    if ((xBomb + bombSize) < 700 && ((map->table[yBomb/blockSize][(xBomb+bombSize)/blockSize])->type == DESTRUCTIBLE_BLOCK ||
                                     (map->table[yBomb/blockSize][(xBomb + 2*bombSize)/blockSize])->type == DESTRUCTIBLE_BLOCK))
    {
        map->table[yBomb/blockSize][(xBomb + 2*bombSize)/blockSize]->removeItem(map->table[yBomb/blockSize][(xBomb + 2*bombSize)/blockSize]);
        map->setEmptyCell(yBomb/blockSize, (xBomb + 2*bombSize)/blockSize);
    }

    scene()->removeItem(this);
    delete timer;
}
