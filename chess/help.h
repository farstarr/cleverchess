#ifndef HELP_H
#define HELP_H

#include <QWidget>

namespace Ui {
class help;
}

class help : public QWidget
{
    Q_OBJECT

public:
    explicit help(QWidget *parent = nullptr);
    ~help();

private slots:
    void on_pushButton_clicked();

private:
    Ui::help *ui;
};

#endif // HELP_H
