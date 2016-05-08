#include "result.h"
#include "ui_result.h"
#include "game.h"
#include <QMovie>
#include <QLabel>
#include <QMediaPlayer>

extern Game *game;


Result::Result(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Result)
{
    ui->setupUi(this);

    //set sound
    QMediaPlayer * bgm = new QMediaPlayer();
    bgm->setMedia(QUrl("qrc:/sounds/gameover.mp3"));
    bgm->play();

    //copy score
    ss.score = game->score->score;
    ui->label->setText(QString("Score: ") + QString::number(ss.score));

    //gif
    QMovie *movie1 = new QMovie(":/images/ch1.gif");
    QLabel* label1 = new QLabel(this);
    label1->setGeometry(350,180,200,200);
    label1->setMovie(movie1);
    movie1->start();

}

Result::~Result()
{
    delete ui;
}

void Result::on_exit_clicked()
{
    this->close();
    game->close();
}

void Result::on_retry_clicked()
{
    game->restart();
    this->close();
}
