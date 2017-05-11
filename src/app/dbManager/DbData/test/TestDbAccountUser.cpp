#include <gtest/gtest.h>
#include "DbAccountUser.h"


static sql::Driver* MYSQL_DRIVER_INSTANCE = get_driver_instance();
static sql::Connection* MYSQL_DB_CONNECTION =
                    MYSQL_DRIVER_INSTANCE->connect(DBHOST, USER, PASSWORD);

class TestDbAccountUser : public ::testing::Test
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


TEST_F(TestDbAccountUser, TestSelectInfoUser_RESULT_OK)
{
    CardInfo item;
    strcpy(item.person.idPerson,"U0001");
    item.person.grantPerson = true;
    strcpy(item.person.userName,"kimnganbui");
    strcpy(item.person.password,"nganit123");

    
    
    CardInfo item1;
    strcpy(item1.person.idPerson,"U0002");
    item1.person.grantPerson = false;
    strcpy(item1.person.userName,"hongha17");
    strcpy(item1.person.password,"hongha123");

    std::vector<CardInfo> vectorInfoUserInfos;

    vectorInfoUserInfos.push_back(item);
    vectorInfoUserInfos.push_back(item1);
    

    DbAccountUser dbAccountUser;
    std::vector<CardInfo*> vectorInfoUserInfosResult;
    bool status = dbAccountUser.selectToDbAccountUser(vectorInfoUserInfosResult);
    
    EXPECT_TRUE(status);
    printf("%s \n", vectorInfoUserInfos[0].person.idPerson);
    printf("%d \n", vectorInfoUserInfos[0].person.grantPerson);

    printf("%s \n", vectorInfoUserInfosResult[0]->person.idPerson);
    printf("%d \n", vectorInfoUserInfosResult[0]->person.grantPerson);
    printf("%d \n", vectorInfoUserInfosResult.size());

    
    for( int i = 0 ; i < vectorInfoUserInfos.size() ; i++){
        EXPECT_EQ(strcmp(vectorInfoUserInfos[i].person.idPerson, vectorInfoUserInfosResult[i]->person.idPerson), 0);
        EXPECT_EQ(vectorInfoUserInfos[i].person.grantPerson, vectorInfoUserInfosResult[i]->person.grantPerson);
        EXPECT_EQ(strcmp(vectorInfoUserInfos[i].person.userName, vectorInfoUserInfosResult[i]->person.userName), 0);
        EXPECT_EQ(strcmp(vectorInfoUserInfos[i].person.password, vectorInfoUserInfosResult[i]->person.password), 0);
    }
}