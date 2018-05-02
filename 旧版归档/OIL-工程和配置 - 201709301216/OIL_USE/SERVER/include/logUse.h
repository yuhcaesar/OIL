#ifndef __logUse_H__    //意思是  "if not define __XXX_H__" 也就是没包含XXX.h
#define __logUse_H__   //就定义__XXX_H__
//因为我的思路是尽可能简化早期功能耦合，所以这些功能大多写在头文件，这个方法是头文件保护，预防重复引用
/*
*log功能的控制单元
我的想法是将有挂log的功能全部实现在这个头文件中调用
*外面的类只能够看到这个脚本
*/

#include <iostream> 
#include<string.h>
#include "Log.h"
#include <pthread.h>
//这个算是一个模块调用的功能，对我而言更相当于“类库”的概念，所以在模块中的实现应该极简
using namespace std;
//这个类是log的管理单元，更加类似于控制模块
//有关线程的阻塞等等操作的实现在这个类实现(这也是一个单例)
//Log类是这个的底层调用类，保持单例
class logController
{
  private:
   Log* GetLog()//获取日志单例
   {  
       static  Log  theLogInstanceSingle  ;//Log的单例，静态
       return &theLogInstanceSingle;//这个方法尚且没有验证是否真的完成了单例模式
   }
  pthread_mutex_t* GetMutex()//获取线程锁单例
  {
     static   pthread_mutex_t  Mutex;//线程的单例
       return &Mutex;//这个方法尚且没有验证是否真的完成了单例模式
  } 
  public://久违了的这种公有方法的写法，不知道用类库的写法处理会不会出问题
   //这个是本脚本类型的写日志的公开方法
   //脚本优点：可读性和可扩展
   //将一些没必要上锁的地方也给锁了，于是乎导致阻塞时间比较长
   void makeLog(int type,string theLogInformation)
   {
     pthread_mutex_lock(GetMutex());//上锁
     GetLog()->LogShow(type,theLogInformation);//调用的是log脚本中的写方法
     pthread_mutex_unlock(GetMutex());//解锁
   }
   void makeLogWithFlush(int type,string theLogInformation)//马上就存入
   {
     pthread_mutex_lock(GetMutex());//上锁
     GetLog()->LogShow(type,theLogInformation);//调用的是log脚本中的写方法
     GetLog()->Flush();//立刻写入文件
     pthread_mutex_unlock(GetMutex());//解锁
   }
   //初始化Log模块
   void InitTheLogModule(string dirPath)
   {
      GetLog()->Init(dirPath);
   }
   void Flush()
   {
       GetLog()->Flush();
   }
 
 
};

#endif




