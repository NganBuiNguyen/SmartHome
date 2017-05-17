#include <gtest/gtest.h>
#include "DbCardForC.h"
#include "DbCard.h"


static sql::Driver* MYSQL_DRIVER_INSTANCE = get_driver_instance();
static sql::Connection* MYSQL_DB_CONNECTION =
                    MYSQL_DRIVER_INSTANCE->connect(DBHOST, USER, PASSWORD);

class TestDbCardForC : public ::testing::Test
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


TEST_F(TestDbCardForC, TestSelectCardForC_RESULT_OK)
{
    CardInfo* info = NULL;
    int numberOfElement = 0;

    CardInfo item;
    strcpy(item.card.idCard,"5D2A821C");
    strcpy(item.card.idPerson,"U0001");
    
    CardInfo item1;
    strcpy(item1.card.idCard,"6628E6EC");
    strcpy(item1.card.idPerson,"U0002");
    
    std::vector<CardInfo> vectorCardInfos;

    vectorCardInfos.push_back(item);
    vectorCardInfos.push_back(item1);

    CardInfo* listCardInfoTmp = new CardInfo[vectorCardInfos.size()];
    int numberOfElement1 = vectorCardInfos.size();

    for (int index = 0; index < numberOfElement1; index++)
    {
        strcpy((listCardInfoTmp[index]).card.idCard,
                                        vectorCardInfos[index].card.idCard);
        strcpy((listCardInfoTmp[index]).card.idPerson,
                                        vectorCardInfos[index].card.idPerson);
    }

    bool status = selectToDbCardForC(&info, &numberOfElement);

    for( int i = 0 ; i < vectorCardInfos.size() ; i++){
        EXPECT_EQ(strcmp(listCardInfoTmp[i].card.idCard, info[i].card.idCard), 0);
        EXPECT_EQ(strcmp(listCardInfoTmp[i].card.idPerson, info[i].card.idPerson),0);
    }
    EXPECT_TRUE(status);
    
}

