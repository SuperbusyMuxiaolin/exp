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
    //连接数字键和对应事件
    connect(ui->pb_0,SIGNAL(clicked(bool)),this,SLOT(pb_number_clicked()));


    ui->tx_pw->setEchoMode(QLineEdit::Password);//输入的时候就显示圆点

    m_username = "123456";
    m_password = "123456";


}
void LogWidget::pb_clear_clicked()
{
    ui->tx_pw->clear();
    ui->tx_usr->clear();
}


void LogWidget::pb_log_clicked()
{
    QString name = ui->tx_usr->text();
    QString password = ui->tx_pw->text();


    if (name == m_username && password == m_password)
    {
        emit(login());
        emit(close_window());
    }
    else
        QMessageBox::information(this, "Warning","Username or Password is wrong !");
}

void LogWidget::pb_number_clicked(){
    Qstring t=((QpushButton*)sender())->text();
    QLineEdit* activeLineEdit = qApp->focusWidget()->findChild<QLineEdit*>();
        if (activeLineEdit) {
            // 将字符串插入到光标位置
            activeLineEdit->insert(t);
        }

}



LogWidget::~LogWidget()
{
    delete ui;
}
