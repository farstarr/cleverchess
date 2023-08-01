#include "help.h"
#include "ui_help.h"

help::help(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::help)
{
    ui->setupUi(this);
    //设置标题
     this->setWindowTitle("帮助");

}

help::~help()
{
    delete ui;
}

void help::on_pushButton_clicked()
{
    this->close();
}
