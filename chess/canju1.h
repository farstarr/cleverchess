#ifndef CANJU1_H
#define CANJU1_H
#include "board.h"
class canju1 : public Board
{
    Q_OBJECT
public:
    explicit canju1(QWidget *parent = 0);
    ~canju1();
     void fupanc1(int);
    virtual void drawStone(QPainter& p,int id);
    virtual void chesstype();
};

#endif // CANJU1_H
