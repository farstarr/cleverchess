#include "regist.h"
#include "ui_regist.h"
#include "mainwindow.h"
#include <QPixmap>
#include "exitapp.h"
#include "ui_exitapp.h"
#include "board.h"
#include "singlegame.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QLineEdit>
Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
    this->setFixedSize(890,590);

   // QWidget *widget = new QWidget();
   // widget->setAutoFillBackground(true);
    QPalette palette;
    QPixmap pixmap(":/res/bk2..png");
    palette.setBrush(QPalette::Window, QBrush(pixmap));
   this->setPalette(palette);
  //  widget->show();

    //QPixmap pixmap(":/res/bk2..png");
    QFont font ( 0, 20, 75); //第一个属性是字体（微软雅黑），第二个是大小，第三个是加粗（权重是75）
   // QImage *img=new QImage;
    QFont fontt ( 0, 15, 75);
   //    img->load(":/res/level4.png");
      // ui->label_5->setPixmap(QPixmap::fromImage(*img));
   ui->label->setFont(font);


      ui->lineEdit->setPlaceholderText("请输入密码!");
      ui->lineEdit->setEchoMode(QLineEdit::Password);//输入的密码以圆点显示
      ui->lineEdit_2->setPlaceholderText("请再次输入密码!");
      ui->lineEdit_2->setEchoMode(QLineEdit::Password);//输入的密码以圆点显示


        ui->lineEdit_3->setPlaceholderText(tr("请输入用户名!"));//占位符
   ui->label_2->setFont(font);
   ui->label_3->setFont(font);
   ui->label_4->setFont(font);


         ui->pushButton->setFont(fontt);
 ui->pushButton_2->setFont(fontt);
   ui->pushButton->setStyleSheet("QPushButton{background-color: rgb(225, 225, 225);border:2px groove gray;border-radius:10px;padding:2px 4px;border-style: outset;}"
                                              "QPushButton:hover{background-color:rgb(229, 241, 251); color: black;}"
                                              "QPushButton:pressed{background-color:rgb(204, 228, 247);border-style: inset;}");
   ui->pushButton_2->setStyleSheet("QPushButton{background-color: rgb(225, 225, 225);border:2px groove gray;border-radius:10px;padding:2px 4px;border-style: outset;}"
                                              "QPushButton:hover{background-color:rgb(229, 241, 251); color: black;}"
                                              "QPushButton:pressed{background-color:rgb(204, 228, 247);border-style: inset;}");

   //设置标题
    this->setWindowTitle("注册");
   //设置图标(QPixMap也可)
   this->setWindowIcon(QIcon(":/res/tubiao.png"));



}

Form::~Form()
{
    delete ui;
}

void Form::on_pushButton_clicked()
{
    GameMenu *fater=new GameMenu();
    this->close();
    fater->show();
}
void Form::on_pushButton_2_clicked()
{

            QString name,pass,pass2,mibao;
            bool right=true;
            name = ui->lineEdit_3->text();
            pass = ui->lineEdit->text();
            pass2 = ui->lineEdit_2->text();
            mibao = ui->lineEdit_4->text();
            //首先判断三个输入框有没有没为空
            if((name != "")&&(pass != "")&&(pass2 != "") )
            {
               if(pass == pass2)
               {
                  qDebug()<<"格式正确";
                  FILE * fp;            //定义一个文件流指针
                  if((fp = fopen("C:/Users/Lenovo/Desktop/newnew/res/player.txt","r+"))==NULL)
                  {
                      perror("fail to open!");
                  }
                  char temp[300];
                  while(fgets(temp,300,fp) != NULL)
                  {
                       qDebug()<<"正在检查是否重名";
                       QString dtn = QString(strtok(temp,":"));
                       if(dtn == name)
                       {
                           QMessageBox::critical(this,"错误","该用户名已经存在");
                           right=false;
                           return ;
                       }
                  }
                  fclose(fp);


                  FILE * fp1;
                  if((fp1 = fopen("C:/Users/Lenovo/Desktop/newnew/res/player.txt","a+"))==NULL)
                  {
                      perror("fail to fopen");
                  }
                  else
                  {
                       QByteArray qtname = ui->lineEdit_3->text().toLatin1();
                       QByteArray qtpass = ui->lineEdit->text().toLatin1();
                       QByteArray qtmibao = ui->lineEdit_4->text().toLatin1();
                       char * tn = qtname.data();
                       char * tp = qtpass.data();
                       char * tm = qtmibao.data();
                       fputs(tn,fp);
                       fputs(":",fp);
                       fputs(tp,fp);
                       fputs("\n",fp);
                       fputs(tn,fp);
                       fputs(":",fp);
                       fputs(tm,fp);
                       fputs("\n",fp);
                       qDebug()<<" 写入文件成功";
                       QMessageBox::information(this,"恭喜","注册成功！");

                  }
                  fclose(fp1);
               }
               else
               {
                   QMessageBox::critical(this,"错误","两次输入的密码不一致！");
                   right=false;
               }
            }
            else
            {
                QMessageBox::critical(this,"错误","密码或账号为空！");
                right=false;
            }
  if(right==true) {
    GameMenu *boar=new GameMenu();
    this->close();
    boar->show();}
}


