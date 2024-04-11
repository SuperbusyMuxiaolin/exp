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
static int update_t_set=1000;
int camera=0;
int W=0;
int FLAG=1;
//DLIST* Qt1:: p=NULL;
DLIST *p;
DLIST *q;
DLIST head;


QTimer* refreshTimer;  // ��ʱ�����ڶ�ʱˢ��ͼƬ
bool isTakingPhoto;  // ��־������ʾ�Ƿ����ڽ������ղ���


void insert_dlinklist(DLIST *d,char *s);
//=====just for you to learn how to use comboBox=======
void Qt1::InitBox()
{
    comboBox->clear();
    QStringList strList;
    strList<<"aaa"<<"bbb"<<"ccc";
    comboBox->addItems(strList);
}

void Qt1::fun_refresh_label()
{
	lb_sum->setText(comboBox->currentText());
}
//=====just for you to learn how to use comboBox=======

Qt1::Qt1(QWidget *parent):QDialog(parent)
{
  	setupUi(this);
//  rb_manual->setChecked(true);
        isCapOpen = false;
        isToSave = false;
        m_image = NULL;
	rb_manual->setDisabled(true);
	rb_auto->setDisabled(true);
	pb_prev->setDisabled(true);
	pb_next->setDisabled(true);
    pb_del->setDisabled(true);
    OpenButton->setDisabled(false);
    TakeButton->setDisabled(false);
	//timer = new QTimer(this);


	refreshTimer = new QTimer(this);
    connect(refreshTimer, SIGNAL(timeout()), this, SLOT(fun_refresh_pic()));
    isTakingPhoto = false;




//=====just for you to learn how to use comboBox=======
	InitBox();
	connect(&t3,SIGNAL(timeout()),this,SLOT(fun_refresh_label())); 
	t3.start(10);
//=====just for you to learn how to use comboBox=======
	
	//connect(timer, SIGNAL(timeout()), this, SLOT(fun_refresh_pic()));
    connect(OpenButton,SIGNAL(clicked()),this,SLOT(fun_cap_open()));
    connect(TakeButton,SIGNAL(clicked()),this,SLOT(fun_take_photo()));
	connect(rb_auto,SIGNAL(clicked()),this,SLOT(fun_cntl())); 
	connect(rb_manual,SIGNAL(clicked()),this,SLOT(fun_cntl())); 
	connect(pb_prev,SIGNAL(clicked()),this,SLOT(fun_prev())); 
	connect(pb_next,SIGNAL(clicked()),this,SLOT(fun_pic())); 
	connect(pb_del,SIGNAL(clicked()),this,SLOT(fun_delete())); 	
	connect(pb_open,SIGNAL(clicked()),this,SLOT(fun_open())); 	
  	connect(&t1,SIGNAL(timeout()),this,SLOT(fun_time()));
 	connect(&t2,SIGNAL(timeout()),this,SLOT(fun_pic())); 
  	t1.start(1000);						//
	connect(&update_t,SIGNAL(timeout()),this,SLOT(updateResistor()));
	update_t.start(update_t_set);
	init_dlinklist(&head);
        width = 480;
        height = 272;
        myCamera = new Camera("/dev/video0", width, height, 0);
        frameBufRGB = new unsigned char[width * height * 3];
        frameBufYUV = new unsigned char[width * height * 2];
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
   //TODO:process_image() function is now empty.
   myCamera->process_image(frameBufYUV, frameBufRGB);
   showCapPhoto();


}


void Qt1::fun_cap_open()
{
    if (camera == 1)
    {
        camera = 0;
        OpenButton->setText("Open");
        TakeButton->setDisabled(true);
        myCamera->CloseDevice();
        printf("00000000000000\n");

        // ֹͣ��ʱ��
        refreshTimer->stop();
    }
    else
    {
        camera = 1;
        OpenButton->setText("Close");
        TakeButton->setDisabled(false);
        label->setText("photo");
        myCamera->OpenDevice();
        printf("111111111111111111\n");

        // ������ʱ����ÿ��һ��ʱ��ˢ��ͼƬ
        refreshTimer->start(1000);  // ÿ��1��ˢ��һ��

        // ���±�־����
        isTakingPhoto = false;
    }
}




// void Qt1::fun_cap_open()
// {
//     //TODO: Use myCamera->OpenDevice() to open camera, and myCamera->CloseDevice() to close it.
//     //You should think of it in two cases: camera closed and camera opened.
//     //When you open camera, how to refresh image? Tips:use timer to trigge it.
//     if(camera==1)
//     {
//         camera=0;
//         OpenButton->setText("Open");
//         TakeButton->setDisabled(true);
//         myCamera->CloseDevice();
// 		printf("00000000000000\n");
//     }
//     else
//     {
//         camera=1;
// 		FLAG=1;
//         OpenButton->setText("Close");
//         TakeButton->setDisabled(false);
//         label->setText("photo");
//         myCamera->OpenDevice();
		
// 		while(FLAG!=0)
// 		{
// 			fun_refresh_pic();
// 			printf("111111111111111111\n");
// 		}

//     }

// }

void Qt1::fun_clean_pixmap()
{
    QPixmap p;
    lb_pic->setPixmap(p);
}



void Qt1::fun_take_photo()
{
    // TODO: ���˰�ť�����ʱ�����ղ�����ͼƬ��
    camera = 0;
    char filename[20];
    if (m_image != NULL)
    {
        sprintf(filename, "mnt/usb/a%d.jpg", W++);
        printf("%s\n", filename);
        m_image->save(filename, "jpg", -1);
    }
    camera = 1;

    // ���±�־����
    isTakingPhoto = true;
}




// void Qt1::fun_take_photo()
// {
//     //TODO: When this button is clicked, we take a photo and save it.
//     camera=0;
// 	FLAG=0;
// 	//fun_refresh_pic();
//     char filename[20];
//     if(m_image!=NULL){
//         sprintf(filename,"mnt/usb/a%d.jpg",W++);
//         printf("%s\n",filename);
//         m_image->save(filename,"jpg",-1);
//     }
//     camera=1;

// }


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
    QDateTime d=QDateTime::currentDateTime();	//��ȡ��ǰʱ��,currentDateTime()��һ����̬����
    lb_time->setText(d.toString("yyyy-MM-dd-ddd hh:mm:ss"));	
}

void Qt1::fun_cntl()
{
	if(rb_manual->isChecked ())
	{
		t2.stop();
		pb_prev->setEnabled(true);	
		pb_next->setEnabled(true);	
	}
	else if(rb_auto->isChecked ())
	{
		t2.start(100);
		pb_prev->setEnabled(false);	
		pb_next->setEnabled(false);	
	}
}

void Qt1::fun_pic()		
{
	i++;
	if(i==(len+1))i=1;

	p=p->next;
	display_pic();
}


void Qt1::fun_prev()	//fun_next()��fun_pic()һ��
{
	i--;
	if(i==0)i=len;

	p=p->prev;
	display_pic();
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


void Qt1::fun_delete()
{
	int ret;
        ret=QMessageBox::warning(this, tr("m_image browser"),
					   tr("Are you sure to delete it?"),
					   QMessageBox::Yes | QMessageBox::No,
					   QMessageBox::No);
	if(ret==QMessageBox::Yes)
	{
		remove(p->path);
		DLIST *r=(&head)->next;
		int n=1;
		while(r!=p)		//�ҵ���ǰ p��λ��
		{
			n++;
			r=r->next;
		}
		p=p->next;
		del_dlinklist(&head,n);
		if(i==len)i--;
		len=legnth_dlinklist(&head);
		display_pic();
	}
//	dlinkilist_tofile(&head);
}

void Qt1::fun_open()//注意文件位置
{
	QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                 "/mnt/usb",
                                                 tr("Images (*.png *.xpm *.jpg)"));
	printf("open folder!\n");
	if(fileName!=NULL)
	{
		init_dlinklist(&head);	//Ϊ����һ��Ŀ¼��׼��
		char *str;
		char filename[100]={0};
		DIR *dp;					//ָ��Ŀ¼
		struct dirent *dirp;		//ָ��Ŀ¼��(��������Ŀ¼����ͨ�ļ�)
		
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
				strcat(filename,dirp->d_name);	//�ļ����ڵ�Ŀ¼+�ļ���=����·��
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
		
		rb_manual->setDisabled(false);
		rb_auto->setDisabled(false);
		pb_prev->setDisabled(false);
		pb_next->setDisabled(false);
		pb_del->setDisabled(false);
		rb_manual->setChecked(true);
//		display_pic();
	}
//	dlinkilist_tofile(&head);
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

void insert_dlinklist(DLIST *d,char *s)	//������ĩβ����,֮���԰���������ᵽ�������Ϊ����ʹ��ȫ�ֱ���DLIST *q
{
	DLIST *r=d;
	//	DLIST *q;
	q=(DLIST*)malloc(sizeof(DLIST));	//�����q�����Ǿֲ��ģ������޷��γ�˫��ѭ������
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
	cout<<"组织信息"<<resistor.getAlert()<<resistor.getResistance()<<endl;
}


Qt1::~Qt1()
{
    delete[] frameBufRGB;
    delete[] frameBufYUV;
    delete m_image;
}
