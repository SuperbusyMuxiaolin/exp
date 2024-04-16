/********************************************************************************
** Form generated from reading UI file 'logwidget.ui'
**
** Created: Tue Apr 16 22:27:25 2024
**      by: Qt User Interface Compiler version 4.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGWIDGET_H
#define UI_LOGWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LogWidget
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *pb_clear;
    QPushButton *pb_6;
    QPushButton *pb_3;
    QPushButton *pb_9;
    QPushButton *pb_1;
    QPushButton *pb_7;
    QPushButton *pb_2;
    QPushButton *pb_4;
    QPushButton *pb_bk;
    QPushButton *pb_8;
    QPushButton *pb_0;
    QPushButton *pb_5;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *tx_usr;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *tx_pw;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pb_log;
    QPushButton *pb_cancel;

    void setupUi(QDialog *LogWidget)
    {
        if (LogWidget->objectName().isEmpty())
            LogWidget->setObjectName(QString::fromUtf8("LogWidget"));
        LogWidget->resize(480, 230);
        gridLayoutWidget = new QWidget(LogWidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(270, 20, 191, 181));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        pb_clear = new QPushButton(gridLayoutWidget);
        pb_clear->setObjectName(QString::fromUtf8("pb_clear"));

        gridLayout->addWidget(pb_clear, 3, 2, 1, 1);

        pb_6 = new QPushButton(gridLayoutWidget);
        pb_6->setObjectName(QString::fromUtf8("pb_6"));

        gridLayout->addWidget(pb_6, 1, 2, 1, 1);

        pb_3 = new QPushButton(gridLayoutWidget);
        pb_3->setObjectName(QString::fromUtf8("pb_3"));

        gridLayout->addWidget(pb_3, 0, 2, 1, 1);

        pb_9 = new QPushButton(gridLayoutWidget);
        pb_9->setObjectName(QString::fromUtf8("pb_9"));

        gridLayout->addWidget(pb_9, 2, 2, 1, 1);

        pb_1 = new QPushButton(gridLayoutWidget);
        pb_1->setObjectName(QString::fromUtf8("pb_1"));

        gridLayout->addWidget(pb_1, 0, 0, 1, 1);

        pb_7 = new QPushButton(gridLayoutWidget);
        pb_7->setObjectName(QString::fromUtf8("pb_7"));

        gridLayout->addWidget(pb_7, 2, 0, 1, 1);

        pb_2 = new QPushButton(gridLayoutWidget);
        pb_2->setObjectName(QString::fromUtf8("pb_2"));

        gridLayout->addWidget(pb_2, 0, 1, 1, 1);

        pb_4 = new QPushButton(gridLayoutWidget);
        pb_4->setObjectName(QString::fromUtf8("pb_4"));

        gridLayout->addWidget(pb_4, 1, 0, 1, 1);

        pb_bk = new QPushButton(gridLayoutWidget);
        pb_bk->setObjectName(QString::fromUtf8("pb_bk"));

        gridLayout->addWidget(pb_bk, 3, 0, 1, 1);

        pb_8 = new QPushButton(gridLayoutWidget);
        pb_8->setObjectName(QString::fromUtf8("pb_8"));

        gridLayout->addWidget(pb_8, 2, 1, 1, 1);

        pb_0 = new QPushButton(gridLayoutWidget);
        pb_0->setObjectName(QString::fromUtf8("pb_0"));

        gridLayout->addWidget(pb_0, 3, 1, 1, 1);

        pb_5 = new QPushButton(gridLayoutWidget);
        pb_5->setObjectName(QString::fromUtf8("pb_5"));

        gridLayout->addWidget(pb_5, 1, 1, 1, 1);

        layoutWidget = new QWidget(LogWidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(11, 20, 231, 27));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        tx_usr = new QLineEdit(layoutWidget);
        tx_usr->setObjectName(QString::fromUtf8("tx_usr"));

        horizontalLayout->addWidget(tx_usr);

        layoutWidget1 = new QWidget(LogWidget);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 90, 231, 27));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        tx_pw = new QLineEdit(layoutWidget1);
        tx_pw->setObjectName(QString::fromUtf8("tx_pw"));
        tx_pw->setEchoMode(QLineEdit::Password);

        horizontalLayout_2->addWidget(tx_pw);

        layoutWidget2 = new QWidget(LogWidget);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(10, 160, 235, 36));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        pb_log = new QPushButton(layoutWidget2);
        pb_log->setObjectName(QString::fromUtf8("pb_log"));

        horizontalLayout_3->addWidget(pb_log);

        pb_cancel = new QPushButton(layoutWidget2);
        pb_cancel->setObjectName(QString::fromUtf8("pb_cancel"));

        horizontalLayout_3->addWidget(pb_cancel);


        retranslateUi(LogWidget);

        QMetaObject::connectSlotsByName(LogWidget);
    } // setupUi

    void retranslateUi(QDialog *LogWidget)
    {
        LogWidget->setWindowTitle(QApplication::translate("LogWidget", "Dialog", 0, QApplication::UnicodeUTF8));
        pb_clear->setText(QApplication::translate("LogWidget", "Clear", 0, QApplication::UnicodeUTF8));
        pb_6->setText(QApplication::translate("LogWidget", "6", 0, QApplication::UnicodeUTF8));
        pb_3->setText(QApplication::translate("LogWidget", "3", 0, QApplication::UnicodeUTF8));
        pb_9->setText(QApplication::translate("LogWidget", "9", 0, QApplication::UnicodeUTF8));
        pb_1->setText(QApplication::translate("LogWidget", "1", 0, QApplication::UnicodeUTF8));
        pb_7->setText(QApplication::translate("LogWidget", "7", 0, QApplication::UnicodeUTF8));
        pb_2->setText(QApplication::translate("LogWidget", "2", 0, QApplication::UnicodeUTF8));
        pb_4->setText(QApplication::translate("LogWidget", "4", 0, QApplication::UnicodeUTF8));
        pb_bk->setText(QApplication::translate("LogWidget", "BackSpace", 0, QApplication::UnicodeUTF8));
        pb_8->setText(QApplication::translate("LogWidget", "8", 0, QApplication::UnicodeUTF8));
        pb_0->setText(QApplication::translate("LogWidget", "0", 0, QApplication::UnicodeUTF8));
        pb_5->setText(QApplication::translate("LogWidget", "5", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("LogWidget", "UserName", 0, QApplication::UnicodeUTF8));
        tx_usr->setText(QApplication::translate("LogWidget", "Please input your username", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("LogWidget", "PassWord", 0, QApplication::UnicodeUTF8));
        tx_pw->setText(QApplication::translate("LogWidget", "Please input your password", 0, QApplication::UnicodeUTF8));
        pb_log->setText(QApplication::translate("LogWidget", "Login", 0, QApplication::UnicodeUTF8));
        pb_cancel->setText(QApplication::translate("LogWidget", "Cancel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class LogWidget: public Ui_LogWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGWIDGET_H
