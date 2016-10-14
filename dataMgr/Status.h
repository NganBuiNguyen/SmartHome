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

>>>>>>> 5df60496ad809eef20b23bd6a2a623d66b3d56f9

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
>>>>>>> 5df60496ad809eef20b23bd6a2a623d66b3d56f9
    std::string getEmployeeID();
    void setEmployeeID(std::string employeeID);
    std::string getRoomID();
    void setRoomID(std::string roomID);

private:
    std::string statusID;
<<<<<<< HEAD
    std::boolean statusName;
    std::string employeeID;
    std::string roomID;
}
=======
    bool statusName;
    std::string employeeID;
    std::string roomID;
};
>>>>>>> 5df60496ad809eef20b23bd6a2a623d66b3d56f9
#endif
