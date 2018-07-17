#ifndef __dataBaseUse_H__    
#define __dataBaseUse_H__ 

//#include"logUse.h"

#include<iostream>
#include<mysql/mysql.h>


using namespace std;

class DBController
{
    public:

      void InitTheDBModule( string hostIP,string user,string password,string database) 
      {

        mysql_init(&connection);
        makeLogShow(1,"try to start DB");
        if(mysql_real_connect(&connection,hostIP.c_str(),user.c_str(),password.c_str(),database.c_str(),0,NULL,0))
        { 
            makeLogShow(1,"DB linked");
        }
        else
       {
         makeLogShow(4,"DB link failed");
       }
       makeLogShow(1,"DB opened");
      }
      
      void DBQuery(string sql)
      {
        if(mysql_query(&connection, sql.c_str()))
            makeLogShow(4,"DB operate fail");
        else 
            makeLogShow(1,"DB operate over");
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
       void makeLogShow(int type,string theinformation)
       {
           cout<<theinformation<<endl;
           
       }
};



#endif
