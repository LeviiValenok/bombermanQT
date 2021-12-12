#include "widget.h"
#include <QApplication>
#include "Player.h"
#include "Game.h"
#include <QGraphicsScene>
#include <QGraphicsView>

Game* bomberman;



int main(int argc, char *argv[]){
    QApplication a(argc, argv);

    bomberman = new Game();
    bomberman->show();

    return a.exec();
}
