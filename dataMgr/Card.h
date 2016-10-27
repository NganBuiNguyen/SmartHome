#ifndef __Card_H_
#define __Card_H_


#include<iostream>
#include<string>
#include<string.h>


class Card 
{
public:
    std::string getCardID();
    void setCardID(std::string cardID);
    std::string getKindCard();
    void setKindCard(std::string kindCard);
private:
    std::string cardID;
    std::string kindCard;

};
#endif
