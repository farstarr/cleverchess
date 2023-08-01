#include "canjuwindow.h"
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
#include "windows.h"
Singlegame::Singlegame(QWidget *parent) : Board(parent)
{

    _level = 3;

    QPalette palette;
    QPixmap pixmap(":/res/cbb.png");
    setFixedSize(pixmap.size());   //让窗口大小就是棋盘图片的大小
    palette.setBrush(QPalette::Window, QBrush(pixmap));
    this->setPalette(palette);
      chesstype();
        _selectid = -1;
        _bRedTurn = true;
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
        connect(loadgame,&QPushButton::clicked,[=]{
      chesstype();
      update();
      Sleep(500);
      qDebug()<<"共有"<<st<<"步";
       for(int k=0;k<st;k++)
       {

           if(k%2==0)

               fupan(k);
           else
           {  Sleep(1000);
                fupan2(k);}

       }
        });
        loadgame->setToolTip(str1);
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
                  huiqi2();

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
void Singlegame:: huiqi2()
{


    if(this->bu.size() == 0) return;//this->_steps.size() == 0&&
       Step* sst = this->bu.last();

       //上一步操作将棋子移动到空白位置
       if(sst->_killId==-1)
       {
           //只要将moveId的行列修改就可以了
           _s[sst->_moveId]._row=sst->_rowPre;
           _s[sst->_moveId]._col=sst->_colPre;
          _bRedTurn=!_bRedTurn;

           update();qDebug() << "机器悔棋了" << endl;
       }
       else
       {
           //需要将killId棋子状态恢复，将moveId棋子状态恢复
           _s[sst->_moveId]._row=sst->_rowPre;
           _s[sst->_moveId]._col=sst->_colPre;
           _s[sst->_killId]._dead=false;
           _s[sst->_killId]._row=sst->_rowNow;
           _s[sst->_killId]._col=sst->_colNow;
          _bRedTurn=!_bRedTurn;
           update();
           qDebug() << "机器悔棋了" << endl;
       }
       //_bRedTurn=true;
       bu.removeLast();
       //恢复棋子的所有状态
       //刚开始棋局，那么悔棋无效

       Step* step = this->_steps.last();

       //上一步操作将棋子移动到空白位置
       if(step->_killId==-1)
       {
           //只要将moveId的行列修改就可以了
           _s[step->_moveId]._row=step->_rowPre;
           _s[step->_moveId]._col=step->_colPre;
           _bRedTurn=!_bRedTurn;

           update();qDebug() << "悔棋了" << endl;
       }
       else
       {
           //需要将killId棋子状态恢复，将moveId棋子状态恢复
           _s[step->_moveId]._row=step->_rowPre;
           _s[step->_moveId]._col=step->_colPre;
           _s[step->_killId]._dead=false;
           _s[step->_killId]._row=step->_rowNow;
           _s[step->_killId]._col=step->_colNow;
           _bRedTurn=!_bRedTurn;
           update();qDebug() << "悔棋了" << endl;
       }
       _steps.removeLast();
       st-=2;
       delete sst; delete step;
}
Singlegame::~Singlegame()
{

}

void Singlegame::back()
{
    if(_bRedTurn)
    {
        backOne();
        backOne();
    }
}
void Singlegame::fupan2(int j)
{

    if(this->bu.size() == 0) return;
    Step* step = this->bu[(j-1)/2];
      QApplication::processEvents();
     qDebug()<<"在Bu数组中的序号是"<<(j-1)/2;
    //上一步操作将棋子移动到空白位置
     QApplication::processEvents();
   if(step->_killId==-1)
    {
       qDebug() << "移动的棋子id是" <<step->_moveId<< endl;
        qDebug() << "从" <<_s[step->_moveId]._row<<"行";
        //只要将moveId的行列修改就可以了
        _s[step->_moveId]._row=step->_rowNow;

                qDebug() << "到" <<_s[step->_moveId]._row<<"行"<< endl;
        _s[step->_moveId]._col=step->_colNow;
     //  _bRedTurn=!_bRedTurn;
      //_bRedTurn!=true?ui->label->setText(s):ui->label->setText(ss);

        update();
      QApplication::processEvents();

  }
    else
   {
         //需要将killId棋子状态恢复，将moveId棋子状态恢复
       QApplication::processEvents();
       qDebug() << "移动的棋子id是" <<step->_moveId<< endl;
        qDebug() << "从" <<_s[step->_moveId]._row<<"行";
        _s[step->_killId]._dead=true;
        QApplication::processEvents();

        _s[step->_moveId]._row=step->_rowNow;

           qDebug() << "到" <<_s[step->_moveId]._row<<"行"<< endl;
        _s[step->_moveId]._col=step->_colNow;


       // _bRedTurn=!_bRedTurn;
     //   _bRedTurn!=true?ui->label->setText(s):ui->label->setText(ss);
        update();

    }
 qDebug() << "以上是机器复盘" << endl;
    delete step;
    Sleep(1000);


}


void Singlegame::click(int id, int row, int col)
{
    if(_bRedTurn)
    {
        Board::click(id, row, col);
        if(!_bRedTurn)
        {
            QTimer::singleShot(100, this, SLOT(computerMove()));

        }
    }
}

void Singlegame::computerMove()
{

    Step* step = getBestMove();
    saveStep(step->_moveId, step->_killId, step->_rowNow, step->_colNow,bu);
    Sleep(1000);
    moveStone(step->_moveId, step->_killId, step->_rowNow, step->_colNow);
    delete step;
    right=true;
    update();


}

Step* Singlegame::getBestMove()
{

    Step* ret = NULL;
    QVector<Step*> steps;
    right=false;
    getAllPossibleMove(steps);
    int maxInAllMinScore = -300000;

    while(steps.count())
    {
        Step* step = steps.back();
        steps.removeLast();

        fakeMove(step);
        int minScore = getMinScore(this->_level-1, maxInAllMinScore);
        unfakeMove(step);

        if(minScore > maxInAllMinScore)
        {
            if(ret) delete ret;

            ret = step;
            maxInAllMinScore = minScore;
        }
        else
        {
            delete step;
        }
    }

    return ret;
}

int Singlegame::score()
{
  //  {WANG,TA,QI,HOU,BING,ZHUJIAO};
    static int s[] = {10000, 500, 350, 1000, 100, 400};
    int scoreBlack = 0;
    int scoreWhite = 0;
    for(int i=16; i<32; ++i)
    {
        if(_s[i]._dead) continue;
        scoreWhite += s[_s[i]._type];
    }
    for(int i=0; i<16; ++i)
    {
        if(_s[i]._dead) continue;
        scoreBlack += s[_s[i]._type];
    }

    return scoreBlack - scoreWhite;
}

int Singlegame::getMinScore(int level, int curMin)
{
    if(level == 0)
        return score();

    QVector<Step*> steps;
    getAllPossibleMove(steps);//whitechessmove
    int minInAllMaxScore = 300000;

    while(steps.count())
    {
        Step* step = steps.back();
        steps.removeLast();

        fakeMove(step);
        int maxScore = getMaxScore(level-1, minInAllMaxScore);
        unfakeMove(step);
        delete step;

        if(maxScore <= curMin)
        {
            while(steps.count())
            {
                Step* step = steps.back();
                steps.removeLast();
                delete step;
            }
            return maxScore;
        }

        if(maxScore < minInAllMaxScore)
        {
            minInAllMaxScore = maxScore;
        }


    }

    return minInAllMaxScore;
}
int Singlegame::getMaxScore(int level, int curMax)
{
    if(level == 0)
        return score();

    QVector<Step*> steps;
    getAllPossibleMove(steps);
    int maxInAllMinScore = -300000;

    while(steps.count())
    {
        //ren=false;
        Step* step = steps.back();
        steps.removeLast();

        fakeMove(step);
        int minScore = getMinScore(level-1, maxInAllMinScore);
        unfakeMove(step);
        delete step;

        if(minScore >= curMax)
        {
            while(steps.count())
            {
                Step* step = steps.back();
                steps.removeLast();
                delete step;
            }
            return minScore;
        }
        if(minScore > maxInAllMinScore)
        {
            maxInAllMinScore = minScore;
        }


    }

    return maxInAllMinScore;
}


void Singlegame::fakeMove(Step *step)
{
    killStone(step->_killId);
    moveStone(step->_moveId, step->_rowNow, step->_colNow);

}

void Singlegame::unfakeMove(Step *step)
{
    reliveStone(step->_killId);
    moveStone(step->_moveId, step->_rowPre, step->_colPre);

}

void Singlegame::getAllPossibleMove(QVector<Step *> &steps)
{
    int min, max;
    if(this->_bRedTurn)
    {
        min = 16, max = 32;
    }
    else
    {
        min = 0, max = 16;
    }

    for(int i=min;i<max; i++)
    {
        if(this->_s[i]._dead) continue;
        for(int row = 0; row<=7; ++row)
        {
            for(int col=0; col<=7; ++col)
            {
                int clickid = this->getStoneId(row, col);
                if(clickid!=-1&&_s[clickid]._red) continue;

                if(canMove(i, clickid, row, col))
                {
                    saveStep(i, clickid, row, col, steps);

                }
            }
        }
    }

}
