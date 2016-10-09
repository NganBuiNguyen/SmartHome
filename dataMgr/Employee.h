/*!
 * @file Employee.h
 * @brief this is decleration of Employee class
 * @author Ha Phan
 */

#ifndef __Employee_H__
#define __Employee_H__

#include<iostream>
class Employee
{
public:
    std::string getEmployeeID();
    void setEmployeeID(std::string employeeID);
    std::string getEmployeeName();
    void setEmployeeName(std::string EmployeeName);
    std::string getRoomID();
    void setRoomID(std::string RoomID);

private:
    std::string employeeID;
    std::string employeeName;
    std::string roomID;
};
#endif


