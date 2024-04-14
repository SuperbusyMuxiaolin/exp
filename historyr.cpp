#include "historyr.h"
#include "ui_historyr.h"

historyr::historyr(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::historyr)
{
    ui->setupUi(this);
    connect(ui->BackButton,SIGNAL(clicked()),this,fun_close());

}
void historyr::fun_close(){
    this->close();
}

historyr::~historyr()
{
    delete ui;
}
