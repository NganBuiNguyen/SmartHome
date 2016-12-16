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
<<<<<<< HEAD
std::boolean Status::getStatusName()
{
 return this->statusName;
}                                                              
void Status::setSatusName(std::boolean statusName)
{
 this->statusName = statusName;
}
std::string Status::getEmployeeID()
{
 return this->employeeID;
}                                                                               void Status::setEmployeeID(std::string employeeID)
=======
bool Status::getStatusName()
{
 return this->statusName;
}                                                              
void Status::setSatusName(bool statusName)
{
 this->statusName = statusName;
<<<<<<< HEAD
}                                                                      std::string Status::getEmployeeID()
{
 return this->employeeID;
}                                                                      void Status::setEmployeeID(std::string employeeID)
>>>>>>> 5df60496ad809eef20b23bd6a2a623d66b3d56f9
{
 this->employeeID = employeeID;
=======
>>>>>>> a056a8048d2a9d921065e10494bb092040d5e5d7
}


 Door Status::getDoorID()
 {
 	return this->doorID;
 }
 void Status::setDoorID(Door doorID)
 {
 	this->doorID = doorID;
 }
 Card Status::getCardID()
 {
 	return this->cardID;
 }
 void Status::setCardID(Card cardID)
 {
 	this->cardID = cardID;
 }

 time_t Status::getTimeIn()
 {
 	return this->timeIn;
 }
 void Status::setTimeIn(time_t timeIn)
 {
 	this->timeIn = timeIn;
 }
 time_t Status::getTimeOut()
 {
 	return this->timeOut;
 }
 void Status::setTimeOut(time_t timeOut)
 {
 	this->timeOut = timeOut;
 } 