#include "exitapp.h"
#include "ui_exitapp.h"
#include "QDebug"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "regist.h"
#include "ui_regist.h"

exitapp::exitapp(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::exitapp)
{
    ui->setupUi(this);
    //设置标题
     this->setWindowTitle("退出");
}

exitapp::~exitapp()
{
    delete ui;
}
void exitapp::on_exityes_clicked()
{
    this->close();

}
void exitapp::on_exitno_clicked()
{
     exit(0);
}
