#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsScene>
#include "game.h"
#include "how.h"

Game * game;
How * how;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setFixedSize(1024,576);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    this->hide();
    game = new Game();
    game->show();

}

void MainWindow::on_pushButton_2_clicked()
{
    this->close();
}

void MainWindow::on_pushButton_3_clicked()
{
    how = new How();
    how->show();
}
