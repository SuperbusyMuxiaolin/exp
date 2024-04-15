#include "historyr.h"
#include "ui_historyr.h"

historyr::historyr(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::historyr)
{
    ui->setupUi(this);
    this->setMinimumSize(480,230);
    this->setMaximumSize(480,230);
    connect(ui->BackButton,SIGNAL(clicked()),this,SLOT(fun_close()));

}
void historyr::fun_close(){
    this->close();
}

historyr::~historyr()
{
    delete ui;
}
