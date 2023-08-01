#ifndef SIGN_H
#define SIGN_H

#include <QWidget>

namespace Ui {
class sign;
}

class sign : public QWidget
{
    Q_OBJECT

public:
    explicit sign(QWidget *parent = nullptr);
    ~sign();

private slots:
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();   //这个格式就行
    void on_pushButton_clicked();

private:
    Ui::sign *ui;
};

#endif // SIGN_H
