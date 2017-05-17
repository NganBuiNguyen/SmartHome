#include <gtest/gtest.h>
#include "DbCardForC.h"
#include "DbHistory.h"


static sql::Driver* MYSQL_DRIVER_INSTANCE = get_driver_instance();
static sql::Connection* MYSQL_DB_CONNECTION =
                    MYSQL_DRIVER_INSTANCE->connect(DBHOST, USER, PASSWORD);

class TestDbHistoryForC : public ::testing::Test
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


TEST_F(TestDbHistoryForC, TestSelectHistoryForC_RESULT_OK)
{
    CardInfo* info = NULL;
    int numberOfElement = 0;

    CardInfo item;
    item.dateTime.day = 7;
    item.dateTime.month = 5; 
    item.dateTime.year = 2017;
    item.dateTime.hour = 9;
    item.dateTime.min = 42;
    item.dateTime.sec = 15;
    item.history.statusDoor = 1;
    item.history.checkCard = 1;

    
    CardInfo item1;
    item1.dateTime.day = 7;
    item1.dateTime.month = 5; 
    item1.dateTime.year = 2017;
    item1.dateTime.hour = 13;
    item1.dateTime.min = 12;
    item1.dateTime.sec = 35;
    item1.history.statusDoor = 1;
    item1.history.checkCard = 1;


    std::vector<CardInfo> vectorHistoryInfos;

    vectorHistoryInfos.push_back(item);
    vectorHistoryInfos.push_back(item1);

    CardInfo* listHistoryInfoTmp = new CardInfo[vectorHistoryInfos.size()];
    int numberOfElement1 = vectorHistoryInfos.size();

    for (int index = 0; index < numberOfElement1; index++)
    {
        (listHistoryInfoTmp[index]).dateTime.day = 
                                        vectorHistoryInfos[index].dateTime.day;
        (listHistoryInfoTmp[index]).dateTime.month = 
                                        vectorHistoryInfos[index].dateTime.month;
        (listHistoryInfoTmp[index]).dateTime.year = 
                                        vectorHistoryInfos[index].dateTime.year;
        (listHistoryInfoTmp[index]).dateTime.hour = 
                                        vectorHistoryInfos[index].dateTime.hour;
        (listHistoryInfoTmp[index]).dateTime.min = 
                                        vectorHistoryInfos[index].dateTime.min;
        (listHistoryInfoTmp[index]).dateTime.sec = 
                                        vectorHistoryInfos[index].dateTime.sec;                                                                                                
        (listHistoryInfoTmp[index]).history.statusDoor = 
                                        vectorHistoryInfos[index].history.statusDoor;
        (listHistoryInfoTmp[index]).history.checkCard = 
                                        vectorHistoryInfos[index].history.checkCard;
    }

    bool status = selectToDbHistoryForC(&info, &numberOfElement);

    for(int i = 0; i < vectorHistoryInfos.size(); i++){
        EXPECT_EQ(listHistoryInfoTmp[i].dateTime.day, info[i].dateTime.day); 
        EXPECT_EQ(listHistoryInfoTmp[i].dateTime.month, info[i].dateTime.month);
        EXPECT_EQ(listHistoryInfoTmp[i].dateTime.year, info[i].dateTime.year);
        EXPECT_EQ(listHistoryInfoTmp[i].dateTime.hour, info[i].dateTime.hour);
        EXPECT_EQ(listHistoryInfoTmp[i].dateTime.min, info[i].dateTime.min);
        EXPECT_EQ(listHistoryInfoTmp[i].dateTime.sec, info[i].dateTime.sec);
        EXPECT_EQ(listHistoryInfoTmp[i].history.statusDoor, info[i].history.statusDoor);
        EXPECT_EQ(listHistoryInfoTmp[i].history.checkCard, info[i].history.checkCard);
    }
    EXPECT_TRUE(status);
    
}

