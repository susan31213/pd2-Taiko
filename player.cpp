#include "player.h"
#include <QGraphicsScene>
#include <QApplication>
#include <QKeyEvent>
#include <QTimer>
#include "hit.h"
#include "hit2.h"
#include "taiko.h"
#include "time.h"
#include "game.h"
#include "taiko2.h"

#include <QDebug>
extern Game * game;

QTimer * timer;

Player::Player(QGraphicsItem *parent): QGraphicsPixmapItem(parent) {
    // set the picture
    setPixmap(QPixmap(":/images/player.png"));

    // make/connect a timer to count down
    timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(timego()));

    // start the timer
    timer->start(1000);
}

void Player::keyPressEvent(QKeyEvent *event){

    // hit taiko with F & J
    if (event->key() == Qt::Key_F)
    {
        Hit * hit = new Hit();
        hit->setPos(x(),y());
        scene()->addItem(hit);
    }
    else if (event->key() == Qt::Key_J)
    {
        Hit2 * hit2 = new Hit2();
        hit2->setPos(x(),y());
        scene()->addItem(hit2);
    }
}

void Player::timerstart()
{
    timer->start(1000);
}

void Player::spawn(){
    // create an taiko
    if(qrand()%2==0){
    Taiko * taiko = new Taiko();
    scene()->addItem(taiko);
    }
    else {
    Taiko2 * taiko2 = new Taiko2();
    scene()->addItem(taiko2);
    }
}

void Player::timego()
{
    game->mytime->decrease();
    if(game->mytime->time < 1) {
        timer->stop();
        game->gameOver();
    }

}
