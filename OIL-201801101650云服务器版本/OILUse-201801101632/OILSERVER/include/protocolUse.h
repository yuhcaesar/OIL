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
    string theSaveString = "INSERT INTO OilDataDemo (Data1 , Data2 , Data3 , Data4, Data5,  Data6 ,Data7,Data8) values("; 
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
           cout<<theSaveString<<endl;
          theDBC.DBQuery(theSaveString);
          theSaveString = "INSERT INTO OilDataDemo (Data1 , Data2 , Data3 , Data4, Data5, Data6 , Data7, Data8) values(";
        }
       
    }
};
 


#endif     
