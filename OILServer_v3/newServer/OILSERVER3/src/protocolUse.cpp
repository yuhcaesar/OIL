#include <string.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <time.h>
#include <math.h>
#include <iomanip>
#include <jsoncpp/json/json.h>
#include "protocolUse.h"
#include "dataBaseUse.h"
#include "param.h"
#include "upParam.h"
#include "upInterval.h"
#include "onData.h"
#include "offData.h"
#include "assistData.h"

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
    int ret = -1;
    string operate2 = information.substr(42,2);
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

    Json :: StyledWriter sw;
    ofstream os;
    os.open("./json/Login.json");
    os << sw.write(root);
    os.close();
    

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
    root["Data"] = info.substr(48,0);
    root["Trailer"] = info.substr(48,4);

    cout << root.toStyledString() << endl;

    Json :: StyledWriter sw;
    ofstream os;
    os.open("./json/Exit.json");
    os << sw.write(root);
    os.close();

    return 1;
}

int protocolUse :: handleUpInterval(string info)
{
    Json::Value root;

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
    os.open("./json/UpParam.json");
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
    tmpData = ToFloatConvert(info.substr(UP_PARAM_DATA01), 2.0);
    root["Data"]["Data01"] = info.substr(UP_PARAM_DATA01);
    param->setDcPotentialK(tmpData);
    root["Parameters"]["DcPotentialK"] = param->getDcPotentialK();

    tmpData = ToFloatConvert(info.substr(UP_PARAM_DATA02), 2.0);
    root["Data"]["Data02"] = info.substr(UP_PARAM_DATA02);
    param->setDcPotentialB(tmpData);
    root["Parameters"]["DcPotentialB"] = param->getDcPotentialB();

    tmpData = ToFloatConvert(info.substr(UP_PARAM_DATA03), 2.0);
    root["Data"]["Data03"] = info.substr(UP_PARAM_DATA03);
    param->setAcPotentialK(tmpData);
    root["Parameters"]["AcPotentialK"] = param->getAcPotentialK();

    tmpData = ToFloatConvert(info.substr(UP_PARAM_DATA04), 2.0);
    root["Data"]["Data04"] = info.substr(UP_PARAM_DATA04);
    param->setAcPotentialB(tmpData);
    root["Parameters"]["AcPotentialB"] = param->getAcPotentialB();

        
    tmpData = ToFloatConvert(info.substr(UP_PARAM_DATA05), 2.0);
    root["Data"]["Data05"] = info.substr(UP_PARAM_DATA05);
    param->setAcHiCurrentK(tmpData);
    root["Parameters"]["AcHiCurrentK"] = param->getAcHiCurrentK();

    tmpData = ToFloatConvert(info.substr(UP_PARAM_DATA06), 2.0);
    root["Data"]["Data06"] = info.substr(UP_PARAM_DATA06);
    param->setAcHiCurrentB(tmpData);
    root["Parameters"]["AcHiCurrentB"] = param->getAcHiCurrentB();

    tmpData = ToFloatConvert(info.substr(UP_PARAM_DATA07), 2.0);
    root["Data"]["Data07"] = info.substr(UP_PARAM_DATA07);
    param->setDcHiCurrentK(tmpData);
    root["Parameters"]["DcHiCurrentK"] = param->getDcHiCurrentK();

    tmpData = ToFloatConvert(info.substr(UP_PARAM_DATA08), 2.0);
    root["Data"]["Data08"] = info.substr(UP_PARAM_DATA08);
    param->setDcHiCurrentB(tmpData);
    root["Parameters"]["DcHiCurrentB"] = param->getDcHiCurrentB();

    tmpData = ToFloatConvert(info.substr(UP_PARAM_DATA09), 2.0);
    root["Data"]["Data09"] = info.substr(UP_PARAM_DATA09);
    param->setAcLoCurrentK(tmpData);
    root["Parameters"]["AcLoCurrentK"] = param->getAcLoCurrentK();
        
    tmpData = ToFloatConvert(info.substr(UP_PARAM_DATA10), 2.0);
    root["Data"]["Data10"] = info.substr(UP_PARAM_DATA10);
    param->setAcLoCurrentB(tmpData);
    root["Parameters"]["AcLoCurrentB"] = param->getAcLoCurrentB();

    tmpData = ToFloatConvert(info.substr(UP_PARAM_DATA11), 2.0);
    root["Data"]["Data11"] = info.substr(UP_PARAM_DATA11);
    param->setDcLoCurrentK(tmpData);
    root["Parameters"]["DcLoCurrentK"] = param->getDcLoCurrentK();

    tmpData = ToFloatConvert(info.substr(UP_PARAM_DATA12), 2.0);
    root["Data"]["Data12"] = info.substr(UP_PARAM_DATA12);
    param->setDcLoCurrentB(tmpData);
    root["Parameters"]["DcLoCurrentB"] = param->getDcLoCurrentB();

    cout << root.toStyledString() << endl;
        
    Json :: StyledWriter sw;
    ofstream os;
    os.open("./json/UpInterval.json");
    os << sw.write(root);
    os.close();
        
    return 1;
}

int protocolUse :: handleOnData(string info)
{
    Json::Value root;
    root["Header"] = info.substr(ON_DATA_HEADER);
    root["VID"] = info.substr(ON_DATA_VID);
    root["PID"] = info.substr(ON_DATA_PID);
    root["DID"] = info.substr(ON_DATA_DID);
    root["Operation1"] = info.substr(ON_DATA_OPERATION1);
    root["Operation2"] = info.substr(ON_DATA_OPERATION2);
    root["Operation3"] = info.substr(ON_DATA_OPERATION3);
    root["Length"] = info.substr(ON_DATA_LENGTH);
    root["Tailer"] = info.substr(ON_DATA_TAILER(info.size()));
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
    tt += 8 * 3600;
    strftime(timeBuf, sizeof(timeBuf), "%Y-%m-%d %H:%M:%S", localtime(&tt));
    length = info.size() - 56 - 4;
    printf("real len:%d\n", length);
    int batchNum = 4;
    int batch = 4;
    int index = 4;
    string sIndex = "";
    string dName = "";
    float result;
    int datum;

    if ( param->getOnMeasureOpt() == 0x1 )
    {
        batchNum = 4;
        batch = 4;
        index = 4;
        for ( int i = 0; i < (length / batchNum / batch); i++ ) {
            root["Spot"]["Points_"+to_string(i)]["Time"] = CtoString(timeBuf);
            for ( int j = 0; j < batchNum; j++ ) {
                index = 4 + i * batchNum + j;
                //sIndex = (index<10)?"Data0"+to_string(index):"Data"+to_string(index);
                datum = ToIntConvert(info.substr(ON_DATA_DATA_(index)));
                //root["Data"]["Data"+to_string(index)] = info.substr(ON_DATA_DATA_(index));
                switch(j)
                {
                case 0:
                    dName = "0_DcPotential";
                    result = 0 - datum * param->getDcPotentialK() - param->getDcPotentialB();
                    break;
                case 1:
                    dName = "1_AcPotential";
                    result = datum * param->getAcPotentialK() + param->getAcPotentialB();
                    break;
                case 2:
                    if ( param->getRangeOpt() == 1 )
                        result = datum * param->getDcHiCurrentK() + param->getDcHiCurrentB();
                    else
                        result = datum * param->getDcLoCurrentK() + param->getDcLoCurrentB();
                    dName = "2_DcCurrent";
                    break;
                case 3:
                    if ( param->getRangeOpt() == 1 )
                        result = datum * param->getAcHiCurrentK() + param->getAcHiCurrentB();
                    else
                        result = datum * param->getAcLoCurrentK() + param->getAcLoCurrentB();
                    dName = "3_AcCurrent";
                    break;
                }
                //root["Spot"]["Points_"+to_string(i)][dName+"_r"] = ToIntConvert(info.substr(ON_DATA_DATA_(index)));
                root["Spot"]["Points_"+to_string(i)][dName] = result;
                tt += param->getOnSampleInterval();
                strftime(timeBuf, sizeof(timeBuf), "%Y-%m-%d %H:%M:%S", gmtime(&tt));
            }
        }
    }
    else if ( param->getOnMeasureOpt() == 0x2 )
    {
        batchNum = 2;
        batch = 4;
        index = 4;
        for ( int i = 0; i < (length / batchNum / batch); i++ ) {
            root["Spot"]["Points_"+to_string(i)]["Time"] = CtoString(timeBuf);
            for ( int j = 0; j < batchNum; j++ ) {
                index = 4 + i * batchNum + j;
                datum = ToIntConvert(info.substr(ON_DATA_DATA_(index)));
                //root["Data"]["Data"+to_string(index)] = datum;
                switch(j)
                {
                case 0:
                    if ( param->getRangeOpt() == 1 )
                        result = datum * param->getDcHiCurrentK() + param->getDcHiCurrentB();
                    else
                        result = datum * param->getDcLoCurrentK() + param->getDcLoCurrentB();
                    dName = "2_DcCurrent";
                    break;
                case 1:
                    if ( param->getRangeOpt() == 1 )
                        result = datum * param->getAcHiCurrentK() + param->getAcHiCurrentB();
                    else
                        result = datum * param->getAcLoCurrentK() + param->getAcLoCurrentB();
                    dName = "3_AcCurrent";
                    break;
                }
                root["Spot"]["Points_"+to_string(i)][dName] = ToIntConvert(info.substr(ON_DATA_DATA_(index)));
            }
            root["Spot"]["Points_"+to_string(i)]["0_DcPotential"] = 0;
            root["Spot"]["Points_"+to_string(i)]["1_AcPotential"] = 0;
            tt += param->getOnSampleInterval();
            strftime(timeBuf, sizeof(timeBuf), "%Y-%m-%d %H:%M:%S", gmtime(&tt));
        }
    }
    else if ( param->getOnMeasureOpt() == 0x3 )
    {
        batchNum = 2;
        batch = 4;
        index = 4;
        for ( int i = 0; i < (length / batchNum / batch); i++ ) {
            root["Spot"]["Points_"+to_string(i)]["Time"] = CtoString(timeBuf);
            for ( int j = 0; j < batchNum; j++ ) {
                index = 4 + i * batchNum + j;
                datum = ToIntConvert(info.substr(ON_DATA_DATA_(index)));
                //root["Data"]["Data"+to_string(index)] = info.substr(ON_DATA_DATA_(index));
                switch(j)
                {
                case 0:
                    result = 0 - datum * param->getDcPotentialK() - param->getDcPotentialB();
                    dName = "0_DcPotential";
                    break;
                case 1:
                    result = datum * param->getAcPotentialK() + param->getAcPotentialB();
                    dName = "1_AcPotential";
                    break;
                }
                root["Spot"]["Points_"+to_string(i)][dName] = ToIntConvert(info.substr(ON_DATA_DATA_(index)));
            }
            root["Spot"]["Points_"+to_string(i)]["2_DcCurrent"] = 0;
            root["Spot"]["Points_"+to_string(i)]["3_AcCurent"] = 0;
            tt += param->getOnSampleInterval();
            strftime(timeBuf, sizeof(timeBuf), "%Y-%m-%d %H:%M:%S", gmtime(&tt));
        }
    }


    cout << root.toStyledString() << endl;
    for ( int i = 0; i < (length / batchNum / batch); i++ ) {
        stringstream ss;
        ss << fixed << setprecision(2);
        ss << "INSERT INTO `t_guid` VALUES ( NULL, '" << root["Spot"]["Points_"+to_string(i)]["0_DcPotential"].asFloat()  << "', '" <<root["Spot"]["Points_"+to_string(i)]["1_AcPotential"].asFloat()  << "', '" << root["Spot"]["Points_"+to_string(i)]["2_DcCurrent"].asFloat()  << "', '" << root["Spot"]["Points_"+to_string(i)]["3_AcCurrent"].asFloat() <<"', '0.00', '0.00', '" << info.substr(ON_DATA_PID) << "', '" << root["Spot"]["Points_"+to_string(i)]["Time"].asString() << "');" << endl;
        cout << ss.str();
        this->theDBC.DBQuery(ss.str());

    }

    Json :: StyledWriter sw;
    ofstream os;
    os.open("./json/OnData_"+time+".json");
    os << sw.write(root);
    os.close();
    return 1;
}

int protocolUse :: handleOffData(string info)
{
    Json::Value root;

    root["Header"] = info.substr(OFF_DATA_HEADER);
    root["VID"] = info.substr(OFF_DATA_VID);
    root["PID"] = info.substr(OFF_DATA_PID);
    root["DID"] = info.substr(OFF_DATA_DID);
    root["Operation1"] = info.substr(OFF_DATA_OPERATIOFF1);
    root["Operation2"] = info.substr(OFF_DATA_OPERATIOFF2);
    root["Operation3"] = info.substr(OFF_DATA_OPERATIOFF3);
    root["Length"] = info.substr(OFF_DATA_LENGTH);

    int length = ToIntConvert(info.substr(OFF_DATA_LENGTH));
    printf("length%d\n", length);
    printf("info.size:%d\n", info.size());
    int tmp = 0;
    char timeBuf[255] = {0};
    struct tm *tm_time = (struct tm*)malloc(sizeof(struct tm));
    time_t timer = time(NULL);       
    string time = "";
    CParam * param = CParam::GetInstance();
        
    strftime(timeBuf, sizeof(timeBuf), "%Y-%m-%d ", gmtime(&timer));

    tmp = ToIntConvert(info.substr(OFF_DATA_DATA01));
    root["Data"]["Data01"] = info.substr(OFF_DATA_DATA01);
    time += (to_string(tmp)+":");
    tmp = ToIntConvert(info.substr(OFF_DATA_DATA02));
    root["Data"]["Data02"] = info.substr(OFF_DATA_DATA02);
    time += (to_string(tmp)+":");
    tmp = ToIntConvert(info.substr(OFF_DATA_DATA03));
    root["Data"]["Data03"] = info.substr(OFF_DATA_DATA03);
    time += (to_string(tmp));

    strcat(timeBuf, time.c_str());
    strptime(timeBuf, "%Y-%m-%d %H:%M:%S", tm_time);
    time_t tt = mktime(tm_time);
    printf("%d:%s\n", (int)tt, timeBuf);

    length = info.size() - 56 - 4;
    printf("real len:%d\n", length);
    if ( param->getOffMeasureOpt() == 0x1 )
    {
        int batchNum = 1;
        int batch = 4;
        int index = 4;
        string sIndex = "";
        string dName = "";
        int datum;
        float result;

        for ( int i = 0; i < (length / batchNum / batch); i++ ) {
            root["Spot"]["Points_"+to_string(i)]["Time"] = CtoString(timeBuf);
            for ( int j = 0; j < batchNum; j++ ) {
                index = 4 + i * batchNum + j;
                //sIndex = (index<10)?"Data0"+to_string(index):"Data"+to_string(index);
                //root["Data"]["Data"+to_string(index)] = info.substr(OFF_DATA_DATA_(index));
                datum = ToIntConvert(info.substr(OFF_DATA_DATA_(index)));
                switch(j)
                {
                case 0:
                    dName = "0_DcPotential";
                    result = 0 - datum * param->getDcPotentialK() - param->getDcPotentialB();
                    break;
                }
                root["Spot"]["Points_"+to_string(i)][dName] = result;
            }
            tt += param->getOffSampleInterval();
            strftime(timeBuf, sizeof(timeBuf), "%Y-%m-%d %H:%M:%S", gmtime(&tt));
        }
    }
    else if ( param->getOffMeasureOpt() == 0x2 )
    {
        int batchNum = 1;
        int batch = 4;
        int index = 4;
        string sIndex = "";
        string dName = "";
        int datum = 0;
        float result = 0;
        for ( int i = 0; i < (length / batchNum / batch); i++ ) {
            root["Spot"]["Points_"+to_string(i)]["Time"] = CtoString(timeBuf);
            for ( int j = 0; j < batchNum; j++ ) {
                index = 4 + i * batchNum + j;
                //root["Data"]["Data"+to_string(index)] = info.substr(OFF_DATA_DATA_(index));
                datum = ToIntConvert(info.substr(OFF_DATA_DATA_(index)));
                switch(j)
                {
                case 0:
                    if ( param->getRangeOpt() == 1 )
                        result = datum * param->getDcHiCurrentK() + param->getDcHiCurrentB();
                    else
                        result = datum * param->getDcLoCurrentK() + param->getDcLoCurrentB();
                    dName = "0_DcCurrent";
                    break;
                }

                root["Spot"]["Points_"+to_string(i)][dName] = result;

            }
            tt += param->getOffSampleInterval();
            strftime(timeBuf, sizeof(timeBuf), "%Y-%m-%d %H:%M:%S", gmtime(&tt));
        }
    }

    cout << root.toStyledString() << endl;

    Json :: StyledWriter sw;
    ofstream os;
    os.open("./json/OffData_"+time+".json");
    os << sw.write(root);
    os.close();

    return 1;
}

int protocolUse :: handleAssistData(string info)
{
    Json::Value root;

    root["Header"] = info.substr(ASSIST_DATA_HEADER);
    root["VID"] = info.substr(ASSIST_DATA_VID);
    root["PID"] = info.substr(ASSIST_DATA_PID);
    root["DID"] = info.substr(ASSIST_DATA_DID);
    root["Operation1"] = info.substr(ASSIST_DATA_OPERATIASSIST1);
    root["Operation2"] = info.substr(ASSIST_DATA_OPERATIASSIST2);
    root["Operation3"] = info.substr(ASSIST_DATA_OPERATIASSIST3);
    root["Length"] = info.substr(ASSIST_DATA_LENGTH);

    int length = ToIntConvert(info.substr(ASSIST_DATA_LENGTH));
    printf("length%d\n", length);
    printf("info.size:%d\n", info.size());
    int tmp = 0;
    char timeBuf[255] = {0};
    struct tm *tm_time = (struct tm*)malloc(sizeof(struct tm));
    time_t timer = time(NULL);
    string time = "";
    CParam * param = CParam::GetInstance();
    strftime(timeBuf, sizeof(timeBuf), "%Y-%m-%d ", gmtime(&timer));

    tmp = ToIntConvert(info.substr(ASSIST_DATA_DATA01));
    root["Data"]["Data01"] = info.substr(ASSIST_DATA_DATA01);
    time += (to_string(tmp)+":");
    tmp = ToIntConvert(info.substr(ASSIST_DATA_DATA02));
    root["Data"]["Data02"] = info.substr(ASSIST_DATA_DATA02);
    time += (to_string(tmp)+":");
    tmp = ToIntConvert(info.substr(ASSIST_DATA_DATA03));
    root["Data"]["Data03"] = info.substr(ASSIST_DATA_DATA03);
    time += (to_string(tmp));

    strcat(timeBuf, time.c_str());
    strptime(timeBuf, "%Y-%m-%d %H:%M:%S", tm_time);
    time_t tt = mktime(tm_time);
    printf("%d:%s\n", (int)tt, timeBuf);

    length = info.size() - 56 - 4;
    printf("real len:%d\n", length);
    if ( param->getOffMeasureOpt() == 0x1 )
    {
        int batchNum = 2;
        int batch = 4;
        int index = 4;
        string sIndex = "";
        string dName = "";
        float result = 0;
        int datum = 0;
        for ( int i = 0; i < (length / batchNum / batch); i++ ) {
            root["Spot"]["Points_"+to_string(i)]["Time"] = CtoString(timeBuf);
            for ( int j = 0; j < batchNum; j++ ) {
                index = 4 + i * batchNum + j;
                //sIndex = (index<10)?"Data0"+to_string(index):"Data"+to_string(index);
                //root["Data"]["Data"+to_string(index)] = info.substr(ASSIST_DATA_DATA_(index));
                root["Spot"]["Points_"+to_string(i)]["Time"] = CtoString(timeBuf);
                datum = ToIntConvert(info.substr(ASSIST_DATA_DATA_(index)));
                switch(j)
                {
                case 0:
                    dName = "0_Temperature";
                    result = 0.00042 * datum - 13.75;
                    break;
                case 1:
                    dName = "1_BatteryLife";
                    result = 0.01 * datum - 367.78;
                    break;
                }
                root["Spot"]["Points_"+to_string(i)][dName] = result;
            }
            tt += param->getOffSampleInterval();
            strftime(timeBuf, sizeof(timeBuf), "%Y-%m-%d %H:%M:%S", gmtime(&tt));
        }
    }

    cout << root.toStyledString() << endl;

    Json :: StyledWriter sw;
    ofstream os;
    os.open("./json/AssistData_"+time+".json");
    os << sw.write(root);
    os.close();

    return 1;
}

//其实就是输出Log等会再说
void makeLogShow(int type,string theinformation)
{
    cout<<"["+to_string(type)+"]"<<theinformation<<endl; 
}

int ToIntConvert(string theString)
{
        
    const char* E = theString.c_str();
    unsigned short n = 0;
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

    /*
      cout <<"convert1:"<< theString <<"->" << theFloat << endl;
      float intergerPart =  floor(theFloat);
      theFloat -= intergerPart;
      theFloat = intergerPart + ( floor(theFloat * pow(10.0, prec) + 0.5) / pow(10.0, prec) );

      float theFloat;
      stringstream ss;
      ss << std::hex << vert;
        
      ss >> theFloat;
    */
    cout <<"convert:"<< theString <<"->" << theFloat << endl;
        
    return theFloat;
}
string CtoString(const char * c)
{
    string ret(c);
    return ret;
}
