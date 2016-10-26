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