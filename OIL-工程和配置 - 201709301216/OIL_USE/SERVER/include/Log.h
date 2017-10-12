#ifndef __Log_H__    //意思是  "if not define __XXX_H__" 也就是没包含XXX.h
#define __Log_H__   //就定义__XXX_H__
//因为我的思路是尽可能简化早期功能耦合，所以这些功能大多写在头文件，这个方法是头文件保护，预防重复引用
 

#include <iostream>
#include<string.h>
#include<fstream> 
#include<time.h> 
//这个算是一个模块调用的功能，对我而言更相当于“类库”的概念，所以在模块中的实现应该极简
using namespace std;

//log类型，真正应对文件编写的类，会被logController类调用使用
//之所以又加上了一个logController是为了保证在扩展功能的时候代码不会太乱套
class Log
{
 public:
    


    void Init(string dirPath)
    {
        theDirName = dirPath;//获取目标文件夹
	makeLogFileName();//自己算一个目标文件的名字
        LogShow(1,"日志模块已经启动");
        Flush();
        cout<<"日志模块已经启动"<<endl;
    }
    void LogShow( int type, string theInformation)
    { 
      //这个执行顺序不要改因为一些文件中所需要的信息例如时间是在onAddLog()里面计算得到的
      onAddLog();
      writeLog(type ,theInformation);
    }
    void Flush()//真正写入文件
    {
        ofstream fout(theDirName+theFileName+theEndName,ios::app);
        fout<<theInformationSave;   //如果没什么事就直接写文件
        theInformationSave = "";//缓存清空，万事大吉
    }
 private:
   //非常重要的配置信息（一般是有默认值的）
   string theDirName="./loger/";//Log的文件夹名称(默认值是用来测试的，如果没有构造成功，那么就会在loger文件夹里面写)
   string theFileName = "Logs";//Log文件的名字,这个是需要计算得到的，外部无法感知到这个文件名字的定义方法
   string theEndName = ".log";//文件的后缀名（说实话没人会在意这个，但是先预留出来）
   const int theLogFileLength = 20000;//如果超过这个长度，就需要更换log文件进行处理
   int logCount=0;//不是很好的方法，计算当前的日志数量上限，如果超界就换文件接着写
   int theLogIndex =0;//一直累加logCount计算文件名我怕溢出，于是每隔一段时间要清空logCount
   //下面是一些用于计算的中间变量
    int today = 0;//记录当前日期，换一天下标也就从头开始，说到底就是怕数太大
    string timeString = "";//在准备调整日志文件输出目标的时候就计算过时间了，于是直接保留一个字符串就好
    string theInformationSave = "";//用字符串先存要记录的信息，每隔一段时间IO一次就好
    //(但是这个还没有实现，因为有逻辑问题,例如每隔一个月日志文件就会被重新写)///////////////////////////////////////////
  
   void onAddLog()//当加入一条记录之后额外需要做什么？计数，防止溢出，判断和开关文件
   {
        logCount++;//记下一条日志了
         
        if(logCount >= theLogFileLength)
        {
         logCount=0;//清空计数器
         theLogIndex ++;//修改文件名
         Flush();//注意，如果信息记录已经过多了，那么强制写到文件里面去
         makeLogFileName();//开始新的文件
        }
   }
/*用这种方式实现的优势：
*1 输入的文件名字，即：当需要写入到下一个日志的时候只需要修改当前文件名就行 
*2 输入的是string这个毕竟要比char*给力
*用这种方式实现的缺点：
*1 效率令人担忧
*2 有关读写/异步锁的问题
*/
   void writeLog(string theInformation)//写文件的方法(默认就是information)
   {
       ofstream fout(theDirName+theFileName+theEndName,ios::app); 
      // fout<<timeString +" [info]: " +theInformation<<endl;   //如果没什么事就直接写文件
       theInformationSave += timeString +" [info]: " +theInformation+"\n";
   }


   string  makeLogTitle(int type)//制作log日志的题头
   {
       string  title = " [info]: ";
       switch (type)
      {
        case 1:
          title = " [info]: "; break;
	case 2:
		  title = " [warn]: "; break;
	case 3:
		  title = " [debug]: "; break;
	case 4:
		  title = " [erro]: "; break;
        default: 
		title = " [info]: "; break;
      }
       return  title;

   }
   void writeLog(int type ,string theInformation)//写文件方法的，无非就是就改一个题头，但是用数字的方法不是很好，可以考虑用枚举
   {

       ofstream fout(theDirName+theFileName+theEndName,ios::app);
      // fout<<timeString + title + theInformation<<endl;   //如果没什么事就直接写文件
       theInformationSave += timeString + makeLogTitle(type) +theInformation+"\n";
   }
   void writeLogWithoutFlush(int type ,string theInformation)//写文件方法,绕过缓冲区直接就写，适合只有一两条数据或者根本就不频繁的情况
   {
       ofstream fout(theDirName+theFileName+theEndName,ios::app);
       fout<<timeString +  makeLogTitle(type)+ theInformation<<endl;   //如果没什么事就直接写文件
   }
   void makeLogFileName()//构建Log文件的文件名称
   {
       time_t nowTime; 
       struct tm *timer;
       nowTime = time(NULL);
       timer = localtime(&nowTime);
       //获取时间信息，具体内容可以参见下面的输出
       // cout<<nowTime; 
       // cout<<(1900+timer->tm_year) <<endl;
       // cout<< (1+timer->tm_mon)<<endl<<timer->tm_mday<<endl;
       
       //通过字符串拼接的方法获取到当前时间作为Log的名字中用于标识的时间的部分
       
       theFileName = "Log_"+ to_string((1900+timer->tm_year))+"_"+to_string((1+timer->tm_mon))+"_"+to_string(timer->tm_mday);
       theFileName += "_"+to_string(theLogIndex);

       timeString  = to_string(timer->tm_year+1900)+"-"+ to_string(timer->tm_mon+1)+"-"+to_string(timer->tm_mday)+" ";//时间：年-月-日
       timeString  +=to_string(timer->tm_hour)+":"+ to_string(timer->tm_min) +":"+ to_string(timer->tm_sec) ;
	//时：分：秒 剩余的时间参数
   }

};

#endif       //否则不需要定义
