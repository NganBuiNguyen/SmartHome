/*!
 * @file Room.cpp
 * @brief Implementation of Door class
 * @author Ngan Bui
 */


#include "Door.h"


std::string Door::getDoorID();
{
    return doorID;
}

void Door::setDoorID(std::string doorID)
{
    this->doorID = doorID;
}


std::string Door::getNameDoor()
{
    return nameDoor;
}


void Door::setNameDoor(std::string nameDoor)
{
    this->nameDoor = nameDoor;
}
