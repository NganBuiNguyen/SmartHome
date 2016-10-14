/*!
 * @file Door.cpp
 * @brief Implementation of Door class
 * @author Ngan Bui
 */


#include "Door.h"


std::string Door::getDoorID()
{
    return this->doorID;
}

void Door::setDoorID(std::string doorID)
{
    this->doorID = doorID;
}


std::string Door::getNameDoor()
{
    return this->nameDoor;
}


void Door::setNameDoor(std::string nameDoor)
{
    this->nameDoor = nameDoor;
}
