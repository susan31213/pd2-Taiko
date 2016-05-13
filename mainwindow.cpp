#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsScene>
#include "game.h"
#include "how.h"
#include <QMediaPlayer>
#include <QTimer>

Game * game;
How * how;
QMediaPlayer * bgm;
QTimer * timerm;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setFixedSize(1024,576);

    bgm = new QMediaPlayer();
    bgm->setMedia(QUrl("qrc:/sounds/start.mp3"));
    bgm->play();

    // make/connect a timer to count down
    timerm = new QTimer();
    connect(timerm,SIGNAL(timeout()),this,SLOT(replay()));

    // start the timer
    timerm->start(96500);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    this->hide();
    bgm->stop();
    game = new Game(this);
    game->show();

}

void MainWindow::on_pushButton_2_clicked()
{
    this->close();
}

void MainWindow::on_pushButton_3_clicked()
{
    how = new How(this);
    how->show();
}

void MainWindow::replay()
{
    bgm->play();
}
