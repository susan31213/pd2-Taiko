#ifndef TIME_H
#define TIME_H

#include <QGraphicsTextItem>

class Time: public QGraphicsTextItem{

public:
    Time(QGraphicsItem * parent=0);
    int getTime();
    void decrease();
    int time;
    void restart();
};

#endif // TIME_H
