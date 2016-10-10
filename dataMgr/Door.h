/*!        
 * @file Room.h                                                        
 * @brief this is decleration of Door class                            
 * @author Ngan Bui                                                    
 */

#ifndef __Door_H_
#define __Door_H_


#include <string>
#include <string.h>
#include <iostream>

class Door 
{
public:
    std::string getDoorID();
    void setDoorID(std::string doorID);
    std::string getNameDoor();
    void setNameDoor(std::string nameDoor);
private:
    std::string doorID;
    std::string nameDoor;
}
