/*!
 * @file Person.h
 * @brief this is decleration of Person class
 * @author Ha Phan
 */

#ifndef __Person_H__
#define __Person_H__

#include <iostream>
#include "Card.h"
class Person
{
public:
    std::string getPersonID();
    void setPersonID(std::string personID);
    std::string getPersonName();
    void setPersonName(std::string personName);
    Card getCardID();
    void setCardID(Card cardID);
    int getAge();
    void setAge(int age);

private:
    std::string personID;
    std::string personName;
    Card cardID;
    int age;
};
#endif


