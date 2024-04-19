#ifndef COMMUNICATION_H
#define COMMUNICATION_H

//标准输入输出函数头文件
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
//字符串操作函数头文件
#include <string.h>
#include <unistd.h>
//文件操作函数头文件
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <termios.h>
#include <errno.h>
#include <math.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/time.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h>   //用于捕捉ctl+c信号的头文件


int TCPconnect(int,char*);             //**建立TCP连接的全套过程函数(函数全部执行成功时返回0,否则返回-1)
int TCPlogin(int,char*,char*);              //**客户端登录的函数
int sendR(int,int);                         //**发送当前采集的ADC阻值
int sendPhoto(int,char*);
int sendHeartbeat();















#endif