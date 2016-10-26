#include "Card.h"


std::string Card::getCardID()
{
    return cardID; 
}


void Card::setCardID(std::string cardID)
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

