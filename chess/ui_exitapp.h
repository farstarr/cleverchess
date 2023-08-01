/********************************************************************************
** Form generated from reading UI file 'exitapp.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXITAPP_H
#define UI_EXITAPP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_exitapp
{
public:
    QLabel *label;
    QPushButton *exityes;
    QPushButton *exitno;

    void setupUi(QWidget *exitapp)
    {
        if (exitapp->objectName().isEmpty())
            exitapp->setObjectName(QStringLiteral("exitapp"));
        exitapp->resize(313, 192);
        label = new QLabel(exitapp);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 50, 281, 51));
        QFont font;
        font.setPointSize(11);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        exityes = new QPushButton(exitapp);
        exityes->setObjectName(QStringLiteral("exityes"));
        exityes->setGeometry(QRect(30, 120, 101, 41));
        exityes->setFont(font);
        exitno = new QPushButton(exitapp);
        exitno->setObjectName(QStringLiteral("exitno"));
        exitno->setGeometry(QRect(172, 120, 101, 41));
        exitno->setFont(font);

        retranslateUi(exitapp);

        QMetaObject::connectSlotsByName(exitapp);
    } // setupUi

    void retranslateUi(QWidget *exitapp)
    {
        exitapp->setWindowTitle(QApplication::translate("exitapp", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("exitapp", "\347\234\237\347\232\204\350\246\201\351\200\200\345\207\272\345\220\227\357\274\237\350\257\267\346\263\250\346\204\217\346\230\257\345\220\246\345\255\230\346\241\243\357\274\201", Q_NULLPTR));
        exityes->setText(QApplication::translate("exitapp", "\350\277\224\345\233\236", Q_NULLPTR));
        exitno->setText(QApplication::translate("exitapp", "\351\200\200\345\207\272", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class exitapp: public Ui_exitapp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXITAPP_H
