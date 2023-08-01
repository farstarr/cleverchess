#ifndef GPUSHBUTTON_H
#define GPUSHBUTTON_H

#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QString>
#include <QDebug>

class GPushButton : public QPushButton
{
    Q_OBJECT
public:
    explicit GPushButton(QObject *parent = nullptr);

    //重写构造函数 两个参数分别传入正常情况和按下情况的图片路径
    GPushButton(QString normalImg, QString pressImg = "");

    QString normalPath;
    QString pressPath;

    //重写鼠标摁下事件
    void mousePressEvent(QMouseEvent *event);

    //重写鼠标释放事件
    void mouseReleaseEvent(QMouseEvent *event);

signals:

};

#endif // GPUSHBUTTON_H
