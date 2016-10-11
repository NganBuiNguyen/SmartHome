#include "Main_Door.h"


std::string Main_Door::getDoorID()
{
    return doorID;
}


void Main_Door::setDoorID(std::string doorID)
{
    this->doorID = doorID;
}


std::Date Main_Door::getTimeIn()
{
    return timeIn;
}

std::Date Main_Door::setTimeIn()
{
    this->timeIn = timeIn;
}

std::Date Main_Door::getTimeOut()
{
    return timeOut;
}

std::Date Main_Door::setTimeOut()
{
    this->timeOut = timeOut;
}
