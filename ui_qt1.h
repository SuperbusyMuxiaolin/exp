/********************************************************************************
** Form generated from reading UI file 'qt1.ui'
**
** Created: Sat Apr 13 19:48:44 2024
**      by: Qt User Interface Compiler version 4.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QT1_H
#define UI_QT1_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Qt1
{
public:
    QLabel *lb_time;
    QLabel *lb_pic;
    QComboBox *comboBox;
    QPushButton *OpenButton;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *lb_resistor;
    QLabel *lb_warning;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *pic_listButton;

    void setupUi(QDialog *Qt1)
    {
        if (Qt1->objectName().isEmpty())
            Qt1->setObjectName(QString::fromUtf8("Qt1"));
        Qt1->resize(480, 272);
        lb_time = new QLabel(Qt1);
        lb_time->setObjectName(QString::fromUtf8("lb_time"));
        lb_time->setGeometry(QRect(140, 250, 191, 20));
        lb_pic = new QLabel(Qt1);
        lb_pic->setObjectName(QString::fromUtf8("lb_pic"));
        lb_pic->setGeometry(QRect(230, 60, 241, 131));
        comboBox = new QComboBox(Qt1);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(10, 10, 69, 22));
        OpenButton = new QPushButton(Qt1);
        OpenButton->setObjectName(QString::fromUtf8("OpenButton"));
        OpenButton->setGeometry(QRect(310, 10, 89, 24));
        verticalLayoutWidget = new QWidget(Qt1);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(110, 60, 101, 51));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        lb_resistor = new QLabel(verticalLayoutWidget);
        lb_resistor->setObjectName(QString::fromUtf8("lb_resistor"));

        verticalLayout->addWidget(lb_resistor);

        lb_warning = new QLabel(verticalLayoutWidget);
        lb_warning->setObjectName(QString::fromUtf8("lb_warning"));

        verticalLayout->addWidget(lb_warning);

        verticalLayoutWidget_2 = new QWidget(Qt1);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(10, 60, 101, 51));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(verticalLayoutWidget_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_2->addWidget(label_3);

        label_4 = new QLabel(verticalLayoutWidget_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout_2->addWidget(label_4);

        pic_listButton = new QPushButton(Qt1);
        pic_listButton->setObjectName(QString::fromUtf8("pic_listButton"));
        pic_listButton->setGeometry(QRect(10, 140, 141, 34));

        retranslateUi(Qt1);

        QMetaObject::connectSlotsByName(Qt1);
    } // setupUi

    void retranslateUi(QDialog *Qt1)
    {
        Qt1->setWindowTitle(QApplication::translate("Qt1", "Dialog", 0, QApplication::UnicodeUTF8));
        lb_time->setText(QApplication::translate("Qt1", "t", 0, QApplication::UnicodeUTF8));
        lb_pic->setText(QString());
        OpenButton->setText(QApplication::translate("Qt1", "Open cap", 0, QApplication::UnicodeUTF8));
        lb_resistor->setText(QString());
        lb_warning->setText(QString());
        label_3->setText(QApplication::translate("Qt1", "Resistance:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Qt1", "Warning", 0, QApplication::UnicodeUTF8));
        pic_listButton->setText(QApplication::translate("Qt1", "picture list", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Qt1: public Ui_Qt1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QT1_H
