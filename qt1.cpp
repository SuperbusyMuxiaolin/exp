#include <iostream>
#include <unistd.h>
#include <dirent.h>
#include <fcntl.h>
#include <QPainter>
#include <QFileDialog>
#include <QFontDialog>
#include <QColorDialog>
#include <QLineEdit>
#include <QTimer>
#include <pthread.h>
#include <QProcess>
#include <QMessageBox>
#include <QInputDialog>
#include <QDebug>
#include <fstream>
#include <QDateTime>
#include "qt1.h"

#include "dlinklist.c"	
extern "C"{                  //表示用C语言编译（当C与C++混合编译时使用）
#include "client.h"   //**引入TCP客户端连接相关函数
}
using namespace std;

static int i=0;
int camera=0;
int W=0;
DLIST *p;
DLIST *q;
DLIST head;
char filename[128]="mnt/usb/a1.jpg";


QTimer* refreshTimer; 
bool isTakingPhoto; 


//class Mythread:public QThread
//{
//    Q_OBJECT
//public:
//    void run()override
//    {
//        sendR()
//    }
//}

void insert_dlinklist(DLIST *d,char *s);

Qt1::Qt1(QWidget *parent):QDialog(parent)
{
  	setupUi(this);
	update_t_set=500;
	//cfd=TCPconnect(1234,"169.254.223.6");
    
    m_log = new LogWidget;
    m_log->setWindowTitle("Login");
    m_log->show();
    // 这个信号槽的作用就是激活主窗口的，已经让主窗口不可以自动打开，
    // 必须通过登录窗口中登录按钮发出的信号槽的信号才能打开
    connect(m_log,SIGNAL(login()),this,SLOT(login()));
    //连接关闭程序信号和close()函数
    connect(m_log,SIGNAL(close_exe()),this,SLOT(close()));

    //固定窗口大小
    this->setMinimumSize(480,235);
    this->setMaximumSize(480,235);
    m_image = NULL;
    OpenButton->setDisabled(false);

    //报警信息按钮不可按
    warnButton1->setDisabled(true);
    warnButton2->setDisabled(true);

    //看上下图片不可用
    pb_prev->setDisabled(true);
    pb_next->setDisabled(true);


    //设置更新时间选择窗
    tSpinBox->setRange(0.4,5);
    tSpinBox->setSingleStep(0.2);
    tSpinBox->setValue(0.5);
    tSpinBox->setPrefix("Time:");
    tSpinBox->setSuffix("s");
    tSpinBox->setWrapping(true);
    connect(tSpinBox,SIGNAL(valueChanged(double)),this,SLOT(fun_change_t()));

    //打开历史阻值窗口
    connect(ResistorButton,SIGNAL(clicked()),this,SLOT(fun_open_resistor()));

	refreshTimer = new QTimer(this);
    connect(refreshTimer, SIGNAL(timeout()), this, SLOT(fun_refresh_pic()));//动态更新图片显示
    isTakingPhoto = false;
    //看上下图片
    connect(pb_prev,SIGNAL(clicked()),this,SLOT(fun_prev()));
    connect(pb_next,SIGNAL(clicked()),this,SLOT(fun_pic()));

    connect(OpenButton,SIGNAL(clicked()),this,SLOT(fun_cap_open()));
	connect(pic_listButton,SIGNAL(clicked()),this,SLOT(fun_open())); 	
  	connect(&t1,SIGNAL(timeout()),this,SLOT(fun_time()));//时间显示
	t1.start(1000);//时间显示每一秒触发一次，即以秒进行时间显示更新

  	connect(&update_t,SIGNAL(timeout()),this,SLOT(fun_take_photo()));
    connect(&update_t,SIGNAL(timeout()),this,SLOT(update_show_Resistor()));//调用adc更新阻值信息&窗口更新阻值及报警信息
	connect(&update_t,SIGNAL(timeout()),this,SLOT(sendsignal()));
	connect(&t3,SIGNAL(timeout()),this,SLOT(sendmsg()));
	connect(&t2,SIGNAL(timeout()),this,SLOT(sendHeart()));
	init_dlinklist(&head);
    width = 480;
	height = 272;
    myCamera = new Camera("/dev/video0", width, height, 0);
    frameBufRGB = new unsigned char[width * height * 3];
    frameBufYUV = new unsigned char[width * height * 2];
}
void Qt1::fun_open_resistor(){
    emit hr_clicked();
}

void Qt1::login(){
    this->show();
    cfd=TCPconnect(1234,"169.254.223.6");
    //cfdp=TCPconnect(11254,"169.254.223.6");
    cfdh=TCPconnect(8108,"169.254.223.6");
    t2.start(1000);
}
void Qt1::sendHeart(){
    sendHeartBeat(cfdh);
}

void Qt1::fun_change_t(){
    update_t_set=1000*tSpinBox->value();
}

void Qt1::fun_refresh_pic()
{
    printf("refresh!!!!!!!!!!\n");
	if (isTakingPhoto)
    {
        //refreshTimer->stop();
    }
   if(!myCamera->GetBuffer(frameBufYUV))
   {
       std::cout<< "Get Camera Buf error!\n";
       return;
   }
   myCamera->process_image(frameBufYUV, frameBufRGB);
   showCapPhoto();
}

void Qt1::fun_pic()
{
    i++;
    if(i==(len+1))i=1;

    p=p->next;
    display_pic();
}

void Qt1::fun_prev()
{
    i--;
    if(i==0)i=len;

    p=p->prev;
    display_pic();
}
void Qt1::fun_cap_open()
{
    if (camera == 1)
    {
        camera = 0;
        OpenButton->setText("Start");
        myCamera->CloseDevice();
        printf("00000000000000\n");
        refreshTimer->stop();
		update_t.stop();//相机处于关闭状态，数据更新及获取停止
		t3.stop();
    }
    else
    {
        camera = 1;
        OpenButton->setText("Close");
        myCamera->OpenDevice();
        printf("111111111111111111\n");
        refreshTimer->start(100);  
        isTakingPhoto = false;
		update_t.start(update_t_set);//相机处于打开状态，数据更新及获取开始，按update_t_set为间隔获取
		t3.start(update_t_set);
    }
}


void Qt1::fun_clean_pixmap()
{
    QPixmap p;
    lb_pic->setPixmap(p);
}



void Qt1::fun_take_photo()
{
    camera = 0;
    char filename1[20];
    if (m_image != NULL)
    {
        sprintf(filename1, "mnt/usb/a%d.jpg", W++);
        printf("%s\n", filename1);
        m_image->save(filename1, "jpg", -1);
        strcpy(filename, filename1);
        printf("外面的字符串是%s\n", filename1);
        cfdp=TCPconnect(11254,"169.254.223.6");
        sendPhoto3(cfdp,filename1);

    }
    camera = 1;
    isTakingPhoto = true;
}

void Qt1::showCapPhoto()
{

    if(m_image != NULL)
        delete m_image;
    m_image = NULL;
    m_image = new QImage(frameBufRGB, width, height, QImage::Format_RGB888);
    lb_pic->setPixmap(QPixmap::fromImage(*m_image));
}


void Qt1::fun_time()
{
    QDateTime d=QDateTime::currentDateTime();	
    lb_time->setText(d.toString("yyyy-MM-dd-ddd hh:mm:ss"));	
}


void Qt1::fun_open()//注意文件位置
{
    //cfd=TCPconnect(1234,"169.254.223.6");
	refreshTimer->stop();
	QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                 "/mnt/usb",
                                                 tr("Images (*.png *.xpm *.jpg)"));
	printf("open folder!\n");
	if(fileName!=NULL)
	{
		init_dlinklist(&head);	
		char *str;
		char filename[100]={0};
		DIR *dp;					
		struct dirent *dirp;		
		
		int m=strlen(fileName.toAscii().data());
		str=(char*)malloc(m);
		strcpy(str,fileName.toAscii().data());
		strcpy(filename,str);

		QString buf(fileName.toAscii().data());
		QPixmap first(buf);
		lb_pic->setPixmap(first);
		lb_pic->setScaledContents(1);
		
		strip(filename);
		dp=opendir(filename);
		while(dirp=readdir(dp))
		{
			if(judge(dirp->d_name)==1)
			{
				strcat(filename,"/");
				strcat(filename,dirp->d_name);
				printf("%s\n",filename);
				insert_dlinklist(&head,filename);
				filename[strlen(filename)-strlen(dirp->d_name)-1]='\0';
			}	
		}

		q->next=(&head)->next;
		(&head)->next->prev=q;
		
		len=legnth_dlinklist(&head);
		int pos=1;
		DLIST *r=(&head)->next;
		while(strcmp(r->path,str)!=0)
		{
			r=r->next;
			pos++;
		}
		p=r;
		i=pos;
        lb_num->setText(QString::number(i));
        lb_sum->setText(QString::number(len));
        pb_prev->setDisabled(false);
        pb_next->setDisabled(false);
	}
}

void Qt1::strip(char *s)
{
	char *p=s;
	int n=0;
	while(*p)
	{
		if(*p=='/')
		{
			n++;
		}
		p++;
	}
	if(n==1)
	{
		s[1]='\0';
	}
	else
	{
		p--;
		while(*p)
		{
			if(*p=='/')
			{
				*p='\0';
				break;
			}
			p--;
		}
	}
}

int Qt1::judge(char * s)	
{
	int i,len=strlen(s);
	char *p=s;
	if(len<5)
	{
		return 0;
	}
	else 
	{
		while(*p)
		{
			p++;
		}
		for(i=0;i<4;i++)p--;
		if((strncmp(p,".jpg",4)==0)||(strncmp(p,".png",4)==0)||(strncmp(p,".xpm",4)==0))
		{
			return 1;
		}
		else 
			return 0;
	}
}

void insert_dlinklist(DLIST *d,char *s)	{
	DLIST *r=d;
	q=(DLIST*)malloc(sizeof(DLIST));	
	memset(q,0,sizeof(q));
	strcpy(q->path,s);

	if(r->next==NULL)
	{
		r->next=q;
		q->next=NULL;
	}
	else
	{
		while(r->next!=NULL)
		{
			r=r->next;
		}
		r->next=q;
		q->prev=r;
		q->next=NULL;
	}
	printf("insert success\n");
}
void Qt1::update_show_Resistor(){
	resistor.update();
	cout<<"阻值信息:"<<resistor.getAlert()<<"   "<<resistor.getResistance()<<endl;
    QString r = QString::number(resistor.getResistance());
    lb_resistor->setText(r);
    lb_warning->setText(resistor.getAlert());

    int resistance=resistor.getResistance();
    cout<<"send的阻值："<<resistance<<endl;
    //sendR(cfd,resistance);



    if(resistance > 1000 && resistance < 9000){
        warnButton2->setStyleSheet("background-color: Green; color: white;");
    }
    else{
        warnButton2->setStyleSheet("background-color: Red; color: white;");
    }

}
void Qt1::sendsignal(){
	int resistance=resistor.getResistance();
	emit(r_updated(resistance));
}


void Qt1::display_pic()
{
	QString buf(p->path);
	QPixmap p(buf);
	lb_pic->setPixmap(p);
	lb_pic->setScaledContents(1);
    lb_num->setText(QString::number(i));
    lb_sum->setText(QString::number(len));

}
void Qt1::sendmsg(){

    sendR(cfd,resistor.getResistance());
    //sendPhoto2(cfdp,filename);

}


Qt1::~Qt1()
{
    delete[] frameBufRGB;
    delete[] frameBufYUV;
    delete m_image;
}
