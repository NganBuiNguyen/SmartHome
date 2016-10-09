/*!
 * @file Room.cpp
 * @brief Implementation of Room class
 * @author Ngan Bui
 */

#include "Room.h"

std::string  Room::getRoomID()
{
    return roomID;
} 

void Room::setRoomID(std::string roomID)
{
    this->roomID = roomID;
}

std::string Room::getnameRoom()
{
    return nameRoom;
}

void Room::setnameRoom(std::string nameRoom)
{
    this->nameRoom = nameRoom;
} 
