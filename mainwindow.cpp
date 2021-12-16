#include "mainwindow.h"
#include "ui_mainwindow.h"


#include "Game.h"
Game* bomberman;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap bkgnd(":/pictures/bombermanPic/mainwindowBACK.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);
    this->setPalette(palette);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_playButton_clicked()
{
    this->close();
    bomberman = new Game();
    bomberman->setUpGameLinks();
    bomberman->show();

}

