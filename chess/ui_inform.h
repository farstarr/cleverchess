/********************************************************************************
** Form generated from reading UI file 'inform.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INFORM_H
#define UI_INFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_inform
{
public:
    QVBoxLayout *verticalLayout;
    QTextBrowser *textBrowser;
    QPushButton *pushButton;

    void setupUi(QWidget *inform)
    {
        if (inform->objectName().isEmpty())
            inform->setObjectName(QStringLiteral("inform"));
        inform->resize(386, 435);
        verticalLayout = new QVBoxLayout(inform);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        textBrowser = new QTextBrowser(inform);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));

        verticalLayout->addWidget(textBrowser);

        pushButton = new QPushButton(inform);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        pushButton->setFont(font);

        verticalLayout->addWidget(pushButton);


        retranslateUi(inform);

        QMetaObject::connectSlotsByName(inform);
    } // setupUi

    void retranslateUi(QWidget *inform)
    {
        inform->setWindowTitle(QApplication::translate("inform", "Form", Q_NULLPTR));
        textBrowser->setHtml(QApplication::translate("inform", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SimSun';\">\346\234\254\346\270\270\346\210\217\344\270\272\351\253\230\344\270\200\350\276\260\343\200\201\347\216\213\346\263\240\346\235\211\345\244\247\344\270\200\344\270\213\345\255\246\346\234\237\345\237\272\344\272\216QT\345\271\263\345\217\260\345\274\200\345\217\221\347\232\204C++\350\257\276\350\256\276\343\200\202\346\204\237\350\260\242\346\202\250\347\232\204\346\270\270\347\216\251\357\274\214\345\246\202\346\234\211\351\227\256\351\242\230\357\274\214\350\257\267\350\201\224\347\263\273\357\274\232</span></p>\n"
"<p styl"
                        "e=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SimSun';\">\345\217\202\350\200\203\346\226\207\347\214\256\357\274\232</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SimSun';\">\345\220\214\346\227\266\346\204\237\350\260\242\350\200\201\345\270\210\347\232\204\345\270\256\345\212\251\344\270\216\346\225\231\346\216\210\343\200\202</span></p></body></html>", Q_NULLPTR));
        pushButton->setText(QApplication::translate("inform", "\347\241\256\350\256\244", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class inform: public Ui_inform {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INFORM_H
