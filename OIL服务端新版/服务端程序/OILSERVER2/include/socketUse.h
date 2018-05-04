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


#define CONNECT_NUM 5
#define MAX_NUM 300

using namespace std;


class socketController
{
   public:
    void InitTheSocketModule(int port)
    { 
      makeLogShow(1,"socket opening");
      startTheServer(port);
    }

       void sendInformation(int clientSock,string information)
       {
           if(isStarted)
           {
	    if(write(clientSock,information.c_str(),MAX_NUM)==-1)//sizeof(information.c_str())
            {
	       makeLogShow(4,"socked send fail");
              return;
	    }
             makeLogShow(1,"send "+information);
           }
       }


       string getInformation(int clientSock)
       {
            string informationReturn = "";
            if(isStarted)
           {
            char revBuf[MAX_NUM]={0};
	    if(read(clientSock,revBuf,sizeof(revBuf))==-1)
	    {
	      makeLogShow(4,"socket read fail");
              return "";
	     }

	      informationReturn = revBuf;
	      makeLogShow(1,"read:("+informationReturn+")");
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
      int port  =10005;
      int maxNumber =100;
      int connectNumber = 5;
      int serverSock=-1;
      int clientSock=-1;
      bool isStarted = false;
     
       void makeLogShow(int type ,string theinformation)
       {
           cout<<theinformation<<endl; 
       }

       void startTheServer(int port)
       {
          serverSock=-1;
          clientSock=-1;
          serverSock=socket(AF_INET,SOCK_STREAM,0);
          if(serverSock<0)
	  {
	     makeLogShow(4,"socket build fail");
	     return;
          }
             makeLogShow(1,"socket build over");
           memset(&serverAddr,0,sizeof(serverAddr));
           serverAddr.sin_family=AF_INET;
	   serverAddr.sin_port=htons((u_short) port);
           serverAddr.sin_addr.s_addr=htons(INADDR_ANY);
          
           if(bind(serverSock,(struct sockaddr*)&serverAddr,sizeof(struct sockaddr_in))==-1)
           {
		makeLogShow(4,"socket lock fail");
                return;
           }
	   makeLogShow(1,"socket lock over");

	   if(listen(serverSock,10)==-1)
	   {
		makeLogShow(4,"socket listten fail");
                return;
	   }
		makeLogShow(1,"socket listen over");
           isStarted =true;
       }
};




#endif 
