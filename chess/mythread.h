#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QObject>
extern int counter;
class myThread : public QObject
{
    Q_OBJECT
public:
    explicit myThread(QObject *parent = 0);
    bool stopFlag = false;
signals:
    void lcd_show();
public slots:

    void startThreadSlot();

};

#endif // MYTHREAD_H
