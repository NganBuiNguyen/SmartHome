#include <gtest/gtest.h>
#include "DbPerson.h"


static sql::Driver* MYSQL_DRIVER_INSTANCE = get_driver_instance();
static sql::Connection* MYSQL_DB_CONNECTION =
                    MYSQL_DRIVER_INSTANCE->connect(DBHOST, USER, PASSWORD);

class TestDbPerson : public ::testing::Test
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


TEST_F(TestDbPerson, TestSelectInfoUser_RESULT_OK)
{
    CardInfo item;
    strcpy(item.person.idPerson,"U0001");
    strcpy(item.person.namePerson,"Ngan");
    item.person.age = 21;
    
    
    CardInfo item1;
    strcpy(item1.person.idPerson,"U0002");
    strcpy(item1.person.namePerson,"Ha");
    item1.person.age = 22;

    std::vector<CardInfo> vectorInfoUserInfos;

    vectorInfoUserInfos.push_back(item);
    vectorInfoUserInfos.push_back(item1);
    

    DbPerson dbperson;
    std::vector<CardInfo*> vectorInfoUserInfosResult;
    bool status = dbperson.selectToDbInfoUser(vectorInfoUserInfosResult);
    
    EXPECT_TRUE(status);
    printf("%s \n", vectorInfoUserInfos[0].person.idPerson);
    printf("%d \n", vectorInfoUserInfos[0].person.age);

    printf("%s \n", vectorInfoUserInfosResult[0]->person.idPerson);
    printf("%d \n", vectorInfoUserInfosResult[0]->person.age);
    printf("%d \n", vectorInfoUserInfosResult.size());

    
    for( int i = 0 ; i < vectorInfoUserInfos.size() ; i++){
        EXPECT_EQ(strcmp(vectorInfoUserInfos[i].person.idPerson, vectorInfoUserInfosResult[i]->person.idPerson), 0);
        EXPECT_EQ(strcmp(vectorInfoUserInfos[i].person.namePerson, vectorInfoUserInfosResult[i]->person.namePerson), 0);
        EXPECT_EQ(vectorInfoUserInfos[i].person.age, vectorInfoUserInfosResult[i]->person.age);
    }
}