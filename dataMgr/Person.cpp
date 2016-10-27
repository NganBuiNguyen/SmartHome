/*!
 * @file Person.cpp
 * @brief Implementation of Person class
 * @author Ha Phan
 */

#include "Person.h"

Person::Person()
{

}

Person::Person(std::string personID,std::string personName,int age)
{
	this->personID = personID;
	this->personName = personName;
	//this->cardID = cardID;
	this->age = age;
}
std::string Person::getPersonID()
{
   return this->personID;
}

void Person::setPersonID(std::string personID)
{
    this->personID = personID;
}

std::string Person::getPersonName()
{
   return this->personName;
}

void Person::setPersonName(std::string personName)
{
   this->personName = personName;
}

Card Person::getCardID()
{
   return this->cardID;
}

void Person::setCardID(Card cardID)
{
   this->cardID = cardID;
}
int Person::getAge()
{
 	return this->age;
}
 
void Person::setAge(int age)
{
 	this->age = age;
}