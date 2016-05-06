#include "Score.h"
#include <QFont>

Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    // initialize the score to 0
    score = 0;

    // draw the text
    setPlainText(QString("Score: ") + QString::number(score)); // Score: 0
    setDefaultTextColor(Qt::blue);
    setFont(QFont("bold",30));
}

void Score::increase()
{
    setPlainText(QString("Score: ") + QString::number(score)); // Score: 1
    score++;
    setPlainText(QString("Score: ") + QString::number(score)); // Score: 1
}

int Score::getScore()
{
    return score;
}

void Score::restart()
{
    score = 0;
    setPlainText(QString("Score: ") + QString::number(score)); // Score: 0
}
