/********************************************************************************
** Form generated from reading UI file 'board.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOARD_H
#define UI_BOARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Board
{
public:
    QLabel *label;

    void setupUi(QWidget *Board)
    {
        if (Board->objectName().isEmpty())
            Board->setObjectName(QStringLiteral("Board"));
        Board->resize(883, 553);
        label = new QLabel(Board);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(580, 220, 281, 91));

        retranslateUi(Board);

        QMetaObject::connectSlotsByName(Board);
    } // setupUi

    void retranslateUi(QWidget *Board)
    {
        Board->setWindowTitle(QApplication::translate("Board", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("Board", "TextLabel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Board: public Ui_Board {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOARD_H
