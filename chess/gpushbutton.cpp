#include "gpushbutton.h"

GPushButton::GPushButton(QString normalImg, QString pressImg)
{
    this->pressPath = pressImg;
    this->normalPath = normalImg;

    //创建Qpixmap
    QPixmap pix;
    bool ret = pix.load(this->normalPath);
    if(!ret)
    {
        QString str = QString("图片加载失败，失败的路径是：%1！").arg(this->normalPath);
        qDebug()<<str;
    }

    //设置按钮固定尺寸
    this->setFixedSize(pix.width(),pix.height());
    //设置不规则样式
    this->setStyleSheet("QPushButton{border:0px;}");
    //设置图标
    this->setIcon(pix);
    //设置图标大小
    this->setIconSize(QSize(pix.width(),pix.height()));

}

void GPushButton::mousePressEvent(QMouseEvent *event)
{
    //按下路径不为空 切图
    if(this->pressPath!="")
    {
        QPixmap pix;
        bool ret = pix.load(this->pressPath);
        if(!ret)
        {
            QString str = QString("图片加载失败，失败的路径是：%1！").arg(this->pressPath);
            qDebug()<<str;
        }

        //设置按钮固定尺寸
        this->setFixedSize(pix.width(),pix.height());
        //设置不规则样式
        this->setStyleSheet("QPushButton{border:0px;}");
        //设置图标
        this->setIcon(pix);
        //设置图标大小
        this->setIconSize(QSize(pix.width(),pix.height()));
    }

    //其他事件交给父类处理
    QPushButton::mousePressEvent(event);
}

void GPushButton::mouseReleaseEvent(QMouseEvent *event)
{
    //按下路径不为空 还原
    if(this->pressPath!="")
    {
        QPixmap pix;
        bool ret = pix.load(this->normalPath);
        if(!ret)
        {
            QString str = QString("图片加载失败，失败的路径是：%1！").arg(this->normalPath);
            qDebug()<<str;
        }

        //设置按钮固定尺寸
        this->setFixedSize(pix.width(),pix.height());
        //设置不规则样式
        this->setStyleSheet("QPushButton{border:0px;}");
        //设置图标
        this->setIcon(pix);
        //设置图标大小
        this->setIconSize(QSize(pix.width(),pix.height()));
    }

    //其他事件交给父类处理
    QPushButton::mouseReleaseEvent(event);
}
