/*!
 *@file Status.h
 *#brief this is decleration of Status class
 *@author Ha Phan
 */
#ifndef __Status_H__
#define __Status_H__

#include<iostream>

class Status
{
public:
    std::string getStatusID();
    void setStatusID(std::string statusID)
    std::boolean getStatusName();
    void setSatusName(std::boolean statusName);
    std::string getEmployeeID();
    void setEmployeeID(std::string employeeID);
    std::string getRoomID();
    void setRoomID(std::string roomID);

private:
    std::string statusID;
    std::boolean statusName;
    std::string employeeID;
    std::string roomID;
}
