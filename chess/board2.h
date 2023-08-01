#ifndef BOARD2_H
#define BOARD2_H

#include <QWidget>
#include "board.h"
namespace Ui {
class board2;
}

class board2 : public Board
{
    Q_OBJECT

public:
    explicit board2(QWidget *parent = nullptr);
    ~board2();

private:
    Ui::board2 *ui;
};

#endif // BOARD2_H
