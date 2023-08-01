/********************************************************************************
** Form generated from reading UI file 'board3.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOARD3_H
#define UI_BOARD3_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_board3
{
public:

    void setupUi(QWidget *board3)
    {
        if (board3->objectName().isEmpty())
            board3->setObjectName(QStringLiteral("board3"));
        board3->resize(400, 300);

        retranslateUi(board3);

        QMetaObject::connectSlotsByName(board3);
    } // setupUi

    void retranslateUi(QWidget *board3)
    {
        board3->setWindowTitle(QApplication::translate("board3", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class board3: public Ui_board3 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOARD3_H
