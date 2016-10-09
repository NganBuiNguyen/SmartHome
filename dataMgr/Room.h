/*!
 * @file Room.h
 * @brief this is decleration of Room class
 * @author Ngan Bui
 */

#ifndef __Room_H_
#define __Room_H_
class Room
{
public:
    std::tring getRoomID();
    std::string setRoomID(std::string roomID;
    std::string getnameRoom();
    std::string setnameRoom(std::string nameRoom);
private:
    std::string roomID;
    std::string nameRoom;
};
#endif

