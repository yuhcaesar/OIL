#include <string.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <time.h>
#include<iomanip>
//#include "operate.h"
#include "log.h"
using namespace std;

void LogUp(char * file)
{
#ifdef LOGMOD
    freopen(file, "a", stderr);
#endif
}

void LogDown()
{
#ifdef LOGMOD
    fclose(stderr);
#endif
}
//其实就是输出Log等会再说
void LOG(int type, string theinformation)
{
    time_t timer = time(NULL);
    string stime = "";

char timeBuf[255] = {0};
    string stype ="";
    switch(type)
    {
    case LOG_RAW:
        stype = "[RAWDATA] ";
        break;
    case LOG_ERR:
        stype = "[ERROR] ";
        break;
    case LOG_MSG:
        stype = "[MESSAGE] ";
        break;
    case LOG_DBG:
        stype = "[DEBUG] ";
        break;
    }
    strftime(timeBuf, sizeof(timeBuf), "[%Y-%m-%d %H:%M:%S] ", localtime(&timer));
    stime= string(timeBuf);
#ifdef LOGMOD
    clog << setw(10) << left << stype << stime << theinformation << endl;
#endif
    cout << setw(10) << left << stype << stime << theinformation << endl;
}

