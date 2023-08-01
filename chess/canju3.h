#ifndef CANJU3_H
#define CANJU3_H
#include "board.h"
class canju3 : public Board
{
    Q_OBJECT
public:
    explicit canju3(QWidget *parent = 0);
    ~canju3();
    void fupanc3(int);
    virtual void drawStone(QPainter& p,int id);
    virtual void chesstype();
};

#endif // CANJU3_H
