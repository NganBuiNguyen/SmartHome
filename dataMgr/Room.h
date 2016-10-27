/*!
 * @file Room.h
 * @brief this is decleration of Room class
 * @author Ngan Bui
 */

#ifndef __Room_H_
#define __Room_H_

#include <iostream>
#include <string>
#include <string.h>
#include "Person.h"
#include "Door.h"

class Room
{
public:
    std::string getRoomID();
    void setRoomID(std::string roomID);
    std::string getNameRoom();
    void setNameRoom(std::string nameRoom);
    int getCountRoom();
    void setCountRoom(int countRoom);
    Person getIDPerson();
	void setIDPerson(Person IDPerson);
	Door getIDDoor();
	void setIDDoor(Door IDDoor);
private:
    std::string roomID;
    std::string nameRoom;
    int countRoom;
    Person IDPerson;
    Door IDDoor;
};
#endif

