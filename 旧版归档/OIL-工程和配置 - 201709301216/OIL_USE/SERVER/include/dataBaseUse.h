#ifndef __dataBaseUse_H__    //意思是  "if not define __XXX_H__" 也就是没包含XXX.h
#define __dataBaseUse_H__   //就定义__XXX_H__
//因为我的思路是尽可能简化早期功能耦合，所以这些功能大多写在头文件，这个方法是头文件保护，预防重复引用

//下面这些引用没有必要有，我在这里列出来是为了记录这个类使用了这些头文件包装的功能
//所有由我编写的Use头文件都只会在operate.cpp里面引用
//#include"logUse.h"

#include<iostream>
#include<mysql/mysql.h>


using namespace std;

class DBController
{
    public:
      //初始化数据库模块，其实这个模块的也就是一个操作集合
      //传入的参数中还有日志控制器（日志控制器每一个模块都会引用一个）
      void InitTheDBModule( logController &theLogControlerIn, string hostIP,string user,string password,string database) 
      {
        theLogControler = theLogControlerIn;//日志控制器的引用保有
        mysql_init(&connection);//没有这一步就连不上数据库
        makeLogShow(1,"尝试初始化数据库模块");
        //根据参数连接数据库
        if(mysql_real_connect(&connection,hostIP.c_str(),user.c_str(),password.c_str(),database.c_str(),0,NULL,0))
        { 
            makeLogShow(1,"数据库连接成功");
        }
        else
       {
         makeLogShow(4,"数据库连接失败");
       }
       makeLogShow(1,"数据库模块已经启动");
      }
      
     //--------------------------------------------------打包的数据库操作--------------------------------------------------------//
      //没有返回值的操作人家已经打包好了，直接用(因为权限超级强大，慎用)
      //这个方法只是在增加新的数据的时候才可以使用，一般不会使用这种语句
      //当然，作为内部，也可以是一个究极的建表操作，因为有一些表是需要动态建立和删除的
      void DBQuery(string sql)//增删改都是一样的，传入sql语句就可以
      {
        if(mysql_query(&connection, sql.c_str()))
            makeLogShow(4,"数据操作失败");
        else 
            makeLogShow(1,"数据操作成功");
      }
      //说实话这个查询只不过就是后台验证是否正确操作了数据库
      //真正的前台调用不可能用这种方法进行，所以这个方法事实上也就算是自己看着玩的......
       void DBSelect(string sql)  
      {  
            mysql_query(&connection, sql.c_str());//首先需要将数据库操作字段“提交”到数据库
            MYSQL_RES *result;  
            MYSQL_ROW row; 
	    result = mysql_use_result(&connection); //这个看上去就是结果集 
	    while(row = mysql_fetch_row(result))//搜索所有的行
	    {  
	      for(int j=0; j < mysql_num_fields(result); j++)  //按列输出
	     {  
		  cout << row[j] << " ";
	     }  
		  cout << endl;  
	    }
		mysql_free_result(result);
      }

     private:
       MYSQL connection;//数据库连接对象引用
       logController theLogControler;//日志文件控制对象，在初始化的时候获取引用，并从内部使用来写日志
       //这个方法私人订制吧，因为我不能确定所有的模块现实的方式都是一样的）
       void makeLogShow(int type,string theinformation)//控制台输出+日志输出
       {
           cout<<theinformation<<endl;  //额外输出到控制台
           theLogControler.makeLogWithFlush(type,theinformation);//额外输出日志
       }
};



#endif       //否则不需要定义
