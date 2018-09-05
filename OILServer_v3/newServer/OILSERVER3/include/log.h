#ifndef __LOG_H__
#define __LOG_H__

#include <string.h>
#include <fstream>
#include <iostream>
#include <time.h>

using namespace std;

const int LOG_RAW = 1;
const int LOG_ERR = 2;
const int LOG_MSG = 3;
const int LOG_DBG = 4;

void LogUp(char * file);
void LogDown();
void LOG(int type,string theinformation);
#endif
