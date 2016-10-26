/*!
 *@file Status.h
 *#brief this is decleration of Status class
 *@author Ha Phan
 */
#ifndef __Status_H__
#define __Status_H__

#include <iostream>
#include <string>
#include <string.h>

#include "Door.h"
#include "Card.h"


class Status
{
public:
    std::string getStatusID();
    void setStatusID(std::string statusID);
    bool getStatusName();
    void setSatusName(bool statusName);

    Door getDoorID();
    void setDoorID(Door doorID);
    Card getCardID();
    void setCardID(Card cardID);

    time_t getTimeIn();
    void setTimeIn(time_t timeIn);
    time_t getTimeOut();
    void setTimeOut(time_t timeOut); 



private:
    std::string statusID;
    bool statusName;
    Door doorID;
    Card cardID;
    time_t timeIn;
    time_t timeOut;
};
#endif
