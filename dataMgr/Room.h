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

class Room
{
public:
    std::string getRoomID();
    void setRoomID(std::string roomID);
    std::string getNameRoom();
    void setNameRoom(std::string nameRoom);
private:
    std::string roomID;
    std::string nameRoom;
};
#endif

