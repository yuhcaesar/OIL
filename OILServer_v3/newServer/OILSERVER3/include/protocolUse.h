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
        //----------------------------------------------------------------------------------------//
        //作为示例存在的处理方式
        void saveStringForDemo(string getIn);
};

void makeLogShow(int type,string theinformation);
int ToIntConvert(string theString);
float ToFloatConvert(string theString, double prec);
string ToStringConvert(string theString);
string CtoString(const char * c);

#endif
