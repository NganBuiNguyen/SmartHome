#include "Card.h"

Card::Card()
{
 
}
Card::Card(std::string CardID)
{
        this->cardID=CardID;
}
Card::Card(std::string CardID,std::string kindCard)
{
	this->cardID=CardID;
	this->kindCard=kindCard;
}

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

