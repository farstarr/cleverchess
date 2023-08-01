#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSound>
#include <regist.h>
#include <sign.h>
#include <QThread>
#include "mythread.h"

GameMenu::GameMenu(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::GameMenu)
{

    //    QSound *startsound=new QSound(":/qss/backgroundmusic.mp3",this);
    //    startsound->play();

        newThread = new QThread;
        myObject = new myThread;
        myObject->moveToThread(newThread);


        //创建帮助按钮
        GPushButton *musicbutn = new GPushButton(":/res/music.png",":/res/music.png");
        musicbutn->setParent(this);
        musicbutn->move(750,500);

        //点击play进入选关
        connect(musicbutn, &GPushButton::clicked,[=]{
            qDebug()<< "进入到选关场景";

            //延时跳转，以展示动画
            QTimer::singleShot(300,this,[=]{
                connect(newThread,SIGNAL(started()),myObject,SLOT(startThreadSlot()));
                newThread->start();
            });
        });
        //设置固定尺寸
        this->setFixedSize(890,590);

        //设置标题
        this->setWindowTitle("CS国际象棋");

        //设置图标(QPixMap也可)
        this->setWindowIcon(QIcon(":/res/tubiao.png"));

        //创建选关场景

        form=new Form;
        ssign=new sign;
                // cb = new chessboard;
        //创建play按钮
        //this->cb->show();
        GPushButton * playBtn = new GPushButton(":/res/sign.png",":/res/sign2.png");
        playBtn->setParent(this);
        playBtn->move(this->width() * 0.5 - playBtn->width() * 0.5, this->height() * 0.5);

        //点击play进入选关
        connect(playBtn, &GPushButton::clicked,[=]{
            qDebug()<< "进入到选关场景";

            //延时跳转，以展示动画
            QTimer::singleShot(300,this,[=]{
              this->ssign->show();//帮助场景 显示
                this->hide();//当前窗口 隐藏
            });
        });




        //创建regist按钮
        GPushButton * helpBtn = new GPushButton(":/res/regist.png",":/res/regist2.png");
        helpBtn->setParent(this);
        helpBtn->move(this->width() * 0.5 - helpBtn->width() * 0.5, this->height() * 0.65);

        //点击help进入帮助
        connect(helpBtn, &GPushButton::clicked,[=]{
            qDebug()<< "进入到帮助场景";

            //延时跳转，以展示动画
            QTimer::singleShot(300,this,[=]{
               this->form->show();//选关场景 显示
                this->hide();//当前窗口 隐藏
            });
        });

        //创建帮助按钮
        GPushButton *exitBtn = new GPushButton(":/res/exit3.png",":/res/exit2.png");
        exitBtn->setParent(this);
        exitBtn->move(this->width()*0.5-exitBtn->width()*0.5,this->height()*0.8);

        //点击exit退出
        connect(exitBtn, &GPushButton::clicked,[=]{
            qDebug()<< "帮助";

            //延时跳转，以展示动画
            QTimer::singleShot(300,this,[=]{
                this->close();
            });
        });

}


GameMenu::~GameMenu()
{
    delete ui;
}

void GameMenu::paintEvent(QPaintEvent *)
{
    //创建画家对象
    QPainter painter(this);
    //创建PixMap对象
    QPixmap pix;
    //加载图片
    pix.load(":/res/bbk.png");
    //画背景图 重载的后两个参数是拉伸
    painter.drawPixmap(0,0,890,590,pix);
    //加载标题资源
    pix.load(":/res/tittl.png");
    //拉伸图片
    pix = pix.scaled(pix.width()*0.8,pix.height()*0.8);
    //画标题boxman
    painter.drawPixmap(this->width()*0.5-pix.width()*0.5,130,pix);

}

