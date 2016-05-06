#ifndef TAIKO2_H
#define TAIKO2_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class Taiko2: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT

public:
    Taiko2(QGraphicsItem * parent=0);

public slots:
    void move();
};

#endif // TAIKO2_H
