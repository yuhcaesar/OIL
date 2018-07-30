#include <string.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <time.h>
#include <math.h>
#include <jsoncpp/json/json.h>
#include "protocolUse.h"
#include "dataBaseUse.h"
#include "param.h"
#include "upParam.h"
#include "upInterval.h"
#include "onData.h"
#include "offData.h"

using namespace std;

void protocolUse :: InitTheProtocolModule( DBController theDBCIn )
{
        this->theDBC = theDBCIn;
        makeLogShow(1,"protocoluse is opened");
}

void protocolUse :: getString( string information )
{
        this->ProtocolOperate(information);
}

//更复杂的协议处理
void protocolUse :: ProtocolOperate(string  information)
{
        int lengthAll =  information.size();
        if(lengthAll < 48)
                return;
        cout<<"all length = "<<lengthAll<<endl;
        string head =  information.substr(0,8);
        int headInt = toIntValue(information .substr(0,8).c_str());
        cout<<"head is "<< head<<"  headInt "<< headInt <<endl;
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
	
        int ret = -1;
        if ( operate2 == LoginEvent )
        {
                ret = this->handleLogin(information);                
        }
        else if ( operate2 == ExitEvent )
        {
                ret = this->handleExit(information);
        }
        else if ( operate2 == UpIntervalEvent )
        {
                ret = this->handleUpInterval(information);
        }
        else if ( operate2 == UpParamEvent )
        {
                ret = this->handleUpParam(information);
        }
        else if ( operate2 == OnDataEvent )
        {
                ret = this->handleOnData(information);
        }
        else if ( operate2 == OffDataEvent )
        {
                ret = this->handleOffData(information);
        }
        else if ( operate2 == AssistDataEvent )
        {
                ret = this->handleAssistData(information);
        } 

        if ( ret < 0 ) {
                makeLogShow(4,"handle event failed");
        }
                
/**
   string length = information .substr(44,4);
   cout<<"length is "<<  length << endl;
   string data = information .substr(48,lengthAll-4-48);
   cout<<"data is "<<  data << endl;
   string tail = information .substr(lengthAll-4,4);
   cout<<"tail is "<<  tail << endl;
   //if( operate1 == "31")//如果是上传过来的数据
   //{
   //if(operate2 == "3D")
   {
   data0x3D( VID,PID, DID, data);
   }
   //}
   */
        
}
    
//-----------------------------------协议处理--------------------------------------------------//

int protocolUse :: handleLogin(string info)
{
        Json::Value root;
        root["Header"] = info.substr(0,8);
        root["VID"] = info.substr(8,4);
        root["PID"] = info.substr(12,4);
        root["DID"] = info.substr(16,24);
        root["Operation1"] = info.substr(40,2);
        root["Operation2"] = info.substr(42,2);
        root["Length"] = info.substr(44,4);
        root["Data"] = info.substr(48,12);
        root["Trailer"] = info.substr(60,4);

        cout << root.toStyledString() << endl;
        return 1;
}

int protocolUse :: handleExit(string info)
{
        Json::Value root;
        root["Header"] = info.substr(0,8);
        root["VID"] = info.substr(8,4);
        root["PID"] = info.substr(12,4);
        root["DID"] = info.substr(16,24);
        root["Operation1"] = info.substr(40,2);
        root["Operation2"] = info.substr(42,2);
        root["Length"] = info.substr(44,4);
        root["Data"] = info.substr(44,0);
        root["Trailer"] = info.substr(44,4);

        cout << root.toStyledString() << endl;
        return 1;
}

int protocolUse :: handleUpInterval(string info)
{
        Json::Value root;

        /**
        root["Header"] = info.substr(0, 8);
        root["VID"] = info.substr(8, 4);
        root["PID"] = info.substr(12, 4);
        root["DID"] = info.substr(16, 24);
        root["Operation1"] = info.substr(40, 2);
        root["Operation2"] = info.substr(42, 2);
        root["Length"] = info.substr(44,4);
        root["Data"]["raw"] = info.substr(48, 34);
        root["Data"]["Data1"] = info.substr(48, 4);
        root["Data"]["Data2"] = info.substr(52, 2);
        root["Data"]["Data3"] = info.substr(54, 2);
        root["Data"]["Data4"] = info.substr(56, 2);
        root["Data"]["Data5"] = info.substr(58, 2);
        root["Data"]["Data6"] = info.substr(60, 4);
        root["Data"]["Data7"] = info.substr(64, 2);
        root["Data"]["Data8"] = info.substr(66, 2);
        root["Data"]["Data9"] = info.substr(68, 4);
        root["Data"]["Data10"] = info.substr(72, 4);
        root["Data"]["Data11"] = info.substr(76, 2);
        root["Data"]["Data12"] = info.substr(78, 2);
        root["Data"]["Data13"] = info.substr(80, 2);
        root["Trailer"] = info.substr(82, 4);
        */
        
        CParam* param = CParam::GetInstance();
        root["Header"] = info.substr(UP_INTERVAL_HEADER);
        root["VID"] = info.substr(UP_INTERVAL_VID);
        root["PID"] = info.substr(UP_INTERVAL_PID);
        root["DID"] = info.substr(UP_INTERVAL_DID);
        root["Operation1"] = info.substr(UP_INTERVAL_OPERATION1);
        root["Operation2"] = info.substr(UP_INTERVAL_OPERATION2);
        root["Length"] = info.substr(UP_INTERVAL_LENGTH);
        root["Trailer"] = info.substr(UP_INTERVAL_TRAILER(info.size()));

        int tmpData = 0;
        tmpData = ToIntConvert(info.substr(UP_INTERVAL_DATA01).c_str());
        root["Data"]["Data01"] = to_string(tmpData);
        param->setOnSampleInterval(tmpData);
        root["Parameters"]["OnlineSampleInterval"] = to_string(param->getOnSampleInterval());

        tmpData = ToIntConvert(info.substr(UP_INTERVAL_DATA02).c_str());
        root["Data"]["Data02"] = to_string(tmpData);
        param->setOffSampleInterval(tmpData);
        root["Parameters"]["OfflineSampleInterval"] = to_string(param->getOffSampleInterval());

        tmpData = ToIntConvert(info.substr(UP_INTERVAL_DATA03).c_str());
        root["Data"]["Data03"] = to_string(tmpData * 100);
        param->setOffLatency(tmpData);
        root["Parameters"]["OfflineSampleLantency"] = to_string(param->getOffLatency());

        tmpData = ToIntConvert(info.substr(UP_INTERVAL_DATA04).c_str());
        root["Data"]["Data04"] = to_string(tmpData * 100);
        param->setDepolInterval(tmpData);
        root["Parameters"]["DepolarizationInterval"] = to_string(param->getDepolInterval());
        
        tmpData = ToIntConvert(info.substr(UP_INTERVAL_DATA05).c_str());
        root["Data"]["Data05"] = to_string(tmpData);
        param->setPolInterval(tmpData);
        root["Parameters"]["PolarizationInterval"] = to_string(param->getPolInterval());

        tmpData = ToIntConvert(info.substr(UP_INTERVAL_DATA06).c_str());
        root["Data"]["Data06"] = to_string(tmpData);
        param->setAsynInterval(tmpData);
        root["Parameters"]["AsynInterval"] = to_string(param->getAsynInterval());

        tmpData = ToIntConvert(info.substr(UP_INTERVAL_DATA07).c_str());
        root["Data"]["Data07"] = to_string(tmpData);
        param->setAssiInterval(tmpData);
        root["Parameters"]["AssistInterval"] = to_string(param->getAssiInterval());

        tmpData = ToIntConvert(info.substr(UP_INTERVAL_DATA08).c_str());
        root["Data"]["Data08"] = to_string(tmpData);
        param->setStabCount(tmpData);
        root["Parameters"]["StableCount"] = to_string(param->getStabCount());

        tmpData = ToIntConvert(info.substr(UP_INTERVAL_DATA09).c_str());
        root["Data"]["Data09"] = to_string(tmpData);
        param->setStabErr(tmpData);
        root["Parameters"]["StableError"] = to_string(param->getStabErr());
        
        tmpData = ToIntConvert(info.substr(UP_INTERVAL_DATA10).c_str());
        root["Data"]["Data10"] = to_string(tmpData * -1);
        param->setTiggThreshold(tmpData);
        root["Parameters"]["TiggerThreshold"] = to_string(param->getTiggThreshold());

        tmpData = ToIntConvert(info.substr(UP_INTERVAL_DATA11).c_str());
        root["Data"]["Data11"] = to_string(tmpData);
        param->setOnMeasureOpt(tmpData);
        root["Parameters"]["OnlineMeasureOption"] = to_string(param->getOffMeasureOpt());

        tmpData = ToIntConvert(info.substr(UP_INTERVAL_DATA12).c_str());
        root["Data"]["Data12"] = to_string(tmpData);
        param->setOffMeasureOpt(tmpData);
        root["Parameters"]["OfflineMeasureOption"] = to_string(param->getOffMeasureOpt());

        tmpData = ToIntConvert(info.substr(UP_INTERVAL_DATA12).c_str());
        root["Data"]["Data12"] = to_string(tmpData);
        param->setRangeOpt(tmpData);
        root["Parameters"]["RangeOption"] = to_string(param->getRangeOpt());

        cout << root.toStyledString() << endl;
        
        Json :: StyledWriter sw;
        ofstream os;
        os.open("UpParam.json");
        os << sw.write(root);
        os.close();
        
        return 1;
}



int protocolUse :: handleUpParam(string info)
{

        Json::Value root;
        
        CParam* param = CParam::GetInstance();
        root["Header"] = info.substr(UP_PARAM_HEADER);
        root["VID"] = info.substr(UP_PARAM_VID);
        root["PID"] = info.substr(UP_PARAM_PID);
        root["DID"] = info.substr(UP_PARAM_DID);
        root["Operation1"] = info.substr(UP_PARAM_OPERATION1);
        root["Operation2"] = info.substr(UP_PARAM_OPERATION2);
        root["Length"] = info.substr(UP_PARAM_LENGTH);
        
        root["Trailer"] = info.substr(UP_PARAM_TRAILER(info.size()));

        float tmpData = 0;
        tmpData = ToFloatConvert(info.substr(UP_PARAM_DATA01).c_str(), 2.0);
        root["Data"]["Data01"] = to_string(tmpData).substr(0, 6);
        param->setDcPotentialK(tmpData);
        root["Parameters"]["DcPotentialK"] = to_string(param->getDcPotentialK()).substr(0, 6);

        tmpData = ToFloatConvert(info.substr(UP_PARAM_DATA02).c_str(), 2.0);
        root["Data"]["Data02"] = to_string(tmpData).substr(0, 6);
        param->setDcPotentialB(tmpData);
        root["Parameters"]["DcPotentialB"] = to_string(param->getDcPotentialB()).substr(0, 6);

        tmpData = ToFloatConvert(info.substr(UP_PARAM_DATA03).c_str(), 2.0);
        root["Data"]["Data03"] = to_string(tmpData).substr(0, 6);
        param->setAcPotentialK(tmpData);
        root["Parameters"]["AcPotentialK"] = to_string(param->getAcPotentialK()).substr(0, 6);

        tmpData = ToFloatConvert(info.substr(UP_PARAM_DATA04).c_str(), 2.0);
        root["Data"]["Data04"] = to_string(tmpData).substr(0, 6);
        param->setAcPotentialB(tmpData);
        root["Parameters"]["AcPotentialB"] = to_string(param->getAcPotentialB()).substr(0, 6);

        
        tmpData = ToFloatConvert(info.substr(UP_PARAM_DATA05).c_str(), 2.0);
        root["Data"]["Data05"] = to_string(tmpData).substr(0, 6);
        param->setAcHiCurrentK(tmpData);
        root["Parameters"]["AcHiCurrentK"] = to_string(param->getAcHiCurrentK()).substr(0, 6);

        tmpData = ToFloatConvert(info.substr(UP_PARAM_DATA06).c_str(), 2.0);
        root["Data"]["Data06"] = to_string(tmpData).substr(0, 6);
        param->setAcHiCurrentB(tmpData);
        root["Parameters"]["AcHiCurrentB"] = to_string(param->getAcHiCurrentB()).substr(0, 6);

        tmpData = ToFloatConvert(info.substr(UP_PARAM_DATA07).c_str(), 2.0);
        root["Data"]["Data07"] = to_string(tmpData).substr(0, 6);
        param->setDcHiCurrentK(tmpData);
        root["Parameters"]["DcHiCurrentK"] = to_string(param->getDcHiCurrentK()).substr(0, 6);

        tmpData = ToFloatConvert(info.substr(UP_PARAM_DATA08).c_str(), 2.0);
        root["Data"]["Data08"] = to_string(tmpData).substr(0, 6);
        param->setDcHiCurrentB(tmpData);
        root["Parameters"]["DcHiCurrentB"] = to_string(param->getDcHiCurrentB()).substr(0, 6);

        tmpData = ToFloatConvert(info.substr(UP_PARAM_DATA09).c_str(), 2.0);
        root["Data"]["Data09"] = to_string(tmpData).substr(0, 6);
        param->setAcLoCurrentK(tmpData);
        root["Parameters"]["AcLoCurrentK"] = to_string(param->getAcLoCurrentK()).substr(0, 6);
        
        tmpData = ToFloatConvert(info.substr(UP_PARAM_DATA10).c_str(), 2.0);
        root["Data"]["Data10"] = to_string(tmpData).substr(0, 6);
        param->setAcLoCurrentB(tmpData);
        root["Parameters"]["AcLoCurrentB"] = to_string(param->getAcLoCurrentB()).substr(0, 6);

        tmpData = ToFloatConvert(info.substr(UP_PARAM_DATA11).c_str(), 2.0);
        root["Data"]["Data11"] = to_string(tmpData).substr(0, 6);
        param->setDcLoCurrentK(tmpData);
        root["Parameters"]["DcLoCurrentK"] = to_string(param->getDcLoCurrentK()).substr(0, 6);

        tmpData = ToFloatConvert(info.substr(UP_PARAM_DATA12).c_str(), 2.0);
        root["Data"]["Data12"] = to_string(tmpData).substr(0, 6);
        param->setDcLoCurrentB(tmpData);
        root["Parameters"]["DcLoCurrentB"] = to_string(param->getDcLoCurrentB()).substr(0, 6);

        cout << root.toStyledString() << endl;
        
        Json :: StyledWriter sw;
        ofstream os;
        os.open("UpInterval.json");
        os << sw.write(root);
        os.close();
        
        return 1;
}

int protocolUse :: handleOnData(string info)
{
        Json::Value root;
/*
        root["Header"] = info.substr(0, 8);
        root["VID"] = info.substr(8, 4);
        root["PID"] = info.substr(12, 4);
        root["DID"] = info.substr(16, 24);
        root["Operation1"] = info.substr(40, 2);
        root["Operation2"] = info.substr(42, 2);
        root["Operation3"] = info.substr(44, 2);
        root["Length"] = info.substr(44,4);
        root["Data"]["raw"] = info.substr(48, info.size()-52);
        root["Data"]["Data01"] = info.substr(48, 2);
        root["Data"]["Data02"] = info.substr(50, 2);
        root["Data"]["Data03"] = info.substr(52, 2);
        root["Data"]["Data04"] = info.substr(54, 4);
        root["Data"]["Data05"] = info.substr(58, 4);
        root["Data"]["Data06"] = info.substr(62, 4);
        root["Data"]["Data07"] = info.substr(66, 4);
        root["Data"]["Data08"] = info.substr(70, 4);
        root["Data"]["Data09"] = info.substr(74, 4);
        root["Data"]["Data10"] = info.substr(78, 4);
        root["Data"]["Data11"] = info.substr(82, 4);
        
        root["Trailer"] = info.substr(info.size()-4, 4);
*/
        root["Header"] = info.substr(ON_DATA_HEADER);
        root["VID"] = info.substr(ON_DATA_VID);
        root["PID"] = info.substr(ON_DATA_PID);
        root["DID"] = info.substr(ON_DATA_DID);
        root["Operation1"] = info.substr(ON_DATA_OPERATION1);
        root["Operation2"] = info.substr(ON_DATA_OPERATION2);
        root["Operation3"] = info.substr(ON_DATA_OPERATION3);
        root["Length"] = info.substr(ON_DATA_LENGTH);

        int length = ToIntConvert(info.substr(ON_DATA_LENGTH));
        printf("length%d\n", length);
	printf("info.size:%d\n", info.size());
        int tmp = 0;
        char timeBuf[255] = {0};
        struct tm *tm_time = (struct tm*)malloc(sizeof(struct tm));
        time_t timer = time(NULL);       
        string time = "";
        CParam * param = CParam::GetInstance();
        
        strftime(timeBuf, sizeof(timeBuf), "%Y-%m-%d ", gmtime(&timer));

        tmp = ToIntConvert(info.substr(ON_DATA_DATA01));
        root["Data"]["Data01"] = info.substr(ON_DATA_DATA01);
        time += (to_string(tmp)+":");
        tmp = ToIntConvert(info.substr(ON_DATA_DATA02));
        root["Data"]["Data02"] = info.substr(ON_DATA_DATA02);
        time += (to_string(tmp)+":");
        tmp = ToIntConvert(info.substr(ON_DATA_DATA03));
        root["Data"]["Data03"] = info.substr(ON_DATA_DATA03);
        time += (to_string(tmp));

        strcat(timeBuf, time.c_str());
        strptime(timeBuf, "%Y-%m-%d %H:%M:%S", tm_time);
        time_t tt = mktime(tm_time);
        printf("%d:%s\n", (int)tt, timeBuf);

        length = info.size() - 56 - 4;
        printf("real len:%d\n", length);
        if ( param->getOnMeasureOpt() == 0x1 )
        {
                int batchNum = 4;
                int batch = 4;
                int index = 4;
                string sIndex = "";
                string dName = "";
                for ( int i = 0; i < (length / batchNum / batch); i++ ) {
                        root["Spot"]["Points"+to_string(i)]["UTC"] = CtoString(timeBuf);
                        for ( int j = 0; j < batchNum; j++ ) {
                                index = 4 + i * batchNum + j;
                                //sIndex = (index<10)?"Data0"+to_string(index):"Data"+to_string(index);
                                root["Data"]["Data"+to_string(index)] = info.substr(ON_DATA_DATA_(index));
                                switch(j)
                                {
                                case 0:
                                        dName = "0_DcPotential";
                                        break;
                                case 1:
                                        dName = "1_AcPotential";
                                        break;
                                case 2:
                                        dName = "2_DcCurrent";
                                        break;
                                case 3:
                                        dName = "3_AcCurrent";
                                        break;
                                }
                                root["Spot"]["Points"+to_string(i)][dName] = info.substr(ON_DATA_DATA_(index));
                        }
                        tt += param->getOnSampleInterval();
                        strftime(timeBuf, sizeof(timeBuf), "%Y-%m-%d %H:%M:%S", gmtime(&tt));
                }
        }
        else if ( param->getOnMeasureOpt() == 0x2 )
        {
                int batchNum = 2;
                int batch = 4;
                int index = 4;
                string sIndex = "";
                string dName = "";
                for ( int i = 0; i < (length / batchNum / batch); i++ ) {
                        root["Spot"]["Points"+to_string(i)]["UTC"] = CtoString(timeBuf);
                        for ( int j = 0; j < batchNum; j++ ) {
                                index = 4 + i * batchNum + j;
                                root["Data"]["Data"+to_string(index)] = info.substr(ON_DATA_DATA_(index));
                                switch(j)
                                {
                                case 0:
                                        dName = "2_DcCurrent";
                                        break;
                                case 1:
                                        dName = "3_AcCurrent";
                                        break;
                                }
                                
                                root["Spot"]["Points"+to_string(i)][dName] = info.substr(ON_DATA_DATA_(index));                     
           
                        }
                        tt += param->getOnSampleInterval();
                        strftime(timeBuf, sizeof(timeBuf), "%Y-%m-%d %H:%M:%S", gmtime(&tt));
                }
        }
        else if ( param->getOnMeasureOpt() == 0x3 )
        {
                int batchNum = 2;
                int batch = 4;
                int index = 4;
                string sIndex = "";
                string dName = "";
                for ( int i = 0; i < (length / batchNum / batch); i++ ) {
                        root["Spot"]["Points"+to_string(i)]["UTC"] = CtoString(timeBuf);
                        for ( int j = 0; j < batchNum; j++ ) {
                                index = 4 + i * batchNum + j;
                                root["Data"]["Data"+to_string(index)] = info.substr(ON_DATA_DATA_(index));
                                switch(j)
                                {
                                case 0:
                                        dName = "0_DcPotential";
                                        break;
                                case 1:
                                        dName = "1_AcPotential";
                                        break;
                                }
                                
                                root["Spot"]["Points"+to_string(i)][dName] = info.substr(ON_DATA_DATA_(index));                     
                        }
                        tt += param->getOnSampleInterval();
                        strftime(timeBuf, sizeof(timeBuf), "%Y-%m-%d %H:%M:%S", gmtime(&tt));
                }
        }
        
        
        cout << root.toStyledString() << endl;
        return 1;
}

int protocolUse :: handleOffData(string info)
{
        Json::Value root;
/*
        root["Header"] = info.substr(0, 8);
        root["VID"] = info.substr(8, 4);
        root["PID"] = info.substr(12, 4);
        root["DID"] = info.substr(16, 24);
        root["Operation1"] = info.substr(40, 2);
        root["Operation2"] = info.substr(42, 2);
        root["Length"] = info.substr(44,4);
        root["Data"]["raw"] = info.substr(48, 48);
        root["Data"]["Data1"] = info.substr(48, 8);
        root["Data"]["Data2"] = info.substr(56, 8);
        root["Data"]["Data3"] = info.substr(64, 8);
        root["Data"]["Data4"] = info.substr(72, 8);
        root["Data"]["Data5"] = info.substr(80, 8);
        root["Data"]["Data6"] = info.substr(88, 8);
        root["Data"]["Data7"] = info.substr(96, 8);
        root["Data"]["Data8"] = info.substr(104, 8);
        root["Data"]["Data9"] = info.substr(112, 8);
        root["Data"]["Data10"] = info.substr(120, 8);
        root["Data"]["Data11"] = info.substr(128, 8);
        root["Data"]["Data12"] = info.substr(136, 8);
        root["Trailer"] = info.substr(144, 4);
*/
        
        cout << root.toStyledString() << endl;
        return 1;
}

int protocolUse :: handleAssistData(string info)
{
        Json::Value root;
        root["Header"] = info.substr(0, 8);
        root["VID"] = info.substr(8, 4);
        root["PID"] = info.substr(12, 4);
        root["DID"] = info.substr(16, 24);
        root["Operation1"] = info.substr(40, 2);
        root["Operation2"] = info.substr(42, 2);
        root["Length"] = info.substr(44,4);
        root["Data"]["raw"] = info.substr(48, 48);
        root["Data"]["Data1"] = info.substr(48, 8);
        root["Data"]["Data2"] = info.substr(56, 8);
        root["Data"]["Data3"] = info.substr(64, 8);
        root["Data"]["Data4"] = info.substr(72, 8);
        root["Data"]["Data5"] = info.substr(80, 8);
        root["Data"]["Data6"] = info.substr(88, 8);
        root["Data"]["Data7"] = info.substr(96, 8);
        root["Data"]["Data8"] = info.substr(104, 8);
        root["Data"]["Data9"] = info.substr(112, 8);
        root["Data"]["Data10"] = info.substr(120, 8);
        root["Data"]["Data11"] = info.substr(128, 8);
        root["Data"]["Data12"] = info.substr(136, 8);
        root["Trailer"] = info.substr(144, 4);

        cout << root.toStyledString() << endl;
        return 1;
}

void protocolUse :: data0x3D(string VID , string PID ,string DID,  string dataIn)
{ 
        int indexNow = 0;
        cout<<dataIn.size()<<" is the size"<<endl;
        for(int i = 0 ; (i+7) < dataIn.size() ; )
        {
                string subString = dataIn.substr(i,i+8).c_str();
                i+=8;
                float theFloat2 = ToFloatConvert(subString, 2.0);
                cout<<"getFloat "<<theFloat2<<" at "<<i<<endl;
        }
}
void protocolUse :: dataUse43(string VID , string PID ,string DID,  string dataIn)
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
void protocolUse :: saveStringForDemo(string getIn)
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

//int 转十六进制
string intTo16(int i)
{
        char str[100];
        sprintf(str,"0x%x" ,i);
        return str;
}
// (十六进制)转int
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

int ToIntConvert(string theString)
{
        
        const char* E = theString.c_str();
        int n = 0;
        sscanf(E, "%x", &n);

        return n;
}
                                                                                          
float ToFloatConvert(string theString, double prec)
{
        if(theString.size()!=8)
                return 0;
     
        string A = theString.substr(0,2);
        string B = theString.substr(2,2);
        string C = theString.substr(4,2);
        string D = theString.substr(6,2);
        string vert = D+C+B+A;
        //vert = A+B +C+D;
        
        const char * E = vert.c_str();
        //printf("E:%s\n",E);
        unsigned int n = 0;
        sscanf(E, "%x", &n);
        
        float theFloat = *((float*)&n);
        
        float intergerPart =  floor(theFloat);
        theFloat -= intergerPart;
        theFloat = intergerPart + ( floor(theFloat * pow(10.0, prec) + 0.5) / pow(10.0, prec) );
        return theFloat;
}

float changeToFloat(const char * a,const char * b,const char * c,const char * d)
{
        //正向
        int AA = strtoll(a , NULL , 16);
        int BB = strtoll(b , NULL , 16);
        int CC = strtoll(c , NULL , 16);
        int DD = strtoll(d , NULL , 16);
        unsigned char pp[] = {AA,BB,CC,DD};
        float * theFloat = (float *) pp;
        unsigned char pp2[] = {DD,CC,BB , AA};
        float * theFloat2 = (float *) pp2;
     
        float A = * theFloat;
        float B = * theFloat2;

        //cout<<A;
        //cout<<"---------"<<endl;
        //cout<<B;
        //cout<<"---------"<<endl;
        return A;
}

//字符串切分
string* stringSplite(string information,char spliteChar)
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

//ASCii转字符串
//deprecated fuction
string ASCOperate(string stringIn)
{
        string out = "";
        for(int i =0 ; i < stringIn.size() ; i ++)
        {
                int ValueUse = stringIn[i];
                //Out +=Tostring(Valueuse);
                out += intTo16(ValueUse).substr(2,2);
        }
        cout<<"theTrueString = "<<out<<endl;
        return out;
}

string CtoString(const char * c)
{
        string ret(c);
        return ret;
}
