#include <gtest/gtest.h>
#include "Card.h"
#include "DbCard.h"

extern sql::Driver* MYSQL_DRIVER_INSTANCE = get_driver_instance();
extern sql::Connection* MYSQL_DB_CONNECTION =
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
    std::vector<CardInfo>& vectorCardInfos;
    std::vector<CardInfo>& vectorCardInfosResult;

    CardInfo* item = new CardInfo;
    strcpy(item->card.idCard,"5D2A821C");
    strcpy(item->card.typeCard,"admin");
    item->card.idPerson = res->getInt(1);
    vectorCardInfos.push_back(*item);

    CardInfo* item1 = new CardInfo;
    strcpy(item1->card.idCard,"6628E6EC");
    strcpy(item1->card.typeCard,"admin");
    item1->card.idPerson = res->getInt(2);
    vectorCardInfos.push_back(*item1);

    bool status = selectToDbCard(vectorCardInfosResult);
    
    EXPECT_TRUE(status);
    EXPECT_EQ(vectorCardInfos, vectorCardInfosResult);
}