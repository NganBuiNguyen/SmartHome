#ifndef __Main_Door_H_
#define __Main_Door_H_

#include <iostream>
#include <string>
#include <string.h>
#include <time.h>

class Main_Door 
{
public:
    Main_Door ();
    Main_Door (std::string doorID,time_t timeIn,time_t timeOut);

    std::string getDoorID();
    void setDoorID(std::string doorID);
    time_t getTimeIn();
    void setTimeIn(time_t timeIn);
    time_t getTimeOut();
    void setTimeOut(time_t timeOut); 
private:
    std::string doorID;
    time_t timeIn;
    time_t timeOut;
};
#endif
