#ifndef QT1_H
#define QT1_H

#include <QDialog>
#include <QWidget>
#include <QString>
#include <QPushButton>
#include <QProcess>
#include <QTimer>
#include <QImage>
#include "camera.h"
#include "Resistor.h"

#include "ui_qt1.h"
//#include "dlinklist.h"

class Qt1: public QDialog,public Ui_Qt1
{
	Q_OBJECT
public:
	Qt1(QWidget *parent = 0);
	~Qt1();
	void strip(char *s);
	int judge(char *s);
        void showCapPhoto();
//	void insert_dlinklist(DLIST *d,char *s);

signals:
//	mysig();
	
public slots:
	void fun_time();
	void fun_pic();
	void fun_cntl();
	void display_pic();
	void fun_prev();
	void fun_delete();
	void fun_open();
        void fun_cap_open();
        void fun_take_photo();
        void fun_refresh_pic();
        void fun_refresh_label();
        void updateResistor();
	
private:
        QTimer t1;	//
        QTimer t2;
        QTimer t3;
        QTimer update_t;
        Resistor resistor;
	int len;
        bool isCapOpen;
        Camera* myCamera;
        int width;
        int height;
        QImage* m_image;
        unsigned char *frameBufRGB;
        unsigned char *frameBufYUV;
        bool isToSave;
        void fun_clean_pixmap();
        void InitBox();
};


#endif 
