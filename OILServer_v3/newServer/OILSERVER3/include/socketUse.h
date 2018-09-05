#ifndef __socketUse_H__    
#define __socketUse_H__   

#include <unistd.h> 
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include "log.h"

#define CONNECT_NUM 5
#define MAX_NUM 3000

#ifdef TEST
#define PORT 10006
#else
#define PORT 10005
#endif

using namespace std;


class socketController
{
public:
    void InitTheSocketModule(int port)
    {
        LOG(LOG_MSG,"socket opening");
        startTheServer(port);
    }

    void sendInformation(int clientSock,string information)
    {
        if(isStarted)
        {
            if(write(clientSock,information.c_str(),MAX_NUM)==-1)//sizeof(information.c_str())
            {
                LOG(LOG_ERR,"socked send fail");
                return;
            }
            LOG(LOG_ERR,"send "+information);
        }
    }


    string getInformation(int clientSock)
    {
        string informationReturn = "";
        int n;
        if(isStarted)
        {
            unsigned char revBuf[MAX_NUM]={0};
/****
     if(read(clientSock,revBuf,sizeof(revBuf))==-1)
     {
     makeLogShow(4,"socket read fail");
     return "";
     }

     informationReturn = revBuf;
     makeLogShow(1,"read:("+informationReturn+")");
     bzero(revBuf,sizeof(revBuf)); 
*/
            n = recv(clientSock,revBuf,sizeof(revBuf),0);
            if ( n < 0 ) {
                LOG(LOG_ERR,"socket read fail");
                return "";
            } else {
                LOG(LOG_MSG,"len:"+to_string(n)+"");
            }
            //printf("chars:%s\n",revBuf);
            char c[255];
            unsigned char x=0;
            for ( int i = 0; i < n ; i++) {
                //printf("%d:%x:%u\n",i,revBuf[i],revBufo[i]);
                sprintf(c,"%02x",revBuf[i]);
                informationReturn += c;
            }

            //informationReturn = revBuf;
            LOG(LOG_RAW,informationReturn);
            LOG(LOG_MSG,"info size: "+to_string(informationReturn.size()));
            //cout<<informationReturn.size();
            bzero(revBuf,sizeof(revBuf));
        }
        return informationReturn;
    }

    int acceptSocket()
    {
        return accept(serverSock,NULL,NULL);
    }
     
    void closeClient(int clientSock)
    {
        close(clientSock);
    } 
    void closeServer()
    {
        close(serverSock);
    }



private:

    struct sockaddr_in serverAddr;
    int port  = PORT;
    int maxNumber =100;
    int connectNumber = 5;
    int serverSock=-1;
    int clientSock=-1;
    bool isStarted = false;
    
    void startTheServer(int port)
    {
        serverSock=-1;
        clientSock=-1;
        serverSock=socket(AF_INET,SOCK_STREAM,0);
        if(serverSock<0)
        {
            LOG(LOG_ERR,"socket build fail");
            return;
        }
        LOG(LOG_MSG,"socket build over");
        memset(&serverAddr,0,sizeof(serverAddr));
        serverAddr.sin_family=AF_INET;
        serverAddr.sin_port=htons((u_short) port);
        serverAddr.sin_addr.s_addr=htons(INADDR_ANY);

        if(bind(serverSock,(struct sockaddr*)&serverAddr,sizeof(struct sockaddr_in))==-1)
        {
            LOG(LOG_ERR,"socket lock fail");
            return;
        }
        LOG(LOG_MSG,"socket lock over");

        if(listen(serverSock,10)==-1)
        {
            LOG(LOG_ERR,"socket listten fail");
            return;
        }
		LOG(LOG_MSG,"socket listen over");
        isStarted =true;
    }
};




#endif 
