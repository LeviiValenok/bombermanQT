#ifndef BOMBERMANQT_HEALTH_H
#define BOMBERMANQT_HEALTH_H


#include <QGraphicsTextItem>

class Health: public QGraphicsTextItem
{
public:
    Health(QGraphicsItem * parent=0);
    void decrease();
    int getHealth();
private:
    int health;
};

#endif
