#include "historyr.h"
#include "ui_historyr.h"
#include <QDebug>
#include <iostream>
#include <QPaintEvent>
#include <QPainter>
#include <QPen>
#include <QRect>
#include <QPoint>
#include <algorithm> // 用于使用 std::min_element 和 std::max_element
#include<cstdlib>
#include<ctime>

using namespace std;

historyr::historyr(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::historyr)
{
    ui->setupUi(this);
    
    this->setMinimumSize(480,235);
    this->setMaximumSize(480,235);
    this->temp=0;
    int width=400;
    int hight=230;
    image = QImage(width,hight,QImage::Format_RGB32);  //画布的初始化大小设为400*220，使用32位颜色
    image.fill(qRgb(255,255,255));//对画布进行填充


    
    connect(ui->BackButton,SIGNAL(clicked()),this,SLOT(fun_close()));//只是隐藏窗口
    t1.start(1000);
    


}
void historyr::fun_close(){
    this->hide();
}
void historyr::fun_update_draw(int r){
    image.fill(qRgb(255,255,255));
    //cout<<"传入的阻值是："<<r<<endl;
    int n=20;//n为数据个数
    if(rlist.size()<n)
    {
        //cout<<"阻值列表小于20"<<endl;
        rlist.append(r);
        //cout<<"末尾加入阻值"<<endl;
        
    }
    else{
        //cout<<"阻值列表大于20"<<endl;
        rlist.removeFirst();
        rlist.append(r);
        //cout<<"现移除，再加入阻值"<<endl;
    }
    //cout<<"列表的size"<<rlist.size()<<endl;
    QPainter painter(&image);
    painter.setRenderHint(QPainter::Antialiasing, true);//设置反锯齿模式，好看一点
    int width1=400;
    int height1=230;
    int pointx=40,pointy=210;//确定坐标轴起点坐标，这里定义(35,200)



    int width=width1-pointx-5,height=190;//确定坐标轴宽度跟高度 上文定义画布为600X300，宽高依此而定。
    //绘制坐标轴 坐标轴原点(35，200)
    painter.drawRect(5,5,width1-5,height1-5);//外围的矩形，从(5,5)起，到(宽高各减10)结束，周围留了5的间隙。

    painter.drawLine(pointx,pointy,width+pointx,pointy);//坐标轴x宽度为width
    painter.drawLine(pointx,pointy-height,pointx,pointy);//坐标轴y高度为height



    int _ma=10000;//数组里的最大值

    int a[n];//数据储存在数组a中，大小为n
    for(int i=0;i<n;i++){
        if(i<rlist.size())
            a[n-1-i]=rlist.at(i);
        else
            a[n-1-i]=0;
        //cout<<a[i]<<endl;
    }

    double kx=(double)(width)/n; //x轴的系数
    double ky=(double)height/_ma;//y方向的比例系数
    QPen pen,penPoint;
    pen.setColor(Qt::black);
    pen.setWidth(2);
    penPoint.setColor(Qt::blue);
    penPoint.setWidth(5);
    for(int i=0;i<n-1;i++)
    {
        //由于y轴是倒着的，所以y轴坐标要pointy-a[i]*ky 其中ky为比例系数
        painter.setPen(pen);//黑色笔用于连线
        painter.drawLine(pointx+kx*i,pointy-a[i]*ky,pointx+kx*(i+1),pointy-a[i+1]*ky);
        painter.setPen(penPoint);//蓝色的笔，用于标记各个点
        painter.drawPoint(pointx+kx*(i),pointy-a[i]*ky);
    }
    painter.drawPoint(pointx+kx*(n-1),pointy-a[n-1]*ky);//绘制最后一个点


    //绘制上限和下限
    QPen penlimit;
    penlimit.setColor(Qt::red);//选择红色
    penlimit.setWidth(2);
    penlimit.setStyle(Qt::DotLine);//线条类型为虚线
    painter.setPen(penlimit);
    painter.drawLine(pointx,pointy-height/10,pointx+width,pointy-height/10);
    painter.drawLine(pointx,pointy-9*height/10,pointx+width,pointy-9*height/10);


    //绘制刻度线
    QPen penDegree;
    penDegree.setColor(Qt::black);
    penDegree.setWidth(2);
    painter.setPen(penDegree);
    //画上x轴刻度线
    for(int i=0;i<10;i++)//分成10份，每隔2绘制一个刻度
    {
        //选取合适的坐标，绘制一段长度为4的直线，用于表示刻度
        painter.drawLine(pointx+(i+1)*width/10,pointy,pointx+(i+1)*width/10,pointy+4);
        painter.drawText(pointx+(i)*width/10,
                         pointy+15,QString::number((int)((i)*((double)n/10))+1));
    }
    //y轴刻度线
    double _maStep=(double)_ma/10;//y轴刻度间隔需根据阻值区间来表示
    for(int i=0;i<10;i++)
    {
        painter.drawLine(pointx,pointy-(i+1)*height/10,
                         pointx-4,pointy-(i+1)*height/10);
        painter.drawText(pointx-30,pointy-(i+0.85)*height/10,
                         QString::number((int)(_maStep*(i+1))));
    }
    update();//实时更新绘图

    
}


historyr::~historyr()
{
    cout<<"hr deleted"<<endl;
    delete ui;
}
