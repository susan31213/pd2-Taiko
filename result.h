#ifndef RESULT_H
#define RESULT_H

#include <QDialog>
#include "score.h"

namespace Ui {
class Result;
}

class Result : public QDialog
{
    Q_OBJECT

public:
    explicit Result(QWidget *parent = 0);
    Score ss;
    ~Result();

private slots:
    void on_exit_clicked();

    void on_retry_clicked();

private:
    Ui::Result *ui;
};

#endif // RESULT_H
