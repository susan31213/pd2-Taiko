#include "taiko.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QKeyEvent>

Taiko::Taiko(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){

    //set random x position (like random time spawn)
    setPos(1024+qrand()%800,400);

    // set the picture
    setPixmap(QPixmap(":/images/taiko11.png"));

    // make/connect a timer to move() the enemy every so often
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    // start the timer

    timer->start(25);
}

void Taiko::move(){
    // move taiko left
    setPos(x()-10,y());

    // destroy taiko when it goes out of the hit area
    if (pos().x() < 35){
        scene()->removeItem(this);
        delete this;
    }
}
