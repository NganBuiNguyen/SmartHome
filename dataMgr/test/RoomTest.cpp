#include <gtest/gtest.h>
#include "Room.h"


class RoomTest : public ::testing::Test
{
protected:
    void SetUp()
    {
    }

    void TearDown()
    {
    }
};


TEST_F(RoomTest, TestGetSetName)
{
    Room room;
    std::string nRoom("Room 1");
    room.setNameRoom(nRoom);
 
    EXPECT_STREQ(room.getNameRoom().c_str(), nRoom.c_str());
}
