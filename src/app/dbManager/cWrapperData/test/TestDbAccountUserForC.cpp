#include <gtest/gtest.h>
#include "DbCardForC.h"
#include "DbAccountUser.h"


static sql::Driver* MYSQL_DRIVER_INSTANCE = get_driver_instance();
static sql::Connection* MYSQL_DB_CONNECTION =
                    MYSQL_DRIVER_INSTANCE->connect(DBHOST, USER, PASSWORD);

class TestDbAccountUserForC : public ::testing::Test
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


TEST_F(TestDbAccountUserForC, TestSelectAccountUserForC_RESULT_OK)
{
    CardInfo* info = NULL;
    int numberOfElement = 0;

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

    std::vector<CardInfo> vectorAccountUserInfos;

    vectorAccountUserInfos.push_back(item);
    vectorAccountUserInfos.push_back(item1);

    CardInfo* listAccountUserInfoTmp = new CardInfo[vectorAccountUserInfos.size()];
    int numberOfElement1 = vectorAccountUserInfos.size();

    for (int index = 0; index < numberOfElement1; index++)
    {
        strcpy((listAccountUserInfoTmp[index]).person.idPerson,
                                        vectorAccountUserInfos[index].person.idPerson);
        (listAccountUserInfoTmp[index]).person.grantPerson = 
                                        vectorAccountUserInfos[index].person.grantPerson;
        strcpy((listAccountUserInfoTmp[index]).person.userName,
                                        vectorAccountUserInfos[index].person.userName);
        strcpy((listAccountUserInfoTmp[index]).person.password,
                                        vectorAccountUserInfos[index].person.password);
    }

    bool status = selectToDbAccountUserForC(&info, &numberOfElement);
    
    for( int i = 0 ; i < vectorAccountUserInfos.size() ; i++){
        EXPECT_EQ(strcmp(listAccountUserInfoTmp[i].person.idPerson, info[i].person.idPerson), 0);
        EXPECT_EQ(listAccountUserInfoTmp[i].person.grantPerson, info[i].person.grantPerson);
        EXPECT_EQ(strcmp(listAccountUserInfoTmp[i].person.userName, info[i].person.userName),0);
        EXPECT_EQ(strcmp(listAccountUserInfoTmp[i].person.password, info[i].person.password),0);
        
    }
    EXPECT_TRUE(status);
}