/*!
 *@file Status.h
 *#brief this is decleration of Status class
 *@author Ha Phan
 */
#ifndef __Status_H__
#define __Status_H__

<<<<<<< HEAD
#include<iostream>
=======
#include <iostream>
#include <string>
#include <string.h>

<<<<<<< HEAD
>>>>>>> 5df60496ad809eef20b23bd6a2a623d66b3d56f9
=======
#include "Door.h"
#include "Card.h"

>>>>>>> a056a8048d2a9d921065e10494bb092040d5e5d7

class Status
{
public:
    std::string getStatusID();
<<<<<<< HEAD
    void setStatusID(std::string statusID)
    std::boolean getStatusName();
    void setSatusName(std::boolean statusName);
=======
    void setStatusID(std::string statusID);
    bool getStatusName();
    void setSatusName(bool statusName);
<<<<<<< HEAD
>>>>>>> 5df60496ad809eef20b23bd6a2a623d66b3d56f9
    std::string getEmployeeID();
    void setEmployeeID(std::string employeeID);
    std::string getRoomID();
    void setRoomID(std::string roomID);
=======

    Door getDoorID();
    void setDoorID(Door doorID);
    Card getCardID();
    void setCardID(Card cardID);

    time_t getTimeIn();
    void setTimeIn(time_t timeIn);
    time_t getTimeOut();
    void setTimeOut(time_t timeOut); 


>>>>>>> a056a8048d2a9d921065e10494bb092040d5e5d7

private:
    std::string statusID;
<<<<<<< HEAD
    std::boolean statusName;
    std::string employeeID;
    std::string roomID;
}
=======
    bool statusName;
    Door doorID;
    Card cardID;
    time_t timeIn;
    time_t timeOut;
};
>>>>>>> 5df60496ad809eef20b23bd6a2a623d66b3d56f9
#endif
