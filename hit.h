#ifndef HIT_H
#define HIT_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>

class Hit: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Hit(QGraphicsItem * parent=0);
public slots:
    void check();
};

#endif // HIT_H
