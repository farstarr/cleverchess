#ifndef CANJU2_H
#define CANJU2_H
#include "board.h"
class canju2 : public Board
{
    Q_OBJECT
public:
    explicit canju2(QWidget *parent = 0);
    ~canju2();
    void fupanc2(int);
    virtual void drawStone(QPainter& p,int id);
    virtual void chesstype();
};


#endif // CANJU2_H
