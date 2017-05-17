#include <gtest/gtest.h>
#include "DbCardForC.h"
#include "DbRoom.h"


static sql::Driver* MYSQL_DRIVER_INSTANCE = get_driver_instance();
static sql::Connection* MYSQL_DB_CONNECTION =
                    MYSQL_DRIVER_INSTANCE->connect(DBHOST, USER, PASSWORD);

class TestDbRoomForC : public ::testing::Test
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


TEST_F(TestDbRoomForC, TestSelectRoomForC_RESULT_OK)
{
    CardInfo* info = NULL;
    int numberOfElement = 0;

    CardInfo item;
    strcpy(item.room.idRoom,"P0001");
    strcpy(item.room.nameRoom,"Phong1");
    
    
    CardInfo item1;
    strcpy(item1.room.idRoom,"P0002");
    strcpy(item1.room.nameRoom,"Phong2");
    
    
    std::vector<CardInfo> vectorRoomInfos;

    vectorRoomInfos.push_back(item);
    vectorRoomInfos.push_back(item1);

    CardInfo* listRoomInfoTmp = new CardInfo[vectorRoomInfos.size()];
    int numberOfElement1 = vectorRoomInfos.size();

    for (int index = 0; index < numberOfElement1; index++)
    {
        strcpy((listRoomInfoTmp[index]).room.idRoom,
                                        vectorRoomInfos[index].room.idRoom);
        strcpy((listRoomInfoTmp[index]).room.nameRoom,
                                        vectorRoomInfos[index].room.nameRoom);
    }

    bool status = selectToDbRoomForC(&info, &numberOfElement);

    for(int i = 0; i < vectorRoomInfos.size(); i++){
        EXPECT_EQ(strcmp(listRoomInfoTmp[i].room.idRoom, info[i].room.idRoom), 0);
        EXPECT_EQ(strcmp(listRoomInfoTmp[i].room.nameRoom, info[i].room.nameRoom),0);
    }
    EXPECT_TRUE(status);
    
}

