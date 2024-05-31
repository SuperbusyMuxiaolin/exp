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
#include "ui_qt1.h"
#include "Resistor.h"
#include "historyr.h"
#include "logwidget.h"
#include <QList>
//#include "dlinklist.h"

class Qt1: public QDialog,public Ui_Qt1
{
	Q_OBJECT
public:
	Qt1(QWidget *parent = 0);
    ~Qt1();
    Resistor resistor;
	void strip(char *s);
	int judge(char *s);
        void showCapPhoto();
//	void insert_dlinklist(DLIST *d,char *s);

signals:
        	void hr_clicked();
        	void r_updated(int r);
	
public slots:
        void fun_time();
        void fun_open();
        void fun_cap_open();
        void fun_take_photo();
        void fun_refresh_pic();
        void update_show_Resistor();
        void fun_change_t();//改变更新时间
        void fun_open_resistor();
        void display_pic();
        void fun_prev();
        void fun_pic();
        void sendsignal();
        void login();
        void sendmsg();
        void sendHeart();
	
private:
        QTimer t1;	//用于更新时间
        QTimer t2;      
        QTimer t3;      //用于自动播放图片
        QTimer update_t;        //用于更新电阻及其报警信息

        int update_t_set;
        LogWidget *m_log;
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
        int cfd;
        int cfdp;
        int cfdh;
};


#endif 
