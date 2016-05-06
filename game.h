#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "score.h"
#include "taiko.h"
#include "player.h"
#include "time.h"



class Game: public QGraphicsView{
public:
    Game(QWidget * parent=0);
    // objects
    QGraphicsScene * scene;
    Player * player;
    Taiko * taiko;
    Score * score;
    Time * mytime;

    //member function
    void gameOver();
    void restart();

};

#endif // GAME_H
