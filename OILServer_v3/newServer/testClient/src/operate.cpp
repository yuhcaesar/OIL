#include <unistd.h> 
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>
#include <string.h>
#include <time.h>
#include <iostream>
#include <sstream>
#include <math.h>
#include <resolv.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#define SRVPORT 10005
#define CONNECT_NUM 5
#define MAX_NUM 80
#define SERVER_ADDR "39.105.154.26"

#define sss "%04x"
using namespace std;

string operateStrings[] = 
{
//管道土壤腐蚀性 4.4 上报管道电位数据帧  0x43
//"21233c3c3c3c31313137303230303030303333333143000E110A14123B080123012301233e3e",
//管道土壤腐蚀性 4.7 上报地理位置帧解析  0x37
//"21233c3c3c3c31313137303230303030303333333137000EA,3957.85008,N,11620.11820,E110x3e0x3e",
//杂散电流  4.4 上报管地电流数据帧  0x53  
//"21233c3c3c3c31313137303230303030303333333153000E110A14123B080123012301233e3e"
    "21233C3C21233C3C3131313D2A3A51FA33C1D200003A51FA33C1D200003C17E133C397D7CF3C17E133C397D7CF3AF27BB3C272F2B03AF27BB3C272F2B03E3E"
//"1","2","3","4","5","6","7","8","9","10","11","12"
};
unsigned char OnData[] = {0x21, 0x23, 0x3C, 0x3C, 0x3C, 0x3C, 0x31, 0x31, 0x31, 0x37, 0x30, 0x32, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x31, 0x31, 0x43, 0xAA, 0x00, 0x75, 0x02, 0x07, 0x2A, 0x98, 0xAD, 0x88, 0xAC, 0x4C, 0x9F, 0x80, 0x8F, 0x98, 0xAD, 0x88, 0xAD, 0x4C, 0x9F, 0x80, 0x8C, 0x98, 0xAD, 0x88, 0xAF, 0x4C, 0x9E, 0x80, 0x8E, 0x98, 0xAC, 0x88, 0xAB, 0x4C, 0x9F, 0x80, 0x8D, 0x98, 0xAC, 0x88, 0xAE, 0x4C, 0x9F, 0x80, 0x8F, 0x98, 0xAC, 0x88, 0xAD, 0x4C, 0x9E, 0x80, 0x8C, 0x98, 0xAB, 0x88, 0xAC, 0x4C, 0x9D, 0x80, 0x90, 0x98, 0xAB, 0x88, 0xAC, 0x4C, 0x9F, 0x80, 0x8B, 0x98, 0xAA, 0x88, 0xAA, 0x4C, 0x9F, 0x80, 0x8B, 0x98, 0xAB, 0x88, 0xAD, 0x4C, 0x9E, 0x80, 0x8C, 0x98, 0xAB, 0x88, 0xAE, 0x4C, 0x9D, 0x80, 0x8F, 0x98, 0xAA, 0x88, 0xAE, 0x4C, 0x9E, 0x80, 0x89, 0x98, 0xAA, 0x88, 0xAC, 0x4C, 0x9E, 0x80, 0x8C, 0x98, 0xAB, 0x88, 0xAB, 0x4C, 0x9F, 0x80, 0x8C, 0x3E, 0x3E
};
unsigned char hexchar[] = { 0x21,0x23,0x3C,0x3C,0x3C,0x3C,0x31,0x31,0x31,0x37,0x30,0x32,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x31,0x31,0x3D,0x00,0x30,0xA4,0x70,0x45,0x41,0x00,0x00,0xD2,0xC1,0x33,0xFA,0x51,0x3A,0x00,0x00,0xD2,0xC1,0x33,0xE1,0x17,0x3C,0xCF,0xD7,0x97,0xC3,0x33,0xE1,0x17,0x3C,0xCF,0xD7,0x97,0xC3,0xB3,0x7B,0xF2,0x3A,0xB0,0xF2,0x72,0xC2,0xB3,0x7B,0xF2,0x3A,0xB0,0xF2,0x72,0xC2,0x3E,0x3E };
unsigned char paramData[] = {0x21, 0x23, 0x3C, 0x3C, 0x3C, 0x3C, 0x31, 0x31, 0x31, 0x37, 0x30, 0x32, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x31, 0x31, 0x3D, 0x00, 0x32, 0x4E, 0xDF, 0x3E, 0x3A, 0x4E, 0xDF, 0xBE, 0xC1, 0x92, 0x98, 0x45, 0x3A, 0x92, 0x98, 0xC5, 0xC1, 0x33, 0xE1, 0x17, 0x3C, 0xCF, 0xD7, 0x97, 0xC3, 0x33, 0xE1, 0x17, 0x3C, 0xCF, 0xD7, 0x97, 0xC3, 0xB3, 0x7B, 0xF2, 0x3A, 0xB0, 0xF2, 0x72, 0xC2, 0xB3, 0x7B, 0xF2, 0x3A, 0xB0, 0xF2, 0x72, 0xC2, 0x3E, 0x3E};
unsigned char offData[] = {0x21, 0x23, 0x3C, 0x3C, 0x3C, 0x3C, 0x31, 0x31, 0x31, 0x37, 0x30, 0x32, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x31, 0x31, 0x44, 0xAA, 0x00, 0x21, 0x02, 0x0C, 0x0C, 0x98, 0xA5, 0x98, 0xA5, 0x98, 0xA5, 0x98, 0xA5, 0x98, 0xA5, 0x98, 0xA4, 0x98, 0xA6, 0x98, 0xA6, 0x98, 0xA6, 0x98, 0xA6, 0x98, 0xA5, 0x98, 0xA5, 0x98, 0xA4, 0x98, 0xA5, 0x3E, 0x3E};
unsigned char onData2[] = {
    0x21, 0x23, 0x3C, 0x3C, 0x3C, 0x3C, 0x31, 0x31, 0x58, 0x75, 0x26, 0x43, 0x6F, 0x6E, 0x67, 0x26, 0x4D, 0x6F, 0x2D, 0x31, 0x31, 0x43, 0xAA, 0x01, 0xE5, 0x01, 0x2D, 0x2D, 0x80, 0x00, 0x80, 0xCD, 0x7F, 0xF4, 0x99, 0x2A, 0x80, 0x01, 0x80, 0xCE, 0x7F, 0xF4, 0x99, 0x32, 0x80, 0x00, 0x80, 0xD8, 0x7F, 0xF3, 0x99, 0x1B, 0x80, 0x00, 0x80, 0xD8, 0x7F, 0xF3, 0x99, 0x30, 0x80, 0x00, 0x80, 0xD8, 0x7F, 0xF3, 0x99, 0x2F, 0x80, 0x01, 0x80, 0xD7, 0x7F, 0xF2, 0x99, 0x25, 0x80, 0x00, 0x80, 0xD8, 0x7F, 0xF2, 0x99, 0x30, 0x80, 0x00, 0x80, 0xD1, 0x7F, 0xF4, 0x99, 0x2F, 0x80, 0x00, 0x80, 0xD0, 0x7F, 0xF2, 0x99, 0x2D, 0x80, 0x00, 0x80, 0xC8, 0x7F, 0xF3, 0x98, 0xF6, 0x80, 0x01, 0x80, 0xD6, 0x7F, 0xF4, 0x99, 0x11, 0x80, 0x00, 0x80, 0xD1, 0x7F, 0xF3, 0x99, 0x15, 0x80, 0x00, 0x80, 0xD5, 0x7F, 0xF3, 0x99, 0x23, 0x80, 0x01, 0x80, 0xD4, 0x7F, 0xF3, 0x99, 0x12, 0x80, 0x07, 0x80, 0xDD, 0x7F, 0xF3, 0x99, 0x27, 0x80, 0x01, 0x80, 0xE1, 0x7F, 0xF4, 0x99, 0x28, 0x80, 0x01, 0x80, 0xEA, 0x7F, 0xF3, 0x99, 0x2B, 0x80, 0x01, 0x80, 0xEA, 0x7F, 0xF3, 0x99, 0x21, 0x80, 0x01, 0x80, 0xEB, 0x7F, 0xF3, 0x99, 0x27, 0x80, 0x00, 0x80, 0xEC, 0x7F, 0xF3, 0x99, 0x25, 0x80, 0x00, 0x80, 0xEA, 0x7F, 0xF3, 0x99, 0x1A, 0x80, 0x00, 0x80, 0xE9, 0x7F, 0xF3, 0x99, 0x24, 0x80, 0x00, 0x80, 0xE8, 0x7F, 0xF3, 0x99, 0x1B, 0x80, 0x01, 0x80, 0xE8, 0x7F, 0xF4, 0x99, 0x27, 0x80, 0x01, 0x80, 0xE7, 0x7F, 0xF3, 0x99, 0x2C, 0x80, 0x05, 0x80, 0xCE, 0x7F, 0xF3, 0x99, 0x20, 0x80, 0x01, 0x80, 0xD3, 0x7F, 0xF3, 0x99, 0x20, 0x80, 0x00, 0x81, 0x1D, 0x7F, 0xF3, 0x98, 0xFE, 0x80, 0x00, 0x81, 0x12, 0x7F, 0xF4, 0x99, 0x08, 0x80, 0x00, 0x81, 0x15, 0x7F, 0xF3, 0x99, 0x0B, 0x80, 0x01, 0x80, 0xDF, 0x7F, 0xF4, 0x99, 0x0B, 0x80, 0x02, 0x80, 0xE3, 0x7F, 0xF3, 0x99, 0x0C, 0x80, 0x01, 0x80, 0xED, 0x7F, 0xF4, 0x99, 0x0D, 0x80, 0x01, 0x80, 0xEB, 0x7F, 0xF4, 0x98, 0xF3, 0x80, 0x01, 0x80, 0xEA, 0x7F, 0xF4, 0x98, 0xE8, 0x80, 0x01, 0x80, 0xE5, 0x7F, 0xF4, 0x98, 0xF6, 0x80, 0x01, 0x80, 0xE5, 0x7F, 0xF3, 0x99, 0x01, 0x80, 0x00, 0x80, 0xE5, 0x7F, 0xF4, 0x99, 0x01, 0x80, 0x01, 0x80, 0xD6, 0x7F, 0xF4, 0x98, 0xFF, 0x80, 0x00, 0x80, 0xD6, 0x7F, 0xF4, 0x99, 0x0C, 0x80, 0x00, 0x80, 0xD7, 0x7F, 0xF4, 0x99, 0x0E, 0x80, 0x00, 0x80, 0xD8, 0x7F, 0xF4, 0x99, 0x0A, 0x80, 0x01, 0x80, 0xD8, 0x7F, 0xF3, 0x98, 0xF5, 0x80, 0x00, 0x80, 0xD5, 0x7F, 0xF4, 0x99, 0x02, 0x80, 0x00, 0x80, 0xDD, 0x7F, 0xF4, 0x98, 0xF3, 0x80, 0x01, 0x80, 0xD5, 0x7F, 0xF3, 0x99, 0x02, 0x80, 0x00, 0x80, 0xE2, 0x7F, 0xF4, 0x98, 0xFB, 0x80, 0x01, 0x80, 0xE7, 0x7F, 0xF3, 0x99, 0x05, 0x80, 0x01, 0x80, 0xD5, 0x7F, 0xF4, 0x99, 0x0A, 0x80, 0x00, 0x80, 0xD7, 0x7F, 0xF4, 0x99, 0x0C, 0x80, 0x01, 0x80, 0xD4, 0x7F, 0xF4, 0x99, 0x0F, 0x80, 0x01, 0x80, 0xCC, 0x7F, 0xF3, 0x98, 0xF6, 0x80, 0x00, 0x80, 0xCD, 0x7F, 0xF3, 0x99, 0x05, 0x80, 0x01, 0x80, 0xD0, 0x7F, 0xF4, 0x99, 0x10, 0x80, 0x02, 0x80, 0xD9, 0x7F, 0xF4, 0x99, 0x0F, 0x80, 0x01, 0x80, 0xE2, 0x7F, 0xF4, 0x99, 0x07, 0x80, 0x00, 0x80, 0xE0, 0x7F, 0xF4, 0x99, 0x07, 0x80, 0x00, 0x80, 0xE6, 0x7F, 0xF4, 0x99, 0x09, 0x80, 0x01, 0x80, 0xE4, 0x7F, 0xF4, 0x98, 0xFC, 0x80, 0x00, 0x80, 0xE2, 0x7F, 0xF4, 0x99, 0x04, 0x3E, 0x3E
};
char * str_period = "21233c3c3c3c3131587526436f6e67264d6f2d333135001200140c050a1e003c0203000c845301013e3e";
char * str_period_new = "21233c3c3c3c31315368656e59616e672d30303131350012000502050a00000f0203000c845301013e3e";
char * str_offdata_new = "21233c3c3c3c31315368656e59616e672d30303131445501170127247fff7fff7fff7fff7fff7fff7fff7fff7fff7fff7fff7fff7fff7fff7fff7fff7fff7fff7fff7fff7fff7fff7fff7fff7fff7fff7fff7fff7fff7fff7fff7fff7fff7fff7fff7fff7fff7ffe7fff7fff7fff80007fff7fff7fff7fff7fff7fff7fff7fff7fff7fff7fff7fff7fff7fff7fff7fff7fff7fff7fff7fff7fff7fff7fff7fff7fff7fff7fff7ffe80017fff7fff7fff7fff7fff7fff7fff7fff7fff7fff7fff7fff7fff7ffe7fff7fff7fff7fff7fff7fff7fff7fff7fff7fff7fff7fff7fff7fff7fff7fff80037fff7fff7fff7fff7fff7fff7fff7fff7fff7fff7fff7fff7fff7fff7fff7fff7fff7fff7fff7fff7fff7fff7fff7fff7fff7fff7fff7fff7fff7fff7fff7fff7ffe7fff7fff3e3e";
unsigned char period_new[] = {
    0x21, 0x23, 0x3C, 0x3C, 0x3C, 0x3C, 0x31, 0x31, 0x53, 0x68, 0x65, 0x6E, 0x59, 0x61, 0x6E, 0x67, 0x2D, 0x30, 0x30, 0x31, 0x31, 0x35, 0x00, 0x12, 0x00, 0x05, 0x02, 0x05, 0x0A, 0x00, 0x00, 0x0F, 0x02, 0x03, 0x00, 0x0C, 0x03, 0x52, 0x01, 0x01, 0x3E, 0x3E 
};
unsigned char offdata_new[] = {
  0x21, 0x23, 0x3C, 0x3C, 0x3C, 0x3C, 0x31, 0x31, 0x53, 0x68, 0x65, 0x6E, 0x59, 0x61, 0x6E, 0x67, 0x2D, 0x30, 0x30, 0x31, 0x31, 0x44, 0x55, 0x01, 0x17, 0x01, 0x27, 0x24, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFE, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x80, 0x00, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFE, 0x80, 0x01, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFE, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x80, 0x03, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFE, 0x7F, 0xFF, 0x7F, 0xFF, 0x3E, 0x3E
};
unsigned char assistdata[] = {
  0x21, 0x23, 0x3c, 0x3c, 0x3c, 0x3c, 0x31, 0x31, 0x53, 0x68, 0x65, 0x6e, 0x59, 0x61, 0x6e, 0x67, 0x2d, 0x30, 0x30, 0x31, 0x31, 0x45, 0x55, 0x00, 0x09, 0x01, 0x2c, 0x1a, 0x99, 0xab, 0xa4, 0xb6, 0x3e, 0x3e
};
int main()
{
    /**
    time_t timer = time(NULL);
    string time="2018-10-1 12:01:33";
    char timeBuf[255]={0};
    struct tm *tm_time = (struct tm*)malloc(sizeof(struct tm));
    
    strcat(timeBuf, time.c_str());
    strptime(timeBuf, "%Y-%m-%d %H:%M:%S", tm_time);
    time_t tt = mktime(tm_time);
    printf("%d:%s\n", (int)tt, timeBuf);
    tt += 8 * 3600;
    strftime(timeBuf, sizeof(timeBuf), "%Y-%m-%d %H:%M:%S", localtime(&tt));
    cout << "timebuff:" << timeBuf << " time:" << time<<endl;
    */
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
    //serverAddr.sin_addr.s_addr=inet_addr("172.24.59.73");
    if ( inet_aton(SERVER_ADDR, &serverAddr.sin_addr) == 0 )
      {
        perror(SERVER_ADDR);
        exit(errno);
      }


    if(connect(clientSock,(struct sockaddr*)&serverAddr,sizeof(struct sockaddr_in))<0)
    {
        printf("Connect error.\n");
        exit(-1);
    }
    printf("Connect successful.\n");

    string sendString = "CDCD";
    char revBuf[MAX_NUM]={0};
    for(int i=0;i<1;i++)
        //while(sendString!= "")
    {
        sleep(1);
        //发送
        //sendString  = assistdata;
        //if(write(clientSock,period_new,sizeof(period_new))==-1)
        //  {
        //    printf("send error!\n");
        //  }
        string info = "21233c3c3c3c31315368656e59616e672d3030333035001300140c050a1e00010303000a03e80101013e3e";
        unsigned char *pC = (unsigned char*)malloc( sizeof(unsigned char) * info.size() / 2);
        for ( int i = 0; i < info.size(); i = i + 2 ) {
            const char * E = info.substr(i,2).c_str();
            unsigned char c = 0;
            sscanf(E, "%02x", &c);
            pC[i/2] = c;
        }
        if(write(clientSock,pC,sizeof(unsigned char) * info.size() / 2)==-1)
        {
            printf("send error!\n");
        }

        info = "21233c3c3c3c31315368656e59616e672d3030333145550009012c1a99aba4b63e3e";
        pC = (unsigned char*)malloc( sizeof(unsigned char) * info.size() / 2);
        for ( int i = 0; i < info.size(); i = i + 2 ) {
          const char * E = info.substr(i,2).c_str();
          unsigned char c = 0;
          sscanf(E, "%02x", &c);
          pC[i/2] = c;
        }
        if(write(clientSock,pC,sizeof(unsigned char) * info.size() / 2)==-1)
        {
            printf("send error!\n");
        }
        /*
        if(write(clientSock,onData2,sizeof(onData2))==-1)
        {
            printf("send error!\n");
        }
        */
        //if(write(clientSock,offdata_new,sizeof(offdata_new))==-1)
        //{
        //    printf("send error!\n");
        //}
        //cout<<"客户端发送了--"<<sendString<<endl;

        //接收
        int n = recv(clientSock,revBuf,sizeof(revBuf),0);
        char c[255];
        unsigned char x=0;
        string receive = "";
        for ( int i = 0; i < n ; i++) {
          //printf("%d:%x:%u\n",i,revBuf[i],revBufo[i]);
          sprintf(c,"%02x",revBuf[i]);
          receive += c;
        }
        cout<<"收到服务器的信息 "<<receive<<endl;
        bzero(revBuf,sizeof(revBuf));
    }
    sleep(1);
    /*
    sendString = "quit";
    if(write(clientSock,sendString.c_str(),strlen(sendString.c_str()))==-1)
    {
        printf("send error!\n");
    }
    */
    close(clientSock);
    char c[8];
    short n = 850;
    sprintf(c,"%04x",n);
    string s = c;
    cout<<"s:"<<s<<endl;
    return 0;
}
