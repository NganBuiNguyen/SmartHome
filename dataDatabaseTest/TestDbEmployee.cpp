#include <gtest/gtest.h>
#include "Employee.h"
#include "DbEmployee.h"

class TestDbEmployeeTest : public ::testing::Test
{
protected:
    void SetUp()
    {

    }

    void TearDown()
    {

    }

};

TEST_F(TestDbEmployeeTest, TestGetSetName)
{
    Employee employee;
    std::string employeeName("GCS2734");
    employee.setEmployeeName(employeeName);

    EXPECT_STREQ(employee.getEmployeeName().c_str(), employeeName.c_str());
}