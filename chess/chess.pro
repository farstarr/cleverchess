QT       += core gui multimedia
CONFIG += resources_big
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Step.cpp \
    Stone.cpp \
    board.cpp \
    board2.cpp \
    board3.cpp \
    canju.cpp \
    canju1.cpp \
    canju2.cpp \
    canju3.cpp \
    canjuwindow.cpp \
    exitapp.cpp \
    forgetpass.cpp \
    gpushbutton.cpp \
    help.cpp \
    inform.cpp \
    main.cpp \
    mainwindow.cpp \
    mythread.cpp \
    regist.cpp \
    sign.cpp \
    singlegame.cpp

HEADERS += \
    Step.h \
    Stone.h \
    board.h \
    board2.h \
    board3.h \
    canju.h \
    canju1.h \
    canju2.h \
    canju3.h \
    canjuwindow.h \
    exitapp.h \
    forgetpass.h \
    gpushbutton.h \
    help.h \
    inform.h \
    mainwindow.h \
    mythread.h \
    regist.h \
    sign.h \
    singlegame.h

FORMS += \
    board.ui \
    board2.ui \
    board3.ui \
    canjuwindow.ui \
    exitapp.ui \
    forgetpass.ui \
    help.ui \
    inform.ui \
    mainwindow.ui \
    regist.ui \
    sign.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc

DISTFILES += \
    res/BACK.png \
    res/BBishop.png \
    res/BKing.png \
    res/BKnigth.png \
    res/BQueen.png \
    res/BRook.png \
    res/Bpawn.png \
    res/EXIT.png \
    res/HELP.png \
    res/MenubackG.jpeg \
    res/PLAY.png \
    res/WBishop.png \
    res/WKing.png \
    res/WKnigth.png \
    res/WPawn.png \
    res/WQueen.png \
    res/WRook.png \
    res/backBtn.png \
    res/background.png \
    res/bgmm.wav \
    res/bk2..png \
    res/bkg.jpg \
    res/board.png \
    res/box.png \
    res/box_fixed.png \
    res/cb.png \
    res/destiny.png \
    res/endgame.png \
    res/exitBtn.png \
    res/exitgame.png \
    res/helpgame.png \
    res/inform.png \
    res/level1.png \
    res/level2.png \
    res/level3.png \
    res/level4.png \
    res/levelBackG.png \
    res/levelBackground.jpeg \
    res/loadgame.png \
    res/man.png \
    res/man_destiny.png \
    res/menuBackground.jpg \
    res/newgame.png \
    res/newgamecopy.png \
    res/planet.png \
    res/playBtn.png \
    res/player.txt \
    res/regist.png \
    res/sign.png \
    res/ssign.png \
    res/tittl.png \
    res/tittle.png \
    res/wall.png \
    res/way.png \
    res/win.png
