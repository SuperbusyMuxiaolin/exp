/********************************************************************************
** Form generated from reading UI file 'qt1.ui'
**
** Created: Wed Apr 17 23:28:24 2024
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
#include <QtGui/QDialog>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QHBoxLayout>
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
    QPushButton *pic_listButton;
    QPushButton *ResistorButton;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QDoubleSpinBox *tSpinBox;
    QPushButton *OpenButton;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_3;
    QLabel *label_4;
    QVBoxLayout *verticalLayout;
    QLabel *lb_resistor;
    QLabel *lb_warning;
    QPushButton *warnButton1;
    QPushButton *warnButton2;
    QLabel *label;
    QLabel *lb_sum;
    QLabel *lb_num;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pb_prev;
    QPushButton *pb_next;

    void setupUi(QDialog *Qt1)
    {
        if (Qt1->objectName().isEmpty())
            Qt1->setObjectName(QString::fromUtf8("Qt1"));
        Qt1->resize(480, 235);
        lb_time = new QLabel(Qt1);
        lb_time->setObjectName(QString::fromUtf8("lb_time"));
        lb_time->setGeometry(QRect(10, 220, 191, 20));
        lb_pic = new QLabel(Qt1);
        lb_pic->setObjectName(QString::fromUtf8("lb_pic"));
        lb_pic->setGeometry(QRect(210, 20, 241, 131));
        pic_listButton = new QPushButton(Qt1);
        pic_listButton->setObjectName(QString::fromUtf8("pic_listButton"));
        pic_listButton->setGeometry(QRect(10, 80, 151, 21));
        ResistorButton = new QPushButton(Qt1);
        ResistorButton->setObjectName(QString::fromUtf8("ResistorButton"));
        ResistorButton->setGeometry(QRect(10, 180, 151, 21));
        layoutWidget = new QWidget(Qt1);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 171, 41));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        tSpinBox = new QDoubleSpinBox(layoutWidget);
        tSpinBox->setObjectName(QString::fromUtf8("tSpinBox"));

        horizontalLayout->addWidget(tSpinBox);

        OpenButton = new QPushButton(layoutWidget);
        OpenButton->setObjectName(QString::fromUtf8("OpenButton"));

        horizontalLayout->addWidget(OpenButton);

        layoutWidget1 = new QWidget(Qt1);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(210, 170, 241, 55));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_3 = new QLabel(layoutWidget1);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_2->addWidget(label_3);

        label_4 = new QLabel(layoutWidget1);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout_2->addWidget(label_4);


        horizontalLayout_2->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        lb_resistor = new QLabel(layoutWidget1);
        lb_resistor->setObjectName(QString::fromUtf8("lb_resistor"));

        verticalLayout->addWidget(lb_resistor);

        lb_warning = new QLabel(layoutWidget1);
        lb_warning->setObjectName(QString::fromUtf8("lb_warning"));

        verticalLayout->addWidget(lb_warning);


        horizontalLayout_2->addLayout(verticalLayout);

        warnButton1 = new QPushButton(Qt1);
        warnButton1->setObjectName(QString::fromUtf8("warnButton1"));
        warnButton1->setGeometry(QRect(460, 80, 16, 16));
        warnButton1->setStyleSheet(QString::fromUtf8("QpushButton{\n"
"border-radius:15px;\n"
"\n"
"\n"
"}"));
        warnButton2 = new QPushButton(Qt1);
        warnButton2->setObjectName(QString::fromUtf8("warnButton2"));
        warnButton2->setGeometry(QRect(460, 190, 16, 16));
        label = new QLabel(Qt1);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(330, 0, 16, 18));
        lb_sum = new QLabel(Qt1);
        lb_sum->setObjectName(QString::fromUtf8("lb_sum"));
        lb_sum->setGeometry(QRect(340, 0, 20, 20));
        lb_num = new QLabel(Qt1);
        lb_num->setObjectName(QString::fromUtf8("lb_num"));
        lb_num->setGeometry(QRect(300, 0, 20, 20));
        layoutWidget2 = new QWidget(Qt1);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(10, 130, 151, 21));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        pb_prev = new QPushButton(layoutWidget2);
        pb_prev->setObjectName(QString::fromUtf8("pb_prev"));

        horizontalLayout_3->addWidget(pb_prev);

        pb_next = new QPushButton(layoutWidget2);
        pb_next->setObjectName(QString::fromUtf8("pb_next"));

        horizontalLayout_3->addWidget(pb_next);


        retranslateUi(Qt1);

        QMetaObject::connectSlotsByName(Qt1);
    } // setupUi

    void retranslateUi(QDialog *Qt1)
    {
        Qt1->setWindowTitle(QApplication::translate("Qt1", "Dialog", 0, QApplication::UnicodeUTF8));
        lb_time->setText(QString());
        lb_pic->setText(QString());
        pic_listButton->setText(QApplication::translate("Qt1", "picture list", 0, QApplication::UnicodeUTF8));
        ResistorButton->setText(QApplication::translate("Qt1", "History Resistance", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        tSpinBox->setWhatsThis(QApplication::translate("Qt1", "<html><head/><body><p><br/></p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        OpenButton->setText(QApplication::translate("Qt1", "Start", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Qt1", "Resistance:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Qt1", "Warning:", 0, QApplication::UnicodeUTF8));
        lb_resistor->setText(QString());
        lb_warning->setText(QString());
        warnButton1->setText(QString());
        warnButton2->setText(QString());
        label->setText(QApplication::translate("Qt1", "/", 0, QApplication::UnicodeUTF8));
        lb_sum->setText(QString());
        lb_num->setText(QString());
        pb_prev->setText(QApplication::translate("Qt1", "Prev", 0, QApplication::UnicodeUTF8));
        pb_next->setText(QApplication::translate("Qt1", "Next", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Qt1: public Ui_Qt1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QT1_H
