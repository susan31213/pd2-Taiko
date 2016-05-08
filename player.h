#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QMediaPlayer>

class Player:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Player(QGraphicsItem * parent=0);
    void keyPressEvent(QKeyEvent * event);
    void delay();
    void timerstart();
public slots:
    void spawn();
    void timego();
private:
    QMediaPlayer * hitsound;
    QMediaPlayer * hit2sound;
};

#endif // PLAYER_H
