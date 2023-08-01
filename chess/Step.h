#ifndef STEP_H
#define STEP_H

#include <QObject>

class Step : public QObject
{
    Q_OBJECT
public:
    explicit Step(QObject *parent = 0);
    ~Step();


        //保存操作
        int _moveId;//移动棋子的ID
        int _killId;//吃掉棋子的ID，悔棋时需要将其_dead属性改变
        int _rowPre;//起先的行
        int _colPre;//起先的列
        int _rowNow;//现在的行
        int _colNow;//现在的列
        bool _redTurnPre;//上一步执棋方


signals:

public slots:
};

#endif // STEP_H
