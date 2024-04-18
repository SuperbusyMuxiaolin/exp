#include "logwidget.h"
#include "ui_logwidget.h"
#include <QString>
#include <iostream>
#include <QDebug>
using namespace std;

LogWidget::LogWidget(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LogWidget)
{
    ui->setupUi(this);


    ui->pb_0->setFocusPolicy(Qt::NoFocus); 
    ui->pb_1->setFocusPolicy(Qt::NoFocus); 
    ui->pb_2->setFocusPolicy(Qt::NoFocus); 
    ui->pb_3->setFocusPolicy(Qt::NoFocus); 
    ui->pb_4->setFocusPolicy(Qt::NoFocus); 
    ui->pb_5->setFocusPolicy(Qt::NoFocus); 
    ui->pb_6->setFocusPolicy(Qt::NoFocus); 
    ui->pb_7->setFocusPolicy(Qt::NoFocus); 
    ui->pb_8->setFocusPolicy(Qt::NoFocus); 
    ui->pb_9->setFocusPolicy(Qt::NoFocus); 
    ui->pb_bk->setFocusPolicy(Qt::NoFocus);
    ui->pb_clear->setFocusPolicy(Qt::NoFocus);



    // connect
    // 触发重置按钮的信号槽连接
    connect(ui->pb_clear,SIGNAL(clicked()),this,SLOT(pb_clear_clicked()));
    // 触发登录按钮的信号槽连接
    connect(ui->pb_log,SIGNAL(clicked()),this,SLOT(pb_log_clicked()));
    // 发出信号后关闭登录窗口的信号槽连接
    connect(this,SIGNAL(close_window()),this,SLOT(close()));
    //连接数字键和对应事件
    connect(ui->pb_0,SIGNAL(clicked()),this,SLOT(pb_0_clicked()));
    connect(ui->pb_1,SIGNAL(clicked()),this,SLOT(pb_1_clicked()));
    connect(ui->pb_2,SIGNAL(clicked()),this,SLOT(pb_2_clicked()));
    connect(ui->pb_3,SIGNAL(clicked()),this,SLOT(pb_3_clicked()));
    connect(ui->pb_4,SIGNAL(clicked()),this,SLOT(pb_4_clicked()));
    connect(ui->pb_5,SIGNAL(clicked()),this,SLOT(pb_5_clicked()));
    connect(ui->pb_6,SIGNAL(clicked()),this,SLOT(pb_6_clicked()));
    connect(ui->pb_7,SIGNAL(clicked()),this,SLOT(pb_7_clicked()));
    connect(ui->pb_8,SIGNAL(clicked()),this,SLOT(pb_8_clicked()));
    connect(ui->pb_9,SIGNAL(clicked()),this,SLOT(pb_9_clicked()));
    //连接退格键
    connect(ui->pb_bk,SIGNAL(clicked()),this,SLOT(pb_bk_clicked()));
    //连接退格键
    connect(ui->pb_cancel,SIGNAL(clicked()),this,SLOT(pb_cancel_clicked()));



    m_username = "1";
    m_password = "1";


}
void LogWidget::pb_clear_clicked()
{
    if(ui->tx_usr->hasFocus()){
        ui->tx_usr->clear();
    }
    if(ui->tx_pw->hasFocus()){
        ui->tx_pw->clear();
    }
}

void LogWidget::pb_cancel_clicked(){
    emit(close_window());
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

void LogWidget::pb_0_clicked(){
    if(ui->tx_usr->hasFocus()){
        QString str=ui->tx_usr->text();
        str+="0";
        qDebug() << str;
        ui->tx_usr->setText(str);//赋值给输入框
    }
    if(ui->tx_pw->hasFocus())
    {
        QString str=ui->tx_pw->text();
        str+="0";
        qDebug() << str;
        ui->tx_pw->setText(str);//赋值给输入框
    }
}

void LogWidget::pb_1_clicked(){
    if(ui->tx_usr->hasFocus()){
        QString str=ui->tx_usr->text();
        str+="1";
        qDebug() << str;
        ui->tx_usr->setText(str);//赋值给输入框
    }
    if(ui->tx_pw->hasFocus())
    {
        QString str=ui->tx_pw->text();
        str+="1";
        qDebug() << str;
        ui->tx_pw->setText(str);//赋值给输入框
    }
    

}

void LogWidget::pb_2_clicked(){
    if(ui->tx_usr->hasFocus()){
        QString str=ui->tx_usr->text();
        str+="2";
        qDebug() << str;
        ui->tx_usr->setText(str);//赋值给输入框
    }
    if(ui->tx_pw->hasFocus())
    {
        QString str=ui->tx_pw->text();
        str+="2";
        qDebug() << str;
        ui->tx_pw->setText(str);//赋值给输入框
    }
   

}

void LogWidget::pb_3_clicked(){
    if(ui->tx_usr->hasFocus()){
        QString str=ui->tx_usr->text();
        str+="3";
        qDebug() << str;
        ui->tx_usr->setText(str);//赋值给输入框
    }
    if(ui->tx_pw->hasFocus())
    {
        QString str=ui->tx_pw->text();
        str+="3";
        qDebug() << str;
        ui->tx_pw->setText(str);//赋值给输入框
    }
   
}

void LogWidget::pb_4_clicked(){
    if(ui->tx_usr->hasFocus()){
        QString str=ui->tx_usr->text();
        str+="4";
        qDebug() << str;
        ui->tx_usr->setText(str);//赋值给输入框
    }
    if(ui->tx_pw->hasFocus())
    {
        QString str=ui->tx_pw->text();
        str+="4";
        qDebug() << str;
        ui->tx_pw->setText(str);//赋值给输入框
    }
    
}

void LogWidget::pb_5_clicked(){
    if(ui->tx_usr->hasFocus()){
        QString str=ui->tx_usr->text();
        str+="5";
        qDebug() << str;
        ui->tx_usr->setText(str);//赋值给输入框
    }
    if(ui->tx_pw->hasFocus())
    {
        QString str=ui->tx_pw->text();
        str+="5";
        qDebug() << str;
        ui->tx_pw->setText(str);//赋值给输入框
    }
   
}

void LogWidget::pb_6_clicked(){
    if(ui->tx_usr->hasFocus()){
        QString str=ui->tx_usr->text();
        str+="6";
        qDebug() << str;
        ui->tx_usr->setText(str);//赋值给输入框
    }
    if(ui->tx_pw->hasFocus())
    {
        QString str=ui->tx_pw->text();
        str+="6";
        qDebug() << str;
        ui->tx_pw->setText(str);//赋值给输入框
    }
   
}

void LogWidget::pb_7_clicked(){
    if(ui->tx_usr->hasFocus()){
        QString str=ui->tx_usr->text();
        str+="7";
        qDebug() << str;
        ui->tx_usr->setText(str);//赋值给输入框
    }
    if(ui->tx_pw->hasFocus())
    {
        QString str=ui->tx_pw->text();
        str+="7";
        qDebug() << str;
        ui->tx_pw->setText(str);//赋值给输入框
    }
  

}

void LogWidget::pb_8_clicked(){
    if(ui->tx_usr->hasFocus()){
        QString str=ui->tx_usr->text();
        str+="8";
        qDebug() << str;
        ui->tx_usr->setText(str);//赋值给输入框
    }
    if(ui->tx_pw->hasFocus())
    {
        QString str=ui->tx_pw->text();
        str+="8";
        qDebug() << str;
        ui->tx_pw->setText(str);//赋值给输入框
    }
  
}

void LogWidget::pb_9_clicked(){
    if(ui->tx_usr->hasFocus()){
        QString str=ui->tx_usr->text();
        str+="9";
        qDebug() << str;
        ui->tx_usr->setText(str);//赋值给输入框
    }
    if(ui->tx_pw->hasFocus())
    {
        QString str=ui->tx_pw->text();
        str+="9";
        qDebug() << str;
        ui->tx_pw->setText(str);//赋值给输入框
    }
   
}

void LogWidget::pb_bk_clicked(){
    if(ui->tx_usr->hasFocus()){
        QString str=ui->tx_usr->text();
        str.chop(1);
        qDebug() << str;
        ui->tx_usr->setText(str);//赋值给输入框
    }
    if(ui->tx_pw->hasFocus())
    {
        QString str=ui->tx_pw->text();
        str.chop(1);
        qDebug() << str;
        ui->tx_pw->setText(str);//赋值给输入框
    }
   

}

LogWidget::~LogWidget()
{
    delete ui;
}
