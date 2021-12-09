//
// Created by gaydi on 09.12.2021.
//

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

#endif //BOMBERMANQT_HEALTH_H
