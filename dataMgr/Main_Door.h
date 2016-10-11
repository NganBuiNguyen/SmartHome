#ifndef __Main_Door_H_
#define __Main_Door_H_

#include <iostream>
#include <string>
#include <string.h>


class Main_Door 
{
public:
    std::string getDoorID();
    void setDoorID(std::string doorID);
    std::Date getTimeIn();
    void setTimeIn(std::Date timeIn);
    std::Date getTimeOut();
    void setTimeOut(std::Date timeOut); 
private:
    std::string doorID;
    std::Date timeIn;
    std::Date timeOut;
}
#endif
