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
    //mysql_thread_init();
    
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
        if ( theprotocolUseC.checkIntervalReady() ) {
            theSocketC.sendInformation(client_fd, theprotocolUseC.getStrDownInterval());
        }
        //theSocketC.sendInformation(client_fd, "information" );

    }
    //theDBC.DBclose();
    //mysql_thread_end();
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
#ifdef LOGMOD
    LOG(LOG_MSG,"Log mod is active.");
#endif
    LogUp("log.txt");
/*

    MYSQL * mysql_handler=mysql_init(NULL);
    mysql_real_connect(mysql_handler,"localhost","root","tree","monitor",0,NULL,0);
    string s = "SELECT threshold FROM t_aux_set WHERE gid = 'ShenYang-001'";
    printf("%s\n",s.c_str());
    if (mysql_real_query(mysql_handler,s.c_str(),s.size())) {
        LOG(LOG_ERR, "fail");
        LOG(LOG_ERR, mysql_error(mysql_handler));
    }
    else {
        LOG(LOG_DBG,"success");
        MYSQL_RES *result;
        unsigned num_fields=111;
        unsigned int num_rows=111;
        unsigned int i;
        result = mysql_store_result(mysql_handler);
        if (result)  // there are rows
        {
            num_fields = mysql_num_fields(result);
            MYSQL_ROW row;
            row = mysql_fetch_row(result);
            if(row==NULL) {
                LOG(LOG_DBG,"my god");
            }
            unsigned long *lengths;
            lengths = mysql_fetch_lengths(result);
            printf("%i\n",num_rows);
            for(i = 0; i < num_fields; i++)
            {
                printf("[%.*s] ", (int) lengths[i],
                       row[i] ? row[i] : "NULL");
            }
            printf("\n");
            // retrieve rows, then call mysql_free_result(result)
        }
        else  // mysql_store_result() returned nothing; should it have?
        {
            if(mysql_field_count(mysql_handler) == 0)
            {
                // query does not return data
                // (it was not a SELECT)
                num_rows = mysql_affected_rows(mysql_handler);
            }
            else // mysql_store_result() should have returned data
            {
                fprintf(stderr, "Error: %s\n", mysql_error(mysql_handler));
            }
        }
        printf("%i,%i\n",num_fields,num_rows);
        /*
        MYSQL_ROW row;
        result = mysql_use_result(mysql_handler);
        row = mysql_fetch_row(result);
        string s = row[0];
        LOG(LOG_DBG, "sql reslut: "+s);
        mysql_free_result(result);
    }
    mysql_close(mysql_handler);


*/
//mysql_library_init(0,NULL,NULL);

    theDBC.InitTheDBModule("localhost","root","tree","monitor");
    theprotocolUseC.InitTheProtocolModule(theDBC);
    //theDBC.DBQuery("insert into t_aux_set values (NULL, 1,1)");
    //theDBC.strDBSelectItem("select threshold from t_aux_set where gid = \"ShenYang-001\" ");
    //LOG(LOG_DBG,"sql test: "+theDBC.strDBSelectItem("select threshold from t_aux_set where gid = \"ShenYang-001\" "));
    theSocketC.InitTheSocketModule(PORT);
    //theprotocolUseC.InitTheProtocolModule(theDBC);
    server();
    //fclose(stderr);
    LogDown();
    //mysql_library_end();
    
    return 0;
}
