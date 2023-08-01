#ifndef BOARD3_H
#define BOARD3_H

#include <QWidget>
#include "board.h"
namespace Ui {
class board3;
}

class board3 :  public Board
{
    Q_OBJECT

public:
    explicit board3(QWidget *parent = nullptr);
    ~board3();

private:
    Ui::board3 *ui;
};

#endif // BOARD3_H
