#include "widget.h"
#include <QApplication>
#include "Player.h"
#include "Bomberman.h"
#include <QGraphicsScene>
#include <QGraphicsView>

Bomberman* bomberman;

int main(int argc, char *argv[]){
    QApplication a(argc, argv);

    bomberman = new Bomberman();
    bomberman->show();

    return a.exec();
}
