#include "canjuwindow.h"
#include "ui_canjuwindow.h"
#include "canju.h"
#include "canju1.h"
#include "canju2.h"
#include "canju3.h"
canjuwindow::canjuwindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::canjuwindow)
{
    ui->setupUi(this);
    //设置标题
     this->setWindowTitle("选择");
    this->resize(300,250);
    //设置图标(QPixMap也可)
    this->setWindowIcon(QIcon(":/res/tubiao.png"));

}

canjuwindow::~canjuwindow()
{
    delete ui;
}

void canjuwindow::on_pushButton_clicked()
{
    this->close();
    canju *can1=new canju();
    can1->show();

}

void canjuwindow::on_pushButton_2_clicked()
{
    this->close();
    canju1 *can2=new canju1();
    can2->show();
}

void canjuwindow::on_pushButton_3_clicked()
{
    this->close();
    canju2 *can3=new canju2();
    can3->show();
}

void canjuwindow::on_pushButton_4_clicked()
{
    this->close();
    canju3 *can4=new canju3();
    can4->show();
}
