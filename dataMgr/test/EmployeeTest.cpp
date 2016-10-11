#include <gtest/gtest.h>
#include "Employee.h"

class EmployeeTest : public ::testing::Test
{
protected:
    void SetUp()
    {
    }

    void TearDown()
    {
    }

};

TEST_F(EmployeeTest, TestGetSetID)
{
    Employee employee;
    std::string employeeID("GCS2734");
    employee.setEmployeeID(employeeID);

    EXPECT_STREQ(employee.getEmployeeID().c_str(), employeeID.c_str());
}
