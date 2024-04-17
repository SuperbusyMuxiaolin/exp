#include "historyr.h"
#include "ui_historyr.h"
#include <QDebug>

historyr::historyr(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::historyr)
{
    ui->setupUi(this);
    this->setMinimumSize(480,230);
    this->setMaximumSize(480,230);
    connect(ui->BackButton,SIGNAL(clicked()),this,SLOT(fun_close()));//只是隐藏窗口

    //connect(, SIGNAL(rListUpdated(QList<int>)), this, SLOT(updaterList(QList<int>)));


}
void historyr::fun_close(){
    this->hide();
}
void historyr::updaterList(const QList<int> &resistorList){
    list=resistorList;
    QDebug<<list.first()<<endl;
}

historyr::~historyr()
{
    delete ui;
}
