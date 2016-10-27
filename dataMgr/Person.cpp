/*!
 * @file Person.cpp
 * @brief Implementation of Person class
 * @author Ha Phan
 */

#include "Person.h"



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