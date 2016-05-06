#include "how.h"
#include "ui_how.h"

How::How(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::How)
{
    ui->setupUi(this);
}

How::~How()
{
    delete ui;
}

void How::on_pushButton_clicked()
{
    this->close();
}
