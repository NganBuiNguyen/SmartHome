#include <gtest/gtest.h>
#include "DbCard.h"


static sql::Driver* MYSQL_DRIVER_INSTANCE = get_driver_instance();
static sql::Connection* MYSQL_DB_CONNECTION =
                    MYSQL_DRIVER_INSTANCE->connect(DBHOST, USER, PASSWORD);

class TestDbCard : public ::testing::Test
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


TEST_F(TestDbCard, TestSelectCard_RESULT_OK)
{
    CardInfo item;
    strcpy(item.card.idCard,"5D2A821C");
    strcpy(item.card.idPerson,"U0001");
    
    CardInfo item1;
    strcpy(item1.card.idCard,"6628E6EC");
    strcpy(item1.card.idPerson,"U0002");
    
    std::vector<CardInfo> vectorCardInfos;

    vectorCardInfos.push_back(item);
    vectorCardInfos.push_back(item1);
    

    DbCard dbcard;
    std::vector<CardInfo*> vectorCardInfosResult;
    bool status = dbcard.selectToDbCard(vectorCardInfosResult);
    
    EXPECT_TRUE(status);
    printf("%s \n", vectorCardInfos[1].card.idCard);

    printf("%s \n", vectorCardInfosResult[1]->card.idCard);
    printf("%d \n", vectorCardInfosResult.size());

    
    for( int i = 0 ; i < vectorCardInfos.size() ; i++){
        EXPECT_EQ(strcmp(vectorCardInfos[i].card.idCard, vectorCardInfosResult[i]->card.idCard), 0);
        EXPECT_EQ(strcmp(vectorCardInfos[i].card.idPerson, vectorCardInfosResult[i]->card.idPerson),0);
    }
}