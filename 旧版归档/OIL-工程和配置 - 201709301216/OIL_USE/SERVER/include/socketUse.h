#ifndef __socketUse_H__    //意思是  "if not define __XXX_H__" 也就是没包含XXX.h
#define __socketUse_H__   //就定义__XXX_H__
//因为我的思路是尽可能简化早期功能耦合，所以这些功能大多写在头文件，这个方法是头文件保护，预防重复引用
//所有由我编写的Use头文件都只会在operate.cpp里面引用

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

//（真正的系统总体控制器，里面应该包含所有小模块引用）
class socketController//socket控制器
{
   public:
    void InitTheSocketModule(logController theLogControlerIn,int port)
    { 
      theLogControler = theLogControlerIn;//初始化日志控制器
      makeLogShow(1,"socket模块尝试启动");//执行顺序中这个应该是最外层的包装
      startTheServer(port);
      makeLogShow(1,"socket模块已经启动");
    }

      //发送消息的方法
       void sendInformation(int clientSock,string information)
       {
           if(isStarted)//为了安全起见包一层，事实上功能一般，结构上看上去好一点
           {
	    if(write(clientSock,information.c_str(),MAX_NUM)==-1)//sizeof(information.c_str())
            {
	       makeLogShow(4,"向客户端发送信息失败了");
              return;
	    }
             makeLogShow(1,"成功向客户端发送信息："+information);
           }
       }


       string getInformation(int clientSock)//获取值的方法
       {
            string informationReturn = "";
            if(isStarted)//为了安全起见包一层，事实上功能一般，结构上看上去好一点
           {
            char revBuf[MAX_NUM]={0};//接受信息最原始的缓冲区，获取到的信息最终传给receiveString（我就是喜欢字符串）
	    if(read(clientSock,revBuf,sizeof(revBuf))==-1)
	    {
	      makeLogShow(4,"读取数据失败");
              return "";
	     }

	      informationReturn = revBuf;//获取的信息交接（从这里可以开始信息处理了）
	      makeLogShow(1,"读取数据:("+informationReturn+")");
	      bzero(revBuf,sizeof(revBuf));  //清理一下缓存(暂时没有想到直接用string的类型接收，这就只能用这种方法替代，尴尬)
           }
              return informationReturn;	
       }

     int acceptSocket()//获取socket连接方便使用
     {
         return accept(serverSock,NULL,NULL);//获取到目标socket，跟多线程的ID关联，具体操作在上层
     }
     
      void closeClient(int clientSock)//关闭客户端
      {
        close(clientSock);//关掉当前的clientSocket
      } 
      void closeServer()//关闭服务器
      {
         close(serverSock);//关掉服务器的socket
      }



   private:
     logController theLogControler;//日志文件控制对象，在初始化的时候获取引用，并从内部使用来写日志
       //这个方法私人订制吧，因为我不能确定所有的模块现实的方式都是一样的）
      struct sockaddr_in serverAddr;//貌似是获取值的结构
      int port  =10005;//侦听的端口号
      int maxNumber =100;//最大连接数量
      int connectNumber = 5;//连接数量
      int serverSock=-1;//服务器socket标记值
      int clientSock=-1;//客户端socket标记值
      bool isStarted = false;//标记量，只有初始化操作全部成功，才可以开始工作
     
       void makeLogShow(int type ,string theinformation)//控制台输出+日志输出
       {
           cout<<theinformation<<endl;  //额外输出到控制台
           theLogControler.makeLogWithFlush(type,theinformation);//额外输出日志
       }

       void startTheServer(int port)//开启服务器
       {
          serverSock=-1;
          clientSock=-1;
          serverSock=socket(AF_INET,SOCK_STREAM,0);
          if(serverSock<0)
	  {
	     makeLogShow(4,"服务器socket创建失败");
	     return;
          }
             makeLogShow(1,"服务器socket创建成功");
           memset(&serverAddr,0,sizeof(serverAddr));//其实就是初始化
           serverAddr.sin_family=AF_INET;
	   serverAddr.sin_port=htons((u_short) port);//指定端口号
           serverAddr.sin_addr.s_addr=htons(INADDR_ANY);//随意网卡连接
          
           if(bind(serverSock,(struct sockaddr*)&serverAddr,sizeof(struct sockaddr_in))==-1)//貌似是锁定端口
           {
		makeLogShow(4,"端口锁定失败");
                return;
           }
	   makeLogShow(1,"端口锁定成功");

	   if(listen(serverSock,10)==-1)//尝试侦听端口
	   {
		makeLogShow(4,"端口侦听失败");
                return;
	   }
		makeLogShow(1,"端口侦听成功");
           isStarted =true;//至此，初始化的功能完成
       }

      
    
};




#endif       //否则不需要定义
