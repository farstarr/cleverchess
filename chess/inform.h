#ifndef INFORM_H
#define INFORM_H

#include <QWidget>

namespace Ui {
class inform;
}

class inform : public QWidget
{
    Q_OBJECT

public:
    explicit inform(QWidget *parent = nullptr);
    ~inform();

private slots:
    void on_pushButton_clicked();

private:
    Ui::inform *ui;
};

#endif // INFORM_H
