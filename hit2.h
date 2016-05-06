#ifndef HIT2_H
#define HIT2_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>

class Hit2: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Hit2(QGraphicsItem * parent=0);
public slots:
    void check();
};

#endif // HIT2_H
