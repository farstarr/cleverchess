#ifndef FORGETPASS_H
#define FORGETPASS_H

#include <QWidget>

namespace Ui {
class forgetpass;
}

class forgetpass : public QWidget
{
    Q_OBJECT

public:
    explicit forgetpass(QWidget *parent = nullptr);
    ~forgetpass();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::forgetpass *ui;
};

#endif // FORGETPASS_H
