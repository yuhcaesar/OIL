#ifndef __protocolUse_H__    //意思是  "if not define __XXX_H__" 也就是没包含XXX.h
#define __protocolUse_H__   //就定义__XXX_H__

//这个类用于处理关于协议的内容，对传过来的数据进行分析，并返回用于操作数据库烦人操作命令
#include <string.h>
#include <iostream>
#include <sstream>//我用的是这种方法做的字符串分割，因为实现上貌似比较简洁
#include<time.h> 
using namespace std;

class protocolUse
{

 public:
  void InitTheProtocolModule( DBController theDBCIn , logController theLogIn  )
  {
    theLogC = theLogIn ;
    theDBC = theDBCIn;
    makeLogShow(1,"协议处理模块初始化完成");
  }

  void getString(string information)
  {
    //切分获得的字符串并且开始选择用哪一个方法来翻译，这一段字符串
     //下面是一个整体切分的例子
     // char  *buffer = new char[4];
     //cout<<"-----收到的信息如下（已经转换）-----"<<endl;
     //for(int i=0; i<length ; i++)
     //{
     //   int index = i%4;
     //   buffer[index] = gets[i];
     //   if(index == 3)
     //   {
     //     cout<<"-----"<< toIntValue(buffer)<<"-----"<<endl;
     //   }
     //}
     //cout<<"------所有信息收到了-----"<<endl;

    //slipMethod1(information);
    cout<<"-------------------------------------"<<endl;
    slipMethod2(information);
    cout<<"-------------------------------------"<<endl;
  }


  private:
    
    logController  theLogC ;//日志文件控制器
    DBController theDBC;//数据库控制器
     //这个方法私人订制吧，因为我不能确定所有的模块现实的方式都是一样的）   
    void makeLogShow(int type,string theinformation)//控制台输出+日志输出（
    {
           cout<<theinformation<<endl;  //额外输出到控制台
           theLogC.makeLogWithFlush(type,theinformation);//额外输出日志
    }
  
    //将0x22，这种16进制的内容搞定成int，翻译一下
    int toIntValue(const char * IN)
    {
         int ValueUse = 0;          
         sscanf(IN, "%x", &ValueUse); 
         return  ValueUse ;    
    }
    //int 转换成为string
    string toString(int In)
    {
      return to_string(In);
    }


 //API方法，真的使用的方法
 //所有的输入都不带0x的切分方法（实际用传入的时候默认十六进制）,
 //切分过程流出来，保持可扩展性
    void slipMethod2(string information)
    {
     int lengthAll =  information.size();
     string head =  information .substr(0,8);
     cout<<"head is "<< head<< endl;
     string VID = information .substr(8,4);
     cout<<"VID is "<< VID << endl;
     string PID =  information .substr(12,4);
     cout<<"PID is "<< PID << endl;
     string DID = information .substr(16,24);
     cout<<"DID is "<< DID << endl;
     string operate1 = information .substr(40,2);
     cout<<"operate1 is "<<  operate1 << endl;
     string operate2 = information .substr(42,2);
     cout<<"operate2 is "<<  operate2 << endl;
     string length = information .substr(44,4);
     cout<<"length is "<<  length << endl;
     string data = information .substr(48,lengthAll-4-48);
     cout<<"data is "<<  data << endl;
     string tail = information .substr(lengthAll-4,4);
     cout<<"tail is "<<  tail << endl;
     if(stringToInt(operate2) == 43)
     {
      dataUse43( VID,PID, DID, data);
     }
     else if(stringToInt(operate2) == 37)
     {
       dataUse37( VID,PID, DID, data);
     }
     else if(stringToInt(operate2) == 53)
     {
       dataUse53( VID,PID, DID, data);
     }
     
    }

//0x37操作,上报的是地理位置
//暂时操作的是一张大表
void dataUse37(string VID , string PID, string DID , string dataIn)
{
  string data1 = dataIn.substr(0,dataIn.size()-2);
  string data2 = dataIn.substr(dataIn.size()-2,2);
  string * theDataGet = stringSplite( data1,',');
  int theLength = getStringClipCount(data1 , ',');//获取长度以备后用
  if(theLength == 5)
  {
	  if(theDataGet[0] == "A")//说明成功定位
	  {
	     string NPos = theDataGet[1];
	     string EPos = theDataGet[3];
             string timeString = "";
             //获取时间信息
             time_t nowTime; 
             struct tm *timer;
             nowTime = time(NULL);
             timer = localtime(&nowTime);
             //通过字符串拼接的方法获取到当前时间（精确到天，因为位置不怎么动）
             timeString = to_string((1900+timer->tm_year))+"/"+to_string((1+timer->tm_mon))+"/"+to_string(timer->tm_mday);
             string command = "INSERT INTO OilData_037 (VID , PID , DID , NPostion, EPosition,  CommandID ,Time) ";
             command += "values('"+VID+"','"+PID+"','"+DID+"','"+NPos+"','"+EPos+"','"+data2 +"','"+timeString+"');"; 
             //cout<<command << endl;
             theDBC.DBQuery(command);
	  }
	  else if(theDataGet[0] == "V")//说明未定位
	  {
	    makeLogShow(2,"定位不成功。");
	  }
  }
  else
  {
   	    makeLogShow(2,"获得的坐标信息不完整。");
  }
}

//0x43的操作，上报的是数据
//暂时操作的是一张数据大表
void dataUse43(string VID , string PID ,string DID,  string dataIn)
{ 
   int data1 = toIntValue( dataIn.substr(0,2).c_str());
   int data2 = toIntValue(dataIn.substr(2,2).c_str());
   int data3 =  toIntValue(dataIn.substr(4,2).c_str());
   int data4 =  toIntValue(dataIn.substr(6,2).c_str());
   int data5 =  toIntValue(dataIn.substr(8,2).c_str());
   int  data6 =  toIntValue(dataIn.substr(10,2).c_str());
   int  data7 =  toIntValue(dataIn.substr(12,4).c_str());
   int  data8 =  toIntValue(dataIn.substr(16,4).c_str());
   int  data9 =  toIntValue(dataIn.substr(20,4).c_str());
   cout<<" data1="<<data1<<endl;
   cout<<" data2="<<data2<<endl;
   cout<<" data3="<<data3<<endl;
   cout<<" data4="<<data4<<endl;
   cout<<" data5="<<data5<<endl;
   cout<<" data6="<<data6<<endl;
   cout<<" data7="<<data7<<endl;
   cout<<" data8="<<data8<<endl;
   cout<<" data9="<<data9<<endl; 
   string timeString = "20"+to_string(data1) +"/"+to_string(data2) +"/"+to_string(data3)+"/"+to_string(data4)+"/"+to_string(data5)+"/"+to_string(data6);
   string command = "INSERT INTO OilData_043 (VID , PID , DID , Data1, Data2, Data3, Time) ";
   command += "values('"+VID+"','"+PID+"','"+DID+"','"+to_string(data7)+"','"+to_string(data8)+"','"+to_string(data9)+"','"+timeString+"');"; 
   //cout<<command << endl;
   theDBC.DBQuery(command);
}

//0x53的操作，上报的是数据(因为不能保证不同数据的操作是一样的，所以只能暂时全分开写)
//暂时操作的是一张数据大表
   
void dataUse53(string VID , string PID ,string DID,  string dataIn)
{ 
   int data1 = toIntValue( dataIn.substr(0,2).c_str());
   int data2 = toIntValue(dataIn.substr(2,2).c_str());
   int data3 =  toIntValue(dataIn.substr(4,2).c_str());
   int data4 =  toIntValue(dataIn.substr(6,2).c_str());
   int data5 =  toIntValue(dataIn.substr(8,2).c_str());
   int  data6 =  toIntValue(dataIn.substr(10,2).c_str());
   int  data7 =  toIntValue(dataIn.substr(12,4).c_str());
   int  data8 =  toIntValue(dataIn.substr(16,4).c_str());
   int  data9 =  toIntValue(dataIn.substr(20,4).c_str());
   cout<<" data1="<<data1<<endl;
   cout<<" data2="<<data2<<endl;
   cout<<" data3="<<data3<<endl;
   cout<<" data4="<<data4<<endl;
   cout<<" data5="<<data5<<endl;
   cout<<" data6="<<data6<<endl;
   cout<<" data7="<<data7<<endl;
   cout<<" data8="<<data8<<endl;
   cout<<" data9="<<data9<<endl; 
   string timeString = "20"+to_string(data1) +"/"+to_string(data2) +"/"+to_string(data3)+"/"+to_string(data4)+"/"+to_string(data5)+"/"+to_string(data6);
   string command = "INSERT INTO OilData_053 (VID , PID , DID , Data1, Data2, Data3, Time) ";
   command += "values('"+VID+"','"+PID+"','"+DID+"','"+to_string(data7)+"','"+to_string(data8)+"','"+to_string(data9)+"','"+timeString+"');"; 
   //cout<<command << endl;
   theDBC.DBQuery(command);
}
 
/****************************备用方法********************************************/
    //统一使用，用一个字符切分成数组大法，返回的是切分好的字符串数组（我们可能不知道它的长度，这个长度可以通过协议编号查询得到）
    //spliteChar是切分用的字符
    string * stringSplite(string information,char spliteChar)
    {
     int index = 0;
     int countNeed = 0;
     string * theStringClips;
     string sub_str;

     stringstream ssForCount(information);
     stringstream ss(information);

     //以;为间隔分割test的内容
     //遇到第一个\0就算是结束了正好与协议的结尾内容相同
     while(getline(ssForCount,sub_str,spliteChar)) 
       countNeed ++;
     theStringClips = new  string [countNeed];     
     while(getline(ss,sub_str,spliteChar)) 
     {
       theStringClips [index] = sub_str;
       index ++;
      }

    return theStringClips;
   }
   
   //简化方法，仅仅获取切分字符串数组的长度
   //比较土的方法 spliteChar是切分用的字符
   int getStringClipCount(string information ,char spliteChar)
   { 
      int countNeed = 0;
      stringstream ssForCount(information);
      string sub_str;
      while(getline(ssForCount,sub_str,spliteChar)) 
       countNeed ++;
      return countNeed;
   }
    
   float stringToFloat(string str)
   {
     float f=atof(str.c_str());
     return f;
    //这种写法仅仅是为了展示结构
   } 
   int stringToInt(string str)
   {
     float i=atoi(str.c_str());
     return i;
    //这种写法仅仅是为了展示结构
   }  
 /****************************备用方法结束********************************************/
 
 /*****************************比较原始的方法*********************************************/
 //很原始的方法数据切分的方法
 //所有的输入都不带0x的切分方法（实际用传入的时候默认十六进制）,
 //切分过程流出来，保持可扩展性
    void slipMethod1(string information)
    {
      const char * gets = information.c_str(); 
       int lengthAll =  information.size();
       cout<< "length "<<lengthAll<<endl;
      //最前面信息的逐项切分
	     int i=0;
	     char * bufferUse = new char[4];//因为一个十六进制数用了四个字符
	     int indexNow = 0;//当前控制的缓存的下标
	     /**************head********************/
	     string head ="";
	     for( ;i<8; i++)
	      head += gets[i];
	     cout<<"head is "<< head<< endl;
	    /**************VID********************/
	    string VID = "";
	     for( ;i<12; i++)
	      VID += gets[i];
	    cout<<"VID is "<< VID << endl;
	    /**************PID********************/
	     string PID = "";
	     for( ;i<16; i++)
	      PID += gets[i];
	    cout<<"PID is "<< PID << endl;
	 /**************DID********************/
	     string DID = "";
	     for( ;i< 40; i++)
	      DID += gets[i];
	    cout<<"DID is "<< DID << endl;
	 /**************operation1********************/
	     string operation1 = "";
	     for( ;i< 42; i++)
	      operation1 += gets[i];
	    cout<<"operation1 is "<< operation1 << endl;
	 /**************operation2********************/
	     string operation2 = "";
	     for( ;i< 44; i++)
	      operation2 += gets[i];
	    cout<<"operation2 is "<< operation2 << endl;
	 /**************length********************/
	     string length = "";
	     for( ;i< 48; i++)
	      length += gets[i];
	    cout<<"length is "<< length << endl;
	 /**************data********************/
	     string data = "";
	     for( ;i< lengthAll-4; i++)
	      data += gets[i];
	    cout<<"data is "<< data << endl;
	 /**************tail********************/
	     string tail = "";
	     for( ;i< lengthAll; i++)
	      tail += gets[i];
	    cout<<"tail is "<< tail << endl;
    }
    /*****************************比较原始的结束*********************************************/
};
 



















#endif       //否则不需要定义
