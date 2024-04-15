#include "logwidget.h"
#include "ui_logwidget.h"

LogWidget::LogWidget(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LogWidget)
{
    ui->setupUi(this);
    // connect
    // 触发重置按钮的信号槽连接
    connect(ui->pb_clear,SIGNAL(clicked()),this,SLOT(pb_clear_clicked()));
    // 触发登录按钮的信号槽连接
    connect(ui->pb_log,SIGNAL(clicked()),this,SLOT(pb_log_clicked()));
    // 发出信号后关闭登录窗口的信号槽连接
    connect(this,SIGNAL(close_window()),this,SLOT(close()));

    ui->edit_pw->setEchoMode(QLineEdit::Password);//输入的时候就显示圆点

    m_username = "123456";
    m_password = "123456";


}
void LogWidget::pb_clear_clicked()
{
    ui->edit_pw->clear();
    ui->edit_name->clear();
}


void LogWidget::btn_log_clicked()
{
    QString name = ui->edit_name->text();
    QString password = ui->edit_pw->text();


    if (name == m_username && password == m_password)
    {
        emit(login());
        emit(close_window());
    }
    else
        QMessageBox::information(this, "Warning","Username or Password is wrong !");
}




LogWidget::~LogWidget()
{
    delete ui;
}
