#include <unistd.h> 
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>
#include <string.h>

#define SRVPORT 10005
#define CONNECT_NUM 5
#define MAX_NUM 80
#include<iostream>

using namespace std ;

string operateStrings[] = 
{
//管道土壤腐蚀性 4.4 上报管道电位数据帧  0x43
"21233c3c3c3c31313137303230303030303333333143000E110A14123B080123012301233e3e",
//管道土壤腐蚀性 4.7 上报地理位置帧解析  0x37
"21233c3c3c3c31313137303230303030303333333137000EA,3957.85008,N,11620.11820,E110x3e0x3e",
//杂散电流  4.4 上报管地电流数据帧  0x53  
"21233c3c3c3c31313137303230303030303333333153000E110A14123B080123012301233e3e"
};


int main()
{
    int clientSock=-1;
    struct sockaddr_in serverAddr;

    clientSock=socket(AF_INET,SOCK_STREAM,0);
    if(clientSock<0)
    {
        printf("socket creation failed\n");
        exit(-1);
    }
    printf("socket create successfully.\n");

    memset(&serverAddr,0,sizeof(serverAddr));
    serverAddr.sin_family=AF_INET;
    serverAddr.sin_port=htons((u_short) SRVPORT);
    serverAddr.sin_addr.s_addr=htons(INADDR_ANY);

    if(connect(clientSock,(struct sockaddr*)&serverAddr,sizeof(struct sockaddr_in))<0)
    {
        printf("Connect error.\n");
        exit(-1);
    }
    printf("Connect successful.\n");

    string sendString = "CDCD";
    char revBuf[MAX_NUM]={0};
     for(int i=0;i<3;i++)
    //while(sendString!= "")
    {
        sleep(1);
        //发送
        sendString  = operateStrings[i];
        if(write(clientSock,sendString.c_str(),strlen(sendString.c_str()))==-1)
        {
            printf("send error!\n");
        }
        cout<<"客户端发送了--"<<sendString<<endl;

        //接收
        if(read(clientSock,revBuf,sizeof(revBuf))==-1)//MAX_NUM
        {
            printf("rev error!\n");
        }
        string receive = revBuf;
        cout<<"收到服务器的信息 "<<receive<<endl;
        bzero(revBuf,sizeof(revBuf));
        
    }
        sleep(1);
       sendString = "quit";
       if(write(clientSock,sendString.c_str(),strlen(sendString.c_str()))==-1)
        {
            printf("send error!\n");
        }
    close(clientSock);
    return 0;
}
