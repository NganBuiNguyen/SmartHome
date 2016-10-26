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

