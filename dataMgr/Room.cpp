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

std::string Room::getNameRoom()
{
    return nameRoom;
}

void Room::setNameRoom(std::string nameRoom)
{
    this->nameRoom = nameRoom;
} 

int Room::getCountRoom()
{
	return countRoom;
}
void Room::setCountRoom(int countRoom)
{
	this->countRoom = countRoom;
}

Person Room::getIDPerson()
{
	return this->IDPerson;
}
void Room::setIDPerson(Person IDPerson)
{
   this->IDPerson=IDPerson;
}
Door Room::getIDDoor()
{
	return this->IDDoor;
}
void Room::setIDDoor(Door IDDoor)
{
	this->IDDoor=IDDoor;
}