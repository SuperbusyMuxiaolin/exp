/********************************************************************************
** Form generated from reading UI file 'historyr.ui'
**
** Created: Wed Apr 17 19:07:43 2024
**      by: Qt User Interface Compiler version 4.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HISTORYR_H
#define UI_HISTORYR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_historyr
{
public:
    QPushButton *BackButton;
    QLabel *r_pic;

    void setupUi(QDialog *historyr)
    {
        if (historyr->objectName().isEmpty())
            historyr->setObjectName(QString::fromUtf8("historyr"));
        historyr->resize(480, 230);
        BackButton = new QPushButton(historyr);
        BackButton->setObjectName(QString::fromUtf8("BackButton"));
        BackButton->setGeometry(QRect(350, 10, 112, 34));
        r_pic = new QLabel(historyr);
        r_pic->setObjectName(QString::fromUtf8("r_pic"));
        r_pic->setGeometry(QRect(20, 10, 291, 171));

        retranslateUi(historyr);

        QMetaObject::connectSlotsByName(historyr);
    } // setupUi

    void retranslateUi(QDialog *historyr)
    {
        historyr->setWindowTitle(QApplication::translate("historyr", "Dialog", 0, QApplication::UnicodeUTF8));
        BackButton->setText(QApplication::translate("historyr", "Back", 0, QApplication::UnicodeUTF8));
        r_pic->setText(QApplication::translate("historyr", "r_pic", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class historyr: public Ui_historyr {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HISTORYR_H
