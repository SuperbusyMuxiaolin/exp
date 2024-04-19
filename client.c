#include "client.h"

int TCPconnect(int port,char* ip){
    int cfd;
    int recbyte;
    int sin_size;
    char buffer[1024] = {0};
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
    char info[22]; 
    resistance =r;
    sprintf(info, sizeof(info), "%d", resistance);
    cout<<info<<endl;
    int wrcbyte;
    if(-1==(wrcbyte = send(cfd,info,strlen(info),0)))
    {
	    printf("send fail.\r\n");
	    return -1;
    }
    return -1;
} 

int Disconnect(int sock){
    close(sock);
}
