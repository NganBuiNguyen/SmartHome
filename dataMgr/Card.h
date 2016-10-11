#ifndef __Card_H_
#define __Card_H_


#include<iostream>
#include<string>
#include<string.h>


class Card 
{
public:
    int getCardID();
    void setCardID(int cardID);
    std::string getKindCard();
    void setKindCard(std::string kindCard);
    std::string getEmployeeID();
    void setEmployeeID(std::string employeeID);
    std::string getRoomID();
    void setRoomID(std::string roomID);
private:
    int cardID;
    std::string kindCard;
    std::string  employeeID ;
    std::string roomID;
};
#endif