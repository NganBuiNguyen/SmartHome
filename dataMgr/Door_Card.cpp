#include"Door_Card.h"

int Door_Card::getCardID()
{
    return cardID;
}

void Door_Card::setCardID(int cardID)
{
    this->cardID = cardID;
}

std::string Door_Card::getDoorID()
{
    return doorID;
}

void Door_Card::setDoorID (std::string doorID)
{
   this->doorID = doorID;
}
