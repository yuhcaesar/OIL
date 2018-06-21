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
    // saveStringForDemo(information);
     ProtocolOperate(information);
  }


  private:
    
    DBController theDBC;
    int stringCount = 0;
    int saveCounter = 0;
    int saveCounterMax = 10;
    string saveStringUse = "INSERT INTO t_guid(data1,data2,data3,data4,data5,data6,gid,time)values";
    string theSaveString = "INSERT INTO t_guid (data1 , data2 , data3 , data4, data5,  data6, gid, time) values"; 

    //更复杂的协议处理
    void ProtocolOperate(string  information)
    {
     int lengthAll =  information.size();
     cout<<"all length = "<<lengthAll<<endl;
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
     //if( operate1 == "31")//如果是上传过来的数据
	{
	     //if(operate2 == "3D")
	     {
	       data0x3D( VID,PID, DID, data);
	     }
	}
    }
    
    //-----------------------------------协议处理--------------------------------------------------//

       void data0x3D(string VID , string PID ,string DID,  string dataIn)
       { 
           int indexNow = 0;
           cout<<dataIn.size()<<" is the size"<<endl;
           for(int i = 0 ; (i+7) < dataIn.size() ; )
           {
                const char *  A = dataIn.substr(i,i+2).c_str();
                i+=2;
                const char *  B = dataIn.substr(i,i+2).c_str();
                i+=2;
                const char *  C = dataIn.substr(i,i+2).c_str();
                i+=2;
                const char *  D = dataIn.substr(i,i+2).c_str();
                i+=2;
                float theFloat = changeToFloat(A,B,C,D);
                cout<<"getFloat "<<theFloat<<" at "<<i<<endl;
           }
       }
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
    //----------------------------------------------------------------------------------------//
    //作为示例存在的处理方式
    void saveStringForDemo(string getIn)
    {
       
       string *  Use = stringSplite(getIn,',');
       string theDataClip = "";
       int checkCount = stringSplitCount(getIn, ',');
       if(checkCount< 7 )
       {
          cout<<"The data is not complete"<<endl;
           return;
       }

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

    //其实就是输出Log等会再说
    void makeLogShow(int type,string theinformation)
    {
           cout<<theinformation<<endl; 
    }


    // char *转int(十六进制)
    int toIntValue(const char * IN)
    {
         int ValueUse = 0;          
         sscanf(IN, "%x", &ValueUse); 
         return  ValueUse ;    
    }
    //int 转string
    string toString(int In)
    {
      return to_string(In);
    }

    //string转float
    float stringToFloat(string str)
   {
     float f=atof(str.c_str());
     return f;
   } 
    //string转int
   int stringToInt(string str)
   {
     float i=atoi(str.c_str());
     return i;
   }  

    float changeToFloat(const char * a,const char * b,const char * c,const char * d)
    {
     int AA = strtoll(a , NULL , 16);
     int BB = strtoll(b , NULL , 16);
     int CC = strtoll(c , NULL , 16);
     int DD = strtoll(d , NULL , 16);
     unsigned char pp[] = {AA,BB,CC,DD};
     float * theFloat = (float *) pp;
     return * theFloat;
    }

    //字符串切分
    string*  stringSplite(string information,char spliteChar)
    {
     int index = 0;
     int countNeed = 0;
     string*  theStringClips;
     string sub_str;

     stringstream ssForCount(information);
     stringstream ss(information);

     while(getline(ssForCount,sub_str,spliteChar)) 
       countNeed ++;
     theStringClips = new  string [countNeed];     
     while(getline(ss,sub_str,spliteChar) && index < countNeed ) 
     {
       theStringClips [index]= sub_str;
       index ++;
      }

    return theStringClips;
   }
   //获取字符串切分长度
   int stringSplitCount(string information , char splitChar)
   {
        int count = 0;
         string sub;
         stringstream S(information);
        while(getline(S,sub,splitChar))
          count++;
        return count;   
   }
   //获得时间字符串
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
