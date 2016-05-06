#include "time.h"
#include <QTimer>
#include <QFont>
#include "game.h"

#include <QDebug>

extern Game * game;

Time::Time(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    // initialize the time to 30sec
    time = 30;

    // draw the text
    setPlainText(QString("Time: ") + QString::number(time)); // Time: 30
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",30));
}

void Time::decrease()
{
    time--;
    setPlainText(QString("Time: ") + QString::number(time)); // Time: 29
    if(time < 1) {
        return;
    }
}

void Time::restart()
{
    time = 30;
    setPlainText(QString("Time: ") + QString::number(time)); // Time: 30
}

int Time::getTime()
{
    return time;
}
