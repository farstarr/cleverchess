#include "mainwindow.h"
#include <QSound>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QApplication>
#include "singlegame.h"
int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    GameMenu w;
    w.show();
    return a.exec();
}
