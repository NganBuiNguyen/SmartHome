#include <gtest/gtest.h>
#include "Card.h"


class CardTest : public ::testing::Test
{
protected:
    void SetUp()
    {
    }
    void TearDown()
    {
    }
};


TEST_F(CardTest, TestGetSetID)
{
    Card card;
    std::string employeeID("GCS2734");
    card.setEmployeeID(employeeID);

    EXPECT_STREQ(card.getEmployeeID().c_str(), employeeID.c_str()); 
}
