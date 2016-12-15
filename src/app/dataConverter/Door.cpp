#include "Door.h"
#include <string>

std::string Door::getIDDoor()
{
   return this->IDDoor;
}
void Door::setIDDoor(std::string IdDoor)
{
    this->IDDoor= IdDoor;
}
std::string Door::getnameDoor()
{
    return this->NameDoor;   
}
void Door::setnameDoor(std::string name)
{
   this->NameDoor=name;
}