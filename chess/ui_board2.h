/********************************************************************************
** Form generated from reading UI file 'board2.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOARD2_H
#define UI_BOARD2_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_board2
{
public:

    void setupUi(QWidget *board2)
    {
        if (board2->objectName().isEmpty())
            board2->setObjectName(QStringLiteral("board2"));
        board2->resize(1034, 645);

        retranslateUi(board2);

        QMetaObject::connectSlotsByName(board2);
    } // setupUi

    void retranslateUi(QWidget *board2)
    {
        board2->setWindowTitle(QApplication::translate("board2", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class board2: public Ui_board2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOARD2_H
