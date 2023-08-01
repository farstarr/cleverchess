#ifndef FORM_H
#define FORM_H
#include "board.h"
#include <QWidget>

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = nullptr);
    ~Form();
    QLineEdit *pwdLEd;
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();   //这个格式就行

private:
    Ui::Form *ui;
};

#endif // FORM_H
