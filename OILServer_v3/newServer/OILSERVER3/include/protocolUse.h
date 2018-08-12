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

const string Header = "21233c3c";
const string Tailer = "3e3e";
const short LenHead = 8;
const short LenTail = 4;
const short LenLength = 4;
const short IdxOp2 = 42;
const short IdxLen_O = 44; // Ordinary package LENTH index
const short IdxLen_D = 46; // Data package LENTH index

class protocolUse
{
public:
        void InitTheProtocolModule( DBController theDBCIn );
        void getString(string information);
private:
        DBController theDBC;
        //更复杂的协议处理
        void ProtocolOperate(string  information);
        int EventHandler(string information);
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
