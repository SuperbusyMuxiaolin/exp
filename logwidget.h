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

public slots:
    void pb_clear_clicked();  //重置按钮按下后触发的事件
    void pb_log_clicked();  //登录按钮按下后触发的事件

private:
    Ui::LogWidget *ui;
    QString m_username;
    QString m_password;
    Keyboard keyboard;
};

#endif // LOGWIDGET_H
