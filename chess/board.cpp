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
#include "inform.h"
#include "singlegame.h"
#include "board2.h"
#include "canju.h"
#include "canjuwindow.h"
#include "ui_canjuwindow.h"
#include <QThread>
#include "help.h"
#include <synchapi.h>
//通过id获取行列，与bool类型的获取函数相区别
#define GetRowCol(__row, __col, __id) \
    int __row = _s[__id]._row;\
    int __col = _s[__id]._col

void Board::chesstype(){
    for(int i=0;i<32;i++)
        {
            _s[i].init(i);
        }
}
Board::Board(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Board)
{

    ui->setupUi(this);
    //设置标题

    //设置图标(QPixMap也可)
    this->setWindowIcon(QIcon(":/res/tubiao.png"));
     this->setWindowTitle("游戏主界面");
    //展示该谁下了
     QFont font ( 0, 20, 75); //第一个属性是字体（微软雅黑），第二个是大小，第三个是加粗（权重是75）
     ui->label->move(650,100);
     ui->label->setText("白棋执子");
     ui-> label->setFont(font);

   //插入背景图片
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

        GPushButton * set= new GPushButton(":/res/changeco.png",":/res/changeco.png");
        set->setParent(this);
        set->move(410,25);
        QString str7=QString::fromUtf8("change");
        set->setToolTip(str7);

        connect(set,&QPushButton::clicked,[=]{
            this->close();
           board2 *boarrd2=new board2();
            boarrd2->show();






        });


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
            lose++;
            qDebug()<<lose;
            QMessageBox::information(NULL,  "GAME OVER",str, QMessageBox::Yes);
                });




          update();

}

Board::~Board()
{
    delete ui;
}



void Board::fupan(int j)
{

    if(this->_steps.size() == 0) return;
    Step* step = this->_steps[j/2];
     qDebug()<<j/2<<endl;
    //上一步操作将棋子移动到空白位置
     QApplication::processEvents();
   if(step->_killId==-1)
    {
        //只要将moveId的行列修改就可以了
        _s[step->_moveId]._row=step->_rowNow;
        _s[step->_moveId]._col=step->_colNow;
     //  _bRedTurn=!_bRedTurn;
       _bRedTurn!=true?ui->label->setText(s):ui->label->setText(ss);

        update();

  }
    else
   {
         //需要将killId棋子状态恢复，将moveId棋子状态恢复
       QApplication::processEvents();
        _s[step->_killId]._dead=true;
        _s[step->_moveId]._row=step->_rowNow;
        _s[step->_moveId]._col=step->_colNow;


       // _bRedTurn=!_bRedTurn;
        _bRedTurn!=true?ui->label->setText(s):ui->label->setText(ss);
        update();
        qDebug() << "复盘2" << endl;
    }

    delete step;
    Sleep(1000);

}

void Board::huiqi()   //在后面加了一步存的
{

        //恢复棋子的所有状态
        //刚开始棋局，那么悔棋无效
        if(this->_steps.size() == 0) return;
        Step* step = this->_steps.last();

        //上一步操作将棋子移动到空白位置
        if(step->_killId==-1)
        {
            //只要将moveId的行列修改就可以了
            _s[step->_moveId]._row=step->_rowPre;
            _s[step->_moveId]._col=step->_colPre;
           _bRedTurn=!_bRedTurn;
           _bRedTurn!=true?ui->label->setText(s):ui->label->setText(ss);
            update();
            qDebug() << "悔棋了" << endl;
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
          _bRedTurn!=true?ui->label->setText(s):ui->label->setText(ss);
            update();
            qDebug() << "悔棋了" << endl;
        }
        st--;
        _steps.removeLast();   //删掉这一步，把后面的接上
        delete step;
}
//绘制棋盘
void Board::paintEvent(QPaintEvent *)
{

    QPainter p;
    //开始绘制
    p.begin(this);
         //将棋子对应的图片导入
    pic[0]=QImage(":/res/BRook.png");
    pic[1]=QImage(":/res/BKnigth.png");
    pic[2]=QImage(":/res/BBishop.png");
    pic[3]=QImage(":/res/BQueen.png");
    pic[4]=QImage(":/res/BKing.png");
    pic[5]=QImage(":/res/BBishop.png");
    pic[6]=QImage(":/res/BKnigth.png");
    pic[7]=QImage(":/res/BRook.png");
    for(int i=8;i<=15;i++)
    {
        pic[i]=QImage(":/res/Bpawn.png");
    }
    pic[16]=QImage(":/res/WRook.png");
    pic[17]=QImage(":/res/WKnigth.png");
    pic[18]=QImage(":/res/WBishop.png");
    pic[19]=QImage(":/res/WQueen.png");
    pic[20]=QImage(":/res/WKing.png");
    pic[21]=QImage(":/res/WBishop.png");
    pic[22]=QImage(":/res/WKnigth.png");
    pic[23]=QImage(":/res/WRook.png");
    for(int i=24;i<=31;i++)
    {
        pic[i]=QImage(":/res/WPawn.png");
    }
    //生成棋子
    for(int i=0;i<32;i++)
    {
        if(i == _raiseid1)
        {
            if(_s[i]._dead)
            {
                continue;
            }
            QPoint c=center(i);
            p.drawImage(QRect(c.x(),c.y(),50,50),QImage(":/res/BQueen.png"));
            continue;
        }
        if(i == _raiseid2)
        {
            if(_s[i]._dead)
            {
                continue;
            }
            QPoint c=center(i);
            p.drawImage(QRect(c.x(),c.y(),50,50),QImage(":/res/WQueen.png"));
            continue;
        }
        drawStone(p,i);
    }
    //生成前一步走棋提示框
   for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            QPoint c1=center(i,j);
            QRect rect = QRect(c1.x()+2,c1.y()-5,60,60);
            if(theLastStep[i][j]==10)
            {


                if (right==false)
                {qDebug()<<"11111111111"<<endl;
                   p.drawImage(rect,QImage(":/res/choose1.png"));}


                theLastStep[i][j]=0;
            }
        }
    }
    //生成可走格子提示
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            QPoint c2=center(i,j);
            QRect rect = QRect(c2.x(),c2.y()-10,65,65);
            if(canSelect[i][j]==10)
            {
                p.drawImage(rect,QImage(":/res/可走.png"));
                canSelect[i][j]=0;
            }
        }
    }
    //结束绘制
    p.end();
}

//棋子生成函数
void Board::drawStone(QPainter & p, int id)
{
    if(_s[id]._dead)
    {
        return;
    }
    //如果该id棋子被选中，则
    QPoint c=center(id);
    QRect rect = QRect(c.x()+5,c.y(),50,50);
    if(id == _selectid )
    {

           qDebug()<<"22222222222222"<<endl;
        p.drawImage(QRect(c.x()+2,c.y()-5,60,60),QImage(":/res/choose1.png"));
    }

    p.drawImage(rect,pic[id]);
}
//从行和列获取棋子id所对应的像素点
QPoint Board::center(int row,int col)
{
    QPoint ret;
    ret.rx()=col*62+20;
    ret.ry()=row*62+109;
    return ret;
}
//从棋子的id获得对应的像素点
QPoint Board::center(int id)
{
    return center(_s[id]._row,_s[id]._col);
}
//------------------------------------------------------------------------------------
//鼠标释放事件函数
void Board::mouseReleaseEvent(QMouseEvent *ev)
{
    if(ev->button() != Qt::LeftButton)
    {
        return;
    }
    QPoint pt = ev->pos(); //获得点击的点的坐标
    click(pt);
}
//点击函数1由鼠标点击坐标点得到对应棋子的坐标点
void Board::click(QPoint pt)
{
    int row, col;
    bool bClicked = getRowCol(pt, row, col);
    // 点击地方不合理,即棋盘外
    if(!bClicked)
    {
        return;
    }
    //点击合理
    int id = getStoneId(row,col);  //通过行和列获取棋子id
    //显示棋子能走的区域
    showSelect(id,row,col);
    //进行下一步
    click(id,row,col);

}
//点击函数2点击棋子的编号和坐标尝试走棋
void Board::click(int id, int row, int col)
{
    if(this->_selectid == -1)        // 如果没有选择到棋子，选择棋子（即获得有效点击范围内的id）
    {
        trySelectStone(id);
    }
    else                             // 选择到棋子，移动棋子
    {
        tryMoveStone(id,row,col);
    }
}
void Board::saveStep(int moveid, int killid, int row, int col, QVector<Step*>& steps)
{
    GetRowCol(row1, col1, moveid);
    Step* step = new Step;
    step->_colPre = col1;
    step->_colNow= col;
    step->_rowPre = row1;
    step->_rowNow = row;
    step->_moveId = moveid;
    step->_killId = killid;

    steps.append(step);
}
// 尝试走棋函数
void Board::tryMoveStone(int killid, int row, int col)
{
    // 如果尝试吃颜色相同的棋子，那么重新选择棋子
    if(killid !=-1 && !sameColor(killid, _selectid))
    {
        trySelectStone(killid);
        return;
    }
    // 如果可以移动棋子，那么移动棋子
    if(canMove(_selectid, killid, row, col))
    {
        //送王警告
        if(!safeForWANG(_selectid,row,col))
        {
            if(_s[_selectid]._red)
            {
                sendKing1+=1;
                //生成送王警告框
                if(sendKing1==1)
                {
                    QString str =QStringLiteral("第一次送王!");
                    QMessageBox::information(NULL,  "WARNING!",str, QMessageBox::Yes);
                }
                if(sendKing1==3)
                {
                    QString str =QStringLiteral("第二次送王!!");
                    QMessageBox::information(NULL,  "WARNING！",str, QMessageBox::Yes);
                }
                if(sendKing1==5)
                {
                    QString str = _bRedTurn?QStringLiteral("黑棋获胜!"):QStringLiteral("白棋获胜!");
                    QMessageBox::information(NULL,  "GAME OVER",str, QMessageBox::Yes);
                }
                sendKing1+=1;
                return;
            }
            if(!_s[_selectid]._red)
            {
                sendKing2+=1;
                //生成送王警告框
                if(sendKing2==1)
                {
                    QString str =QStringLiteral("第一次送王!");
                    QMessageBox::information(NULL,  "WARNING!",str, QMessageBox::Yes);
                }
                if(sendKing2==3)
                {
                    QString str =QStringLiteral("第二次送王!");
                    QMessageBox::information(NULL,  "WARNING！",str, QMessageBox::Yes);
                }
                if(sendKing2==5)
                {
                    QString str = _bRedTurn?QStringLiteral("黑棋获胜!"):QStringLiteral("白棋获胜!");
                    QMessageBox::information(NULL,  "GAME OVER",str, QMessageBox::Yes);
                }
                sendKing2+=1;
                return;
            }
        }

        saveStep(_selectid, killid, row, col, _steps);
        moveStone(_selectid, killid, row, col);

        _selectid = -1;
        update();
    }
}
//同色棋子判断
bool Board::sameColor(int moveid, int killid)
{
    if(_s[moveid]._red == _s[killid]._red)  //颜色一样
    {
        //换选择
        _selectid=killid;
        update();
        return false;
    }
    return true;
}
//走棋函数：吃子和移动
void Board::moveStone(int _selectid, int killid, int row, int col)
{
    if(lose!=0) return;
    //QLabel *label = new QLabel(this);
       //_bRedTurn==true?label->setText (  ss ):label->setText(s);

        _s[_selectid]._row = row;
        _s[_selectid]._col = col;
        //吃子
        QSound *startsound=new QSound(":/res/luozi.WAV",this);
        startsound->play();//
        if(killid!=-1)
        {
            _s[killid]._dead = true;
            if(checkMate(_selectid,row,col))
            {
                update();
                QString str =_bRedTurn?QStringLiteral("黑棋请注意!"):QStringLiteral("白棋请注意!");
                QMessageBox::information(NULL,  "WARNING!",str, QMessageBox::Yes,QMessageBox::Yes);
                isCheck=true;
                canChange=false;
            }
            if(resCheck(row,col))
            {
                isCheck=false;
                canChange=true;    //王车易位
            }
            if(_s[killid]._type==Stone::WANG)
            {
                lose++;
                QString str = _bRedTurn?QStringLiteral("白棋获胜!"):QStringLiteral("黑棋获胜!");
                QMessageBox::warning(NULL,  "GAME OVER",str, QMessageBox::Yes ,QMessageBox::Yes);
            }
        }
        if(killid==-1)
        {
            if(checkMate(_selectid,row,col))
            {
                update();
                QString str =_bRedTurn?QStringLiteral("黑棋请注意!"):QStringLiteral("白棋请注意!");
                QMessageBox::information(NULL,  "WARNING!",str, QMessageBox::Yes,QMessageBox::Yes);
                isCheck=true;
                canChange=false;
            }
            if(resCheck(row,col))
            {
                isCheck=false;
                canChange=true;
            }
        }
        _selectid = -1;
        //轮到另一边走棋
        _bRedTurn==true?ui->label->setText(s):ui->label->setText(ss);
        st++;   //一共下了多少步
       if(lose==0)_bRedTurn = !_bRedTurn;
}
//棋子鉴别函数
void Board::trySelectStone(int id)
{
    if(_bRedTurn != _s[id]._red)//鉴别是否该某一方走棋
    {
        _selectid = id;
        update();
    }

}
void Board::killStone(int id)
{
    if(id==-1) return;
    _s[id]._dead = true;
}
void Board::backOne()
{
    if(this->_steps.size() == 0) return;

    Step* step = this->_steps.last();
    _steps.removeLast();
    back(step);

    update();
    delete step;
}
void Board::back()
{
    backOne();
}
void Board::back(Step *step)
{
    reliveStone(step->_killId);
    moveStone(step->_moveId, step->_rowPre, step->_colPre);
}
void Board::reliveStone(int id)
{
    if(id==-1) return;
    _s[id]._dead = false;
}
void Board::moveStone(int moveid, int row, int col)
{
    _s[moveid]._row = row;
    _s[moveid]._col = col;

    _bRedTurn = !_bRedTurn;
}

//判断能否选择棋子
bool Board::getRowCol(QPoint pt, int &row, int &col)//临时引用
{
    for(row=0; row<=7; row++)
    {
        for(col=0; col<=7; col++)
        {
            QPoint c = center(row, col);
            int dx = c.x() - pt.x();
            int dy = c.y() - pt.y();
            int dist = dx*dx+dy*dy;
            if(dist < 60*60)    //点击的和棋子的差距，原来这里是80，就老出错，现在改成新格子大小就好了
            {
                return true;
            }
        }
    }
    return false;
}
//通过行和列获取棋子ID
int Board::getStoneId(int row, int col)
{
    for(int i=0; i<32; ++i)
    {
        if(_s[i]._row == row && _s[i]._col== col && !_s[i]._dead)
        {
            return i;
        }
    }
    return -1;
}
//最基本的能否行走函数
bool Board::canMove(int moveid,int killid,int row,int col)
{
    switch (_s[moveid]._type)
    {
        case Stone::WANG:
            return canMoveWANG(moveid, killid, row, col);
            break;
        case Stone::HOU:
            return canMoveHOU(moveid, killid, row, col);
            break;
        case Stone::TA:
            return canMoveTA(moveid, killid, row, col);
            break;
        case Stone::BING:
            return canMoveBING(moveid, killid, row, col);
            break;
        case Stone::ZHUJIAO:
            return canMoveZHUJIAO(moveid, killid, row, col);
            break;
        case Stone::QI:
            return canMoveQI(moveid, killid, row, col);
            break;
        default:break;
    }
    return false;
}
//判断塔能否移动
bool Board::canMoveTA(int moveid,int ,int row,int col) //此处忽略killid，避免warning
{
    GetRowCol(row1, col1, moveid);
    int ret = getStoneCountAtLine(row1, col1, row, col);
    if((row1==row || col1==col) && ret==0)  //标记该棋上一步的动作，下同
    {
        theLastStep[row1][col1]=10;
        theLastStep[row][col]=10;
    }
    if(ret == 0)
    {
        if(row1==0  && (col1==0 || col1==7))
        {
            changeT1+=1;
        }
        if(row1==7  && (col1==0 || col1==7))
        {
            changeT2+=1;
        }
        return true;
    }
    return false;

}
//判断主教能否移动
bool Board::canMoveZHUJIAO(int moveid, int , int row, int col) //此处忽略killid，避免warning
{
    GetRowCol(row1, col1, moveid);
    int ret = getStoneCountObliqueLine(row1, col1, row, col);
    if(qAbs(row1-row)==qAbs(col1-col) && ret==0)
    {
        theLastStep[row1][col1]=10;
        theLastStep[row][col]=10;
    }
    if(ret == 0 )
    {
        return true;
    }
    return false;

}
//判断后能否移动
bool Board::canMoveHOU(int moveid,int ,int row,int col) //此处忽略killid，避免warning
{
    GetRowCol(row1, col1, moveid);
    int ret1 = getStoneCountAtLine(row1, col1, row, col);
    int ret2 = getStoneCountObliqueLine(row1,col1,row,col);
    if((row1==row || col1==col || qAbs(row1-row)==qAbs(col1-col)) && ((ret1 == 0 && ret2== -1) || (ret2 == 0 && ret1 == -1)))
    {
        theLastStep[row1][col1]=10;
        theLastStep[row][col]=10;
    }
    if(ret1 == 0 && ret2 == -1)
    {
        return true;
    }
    if(ret1 == -1 && ret2 == 0)
    {
        return true;
    }
    return false;

}
//判断骑能否移动
bool Board::canMoveQI(int moveid,int ,int row,int col)//此处忽略killid，避免warning
{
    GetRowCol(row1, col1, moveid);
    if((qAbs(row1-row)==1 && qAbs(col1-col)==2)||(qAbs(row1-row)==2 && qAbs(col1-col)==1))
    {
        theLastStep[row1][col1]=10;
        theLastStep[row][col]=10;
    }
    int r = relation(row1, col1, row, col);
    if(r == 12 || r == 21)
    {
        return true;
    }
    return false;
}
//判断兵能否移动
bool Board::canMoveBING(int moveid,int killid,int row,int col)//此处忽略killid，避免warning
{
    GetRowCol(row1, col1, moveid);
    int r = relation(row1, col1, row, col);
    int ret = getStoneCountAtLine(row1, col1, row, col);
    //在上方
    if(isTopSide(moveid))
    {
        //只能往前走
        if(row>row1)
        {
            //兵在初始点的时候，可以选择往前走一步或两步
            if(row1==1)
            {
                if(r==10 && killid == -1)
                {
                    theLastStep[row1][col1]=10;
                    theLastStep[row][col]=10;
                    return true;
                }
                if(r==20 && ret==0 && killid == -1)
                {
                    //特殊规则：吃过路兵
                    int cid1=getStoneId(row,col+1);
                    int cid2=getStoneId(row,col-1);
                    if(_s[cid1]._type==Stone::BING || _s[cid2]._type==Stone::BING)
                    {
                        if(_s[moveid]._red!=_s[cid1]._red||_s[moveid]._red!=_s[cid2]._red)
                        {
                            enptP.rx()=row-1;
                            enptP.ry()=col;
                            enpt=true;
                        }
                    }
                    theLastStep[row1][col1]=10;
                    theLastStep[row][col]=10;
                    return true;
                }
                if(r==11 && killid !=-1)
                {
                    theLastStep[row1][col1]=10;
                    theLastStep[row][col]=10;
                    return true;
                }
            }
            //其他时候除了斜格吃子，只能往前走一步
            else
            {
                if(r==10 && killid ==-1)
                {
                    theLastStep[row1][col1]=10;
                    theLastStep[row][col]=10;
                    //特殊规则，兵升变
                    if(row==7)
                    {
                        _s[moveid]._type=Stone::HOU;
                        _raiseid1=moveid;
                    }
                    return true;
                }
                if(r==11 && (killid !=-1 || (enpt==true&& row==enptP.rx()&& col==enptP.ry() && killid ==-1)))
                {
                    theLastStep[row1][col1]=10;
                    theLastStep[row][col]=10;
                    int cid=getStoneId(row-1,col);
                    //特殊规则，兵升变
                    if(row==7 )
                    {
                        _s[moveid]._type=Stone::HOU;
                        _raiseid1=moveid;
                    }
                    if(enpt==true&& row==enptP.rx()&& col==enptP.ry())
                    {
                        _s[cid]._dead=true;
                        enpt = false;
                    }
                    return true;
                }
            }
        }
        //不允许后退或横走
        else
        {
            return false;
        }
    }
    //在下方
    else
    {
        //只能往前走
        if(row<row1)
        {
            //兵在初始点的时，可以选择往前走一步或两步
            if(row1==6)
            {
                if(r==10 && killid ==-1)
                {
                    theLastStep[row1][col1]=10;
                    theLastStep[row][col]=10;
                    return true;
                }
                if(r==20 && ret==0 && killid == -1)
                {
                    //特殊规则：吃过路兵
                    int cid1=getStoneId(row,col+1);
                    int cid2=getStoneId(row,col-1);
                    if((_s[cid1]._type==Stone::BING && _s[moveid]._red!=_s[cid1]._red)||(_s[cid2]._type==Stone::BING && _s[moveid]._red!=_s[cid2]._red))
                    {
                        enptP.rx()=row+1;
                        enptP.ry()=col;
                        enpt=true;
                    }
                    theLastStep[row1][col1]=10;
                    theLastStep[row][col]=10;
                    return true;
                }
                if(r==11 && killid !=-1)
                {
                    theLastStep[row1][col1]=10;
                    theLastStep[row][col]=10;
                    return true;
                }

            }
            //其他时候除了斜格吃子，只能往前走一步
            else
            {
                if(r==10 && killid == -1)
                {
                    theLastStep[row1][col1]=10;
                    theLastStep[row][col]=10;
                    //特殊规则：兵升变
                    if(row==0 )
                    {
                        _s[moveid]._type=Stone::HOU;
                        _raiseid2 = moveid;
                    }
                    return true;
                }
                if(r==11 && (killid !=-1 || (enpt==true&& row==enptP.rx()&& col==enptP.ry() && killid ==-1)))
                {
                    theLastStep[row1][col1]=10;
                    theLastStep[row][col]=10;
                    int cid=getStoneId(row+1,col);
                    //特殊规则：兵升变
                    if(row==0 )
                    {
                        _s[moveid]._type=Stone::HOU;
                        _raiseid2 = moveid;
                    }
                    if(enpt==true&& row==enptP.rx()&& col==enptP.ry())
                    {
                        _s[cid]._dead=true;
                        enpt = false;
                    }
                    return true;
                }
            }
        }
        //不允许后退或横走
        else
        {
            return false;
        }
    }
    return false;
}
//判断王能否移动
bool Board::canMoveWANG(int moveid,int ,int row,int col)//此处忽略killid，避免warning
{
    GetRowCol(row1, col1, moveid);
    int ret = getStoneCountAtLine(row1, col1, row, col);
    int r = relation(row1, col1, row, col);
    if(r == 10 || r == 1 || r == 11)
    {
        if(row1==row || col1==col || qAbs(row1-row)==qAbs(col1-col))
        {
            theLastStep[row1][col1]=10;
            theLastStep[row][col]=10;
        }
        if(row1==0  && col1==4)
        {
            changeT1+=1;
        }
        if(row1==7  && col1==4)
        {
            changeT2+=1;
        }
        return true;
    }
    //特殊规则：王车易位
    if(row==7 && ret==0 && safeForWANG(moveid,row,col) && r==2 && canChange==true && isCheck==false && changeT2==0  )
    {
        if(col==2)
        {
            _s[16]._col=2;
            changeT2+=1;
            return true;
        }
        if(col==6)
        {
            _s[23]._col=5;
            changeT2+=1;
            return true;
        }
    }
    if(row==0 && ret==0 && safeForWANG(moveid,row,col) && r==2 && canChange==true && isCheck==false && changeT1==0  )
    {
        if(col==2)
        {
            _s[0]._col=2;
            changeT1+=1;
            return true;
        }
        if(col==6)
        {
            _s[7]._col=5;
            changeT1+=1;
            return true;
        }
    }
    return false;
}
//获取棋子位置与点击位置是否是直线且该直线有多少棋子的函数
int Board::getStoneCountAtLine(int row1, int col1, int row2, int col2)
{
    int ret = 0;
    if(row1 != row2 && col1 != col2)
    {
        return -1;
    }
    if(row1 == row2 && col1 == col2)
    {
        return -1;
    }
    //行相等，取最小行累加到最大行的值，列的值固定，则根据行列得到的id判别该列行有无棋子（空行列默认值为-1）
    if(row1 == row2)
    {
        int min = col1 < col2 ? col1 : col2;
        int max = col1 < col2 ? col2 : col1;
        for(int col = min+1; col<max; ++col)
        {
            if(getStoneId(row1, col) != -1)
            {
                ++ret;
            }
        }
    }
    //列相等，同理
    if(col1 == col2)
    {
        int min = row1 < row2 ? row1 : row2;
        int max = row1 < row2 ? row2 : row1;
        for(int row = min+1; row<max; ++row)
        {
            if(getStoneId(row, col1) != -1)
            {
                ++ret;
            }
        }
    }

    return ret;
}
//获取棋子位置与点击位置是否是斜线且其中有多少棋子的函数
int Board::getStoneCountObliqueLine(int row1, int col1, int row2, int col2)
{
    int ret = 0;
    if(row1==row2 && col1==col2)
    {
        return -1;
    }
    //斜线上两位置行之间的差=列之间的差，则根据行列得到的id判别该列行有无棋子（空行列默认值为-1）
    if(qAbs(row1-row2)==qAbs(col1-col2))
    {
        int mincol = col1 < col2 ? col1 : col2;
        int maxcol = col1 < col2 ? col2 : col1;

        int minrow = row1 < row2 ? row1 : row2;
        int maxrow = row1 < row2 ? row2 : row1;
        for(int col = mincol+1; col<maxcol; ++col)
        {
            for(int row = minrow+1;row<maxrow;++row)
            {
                if(getStoneId(row, col) != -1 && qAbs(row-row2)==qAbs(col-col2))
                {
                    ++ret;
                }
            }
        }
    }
    else
    {
        return -1;
    }
    return ret;
}
//得到两点之间的关系
int Board::relation(int row1, int col1, int row, int col)
{
    return qAbs(row1-row)*10+qAbs(col1-col);  //得到一个两位数，十位是横着的差值，个位是竖着的
}
//判断是否是上方
bool Board::isTopSide(int id)
{
    return _bSide == _s[id]._red;
}

//判断王的行走位置是否是敌对棋子的攻击空间,即送王三次判负
bool Board::safeForWANG(int moveid,int row, int col)
{
    for(int r=0;r<8;r++)
    {
        for(int c=0;c<8;c++)
        {
            int s=getStoneId(r,c);
            //判断是否在敌对骑士的攻击格子内
            if(_s[moveid]._type==Stone::WANG && _bRedTurn != _s[moveid]._red )
            {
                if((qAbs(r-row)==1 && qAbs(c-col)==2)||(qAbs(r-row)==2 && qAbs(c-col)==1))
                {
                    if(_s[s]._red!=_s[moveid]._red && _s[s]._type==Stone::QI)
                    {
                        return  false;
                    }

                }
            }
            //判断是否在敌对塔的攻击格子内
            if(_s[moveid]._type==Stone::WANG && _bRedTurn != _s[moveid]._red )
            {
                if(r==row || c==col)
                {
                    if(_s[s]._red!=_s[moveid]._red && _s[s]._type==Stone::TA)
                    {
                        int ret = getStoneCountAtLine(r, c, row, col);
                        if(ret == 0)
                        {
                            return false;
                        }
                    }

                }
            }
            //判断是否在敌对主教的攻击格子内
            if(_s[moveid]._type==Stone::WANG && _bRedTurn != _s[moveid]._red )
            {
                if(qAbs(r-row)==qAbs(c-col))
                {
                    if(_s[s]._red!=_s[moveid]._red && _s[s]._type==Stone::ZHUJIAO)
                    {
                        int ret = getStoneCountObliqueLine(r, c, row, col);
                        if(ret == 0 )
                        {
                            return false;
                        }
                    }
                }
            }
            //判断是否在敌对后的攻击格子内
            if(_s[moveid]._type==Stone::WANG && _bRedTurn != _s[moveid]._red )
            {
                if(r==row || c==col || qAbs(r-row)==qAbs(c-col))
                {

                    if(_s[s]._red!=_s[moveid]._red && _s[s]._type==Stone::HOU)
                    {
                        int ret1 = getStoneCountObliqueLine(r, c, row, col);
                        int ret2 = getStoneCountAtLine(r, c, row, col);
                        if((ret1 == 0 && ret2== -1) || (ret2 == 0 && ret1 == -1) )
                        {
                            return false;
                        }
                    }

                }
            }
            //判断是否在敌对兵的攻击格子内
            if(_s[moveid]._type==Stone::WANG && _bRedTurn != _s[moveid]._red )
            {
                int rel = relation(r, c, row, col);
                //在上方
                if(isTopSide(moveid))
                {
                    if(row<r)
                    {
                        if(rel==11 && (_s[s]._red!=_s[moveid]._red && _s[s]._type==Stone::BING))
                        {
                            return false;
                        }
                    }
                }
                //在下方
                else
                {
                    if(row>r)
                    {
                        if(rel==11 && (_s[s]._red!=_s[moveid]._red && _s[s]._type==Stone::BING))
                        {
                            return false;
                        }
                    }
                }
            }
            //判断是否在敌对王的攻击格子之类
            if(_s[moveid]._type==Stone::WANG && _bRedTurn != _s[moveid]._red ) //待王的安全位置函数完善后修改
            {
                int rel = relation(r, c, row, col);
                if(rel == 10 || rel == 1 || rel == 11)
                {
                    if(r==row || c==col || qAbs(r-row)==qAbs(c-col))
                    {
                        if(_s[s]._red!=_s[moveid]._red && _s[s]._type==Stone::WANG)
                        {
                            return false;
                        }
                    }
                }
            }
        }
    }
    return true;
}
//判断是否将军
bool Board::checkMate(int moveid, int row, int col)
{
    for(int r=0;r<8;r++)
    {
        for(int c=0;c<8;c++)
        {
            int s=getStoneId(r,c);
            //判断骑士是否将军
            if(_s[moveid]._type==Stone::QI && _bRedTurn != _s[moveid]._red )
            {
                if((qAbs(r-row)==1 && qAbs(c-col)==2)||(qAbs(r-row)==2 && qAbs(c-col)==1))
                {
                    if(_s[s]._red!=_s[moveid]._red && _s[s]._type==Stone::WANG)
                    {
                        ptW.rx()=_s[s]._row;
                        ptW.ry()=_s[s]._col;
                        ptC.rx()=_s[moveid]._row;
                        ptC.ry()=_s[moveid]._col;
                        return  true;
                    }

                }
            }
            //判断塔是否将军
            if(_s[moveid]._type==Stone::TA && _bRedTurn != _s[moveid]._red )
            {
                if(r==row || c==col)
                {
                    if(_s[s]._red!=_s[moveid]._red && _s[s]._type==Stone::WANG)
                    {
                        ptW.rx()=_s[s]._row;
                        ptW.ry()=_s[s]._col;
                        ptC.rx()=_s[moveid]._row;
                        ptC.ry()=_s[moveid]._col;
                        int ret = getStoneCountAtLine(r, c, row, col);
                        if(ret == 0)
                        {
                            return true;
                        }
                    }

                }
            }
            //判断主教是否将军
            if(_s[moveid]._type==Stone::ZHUJIAO && _bRedTurn != _s[moveid]._red )
            {
                if(qAbs(r-row)==qAbs(c-col))
                {
                    if(_s[s]._red!=_s[moveid]._red && _s[s]._type==Stone::WANG)
                    {
                        ptW.rx()=_s[s]._row;
                        ptW.ry()=_s[s]._col;
                        ptC.rx()=_s[moveid]._row;
                        ptC.ry()=_s[moveid]._col;
                        int ret = getStoneCountObliqueLine(r, c, row, col);
                        if(ret == 0)
                        {
                            return true;
                        }
                    }
                }
            }
            //判断后是否将军
            if(_s[moveid]._type==Stone::HOU && _bRedTurn != _s[moveid]._red )
            {
                if(r==row || c==col || qAbs(r-row)==qAbs(c-col))
                {

                    if(_s[s]._red!=_s[moveid]._red && _s[s]._type==Stone::WANG)
                    {
                        ptW.rx()=_s[s]._row;
                        ptW.ry()=_s[s]._col;
                        ptC.rx()=_s[moveid]._row;
                        ptC.ry()=_s[moveid]._col;
                        int ret1 = getStoneCountObliqueLine(r, c, row, col);
                        int ret2 = getStoneCountAtLine(r, c, row, col);
                        if((ret1 == 0 && ret2== -1) || (ret2 == 0 && ret1 == -1) )
                        {
                            return true;
                        }
                    }

                }
            }
            //判断兵是否将军
            if(_s[moveid]._type==Stone::BING && _bRedTurn != _s[moveid]._red )
            {
                int rel = relation(r, c, row, col);
                //在上方
                if(isTopSide(moveid))
                {
                    if(row<r)
                    {
                        if(rel==11 && (_s[s]._red!=_s[moveid]._red && _s[s]._type==Stone::WANG))
                        {
                            ptW.rx()=_s[s]._row;
                            ptW.ry()=_s[s]._col;
                            ptC.rx()=_s[moveid]._row;
                            ptC.ry()=_s[moveid]._col;
                            return true;
                        }
                    }
                }
                //在下方
                else
                {
                    if(row>r)
                    {
                        if(rel==11 && (_s[s]._red!=_s[moveid]._red && _s[s]._type==Stone::WANG))
                        {
                            ptW.rx()=_s[s]._row;
                            ptW.ry()=_s[s]._col;
                            ptC.rx()=_s[moveid]._row;
                            ptC.ry()=_s[moveid]._col;
                            return true;
                        }
                    }
                }
            }
        }
    }
    return false;
}
//显示可选择格子的函数
void Board::showSelect(int id, int row, int col)
{
    for(int r=0;r<8;r++)
    {
        for(int c=0;c<8;c++)
        {
            int s=getStoneId(r,c);
            //显示骑士能走的格子
            if(_s[id]._type==Stone::QI && _bRedTurn != _s[id]._red )
            {
                if((qAbs(r-row)==1 && qAbs(c-col)==2)||(qAbs(r-row)==2 && qAbs(c-col)==1))
                {

                    if(_s[s]._red!=_s[id]._red || s==-1)
                    {
                        canSelect[r][c]=10;
                    }

                }
            }
            //显示塔能走的格子
            if(_s[id]._type==Stone::TA && _bRedTurn != _s[id]._red )
            {
                if(r==row || c==col)
                {

                    if(_s[s]._red!=_s[id]._red || s==-1)
                    {
                        int ret = getStoneCountAtLine(r, c, row, col);
                        if(ret == 0)
                        {
                            canSelect[r][c]=10;
                        }
                    }

                }
            }
            //显示主教能走的格子
            if(_s[id]._type==Stone::ZHUJIAO && _bRedTurn != _s[id]._red )
            {
                if(qAbs(r-row)==qAbs(c-col))
                {

                    if(_s[s]._red!=_s[id]._red || s==-1)
                    {
                        int ret = getStoneCountObliqueLine(r, c, row, col);
                        if(ret == 0)
                        {
                            canSelect[r][c]=10;
                        }
                    }

                }
            }
            //显示后能走的格子
            if(_s[id]._type==Stone::HOU && _bRedTurn != _s[id]._red )
            {
                if(r==row || c==col || qAbs(r-row)==qAbs(c-col))
                {

                    if(_s[s]._red!=_s[id]._red || s==-1)
                    {
                        int ret1 = getStoneCountObliqueLine(r, c, row, col);
                        int ret2 = getStoneCountAtLine(r, c, row, col);
                        if((ret1 == 0 && ret2== -1) || (ret2 == 0 && ret1 == -1))
                        {
                            canSelect[r][c]=10;
                        }
                    }

                }
            }
            //显示兵能走的格子
            if(_s[id]._type==Stone::BING && _bRedTurn != _s[id]._red )
            {
                int rel = relation(r, c, row, col);
                int ret = getStoneCountAtLine(r, c, row, col);
                //在上方
                if(isTopSide(id))
                {
                    if(row<r)
                    {
                        if(row==1)
                        {
                            if(rel ==10 && s==-1)
                            {
                                canSelect[r][c]=10;
                            }
                            if(rel==20 && ret==0 && s==-1)
                            {
                                canSelect[r][c]=10;
                            }
                            if(rel==11 && (_s[s]._red!=_s[id]._red && s!=-1))
                            {
                                canSelect[r][c]=10;
                            }
                        }
                        //其他时候除了斜格吃子，只能往前走一步
                        else
                        {
                            if(rel==10 && s==-1)
                            {
                                canSelect[r][c]=10;
                            }
                            if(rel==11 && ( (_s[s]._red!=_s[id]._red && s!=-1) || (enpt==true&& r==enptP.rx()&& c==enptP.ry()) ))
                            {
                                canSelect[r][c]=10;
                            }
                        }
                    }
                }
                //在下方
                else
                {
                    if(row>r)
                    {
                        if(row==6)
                        {
                            if(rel==10 && s==-1)
                            {
                                canSelect[r][c]=10;
                            }
                            if(rel==20 && ret==0 && s==-1)
                            {
                                canSelect[r][c]=10;
                            }
                            if(rel==11 && (_s[s]._red!=_s[id]._red && s!=-1))
                            {
                                canSelect[r][c]=10;
                            }
                        }
                        //其他时候除了斜格吃子，只能往前走一步
                        else
                        {
                            if(rel==10 &&  s==-1)
                            {
                                canSelect[r][c]=10;
                            }
                            if(rel==11 && ( (_s[s]._red!=_s[id]._red && s!=-1) || (enpt==true&& r==enptP.rx()&& c==enptP.ry()) ))
                            {
                                canSelect[r][c]=10;
                            }
                        }
                    }
                }
            }
            //显示王能走的格子
            if(_s[id]._type==Stone::WANG && _bRedTurn != _s[id]._red )
            {
                int rel = relation(r, c, row, col);
                int ret = getStoneCountAtLine(r,c,row,col);
                if(row==7 && ret==0 && safeForWANG(id,7,2) && rel==2 && canChange==true && isCheck==false && changeT2==0  )
                {
                    canSelect[r][c]=10;
                }
                if(row==0 && ret==0 && safeForWANG(id,7,2) && rel==2 && canChange==true && isCheck==false && changeT1==0  )
                {
                    canSelect[r][c]=10;
                }
                if(rel == 10 || rel == 1 || rel == 11)
                {
                    if(r==row || c==col || qAbs(r-row)==qAbs(c-col))
                    {
                        if(_s[s]._red!=_s[id]._red || s==-1)
                        {
                            canSelect[r][c]=10;
                        }
                    }
                }
            }
        }
    }
    update();
}
//是否应将判断函数
bool Board::resCheck(int row,int col)
{
    int rid=getStoneId(ptC.rx(),ptC.ry());
    //对塔应将
    if(_s[rid]._type==Stone::TA)
    {
        //其他棋子应将的情况
        int ret1 = getStoneCountAtLine(ptW.rx(), ptW.ry(), ptC.rx(), ptC.ry());
        //移动王应将的情况
        int ret2 = getStoneCountAtLine(row, col, ptC.rx(), ptC.ry());
        if(ret1 != 0 || ret2 ==-1)
        {
            return true;
        }
        if(_s[rid]._dead==true)
        {
            return true;
        }
    }
    //对主教应将
    if(_s[rid]._type==Stone::ZHUJIAO)
    {
        int ret1 = getStoneCountObliqueLine(ptW.rx(), ptW.ry(), ptC.rx(), ptC.ry());
        int ret2 = getStoneCountObliqueLine(row, col, ptC.rx(), ptC.ry());
        if(ret1 != 0 || ret2==-1)
        {
            return true;
        }
        if(_s[rid]._dead==true)
        {
            return true;
        }
    }
    //对后应将
    if(_s[rid]._type==Stone::HOU)
    {
        int ret1 = getStoneCountAtLine(ptW.rx(), ptW.ry(), ptC.rx(), ptC.ry());
        int ret2 = getStoneCountObliqueLine(ptW.rx(), ptW.ry(), ptC.rx(), ptC.ry());
        //其他棋子应将的情况
        if(ret1 != 0 && ret2 == -1)
        {
            return true;
        }
        if(ret1 == -1 && ret2 != 0)
        {
            return true;
        }
        //移动王应将的情况
        if(ret1 == -1 && ret2 == -1)
        {
            return true;
        }
        if(_s[rid]._dead==true)
        {
            return true;
        }
    }
    //对骑应将
    if(_s[rid]._type==Stone::QI)
    {
        int r1 = relation(ptW.rx(), ptW.ry(), ptC.rx(), ptC.ry());
        int r2 = relation(row, col, ptC.rx(), ptC.ry());
        if(r1 != 12 && r1 != 21)
        {
            return true;
        }
        if(r2 != 12 && r2 != 21)
        {
            if((row==2 && col==7)||(row==6 && col==7))
            {
                return false;
            }
            return true;
        }
        if(_s[rid]._dead==true)
        {
            return true;
        }
    }
    //对兵应将
    if(_s[rid]._type==Stone::BING)
    {
        int r1 = relation(ptW.rx(), ptW.ry(), ptC.rx(), ptC.ry());
        int r2 = relation(row, col, ptC.rx(), ptC.ry());
        if(r1!=11 || r2!=11)
        {
            if((row==2 && col==7)||(row==6 && col==7))
            {
                return false;
            }
            return true;
        }
        if(_s[rid]._dead==true)
        {
            return true;
        }
    }
    return false;
}

