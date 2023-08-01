#ifndef GAMEMENU_H
#define GAMEMENU_H

#include <QMainWindow>
#include <QPainter>
#include <QPixmap>
#include <QTimer>
#include "gpushbutton.h"
#include "QSound"
#include "regist.h"
#include "sign.h"
#include <QThread>
#include <windows.h>
#include "mythread.h"
QT_BEGIN_NAMESPACE
namespace Ui { class GameMenu; }
QT_END_NAMESPACE

class GameMenu : public QMainWindow
{
    Q_OBJECT

public:
    GameMenu(QWidget *parent = nullptr);
    ~GameMenu();
    void on_label_clicked();
    //重写绘图事件
    void paintEvent(QPaintEvent *);

   //QLabel *label ;
    //创建选关窗口对象

    Form * form;
    sign *ssign;

    //创建帮助窗口

     void xiancheng(int);
private:
    Ui::GameMenu *ui;
    myThread *myObject;
    QThread *newThread;
};
#endif // GAMEMENU_H
