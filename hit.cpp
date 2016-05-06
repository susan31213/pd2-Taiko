#include "hit.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "taiko.h"
#include "game.h"
#include <typeinfo>

extern Game * game; // there is an external global object called game

Hit::Hit(QGraphicsItem *parent)
{
    // set the picture
    setPixmap(QPixmap(":/images/hit1.png"));

    // make/connect a timer to check() if hit on taiko every so often
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(check()));

    // start the timer
    timer->start(80);
}

void Hit::check()
{
    // get a list of all the items currently colliding with this bullet
    QList<QGraphicsItem *> colliding_items = collidingItems();

    // if one of the colliding items is an Enemy, destroy both the bullet and the enemy
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(Taiko)){
            // increase the score
            game->score->increase();

            // remove them from the scene (still on the heap)
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);

            // delete them from the heap to save memory
            delete colliding_items[i];
            delete this;

            // return (all code below refers to a non existint bullet)
            return;
        }
        else {
            scene()->removeItem(this);
            delete this;
        return;
        }
    }

}
