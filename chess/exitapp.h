#ifndef EXITAPP_H
#define EXITAPP_H

#include <QWidget>

namespace Ui {
class exitapp;
}

class exitapp : public QWidget
{
    Q_OBJECT

public:
    explicit exitapp(QWidget *parent = nullptr);
    ~exitapp();
private slots:   //这个格式就行
    void on_exityes_clicked();
    void on_exitno_clicked();
private:
    Ui::exitapp *ui;
};

#endif // EXITAPP_H
