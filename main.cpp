#include <QtGui/QApplication>
#include <QtCore/QTextCodec>
#include "qt1.h"
#include "ui_qt1.h"
#include<iostream>
using namespace std;
int main(int argc, char** argv)
{
	QApplication app(argc, argv);

	QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8")) ;
	app.setFont(QFont("wenquanyi", 12));

	Qt1 MD;
    MD.setWindowTitle("Resistance Video Monitoring System");
    //MD.show();
	// MD.setDefaultWeight();
	return app.exec();
}
