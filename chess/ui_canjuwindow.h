/********************************************************************************
** Form generated from reading UI file 'canjuwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CANJUWINDOW_H
#define UI_CANJUWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_canjuwindow
{
public:
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;

    void setupUi(QWidget *canjuwindow)
    {
        if (canjuwindow->objectName().isEmpty())
            canjuwindow->setObjectName(QStringLiteral("canjuwindow"));
        canjuwindow->resize(292, 411);
        verticalLayout = new QVBoxLayout(canjuwindow);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        pushButton = new QPushButton(canjuwindow);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(canjuwindow);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        verticalLayout->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(canjuwindow);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        verticalLayout->addWidget(pushButton_3);

        pushButton_4 = new QPushButton(canjuwindow);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        verticalLayout->addWidget(pushButton_4);


        retranslateUi(canjuwindow);

        QMetaObject::connectSlotsByName(canjuwindow);
    } // setupUi

    void retranslateUi(QWidget *canjuwindow)
    {
        canjuwindow->setWindowTitle(QApplication::translate("canjuwindow", "Form", Q_NULLPTR));
        pushButton->setText(QApplication::translate("canjuwindow", "\347\216\213\347\261\273\346\256\213\345\261\200\302\267\345\215\225\350\275\246\346\235\200\345\215\225\347\216\213", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("canjuwindow", "\345\220\216\347\261\273\346\256\213\345\261\200\302\267\345\215\225\345\220\216\346\235\200\345\215\225\347\216\213", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("canjuwindow", "\350\275\246\347\261\273\346\256\213\345\261\200\302\267\345\217\214\350\275\246\346\235\200\345\215\225\347\216\213", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("canjuwindow", "\345\205\266\344\273\226\346\256\213\345\261\200\302\267\345\220\216\345\257\271\345\215\225\351\251\254", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class canjuwindow: public Ui_canjuwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CANJUWINDOW_H
