#include "client.h"

int TCPconnect(int port,char* ip){
    int cfd;
    int recbyte;
    int sin_size;
    char buffer[1024]={0};
    char war[12];

    struct sockaddr_in s_add, c_add;
    unsigned short portnum = port;

    //创建socket网络套接字cfd
    cfd = socket(AF_INET, SOCK_STREAM, 0); //***1表示非阻塞，0表示阻塞
	if(-1 == cfd)
	{
		printf("socket fail ! \r\n");
		return -1;
	}
    printf("socket ok !\r\n");

    bzero(&s_add,sizeof(struct sockaddr_in));
	s_add.sin_family=AF_INET;
	s_add.sin_addr.s_addr= inet_addr(ip);
	s_add.sin_port=htons(portnum);

    if(-1 == connect(cfd,(struct sockaddr *)(&s_add), sizeof(struct sockaddr)))
	{
			printf("connect fail !\r\n");
			return -1;
	}
	printf("t1:connect ok !\r\n");
    return cfd;

}


int TCPlogin(int sock,char* usr,char* pwd){
    

}



//发送电阻阻值
int sendR(int sock,int r){
    printf("%d\n",cfd);
    char info[22]; 
    char info2[22] = {}; 
    int resistance =r;
    snprintf(info, sizeof(info), "%d", resistance);
    int wrcbyte;
    if(-1==(wrcbyte = send(cfd,info,strlen(info),0)))
    {
        printf("send fail.\r\n");
        return -1;
    }
    printf("send success");
    read(sock, info2, 20);
    printf("Message from server: %s \n", buff);
    return -1;
} 

int Disconnect(int sock){
    close(sock);
}


int sendPhoto(int sock,char* filename){
    printf(filename);
    struct sockaddr_in serv_addr;
    int fp;
    char buf[1024];
    char buff[25] = {};
    int read_cnt;
    printf("111\n");
    fp = fopen(filename, "rb");
    if(fp == NULL)
        printf("File open error");

    printf("suc:");

    while(1)
    {
        read_cnt = fread((void*)buf, 1, 1024, fp);
        if(read_cnt < 1024)
        {
            write(sock, buf, read_cnt);
            break;
        }
        write(sock, buf, 1024);
    }
    shutdown(sock,SHUT_WR);
    printf("send success");
    read(sock, buff, 24);
    printf("Message from server: %s \n", buff);
    fclose(fp);
    return -1;
}


int sendPhoto2(int sock,char* IOphoto,int k){
    int cfd=sock;
    char file_info[2048] = {0};//文件信息
    char file_name[128] = {0}; //文件名
    char *p; 				   //"/"+文件名
    char buf[1024] = {0};
    char bbuf[1024] = {};
    strcpy(file_name, IOphoto);	//获取文件名
    sprintf(file_name, "mnt/usb/a%d.jpg", k);
    int recbyte;                        //当前read接收的字节数
    char buffer[1024] = {0};            //接收缓存
    memset(buffer, 0, sizeof (buffer));           //清空接收缓存

    //打开文件
    int fd_p = open(IOphoto, O_RDWR);
        if (fd_p == -1)
        {
            printf("open [%s]  failed!\n", IOphoto);
            return -1;
        }
    printf("open file success：%s\n",file_name);
    int file_len = lseek(fd_p, 0, SEEK_END);	//lseek(fd_p, 0, SEEK_END)作用:光标移到文件尾，返回字节数
    printf("f_len:%d\t",file_len);
    lseek(fd_p, 0, SEEK_SET);	    	     //文件光标偏移回文件开始位置

    //发送图片
    int send_len = 0;//记录发送了多少字节
    while (1)
        {
            bzero(buf, sizeof(buf));				//buf缓存清零
            recbyte = read(fd_p, buf, sizeof(buf));	//读取数据
            if (recbyte <= 1)
            {
                write(cfd, bbuf,1024);
                break;
            }
            write(cfd, buf, recbyte);		//发送数据
            send_len += recbyte;            //统计发送了多少字节
            if(send_len=file_len){
                break;
                }
        }
    shutdown(sock,SHUT_WR);
    //发送图片发送完毕结束信号
    close(fd_p);
    close(cfd);

}

int sendPhoto3(int sock, char* IOphoto) {
        int cfd=sock;
        char file_info[2048] = {0};//文件信息
        char file_name[128] = {0}; //文件名
        char *p;                    //"/"+文件名
        char buf[1024] = {0};
        char bbuf[1024] = {};
        char info[22];
        strcpy(file_name, IOphoto);    //获取文件名
        //sprintf(file_name, "mnt/usb/a%d.jpg", k);
        int recbyte;                        //当前read接收的字节数
        char buffer[1024] = {0};            //接收缓存
        memset(buffer, 0, sizeof (buffer));           //清空接收缓存

        //打开文件
        int fd_p = open(IOphoto, O_RDWR);
            if (fd_p == -1)
            {
                printf("open [%s]  failed!\n", IOphoto);
                return -1;
            }
        printf("open file success：%s\n",file_name);
        int file_len = lseek(fd_p, 0, SEEK_END);    //lseek(fd_p, 0, SEEK_END)作用:光标移到文件尾，返回字节数
        printf("f_len:%d\t",file_len);
        lseek(fd_p, 0, SEEK_SET);                 //文件光标偏移回文件开始位置
        snprintf(info, sizeof(info), "%d", file_len);
          printf("%s",info);
        int wrcbyte;
        if(-1==(wrcbyte = send(cfd,info,strlen(info),0)))
        {
        printf("send fail.\r\n");
        return -1;
        }

        bzero(info, sizeof(info));
        read(sock, info, 21);
        printf("Message from server: %s \n", info);
        //发送图片
           int ret;
        while ((ret = read(fd_p, buf, 1024)) > 0) {
            if (write(cfd, buf, ret) != ret) {
                printf("Error writing to socket");
                close(fd_p);
                return -1;
            }
        }
        if (ret == -1) {
            printf("Error reading file");
            close(fd_p);
            return -1;
        }

        close(fd_p);
        return 0;

}


int sendHeartBeat(int sock){
        int cfd=sock;
        char buffer[1024] = {0};            //接收缓存
        memset(buffer, 0, sizeof (buffer));           //清空接收缓存
        int recbyte;                        //当前read接收的字节数
    	int i;
    	printf("循环开始\r\n");
    	for(i = 0; i < 3; i++){    //同一数据最多只发送3次，否则视为网络连接有问题
    		//1 发送心跳包
            if(-1 == (send(cfd, "1\r\n", strlen("1\r\n"), 0)))
    		{
    			printf("Hearbeat: send data fail !\r\n");
    			return -1;
    		}
    		printf("Hearbeat: send data not fail !\r\n");
    		//2 接收上位机回复（反映上位机是否接收成功）
            if(-1 == (recbyte = read(cfd, buffer, sizeof (buffer))))  //接收服务器反馈
    		{
    			printf("Hearbeat: read data fail !\r\n");
    			return -1;
    		}
    //		printf("read ok\r\nREC:\r\n");
    		buffer[recbyte]='\0';   //接收的最后一位加上\0变为字符串
    		printf("Hearbeat: %s\r\n",buffer);

    		//3 通过上位机回复决定是否重传
    		if(strcmp(buffer,"1\r\n") == 0){      //若上位机接收成功，则跳出循环
                memset(buffer, 0, sizeof (buffer));           //清空接收缓存
    			break;                            //跳出循环
    		}
    		else{                                 //若上位机接收失败，则继续循环，重传
    			printf("Hearbeat: Send data failed！ Retransmit!\r\n");
                memset(buffer, 0, sizeof (buffer));           //清空接收缓存
    		}
    	}

    	//4 若发送了3次均失败，则判断网络连接有问题
    	if(i == 3) {
            printf("Hearbeat: Send data 3 times failed! Examinate the connection!\r\n");
            return -1;
        }
        else{
            //return 0;
        }
}

















