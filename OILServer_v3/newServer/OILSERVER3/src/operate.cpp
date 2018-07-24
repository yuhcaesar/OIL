#include "dataBaseUse.h" 
#include "socketUse.h"
#include "protocolUse.h"
#include "param.h"
#include <unistd.h>


DBController theDBC;
socketController theSocketC;
protocolUse theprotocolUseC;

void makeLog(int type,string information)
{
        cout<<information<<endl;
}

int client_fd=0; 
pthread_t tid;  
sockaddr_in client_addr;  
socklen_t socklen = sizeof(client_addr); 
unsigned client_port=0;  
char client_ip[20]; 

 
void *run(void *arg)
{
        int client_fd = *((int*)&arg);  
        bool canRun =true;
        while(canRun)
        {
                string receiveString = theSocketC.getInformation(client_fd);
                if(receiveString ==""||receiveString =="Quit" ||receiveString == "quit")
                {
                        theSocketC. closeClient(client_fd);
                        canRun = false;
                        break;
                }
                //cout<<"receive :"<<receiveString<<endl;
                theprotocolUseC.getString(receiveString);
                theSocketC.sendInformation(client_fd, "information" ); 
            
        }
}

void server()
{
        makeLog(1,"server is opened......");
        cout<<"-----------------------------------------------------------"<<endl;
        while(1)  
        {  
                //client_fd = accept(fd,(struct sockaddr *)&client_addr,&socklen);
                client_fd = theSocketC.acceptSocket();
                if(client_fd<0)  
                {  
                        makeLog(4,"server open failed");
                        theSocketC.closeServer(); 
                        return;  
                }  
                pthread_create(&tid,NULL,run,(void *)client_fd);  
                pthread_detach(tid);  
        }  
        theSocketC.closeServer(); 
}

int main()
{
	theDBC.InitTheDBModule("localhost","root","tree","monitor");
	theSocketC.InitTheSocketModule(10005);
        theprotocolUseC.InitTheProtocolModule(theDBC);
        server();
        return 0;
}
