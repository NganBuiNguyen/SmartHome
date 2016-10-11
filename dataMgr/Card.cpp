#include "Card.h"


int Card::getCardID()
{
    return cardID; 
}


void Card::setCardID(int cardID)
{
    this->cardID = cardID;
}


std::string Card::getKindCard()
{
    return kindCard;
}

void Card::setKindCard(std::string kindCard)
{
    this->kindCard = kindCard;
}

std::string Card::getEmployeeID()
{
    return employeeID;
}

void Card::setEmployeeID(std::string employeeID)
{
    this->employeeID = employeeID;
}

std::string Card::getRoomID()
{
    return roomID;
}

void Card::setRoomID(std::string roomID)
{
   this->roomID = roomID;
}
