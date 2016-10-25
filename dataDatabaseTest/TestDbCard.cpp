#include <gtest/gtest.h>
#include "Card.h"
#include "DbCard.h"


class TestDbCard : public ::testing::Test
{
protected:
    void SetUp()
    {

    }
    void TearDown()
    {

    }
};


TEST_F(TestDbCard, TestGetSetCard)
{
    Card card;
    std::string employeeID("GCS2734");
    card.setEmployeeID(employeeID);

    EXPECT_STREQ(card.getEmployeeID().c_str(), employeeID.c_str());
}