#include "canju1.h"
#include "board.h"
#include "ui_board.h"
#include <QMessageBox>
#include <QMouseEvent>
#include <QLabel>
#include <QString>
#include<QDebug>
#include<QTimer>
#include"Step.h"
#include"Stone.h"
#include <QPixmap>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "exdispid.h"
#include "ui_exitapp.h"
#include "exitapp.h"
#include "help.h"
#include "inform.h"
#include "singlegame.h"
#include "canju.h"
#include "canjuwindow.h"
#include <windows.h>
canju1::canju1(QWidget *parent) : Board(parent)
{
    //this->resize(561,557);
    QPalette palette;
    QPixmap pixmap(":/res/cbb.png");
    setFixedSize(pixmap.size());   //让窗口大小就是棋盘图片的大小
    palette.setBrush(QPalette::Window, QBrush(pixmap));
    this->setPalette(palette);
      chesstype();
        _selectid = -1;
        _bRedTurn = true;
        //设置标题
         this->setWindowTitle("残局2");
        //新开游戏的按钮，功能为棋子归位重开一局
        GPushButton * newgame = new GPushButton(":/res/newgame.png",":/res/newgamecopy.png");
        newgame->setParent(this);
        newgame->move(25,25);
        QString str=QString::fromUtf8("newgame");
        newgame->setToolTip(str);
        connect(newgame,&QPushButton::clicked,[=]{

            this->close();
            Board *b=new Board();
            b->show();
        });
        //读取游戏的按钮，功能为读取上一次的棋盘
        GPushButton * loadgame = new GPushButton(":/res/loadgame.png",":/res/loadgame.png");
        loadgame->setParent(this);
        loadgame->move(80,25);
        QString str1=QString::fromUtf8("loadgame");
        loadgame->setToolTip(str1);
        connect(loadgame,&QPushButton::clicked,[=]{

           chesstype();
           update();
           Sleep(500);
           qDebug()<<"共有"<<st<<"步";
            for(int j=0;j<2*st;j+=2)
            {
                fupan(j);

            }
                });
        //残局按钮，点击选择所需残局
        GPushButton * endgame = new GPushButton(":/res/endgame.png",":/res/endgame.png");
        endgame->setParent(this);
        endgame->move(135,25);
        QString str6=QString::fromUtf8("endgame");
        endgame->setToolTip(str6);
        connect(endgame,&QPushButton::clicked,[=]{
            this->close();
            canjuwindow *c=new canjuwindow();
            c->show();
        });
        //帮助按钮，点击将显示国际象棋规则
        GPushButton * helps = new GPushButton(":/res/helpgame.png",":/res/helpgame.png");
        helps->setParent(this);
        helps->move(190,25);
        QString str2=QString::fromUtf8("help");
        helps->setToolTip(str2);
        help *he=new help();
        connect(helps,&QPushButton::clicked,he,&QWidget::show);
        //信息按钮，点击将显示本游戏相关信息
        GPushButton * informs = new GPushButton(":/res/inform.png",":/res/inform.png");
        informs->setParent(this);
        informs->move(245,25);
        QString str3=QString::fromUtf8("information");
        informs->setToolTip(str3);
        inform *inf=new  inform();
        connect(informs,&QPushButton::clicked,inf,&QWidget::show);
        //人机按钮，点击进入人机对战
        GPushButton * ai = new GPushButton(":/res/AI.png",":/res/AI.png");
        ai->setParent(this);
        ai->move(300,25);
        QString str5=QString::fromUtf8("AI practice");
        ai->setToolTip(str5);
        connect(ai,&QPushButton::clicked,[=]{

            this->close();
            Singlegame *s=new Singlegame();
            s->show();
        });
        //退出游戏按钮，即点即退
        GPushButton * exitgame = new GPushButton(":/res/exitgame.png",":/res/exitgame.png");
        exitgame->setParent(this);
        exitgame->move(355,25);
        QString str4=QString::fromUtf8("exit");
        exitgame->setToolTip(str4);
        exitapp *e=new exitapp();
        connect(exitgame,&QPushButton::clicked,e,&QWidget::show);
        //创建save按钮
        GPushButton * sa = new GPushButton(":/res/save.png",":/res/save.png");
        sa->setParent(this);
        sa->move(640,340);
        QString s=QString::fromUtf8("Save");
        sa->setToolTip(s);
        connect(sa,&QPushButton::clicked,[=]{

            if(st==0)
                  QMessageBox::information(NULL,  "提示","存档失败！", QMessageBox::Yes);
              if(st!=0)
                  QMessageBox::information(NULL,  "提示","存档成功！", QMessageBox::Yes);
        });
        //创建悔棋按钮
        GPushButton * re = new GPushButton(":/res/huiqi.png",":/res/huiqi.png");
        re->setParent(this);
        re->move(640,420);
        QString r=QString::fromUtf8("Regret");
        re->setToolTip(r);
        connect(re,&QPushButton::clicked,[=]{
                  huiqi();
                });
        //创建认输按钮
        GPushButton * de= new GPushButton(":/res/defeat.png",":/res/defeat.png");
        de->setParent(this);
        de->move(640,500);
        QString d=QString::fromUtf8("Abandon");
        de->setToolTip(d);
        connect(de,&QPushButton::clicked,[=]{
            QString str = _bRedTurn?QStringLiteral("黑棋获胜!"):QStringLiteral("白棋获胜!");
            QMessageBox::information(NULL,  "GAME OVER",str, QMessageBox::Yes);
                });
          update();

}

canju1::~canju1()
{

}
void canju1::chesstype(){
    for(int i=0;i<32;i++)
        {
            _s[i].canju2(i);
            if(i>3){
                _s[i]._dead=true;
            }
        }
}
void canju1::drawStone(QPainter & p, int id)
{
    if(_s[id]._dead||id>=3)
    {
        return;
    }
    //如果该id棋子被选中，则
    QPoint c=center(id);
    QRect rect = QRect(c.x()+5,c.y(),50,50);
    if(id == _selectid)
    {
        p.drawImage(QRect(c.x()+2,c.y()-5,60,60),QImage(":/res/choose1.png"));
    }

    if(id==0)p.drawImage(rect,pic[4]);
    if(id==1)p.drawImage(rect,pic[20]);
    if(id==2)p.drawImage(rect,pic[19]);
}

