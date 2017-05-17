#include <gtest/gtest.h>
#include "DbCardForC.h"
#include "DbDoorCard.h"


static sql::Driver* MYSQL_DRIVER_INSTANCE = get_driver_instance();
static sql::Connection* MYSQL_DB_CONNECTION =
                    MYSQL_DRIVER_INSTANCE->connect(DBHOST, USER, PASSWORD);

class TestDbDoorCardForC : public ::testing::Test
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


TEST_F(TestDbDoorCardForC, TestSelectDoorCardForC_RESULT_OK)
{
    CardInfo* info = NULL;
    int numberOfElement = 0;

    CardInfo item;
    strcpy(item.card.idCard,"5D2A821C");
    strcpy(item.door.idDoor,"C0001");
    
    
    CardInfo item1;
    strcpy(item1.card.idCard,"6628E6EC");
    strcpy(item1.door.idDoor,"C0002");
    
    std::vector<CardInfo> vectorDoorCardInfos;

    vectorDoorCardInfos.push_back(item);
    vectorDoorCardInfos.push_back(item1);

    CardInfo* listDoorCardInfoTmp = new CardInfo[vectorDoorCardInfos.size()];
    int numberOfElement1 = vectorDoorCardInfos.size();

    for (int index = 0; index < numberOfElement1; index++)
    {
        strcpy((listDoorCardInfoTmp[index]).card.idCard,
                                        vectorDoorCardInfos[index].card.idCard);
        strcpy((listDoorCardInfoTmp[index]).door.idDoor,
                                        vectorDoorCardInfos[index].door.idDoor);
    }

    bool status = selectToDbDoorCardForC(&info, &numberOfElement);

    for(int i = 0; i < vectorDoorCardInfos.size(); i++){
        EXPECT_EQ(strcmp(listDoorCardInfoTmp[i].card.idCard, info[i].card.idCard), 0);
        EXPECT_EQ(strcmp(listDoorCardInfoTmp[i].door.idDoor, info[i].door.idDoor),0);
    }
    EXPECT_TRUE(status);
    
}

