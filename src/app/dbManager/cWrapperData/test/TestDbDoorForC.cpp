#include <gtest/gtest.h>
#include "DbCardForC.h"
#include "DbDoor.h"


static sql::Driver* MYSQL_DRIVER_INSTANCE = get_driver_instance();
static sql::Connection* MYSQL_DB_CONNECTION =
                    MYSQL_DRIVER_INSTANCE->connect(DBHOST, USER, PASSWORD);

class TestDbDoorForC : public ::testing::Test
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


TEST_F(TestDbDoorForC, TestSelectDoorForC_RESULT_OK)
{
    CardInfo* info = NULL;
    int numberOfElement = 0;

    CardInfo item;
    strcpy(item.door.idDoor,"C0001");
    strcpy(item.door.nameDoor,"Cua1");
    strcpy(item.door.ip,"192.168.3.100");
    item.door.port = 5563;
    strcpy(item.door.idRoom,"P0001");
    
    
    CardInfo item1;
    strcpy(item1.door.idDoor,"C0002");
    strcpy(item1.door.nameDoor,"Cua2");
    strcpy(item1.door.ip,"192.168.3.100");
    item1.door.port = 5563;
    strcpy(item1.door.idRoom,"P0002");
    
    std::vector<CardInfo> vectorDoorInfos;

    vectorDoorInfos.push_back(item);
    vectorDoorInfos.push_back(item1);

    CardInfo* listDoorInfoTmp = new CardInfo[vectorDoorInfos.size()];
    int numberOfElement1 = vectorDoorInfos.size();

    for (int index = 0; index < numberOfElement1; index++)
    {
        strcpy((listDoorInfoTmp[index]).door.idDoor,
                                        vectorDoorInfos[index].door.idDoor);
        strcpy((listDoorInfoTmp[index]).door.nameDoor,
                                        vectorDoorInfos[index].door.nameDoor);
        strcpy((listDoorInfoTmp[index]).door.ip,
                                        vectorDoorInfos[index].door.ip);

        (listDoorInfoTmp[index]).door.port = vectorDoorInfos[index].door.port;
        
        strcpy((listDoorInfoTmp[index]).door.idRoom,
                                        vectorDoorInfos[index].door.idRoom);
    }

    bool status = selectToDbDoorForC(&info, &numberOfElement);
    
    for( int i = 0 ; i < vectorDoorInfos.size() ; i++){
        EXPECT_EQ(strcmp(listDoorInfoTmp[i].door.idDoor, info[i].door.idDoor), 0);
        EXPECT_EQ(strcmp(listDoorInfoTmp[i].door.nameDoor, info[i].door.nameDoor),0);
        EXPECT_EQ(strcmp(listDoorInfoTmp[i].door.ip, info[i].door.ip),0);
        EXPECT_EQ(listDoorInfoTmp[i].door.port, info[i].door.port);
        EXPECT_EQ(strcmp(listDoorInfoTmp[i].door.idRoom, info[i].door.idRoom),0);
    }
    EXPECT_TRUE(status);
    
}