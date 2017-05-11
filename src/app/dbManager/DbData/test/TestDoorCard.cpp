#include <gtest/gtest.h>
#include "DbDoorCard.h"


static sql::Driver* MYSQL_DRIVER_INSTANCE = get_driver_instance();
static sql::Connection* MYSQL_DB_CONNECTION =
                    MYSQL_DRIVER_INSTANCE->connect(DBHOST, USER, PASSWORD);

class TestDbDoorCard : public ::testing::Test
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


TEST_F(TestDbDoorCard, TestSelectDoorCard_RESULT_OK)
{
    CardInfo item;
    strcpy(item.card.idCard,"5D2A821C");
    strcpy(item.door.idDoor,"C0001");
    
    
    
    CardInfo item1;
    strcpy(item1.card.idCard,"6628E6EC");
    strcpy(item1.door.idDoor,"C0002");
    
    
    std::vector<CardInfo> vectorCardInfos;

    vectorCardInfos.push_back(item);
    vectorCardInfos.push_back(item1);
    

    DbDoorCard dbDoorCard;
    std::vector<CardInfo*> vectorCardInfosResult;
    bool status = dbDoorCard.selectToDbDoorCard(vectorCardInfosResult);
    
    EXPECT_TRUE(status);
    // printf("%d info\n", vectorCardInfos[1].door.port);

    // printf("%d result\n", vectorCardInfosResult[1]->door.port);
    // printf("%d \n", vectorCardInfosResult.size());

    
    for( int i = 0 ; i < vectorCardInfos.size() ; i++){
        EXPECT_EQ(strcmp(vectorCardInfos[i].card.idCard, vectorCardInfosResult[i]->card.idCard),0);
        EXPECT_EQ(strcmp(vectorCardInfos[i].door.idDoor, vectorCardInfosResult[i]->door.idDoor), 0);
        
    }
}