/*!
 * @file Employee.cpp
 * @brief Implementation of Employee class
 * @author Ha Phan
 */

#include "Employee.h"

std::string Employee::getEmployeeID()
{
   return this->employeeID;
}

void Employee::setEmployeeID(std::string employeeID)
{
    this->employee = employeeID;
}

std::string Employee::getEmployeeName()
{
   return this->employeeName;
}

void Employee::setEmployeeName(std::string EmployeeName)
{
   this->employeeName = EmployeeName;
}

std::string Employee:: getRoomID()
{
   return this->RoomID;
}

void Employee::setRoomID(std::string RoomID)
{
   this->RoomID = RoomID;
}
