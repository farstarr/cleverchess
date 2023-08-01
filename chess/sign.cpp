#include "sign.h"
#include "ui_sign.h"
#include "board.h"
#include <QPixmap>
#include "mainwindow.h"
#include "board.h"
#include <QMessageBox>
#include "forgetpass.h"
#include "ui_forgetpass.h"
sign::sign(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::sign)
{
   ui->setupUi(this);
   this->setFixedSize(890,590);
   QPalette palette;
   QPixmap pixmap(":/res/bk2..png");
   palette.setBrush(QPalette::Window, QBrush(pixmap));
   this->setPalette(palette);
   QFont font ( 0, 20, 75); //第一个属性是字体（微软雅黑），第二个是大小，第三个是加粗（权重是75）
   QFont fontt ( 0, 15, 75);
   ui->label->setFont(font);
   ui->label_2->setFont(font);
   ui->pushButton_3->setFont(fontt);
   ui->pushButton_2->setFont(fontt);
   ui->pushButton_3->setStyleSheet("QPushButton{background-color: rgb(225, 225, 225);border:2px groove gray;border-radius:10px;padding:2px 4px;border-style: outset;}"
                                              "QPushButton:hover{background-color:rgb(229, 241, 251); color: black;}"
                                              "QPushButton:pressed{background-color:rgb(204, 228, 247);border-style: inset;}");
   ui->pushButton_2->setStyleSheet("QPushButton{background-color: rgb(225, 225, 225);border:2px groove gray;border-radius:10px;padding:2px 4px;border-style: outset;}"
                                              "QPushButton:hover{background-color:rgb(229, 241, 251); color: black;}"
                                              "QPushButton:pressed{background-color:rgb(204, 228, 247);border-style: inset;}");

   //设置标题
    this->setWindowTitle("登录");

   //设置图标(QPixMap也可)
   this->setWindowIcon(QIcon(":/res/tubiao.png"));

}


void sign::on_pushButton_2_clicked()
{
    GameMenu *fater=new GameMenu();
    this->close();
    fater->show();
}
void sign::on_pushButton_3_clicked()
{
    static int count = 0;

    Board *board=new Board();
       QString name = ui->lineEdit->text();
       QString pass = ui->lineEdit_2->text();

       if((name!=NULL) && (pass!=NULL))
       {
           FILE * fp;            //定义一个文件流指针
           if((fp = fopen("C:/Users/Lenovo/Desktop/newnew/res/player.txt","r+"))==NULL)
           {
               perror("fail to open!");
           }
           char temp[300];
           while(fgets(temp,300,fp) != NULL)
           {
                qDebug()<<"正在检查是否是否有匹配的id和密码";
                QString dtn = QString(strtok(temp,":"));
                QString dtp = QString(strtok(NULL,"\n"));
                qDebug()<<dtn<<"  "<<dtp;
                if((dtn == name ) && (dtp == pass))
                {
                    //QMessageBox::information(this,"恭喜","登录成功！");
                    //然后跳转新窗口
                    this->hide();       //子窗口不能够使父窗口隐藏！（需要自定义信号与槽）
                    board->show();
                    count++;
                }
           }
           if(count == 0)
           {
               QMessageBox::critical(this,"错误！","密码或账号有误！");
           }
           fclose(fp);
       }
       else
       {
           QMessageBox::critical(this,"错误！","密码为空");
       }

       //this->close();
       //board->show();
   }






sign::~sign()
{
    delete ui;
}

void sign::on_pushButton_clicked()
{
    this->close();
    forgetpass *forget=new forgetpass();
    forget->show();
}
