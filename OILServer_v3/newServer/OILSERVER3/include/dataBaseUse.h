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
        //&connect = mysql_init(NULL);
        LOG(LOG_MSG,"try to start DB");
        strIp = hostIP;
        strUser = user;
        strPasswd = password;
        strDb = database;
        IpSave = strIp.c_str();
        userSave = strUser.c_str();
        passwordSave = strPasswd.c_str();
        databaseSave = strDb.c_str();

        if(mysql_real_connect(&connection,IpSave,userSave,passwordSave,databaseSave,0,NULL,0))
        {
            LOG(LOG_MSG,"DB linked");
        }
        else
        {
            LOG(LOG_ERR,"[init] DB link failed");
            LOG(LOG_ERR,mysql_error(&this->connection));
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
            LOG(LOG_ERR,"[restart] DB link failed");
            LOG(LOG_ERR, mysql_error(&this->connection));
        }
        LOG(LOG_MSG,"DB opened");
    }

    void DBQuery(string sql)
    {
        if(mysql_query(&connection, sql.c_str()))
        {
            LOG(LOG_ERR,"[Query] DB operate fail");
            LOG(LOG_ERR , mysql_error(&connection));
            if(!mysql_ping(&this->connection))
                reStart();
        }
        else
            LOG(LOG_MSG,"DB operate over");
    }
/*
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
*/
    string strDBSelectItem(string sql)
    {
        MYSQL_RES *result;
        string s = "";
        //LOG(LOG_DBG,"sql select querying... ");
        if (mysql_query(&this->connection, sql.c_str())) {
            LOG(LOG_DBG,"[Select] DB operation fail");
            LOG(LOG_ERR , mysql_error(&connection));
            if(!mysql_ping(&connection))
                reStart();
        }
        else {
          MYSQL_ROW row;
          result = mysql_use_result(&connection);
          if (mysql_num_fields(result) > 1) {
              //printf("i:%i\n",mysql_num_fields(result));
              LOG(LOG_ERR,"Multi-fields are not support.");
          }
          else {
              row = mysql_fetch_row(result);
              if (row!=NULL) {
                  s = row[0];
              }
              else {
                  LOG(LOG_ERR,"Empty set: "+sql);
              }
          }
          //int i = stoi(row[0]);
          mysql_free_result(result);
        }
        LOG(LOG_DBG,"sql select querying... "+s);
        return s;
    }
    void DBclose()
    {
        mysql_close(&this->connection);
    }
private:
    MYSQL connection;
    const char* IpSave ;
    const char* userSave ;

    const char* passwordSave ;
    const char* databaseSave ;
    string strIp;
    string strUser;
    string strPasswd;
    string strDb;
};



#endif
