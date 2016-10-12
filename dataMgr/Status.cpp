/*!
 *@file Status.cpp
 *#brief implementation of Status class
 *@author Ha Phan
*/


#include"Status.h"  

 std::string Status::getStatusID()
{
 return this->statusID;
}                                   
void Status::setStatusID(std::string statusID)
{
 this->statusID = statusID;
}                        
bool Status::getStatusName()
{
 return this->statusName;
}                                                              
void Status::setSatusName(bool statusName)
{
 this->statusName = statusName;
}                                                                      std::string Status::getEmployeeID()
{
 return this->employeeID;
}                                                                      void Status::setEmployeeID(std::string employeeID)
{
 this->employeeID = employeeID;
}
std::string Status::getRoomID()
{
 return this->roomID;
}                   
void Status::setRoomID(std::string roomID)
{
 this->roomID = roomID;
}  
