#include <gtest/gtest.h>
#include "DbHistory.h"


static sql::Driver* MYSQL_DRIVER_INSTANCE = get_driver_instance();
static sql::Connection* MYSQL_DB_CONNECTION =
                    MYSQL_DRIVER_INSTANCE->connect(DBHOST, USER, PASSWORD);

class TestDbHistory : public ::testing::Test
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


TEST_F(TestDbHistory, TestSelectHistory_RESULT_OK)
{
    CardInfo item;
    strcpy(item.card.idCard,"5D2A821C");
    strcpy(item.ip_port.ip,"192.168.3.100");
    item.ip_port.port = 5563;
    item.dateTime.day = 7;
    item.dateTime.month = 5; 
    item.dateTime.year = 2017;
    item.dateTime.hour = 9;
    item.dateTime.min = 42;
    item.dateTime.sec = 15;


    
    CardInfo item1;
    strcpy(item.card.idCard,"5D2A821C");
    strcpy(item.ip_port.ip,"192.168.3.100");
    item.ip_port.port = 5563;
    item.dateTime.day = 7;
    item.dateTime.month = 5; 
    item.dateTime.year = 2017;
    item.dateTime.hour = 13;
    item.dateTime.min = 12;
    item.dateTime.sec = 35;


    std::vector<CardInfo> vectorCardInfos;

    vectorCardInfos.push_back(item);
    vectorCardInfos.push_back(item1);
    

    DbHistory dbHistory;
    std::vector<CardInfo*> vectorCardInfosResult;
    bool status = dbHistory.selectToDbHistory(vectorCardInfosResult);
    
    EXPECT_TRUE(status);
    // printf("%s \n", vectorCardInfos[1].card.idCard);

    printf("%s IP \n", vectorCardInfosResult[1]->ip_port.ip);
    printf("%lf Port \n", vectorCardInfosResult[1]->ip_port.port);
    printf("%d Day \n", vectorCardInfosResult[1]->dateTime.day);
    printf("%d Sec \n", vectorCardInfosResult[1]->dateTime.sec);

    // printf("%s IP \n", vectorCardInfosResult[1]->ip_port.ip);
    // printf("%d \n", vectorCardInfosResult.size());

    
    for( int i = 0 ; i < vectorCardInfos.size() ; i++){
        EXPECT_EQ(strcmp(vectorCardInfos[i].card.idCard, vectorCardInfosResult[i]->card.idCard), 0);
        EXPECT_EQ(strcmp(vectorCardInfos[i].ip_port.ip, vectorCardInfosResult[i]->ip_port.ip),0);
        EXPECT_EQ(vectorCardInfos[i].ip_port.port, vectorCardInfosResult[i]->ip_port.port);
        EXPECT_EQ(vectorCardInfos[i].dateTime.day, vectorCardInfosResult[i]->dateTime.day); 
        EXPECT_EQ(vectorCardInfos[i].dateTime.month, vectorCardInfosResult[i]->dateTime.month);
        EXPECT_EQ(vectorCardInfos[i].dateTime.year, vectorCardInfosResult[i]->dateTime.year);
        EXPECT_EQ(vectorCardInfos[i].dateTime.hour, vectorCardInfosResult[i]->dateTime.hour);
        EXPECT_EQ(vectorCardInfos[i].dateTime.min, vectorCardInfosResult[i]->dateTime.min);
        EXPECT_EQ(vectorCardInfos[i].dateTime.sec, vectorCardInfosResult[i]->dateTime.sec);
    }
}