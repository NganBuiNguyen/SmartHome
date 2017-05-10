#include <gtest/gtest.h>
#include "DbDoor.h"


static sql::Driver* MYSQL_DRIVER_INSTANCE = get_driver_instance();
static sql::Connection* MYSQL_DB_CONNECTION =
                    MYSQL_DRIVER_INSTANCE->connect(DBHOST, USER, PASSWORD);

class TestDbDoor : public ::testing::Test
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


TEST_F(TestDbDoor, TestSelectCard_RESULT_OK)
{
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
    
    std::vector<CardInfo> vectorCardInfos;

    vectorCardInfos.push_back(item);
    vectorCardInfos.push_back(item1);
    

    DbDoor dbdoor;
    std::vector<CardInfo*> vectorCardInfosResult;
    bool status = dbdoor.selectToDbDoor(vectorCardInfosResult);
    
    EXPECT_TRUE(status);
    printf("%d info\n", vectorCardInfos[1].door.port);

    printf("%d result\n", vectorCardInfosResult[1]->door.port);
    printf("%d \n", vectorCardInfosResult.size());

    
    for( int i = 0 ; i < vectorCardInfos.size() ; i++){
        EXPECT_EQ(strcmp(vectorCardInfos[i].door.idDoor, vectorCardInfosResult[i]->door.idDoor), 0);
        EXPECT_EQ(strcmp(vectorCardInfos[i].door.nameDoor, vectorCardInfosResult[i]->door.nameDoor),0);
        EXPECT_EQ(strcmp(vectorCardInfos[i].door.ip, vectorCardInfosResult[i]->door.ip),0);
        EXPECT_EQ(vectorCardInfos[i].door.port, vectorCardInfosResult[i]->door.port);
        EXPECT_EQ(strcmp(vectorCardInfos[i].door.idRoom, vectorCardInfosResult[i]->door.idRoom),0);
    }
}