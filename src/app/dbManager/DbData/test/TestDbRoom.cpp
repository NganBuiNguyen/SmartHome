#include <gtest/gtest.h>
#include "DbRoom.h"


static sql::Driver* MYSQL_DRIVER_INSTANCE = get_driver_instance();
static sql::Connection* MYSQL_DB_CONNECTION =
                    MYSQL_DRIVER_INSTANCE->connect(DBHOST, USER, PASSWORD);

class TestDbRoom : public ::testing::Test
{
public:
protected:
    virtual void SetUp()
    {
    }

    virtual void TearDown()
    {
    }
};


TEST_F(TestDbRoom, TestSelectCard_RESULT_OK)
{
    CardInfo item;
    strcpy(item.room.idRoom,"P0001");
    strcpy(item.room.nameRoom,"Phong1");
    
    
    CardInfo item1;
    strcpy(item1.room.idRoom,"P0002");
    strcpy(item1.room.nameRoom,"Phong2");
    
    
    std::vector<CardInfo> vectorCardInfos;

    vectorCardInfos.push_back(item);
    vectorCardInfos.push_back(item1);
    

    DbRoom dbroom;
    std::vector<CardInfo*> vectorCardInfosResult;
    bool status = dbroom.selectToDbRoom(vectorCardInfosResult);
    
    EXPECT_TRUE(status);
    

    
    for( int i = 0 ; i < vectorCardInfos.size() ; i++){
        EXPECT_EQ(strcmp(vectorCardInfos[i].room.idRoom, vectorCardInfosResult[i]->room.idRoom), 0);
        EXPECT_EQ(strcmp(vectorCardInfos[i].room.nameRoom, vectorCardInfosResult[i]->room.nameRoom),0);
    }
}