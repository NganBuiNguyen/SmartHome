#ifndef __Door_H_
#define __Door_H_


#include <iostream>
#include <string>
#include <string.h>

class Door
{
public:
	std::string getIDDoor();
    void setIDDoor(std::string IdDoor);
    std::string getnameDoor();
    void setnameDoor(std::string name);
private:
	std::string IDDoor;
	std::string NameDoor;
};
#endif
