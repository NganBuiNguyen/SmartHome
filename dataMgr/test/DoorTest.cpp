#include <gtest/gtest.h>
#include "Door.h"


class DoorTest : public ::testing::Test
{
protected:
    void SetUp()
    {
    }

    void TearDown()
    { 
    }
};


TEST_F(DoorTest, TestGetSetName)
{
    Door door;
    std::string doorName("cua 1");
    door.setNameDoor(doorName);

    EXPECT_STREQ(door.getNameDoor().c_str(), doorName.c_str());
}
