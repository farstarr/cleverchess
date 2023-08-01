#ifndef SINGLEGAME_H
#define SINGLEGAME_H
#include "board.h"
#include "ui_board.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"


class Singlegame : public Board
{
    Q_OBJECT
public:
    explicit Singlegame(QWidget *parent = 0);
    ~Singlegame();
  QVector<Step*> bu;//一个存储用数组
  void huiqi2();
    int _level;
    void fupan2(int j);
    void back();
    virtual void click(int id, int row, int col);

    Step* getBestMove();
    void getAllPossibleMove(QVector<Step*>& steps);
    int getMinScore(int level, int curMin);
    int getMaxScore(int level, int curMax);
    int score();

    void fakeMove(Step* step);
    void unfakeMove(Step* step);

signals:

public slots:
    void computerMove();
};

#endif // SINGLEGAME_H
