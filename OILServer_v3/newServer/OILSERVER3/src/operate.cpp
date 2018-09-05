#include <unistd.h>
#include "operate.h"
#include "dataBaseUse.h"
#include "socketUse.h"
#include "protocolUse.h"
#include "param.h"
#include "log.h"

using namespace std;

DBController theDBC;
socketController theSocketC;
protocolUse theprotocolUseC;

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
        //theSocketC.sendInformation(client_fd, "information" ); 

    }
}

void server()
{
    LOG(LOG_MSG,"server is opened......");
    LOG(LOG_MSG,"-------------------------------");

    while(1)  
    {  
        //client_fd = accept(fd,(struct sockaddr *)&client_addr,&socklen);
        client_fd = theSocketC.acceptSocket();
        if(client_fd<0)  
        {  
            LOG(LOG_ERR,"server open failed");
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
    //freopen("log.txt", "a", stderr);
    LogUp("log.txt");
    theDBC.InitTheDBModule("localhost","root","tree","monitor");
    theSocketC.InitTheSocketModule(PORT);
    theprotocolUseC.InitTheProtocolModule(theDBC);
    server();
    //fclose(stderr);
    LogDown();
    return 0;
}
