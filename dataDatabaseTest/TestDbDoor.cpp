#include <gtest/gtest.h>
#include "Door.h"
#include "DbDoor.h"


class TestDbDoor : public ::testing::Test
{
protected:
    void SetUp()
    {

    }
    void TearDown()
    {

    }
};


TEST_F(TestDbDoor, TestGetSetDoor)
{
    Door door;
    std::string doorID("Door 1A");
    door.setDoorID(doorID);

    EXPECT_STREQ(door.getDoorID().c_str(), doorID.c_str());
}