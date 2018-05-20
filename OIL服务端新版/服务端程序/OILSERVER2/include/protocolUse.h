#ifndef __protocolUse_H__   
#define __protocolUse_H__   
#include <string.h>
#include <iostream>
#include <sstream>
#include<time.h> 
using namespace std;

class protocolUse
{

 public:
  void InitTheProtocolModule( DBController theDBCIn )
  {
    theDBC = theDBCIn;
    makeLogShow(1,"protocoluse is opened");
  }

  void getString(string information)
  {
    saveStringForDemo(information);
  }


  private:
    
    DBController theDBC;
    int stringCount = 0;
    int saveCounter = 0;
    int saveCounterMax = 10;
    string saveStringUse = "INSERT INTO t_guid(data1,data2,data3,data4,data5,data6,gid,time)values";
    string theSaveString = "INSERT INTO t_guid (data1 , data2 , data3 , data4, data5,  data6, gid, time) values"; 
    void makeLogShow(int type,string theinformation)
    {
           cout<<theinformation<<endl; 
    }
  
    int toIntValue(const char * IN)
    {
         int ValueUse = 0;          
         sscanf(IN, "%x", &ValueUse); 
         return  ValueUse ;    
    }
    string toString(int In)
    {
      return to_string(In);
    }

    void saveStringForDemo(string getIn)
    {
       string* Use = stringSplite(getIn,',');
       string theDataClip = "";
       for(int i = 0 ; i < 7 ;i ++)
          theDataClip += Use[i]+",";
 
       saveCounter++;
       saveStringUse +=  "\n("+ theDataClip +"'"+getTime() +"')";
       saveStringUse += saveCounter<saveCounterMax? ",":";";
       if(saveCounter >= saveCounterMax)
       {
            saveCounter = 0;
           // theDBC.DBQuery(saveStringUse);
            cout<<"\n-------------------\n"<<saveStringUse<<"\n-------------------\n";
            theDBC.DBQuery(saveStringUse);
            saveStringUse = theSaveString;   
       }
       // cout<<save<<endl;
       // theDBC.DBQuery(save);

    }

//splite String With Char
    string * stringSplite(string information,char spliteChar)
    {
     int index = 0;
     int countNeed = 0;
     string * theStringClips;
     string sub_str;

     stringstream ssForCount(information);
     stringstream ss(information);

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

  string getTime()
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

       string timeString  = to_string(timer->tm_year+1900)+"-"+ to_string(timer->tm_mon+1)+"-"+to_string(timer->tm_mday)+" ";//时间：年-月-日
       timeString  +=to_string(timer->tm_hour)+":"+ to_string(timer->tm_min) +":"+ to_string(timer->tm_sec) ;
	//时：分：秒 剩余的时间参数
       return timeString;
  }
};
 


#endif     
