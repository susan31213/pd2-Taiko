#ifndef HOW_H
#define HOW_H

#include <QDialog>

namespace Ui {
class How;
}

class How : public QDialog
{
    Q_OBJECT

public:
    explicit How(QWidget *parent = 0);
    ~How();

private slots:
    void on_pushButton_clicked();

private:
    Ui::How *ui;
};

#endif // HOW_H
