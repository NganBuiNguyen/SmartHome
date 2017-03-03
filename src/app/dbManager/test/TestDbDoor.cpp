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


TEST_F(TestDbDoor, TestInsertDoor)
{
    Door door;
    DbDoor dbDoor;
    sql::Connection* conn;
    strcpy(door.IDDoor,"D1");
    strcpy(door.nameDoor,"Door 1");
    EXPECT_STREQ(dbDoor.insert_node_to_db(conn,door),1) ;
}
TEST_F(TestDbDoor,TestDeleteDoor)
{
    
}