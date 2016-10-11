#ifndef __Door_Card_H_
#define __Door_Card_H_


#include <iostream>
#include <string>
#include <string.h>


class Door_Card
{
public:
    int getCardID();
    void setCardID(int cardID);
    std::string getDoorID();
    void setDoorID(std::string doorID);
private:
    int cardID;
    std::string doorID;
}
#endif
