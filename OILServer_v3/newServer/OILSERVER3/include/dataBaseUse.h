#ifndef __dataBaseUse_H__    
#define __dataBaseUse_H__ 

//#include"logUse.h"

#include<iostream>
#include<mysql/mysql.h>
#include "log.h"

using namespace std;

class DBController
{
public:

    void InitTheDBModule( string hostIP,string user,string password,string database) 
    {

        mysql_init(&connection);
        LOG(LOG_MSG,"try to start DB");
        IpSave = hostIP.c_str();
        userSave = user.c_str();
        passwordSave = password.c_str();
        databaseSave =database.c_str();

        if(mysql_real_connect(&connection,IpSave,userSave,passwordSave,databaseSave,0,NULL,0))
        { 
            LOG(LOG_MSG,"DB linked");
        }
        else
        {
            LOG(LOG_ERR,"DB link failed");
            LOG(LOG_ERR,mysql_error(&connection));
        }
        LOG(LOG_MSG,"DB opened");
    }
    void reStart()
    {
        mysql_close(&connection);
        mysql_init(&connection);
        LOG(LOG_MSG,"try to start DB");
        if(mysql_real_connect(&connection,IpSave,userSave,passwordSave,databaseSave,0,NULL,0))
        { 
            LOG(LOG_MSG,"DB linked");
        }
        else
        {
            LOG(LOG_ERR,"DB link failed");
            LOG(LOG_ERR, mysql_error(&connection));
        }
        LOG(LOG_MSG,"DB opened");
    }
      
    void DBQuery(string sql)
    {
        if(mysql_query(&connection, sql.c_str()))
        {
            LOG(LOG_ERR,"DB operate fail");
            LOG(LOG_ERR , mysql_error(&connection));
            if(!mysql_ping(&connection))
                reStart();
        }
        else 
            LOG(LOG_MSG,"DB operate over");
    }

    void DBSelect(string sql)  
    {  
        mysql_query(&connection, sql.c_str());
        MYSQL_RES *result;  
        MYSQL_ROW row; 
        result = mysql_use_result(&connection); 
        while(row = mysql_fetch_row(result))
        {  
            for(int j=0; j < mysql_num_fields(result); j++)
            {  
                cout << row[j] << " ";
            }  
            cout << endl;  
        }
		mysql_free_result(result);
    }

private:
    MYSQL connection;
    const char* IpSave ;
    const char* userSave ;

    const char* passwordSave ;
    const char* databaseSave ;

    
};



#endif
