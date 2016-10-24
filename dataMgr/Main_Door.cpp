#include "Main_Door.h"



Main_Door::Main_Door()
{}


Main_Door::Main_Door(std::string doorID, time_t timeIn, time_t timeOut)
{
    this->timeIn = timeIn;
    this->doorID = doorID;
    this->timeOut = timeOut;
}



std::string Main_Door::getDoorID()
{
    return this->doorID;
}


void Main_Door::setDoorID(std::string doorID)
{
    this->doorID = doorID;
}


time_t Main_Door::getTimeIn()
{
    return this->timeIn;
}

void Main_Door::setTimeIn(time_t timeIn)
{
    this->timeIn = timeIn;
}

time_t Main_Door::getTimeOut()
{
    return this->timeOut;
}

void Main_Door::setTimeOut(time_t timeOut)
{
    this->timeOut = timeOut;
}
