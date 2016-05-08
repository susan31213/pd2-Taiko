#include "game.h"
#include <QTimer>
#include "taiko.h"
#include <QGraphicsTextItem>
#include <QFont>
#include "result.h"
#include <QBrush>
#include <QImage>
#include <QMovie>
#include <QLabel>
#include <QMediaPlayer>

QTimer * tt;
QMediaPlayer * music;

Game::Game(QWidget * parent)
{    
    //creat a scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,1024,576); // make the scene
    scene->setBackgroundBrush (QBrush(QImage(":/images/bg1.png")));

    // make the newly created scene the scene to visualize (since Game is a QGraphicsView Widget,
    // it can be used to visualize scenes)
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1024,576);

    // create the player
    player = new Player();
    player->setPos(60,400); // TODO generalize to always be in the middle bottom of screen
    // make the player focusable and set it to be the current focus
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    // add the player to the scene
    scene->addItem(player);

    //creat the score
    score = new Score();
    score->setPos(score->x()+150,score->y()+50);
    scene->addItem(score);

    //creat the time
    mytime = new Time();
    mytime->setPos(mytime->x()+150,mytime->y()+130);
    scene->addItem(mytime);

    // spawn taiko
    tt = new QTimer();
    QObject::connect(tt,SIGNAL(timeout()),player,SLOT(spawn()));
    tt->start(800);

    //gif
    QMovie *movie1 = new QMovie(":/images/200.gif");
    QLabel* label1 = new QLabel(this);
    label1->setGeometry(35,200,958,119);
    label1->setMovie(movie1);
    movie1->start();

    //bgm
    music = new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sounds/bgsound.mp3"));
    music->play();

}

void Game::gameOver()
{
    //stop timer and music
    tt->stop();
    music->stop();

    //creat a result window
    Result * rr = new Result();
    rr->show();
}

void Game::restart()
{
    //restart timer and music
    tt->start(1000);
    music->play();
    player->timerstart();

    //reset score and time
    score->restart();
    mytime->restart();

}
