#ifndef CANJUWINDOW_H
#define CANJUWINDOW_H
#include "canju.h"
#include <QWidget>

namespace Ui {
class canjuwindow;
}

class canjuwindow : public QWidget
{
    Q_OBJECT

public:
    explicit canjuwindow(QWidget *parent = nullptr);
    ~canjuwindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::canjuwindow *ui;
};

#endif // CANJUWINDOW_H
