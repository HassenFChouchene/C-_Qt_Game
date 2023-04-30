#include "mainwindow.h"
#include <QApplication>
#include <QGraphicsScene>
#include "Myrect.h"
#include <QGraphicsView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //Create a scene

    QGraphicsScene * scene = new QGraphicsScene();

    Myrect * player = new  Myrect();

    player->setRect(0,0,100,100);

    scene->addItem(player);

    player -> setFlag(QGraphicsItem::ItemIsFocusable);
    player -> setFocus();

    QGraphicsView * view = new QGraphicsView(scene);

    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    view->show();

    view->setFixedSize(800,600);
    view->setSceneRect(0,0,800,600);

    player->setPos(view->width()/2,view->height()-player->rect().height());


    return a.exec();
}
