#include <gtest/gtest.h>
#include "Room.h"
#include "DbRoom.h"


class TestDbRoom : public ::testing::Test
{
protected:
    void SetUp()
    {

    }
    void TearDown()
    {

    }
};


TEST_F(TestDbRoom, TestGetSetRoom)
{
    Room room;
    std::string roomID("Room 1A");
    room.setRoomID(roomID);
    
    EXPECT_STREQ(room.getRoomID().c_str(), roomID.c_str());
}