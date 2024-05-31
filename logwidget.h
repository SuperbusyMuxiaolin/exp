#ifndef LOGWIDGET_H
#define LOGWIDGET_H

#include <QDialog>
#include <QWidget>
#include <QMessageBox>
#include <QFile>
#include <QDebug>
#include <QByteArray>
#include "Keyboard.h"
#include "NumberKeyboard.h"

using namespace AeaQt;


namespace Ui {
class LogWidget;
}

class LogWidget : public QDialog
{
    Q_OBJECT

public:
    explicit LogWidget(QWidget *parent = 0);
    ~LogWidget();

signals:
    void login(); //登录主界面信号
    void close_window();  //关闭登录界面信号
    void close_exe();

public slots:
    void pb_clear_clicked();  //重置按钮按下后触发的事件
    void pb_log_clicked();  //登录按钮按下后触发的事件
    void pb_0_clicked();
    void pb_1_clicked();
    void pb_2_clicked();
    void pb_3_clicked();
    void pb_4_clicked();
    void pb_5_clicked();
    void pb_6_clicked();
    void pb_7_clicked();
    void pb_8_clicked();
    void pb_9_clicked();
    void pb_bk_clicked();
    void pb_cancel_clicked();

private:
    Ui::LogWidget *ui;
    QString m_username;
    QString m_password;
    Keyboard keyboard;
};

#endif // LOGWIDGET_H
