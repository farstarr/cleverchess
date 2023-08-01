#ifndef CANJU_H
#define CANJU_H
#include "board.h"
class canju : public Board
{
    Q_OBJECT
public:
    explicit canju(QWidget *parent = 0);
    ~canju();
    void fupanc(int);
    virtual void drawStone(QPainter& p,int id);
    virtual void chesstype();
};


#endif // CANJU_H
