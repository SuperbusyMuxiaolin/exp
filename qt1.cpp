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
//#include <QImage>
#include "qt1.h"

#include "dlinklist.c"	
using namespace std;

static int i=0;
int update_t_set=500;
int camera=0;
int W=0;
int FLAG=1;
DLIST *p;
DLIST *q;
DLIST head;


QTimer* refreshTimer; 
bool isTakingPhoto; 


void insert_dlinklist(DLIST *d,char *s);

Qt1::Qt1(QWidget *parent):QDialog(parent)
{
  	setupUi(this);
    isCapOpen = false;
    isToSave = false;
    m_image = NULL;
    OpenButton->setDisabled(false);

    //报警信息按钮不可按
    warnButton1->setDisabled(true);
    warnButton2->setDisabled(true);


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

    connect(OpenButton,SIGNAL(clicked()),this,SLOT(fun_cap_open()));
	connect(pic_listButton,SIGNAL(clicked()),this,SLOT(fun_open())); 	
  	connect(&t1,SIGNAL(timeout()),this,SLOT(fun_time()));//时间显示
	t1.start(1000);//时间显示每一秒触发一次，即以秒进行时间显示更新

  	connect(&update_t,SIGNAL(timeout()),this,SLOT(fun_take_photo()));
	connect(&update_t,SIGNAL(timeout()),this,SLOT(updateResistor()));//调用adc更新阻值信息
	connect(&update_t,SIGNAL(timeout()),this,SLOT(fun_showResistor()));//窗口更新阻值及报警信息
	init_dlinklist(&head);
        width = 480;
        height = 272;
        myCamera = new Camera("/dev/video0", width, height, 0);
        frameBufRGB = new unsigned char[width * height * 3];
        frameBufYUV = new unsigned char[width * height * 2];
}
void Qt1::fun_open_resistor(){
    hr.setWindowTitle("Resistance Value History Record");
    hr.show();
}

void Qt1::fun_change_t(){
    update_t_set=1000*tSpinBox->value();
}

void Qt1::fun_refresh_pic()
{
    printf("refresh!!!!!!!!!!\n");
	if (isTakingPhoto)
    {
        refreshTimer->stop();
    }
   if(!myCamera->GetBuffer(frameBufYUV))
   {
       std::cout<< "Get Camera Buf error!\n";
       return;
   }
   myCamera->process_image(frameBufYUV, frameBufRGB);
   showCapPhoto();
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
    }
    else
    {
        camera = 1;
        OpenButton->setText("Close");
        myCamera->OpenDevice();
        printf("111111111111111111\n");
        refreshTimer->start(1000);  
        isTakingPhoto = false;
		update_t.start(update_t_set);//相机处于打开状态，数据更新及获取开始，按update_t_set为间隔获取
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
    char filename[20];
    if (m_image != NULL)
    {
        sprintf(filename, "mnt/usb/a%d.jpg", W++);
        printf("%s\n", filename);
        m_image->save(filename, "jpg", -1);
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

//显示阻值和报警信息
void Qt1::fun_showResistor(){
	QString r = QString::number(resistor.getResistance());
	lb_resistor->setText(r);
	lb_warning->setText(resistor.getAlert());

    if(1000<resistor.getResistance()<9000){
        warnButton2->setStyleSheet("background-color: Green; color: white;");
    }
    else{
        warnButton2->setStyleSheet("background-color: Red; color: white;");
    }

}

void Qt1::fun_open()//注意文件位置
{
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
void Qt1::updateResistor(){
	resistor.update();
	cout<<"阻值信息"<<resistor.getAlert()<<resistor.getResistance()<<endl;
}


Qt1::~Qt1()
{
    delete[] frameBufRGB;
    delete[] frameBufYUV;
    delete m_image;
}
