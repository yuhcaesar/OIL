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
  void InitTheProtocolModule( DBController theDBCIn , logController theLogIn  )
  {
    theLogC = theLogIn ;
    theDBC = theDBCIn;
    makeLogShow(1,"protocoluse is opened");
  }

  void getString(string information)
  {
    saveStringForDemo(information);
  }


  private:
    
    logController  theLogC ;
    DBController theDBC;
    int stringCount = 0;
    string theSaveString = "INSERT INTO OilDataDemo (Data1 , Data2 , Data3 , Data4, Data5,  Data6 ) values("; 
    void makeLogShow(int type,string theinformation)
    {
           cout<<theinformation<<endl; 
           theLogC.makeLogWithFlush(type,theinformation);
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
        stringCount ++;
        theSaveString += getIn;
        if(stringCount <=7) 
        {
           theSaveString  += ",";
        }
        else
        {
          stringCount = 0;
          theSaveString += ");";
           cout<<theSaveString<<" to mysql -----"<<endl;
          theDBC.DBQuery(theSaveString);
          theSaveString = "INSERT INTO OilDataDemo (Data1 , Data2 , Data3 , Data4, Data5,  Data6 ，Data7 , Data8) values(";
        }
       
    }

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


void dataUse37(string VID , string PID, string DID , string dataIn)
{
  string data1 = dataIn.substr(0,dataIn.size()-2);
  string data2 = dataIn.substr(dataIn.size()-2,2);
  string * theDataGet = stringSplite( data1,',');
  int theLength = getStringClipCount(data1 , ',');
  if(theLength == 5)
  {
	  if(theDataGet[0] == "A")
	  {
	     string NPos = theDataGet[1];
	     string EPos = theDataGet[3];
             string timeString = "";
             time_t nowTime; 
             struct tm *timer;
             nowTime = time(NULL);
             timer = localtime(&nowTime);
             timeString = to_string((1900+timer->tm_year))+"/"+to_string((1+timer->tm_mon))+"/"+to_string(timer->tm_mday);
             string command = "INSERT INTO OilData_037 (VID , PID , DID , NPostion, EPosition,  CommandID ,Time) ";
             command += "values('"+VID+"','"+PID+"','"+DID+"','"+NPos+"','"+EPos+"','"+data2 +"','"+timeString+"');"; 
             theDBC.DBQuery(command);
	  }
	  else if(theDataGet[0] == "V")
	  {
	    makeLogShow(2,"protocoluse positioning fail");
	  }
  }
  else
  {
   	    makeLogShow(2,"protocoluse positioning fail");
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
   } 
   int stringToInt(string str)
   {
     float i=atoi(str.c_str());
     return i;
   }  

    void slipMethod1(string information)
    {
      const char * gets = information.c_str(); 
       int lengthAll =  information.size();
       cout<< "length "<<lengthAll<<endl;

	     int i=0;
	     char * bufferUse = new char[4];
	     int indexNow = 0;
	     string head ="";
	     for( ;i<8; i++)
	      head += gets[i];
	     cout<<"head is "<< head<< endl;
	    string VID = "";
	     for( ;i<12; i++)
	      VID += gets[i];
	    cout<<"VID is "<< VID << endl;
	     string PID = "";
	     for( ;i<16; i++)
	      PID += gets[i];
	    cout<<"PID is "<< PID << endl;
	     string DID = "";
	     for( ;i< 40; i++)
	      DID += gets[i];
	    cout<<"DID is "<< DID << endl;
	     string operation1 = "";
	     for( ;i< 42; i++)
	      operation1 += gets[i];
	    cout<<"operation1 is "<< operation1 << endl;
	     string operation2 = "";
	     for( ;i< 44; i++)
	      operation2 += gets[i];
	    cout<<"operation2 is "<< operation2 << endl;
	     string length = "";
	     for( ;i< 48; i++)
	      length += gets[i];
	    cout<<"length is "<< length << endl;
	     string data = "";
	     for( ;i< lengthAll-4; i++)
	      data += gets[i];
	    cout<<"data is "<< data << endl;
	     string tail = "";
	     for( ;i< lengthAll; i++)
	      tail += gets[i];
	    cout<<"tail is "<< tail << endl;
    }
};
 


#endif     
