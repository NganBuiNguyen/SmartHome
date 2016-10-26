#ifndef __Card_H_
#define __Card_H_


#include<iostream>
#include<string>
#include<string.h>


class Card 
{
public:
    string getCardID();
    void setCardID(int cardID);
    std::string getKindCard();
    void setKindCard(std::string kindCard);
<<<<<<< HEAD
   
=======
    
>>>>>>> e6a0f2a15a28377265d8214090261c1e36b95006
private:
    std::string cardID;
    std::string kindCard;
<<<<<<< HEAD
    
=======
>>>>>>> e6a0f2a15a28377265d8214090261c1e36b95006
};
#endif
