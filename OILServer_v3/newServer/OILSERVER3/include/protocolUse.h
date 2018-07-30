#ifndef __protocolUse_H__   
#define __protocolUse_H__   
#include <string.h>
#include <iostream>
#include <sstream>
#include <time.h> 
#include "dataBaseUse.h"
using namespace std;


//typedef unsigned int Event;
const string LoginEvent = "30";
const string ExitEvent = "31";
const string UpIntervalEvent = "35";
const string UpParamEvent = "3d";
const string OnDataEvent = "43";
const string OffDataEvent = "44";
const string AssistDataEvent = "45";

class protocolUse
{

public:
        void InitTheProtocolModule( DBController theDBCIn );

        void getString(string information);

private:
    
        DBController theDBC;
        int stringCount = 0;
        int saveCounter = 0;
        int saveCounterMax = 10;
        string saveStringUse = "INSERT INTO t_guid(data1,data2,data3,data4,data5,data6,gid,time)values";
        string theSaveString = "INSERT INTO t_guid (data1 , data2 , data3 , data4, data5,  data6, gid, time) values"; 

        //更复杂的协议处理
        void ProtocolOperate(string  information);
    
        //-----------------------------------协议处理--------------------------------------------------//

        int handleLogin(string info);
        int handleExit(string info);
        int handleUpInterval(string info);
        int handleUpParam(string info);
        int handleOnData(string info);
        int handleOffData(string info);
        int handleAssistData(string info);
        void data0x3D(string VID , string PID ,string DID,  string dataIn);
       	void dataUse43(string VID , string PID ,string DID,  string dataIn);
        //----------------------------------------------------------------------------------------//
        //作为示例存在的处理方式
        void saveStringForDemo(string getIn);
        
};

string ASCOperate(string stringIn);
//其实就是输出Log等会再说
void makeLogShow(int type,string theinformation);

//int 转十六进制
string intTo16(int i);
// (十六进制)转int
int toIntValue(const char * IN);

//int 转string
string toString(int In);

//string转float
float stringToFloat(string str);
//string转int
int stringToInt(string str);

int ToIntConvert(string theString);

float ToFloatConvert(string theString, double prec);

float changeToFloat(const char * a,const char * b,const char * c,const char * d);

//字符串切分
string*  stringSplite(string information,char spliteChar);
//获取字符串切分长度
int stringSplitCount(string information , char splitChar);
//获得时间字符串
string getTime();

string CtoString(const char * c);
 


#endif     
