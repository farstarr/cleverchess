#include "inform.h"
#include "ui_inform.h"

inform::inform(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::inform)
{
    ui->setupUi(this);
    //设置标题
     this->setWindowTitle("关于");

}

inform::~inform()
{
    delete ui;
}

void inform::on_pushButton_clicked()
{
    this->close();
}
