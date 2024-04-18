#include <QtGui/QApplication>
#include <QtCore/QTextCodec>
#include "qt1.h"
#include "ui_qt1.h"
#include<iostream>
#include "historyr.h"
using namespace std;
int main(int argc, char** argv)
{
	QApplication app(argc, argv);

	QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8")) ;
	app.setFont(QFont("wenquanyi", 12));
    historyr hr;
	Qt1 MD;
    MD.setWindowTitle("Resistance Video Monitoring System");
    hr.setWindowTitle("Resistance Value History Record");
    QObject::connect(&MD,SIGNAL(hr_clicked()),&hr,SLOT(show()));
    QObject::connect(&MD,SIGNAL(r_updated(int)),&hr,SLOT(fun_update_draw(int)));


	return app.exec();
}
