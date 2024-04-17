#include "historyr.h"
#include "ui_historyr.h"
#include <QDebug>
#include <iostream>
#include <QPaintEvent>
#include <QPainter>
#include <QPen>
#include <QRect>
#include <QPoint>
#include <algorithm> // 用于使用 std::min_element 和 std::max_element
using namespace std;

historyr::historyr(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::historyr)
{
    ui->setupUi(this);
    this->setMinimumSize(480,230);
    this->setMaximumSize(480,230);
    
    connect(ui->BackButton,SIGNAL(clicked()),this,SLOT(fun_close()));//只是隐藏窗口
    connect(&t1,SIGNAL(timeout()),this,SLOT(fun_draw()));
    t1.start(1000);
    


}
void historyr::fun_close(){
    this->hide();
}
void historyr::fun_draw(){
    cout<<"列表的最后一个值"<<List.last()<<endl;
    
}

historyr::~historyr()
{
    delete ui;
}
