/********************************************************************************
** Form generated from reading UI file 'forgetpass.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORGETPASS_H
#define UI_FORGETPASS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_forgetpass
{
public:
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *forgetpass)
    {
        if (forgetpass->objectName().isEmpty())
            forgetpass->setObjectName(QStringLiteral("forgetpass"));
        forgetpass->resize(811, 550);
        label = new QLabel(forgetpass);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(160, 119, 131, 41));
        label->setStyleSheet(QStringLiteral("color:rgb(255, 255, 255)"));
        lineEdit = new QLineEdit(forgetpass);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(300, 120, 261, 31));
        label_2 = new QLabel(forgetpass);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(160, 220, 641, 71));
        label_2->setStyleSheet(QStringLiteral("color:rgb(255, 255, 255)"));
        lineEdit_2 = new QLineEdit(forgetpass);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(310, 330, 261, 31));
        pushButton = new QPushButton(forgetpass);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(380, 410, 111, 51));
        pushButton_2 = new QPushButton(forgetpass);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(600, 410, 111, 51));

        retranslateUi(forgetpass);

        QMetaObject::connectSlotsByName(forgetpass);
    } // setupUi

    void retranslateUi(QWidget *forgetpass)
    {
        forgetpass->setWindowTitle(QApplication::translate("forgetpass", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("forgetpass", "\347\224\250\346\210\267\345\220\215\357\274\232", Q_NULLPTR));
        label_2->setText(QApplication::translate("forgetpass", "\345\257\206\344\277\235\351\227\256\351\242\230\357\274\232\346\202\250\345\260\217\345\255\246\346\227\266\346\234\200\345\245\275\347\232\204\346\234\213\345\217\213\346\230\257\357\274\237", Q_NULLPTR));
        pushButton->setText(QApplication::translate("forgetpass", "\345\217\226\346\266\210", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("forgetpass", "\344\270\213\344\270\200\346\255\245", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class forgetpass: public Ui_forgetpass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORGETPASS_H
