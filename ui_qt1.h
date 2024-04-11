/********************************************************************************
** Form generated from reading UI file 'qt1.ui'
**
** Created: Sat Mar 16 11:10:00 2024
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
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Qt1
{
public:
    QLabel *lb_time;
    QLabel *lb_pic;
    QLabel *label;
    QLabel *lb_num;
    QLabel *lb_sum;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout;
    QPushButton *pb_prev;
    QPushButton *pb_next;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout;
    QRadioButton *rb_manual;
    QRadioButton *rb_auto;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pb_del;
    QPushButton *pb_open;
    QComboBox *comboBox;
    QPushButton *OpenButton;
    QPushButton *TakeButton;

    void setupUi(QDialog *Qt1)
    {
        if (Qt1->objectName().isEmpty())
            Qt1->setObjectName(QString::fromUtf8("Qt1"));
        Qt1->resize(480, 272);
        lb_time = new QLabel(Qt1);
        lb_time->setObjectName(QString::fromUtf8("lb_time"));
        lb_time->setGeometry(QRect(200, 190, 191, 20));
        lb_pic = new QLabel(Qt1);
        lb_pic->setObjectName(QString::fromUtf8("lb_pic"));
        lb_pic->setGeometry(QRect(150, 60, 311, 131));
        label = new QLabel(Qt1);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(360, 10, 16, 17));
        lb_num = new QLabel(Qt1);
        lb_num->setObjectName(QString::fromUtf8("lb_num"));
        lb_num->setGeometry(QRect(20, 100, 41, 31));
        lb_sum = new QLabel(Qt1);
        lb_sum->setObjectName(QString::fromUtf8("lb_sum"));
        lb_sum->setGeometry(QRect(30, 60, 31, 20));
        layoutWidget1 = new QWidget(Qt1);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 120, 121, 31));
        horizontalLayout = new QHBoxLayout(layoutWidget1);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pb_prev = new QPushButton(layoutWidget1);
        pb_prev->setObjectName(QString::fromUtf8("pb_prev"));

        horizontalLayout->addWidget(pb_prev);

        pb_next = new QPushButton(layoutWidget1);
        pb_next->setObjectName(QString::fromUtf8("pb_next"));

        horizontalLayout->addWidget(pb_next);

        layoutWidget2 = new QWidget(Qt1);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(10, 40, 101, 71));
        verticalLayout = new QVBoxLayout(layoutWidget2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        rb_manual = new QRadioButton(layoutWidget2);
        rb_manual->setObjectName(QString::fromUtf8("rb_manual"));

        verticalLayout->addWidget(rb_manual);

        rb_auto = new QRadioButton(layoutWidget2);
        rb_auto->setObjectName(QString::fromUtf8("rb_auto"));

        verticalLayout->addWidget(rb_auto);

        layoutWidget3 = new QWidget(Qt1);
        layoutWidget3->setObjectName(QString::fromUtf8("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(10, 170, 121, 31));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        pb_del = new QPushButton(layoutWidget3);
        pb_del->setObjectName(QString::fromUtf8("pb_del"));

        horizontalLayout_2->addWidget(pb_del);

        pb_open = new QPushButton(layoutWidget3);
        pb_open->setObjectName(QString::fromUtf8("pb_open"));

        horizontalLayout_2->addWidget(pb_open);

        comboBox = new QComboBox(Qt1);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(10, 10, 69, 22));
        OpenButton = new QPushButton(Qt1);
        OpenButton->setObjectName(QString::fromUtf8("OpenButton"));
        OpenButton->setGeometry(QRect(120, 10, 89, 24));
        TakeButton = new QPushButton(Qt1);
        TakeButton->setObjectName(QString::fromUtf8("TakeButton"));
        TakeButton->setGeometry(QRect(240, 10, 89, 24));

        retranslateUi(Qt1);

        QMetaObject::connectSlotsByName(Qt1);
    } // setupUi

    void retranslateUi(QDialog *Qt1)
    {
        Qt1->setWindowTitle(QApplication::translate("Qt1", "Dialog", 0, QApplication::UnicodeUTF8));
        lb_time->setText(QString());
        lb_pic->setText(QString());
        label->setText(QApplication::translate("Qt1", "/", 0, QApplication::UnicodeUTF8));
        lb_num->setText(QString());
        lb_sum->setText(QString());
        pb_prev->setText(QApplication::translate("Qt1", "Former", 0, QApplication::UnicodeUTF8));
        pb_next->setText(QApplication::translate("Qt1", "Next", 0, QApplication::UnicodeUTF8));
        rb_manual->setText(QApplication::translate("Qt1", "Manual", 0, QApplication::UnicodeUTF8));
        rb_auto->setText(QApplication::translate("Qt1", "Auto", 0, QApplication::UnicodeUTF8));
        pb_del->setText(QApplication::translate("Qt1", "Del", 0, QApplication::UnicodeUTF8));
        pb_open->setText(QApplication::translate("Qt1", "Open", 0, QApplication::UnicodeUTF8));
        OpenButton->setText(QApplication::translate("Qt1", "Open cap", 0, QApplication::UnicodeUTF8));
        TakeButton->setText(QApplication::translate("Qt1", "Take photo", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Qt1: public Ui_Qt1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QT1_H
