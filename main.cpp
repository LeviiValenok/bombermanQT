#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>

#include "Game.h"

Game* bomberman;

int main(int argc, char *argv[]){
    QApplication a(argc, argv);

    bomberman = new Game();
    bomberman->setUpGameLinks();
    bomberman->show();

    return a.exec();
}
