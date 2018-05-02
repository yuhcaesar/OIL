/*
*整个工程的入口类，也是唯一的总体操作脚本 
*作为一个main脚本其实什么都不用做，调用已经写好的类就是唯一的职责（注意这里的封装）
*/


//所有我编写的Use头文件原则上都只会在这里引用
//这里的调用顺序不可以被打乱
#include"logUse.h" 
#include"dataBaseUse.h" 
#include"socketUse.h"
#include"protocolUse.h"
#include <unistd.h>

 logController  theLogC ;//日志文件控制器
 DBController theDBC;//数据库控制器
 socketController theSocketC;//socket控制器
 protocolUse theprotocolUseC;//协议控制器
//这之下是各个模块的测试方法
/*
日志文件标题类型如下（更新log类的时候注意这里的更新）
默认 [info] 信息
1 [info] 信息
2 [warn] 警告
3 [debug]调试
4 [erro]错误
*/
    void playForLog()
	{
	    theLogC.makeLog(0,"战斗吧!!!__"+ to_string(11));
	    theLogC.makeLog(1,"为了宇宙和平!!!__"+ to_string(22));
	   theLogC.makeLog(2,"中二病拯救世界!!!__"+ to_string(33));
	   theLogC.makeLog(3,"男人不二怎么行!!!__"+ to_string(44));
	    theLogC.makeLog(4,"真理就在这里!!!__"+ to_string(55));
            cout<<"\n-------日志测试成功-------\n"<<endl;
	}
   void playForDB()//数据库模块测试方法
	{
	   theDBC.DBQuery("insert into test values ('jujietou4','shenyiyang5')");
	   theDBC.DBSelect("select * from test")  ;
           cout<<"\n--------数据库测试成功-------\n"<<endl;
	}

 
/****************************************************具体操作方法**********************************************************************/
void makeLog(int type,string information)
{
      cout<<information<<endl;  //额外输出到控制台
      theLogC.makeLogWithFlush(type,information);//额外输出日志
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
           //获取到相关的字符串，也就是传书的内容之后就可以处理数据了（其实就是入库）
	   if(receiveString ==""||receiveString =="Quit" ||receiveString == "quit")//给出结束的符号
	   {
	        theSocketC. closeClient(client_fd);
                canRun = false;
		break;
	    }
   
            //接收数据并处理
            theprotocolUseC.getString(receiveString);
            //如果有命令需要对某硬件进行操控
            theSocketC.sendInformation(client_fd, "information" ); 
            
         }
    }

void server()
{
    makeLog(1,"服务器正式启动，开始侦听端口......");
    cout<<"-----------------------------------------------------------"<<endl;
    while(1)  
    {  
        //client_fd = accept(fd,(struct sockaddr *)&client_addr,&socklen);
        client_fd = theSocketC.acceptSocket();
        if(client_fd<0)  
        {  
            makeLog(4,"并没有被接受服务器被迫停止，原因有可能是端口被占用，请重试");
            theSocketC. closeServer(); 
            return;  
        }  
        //新线程
        pthread_create(&tid,NULL,run,(void *)client_fd);  
        pthread_detach(tid);  
    }  
       theSocketC. closeServer(); 
}

int main()
{
	  theLogC.InitTheLogModule("./log/");//Log模块初始化
	  //参数是要存日志makeLog的目录
          //不断删除和生成的测试数据库 "demos"
          //测试用数据库 "platformUse"
          //留待扩展的数据库数据库 "platformIOT"
          //暂时正式使用的数据库icpscloud
	 theDBC.InitTheDBModule(theLogC,"localhost","root","tree","OIL");//数据库模块的初始化
	 //参数从左到右分别是：log模块控制器，目标主机，用户名，密码，要用到的数据库名字
	 theSocketC.InitTheSocketModule(theLogC,10005);//socket模块初始化
         //参数为  DB模块控制器 log模块控制器 redis模块控制器
        theprotocolUseC. InitTheProtocolModule(theDBC,theLogC);
        server();
        return 0;
}
