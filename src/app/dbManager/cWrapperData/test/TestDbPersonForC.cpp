#include <gtest/gtest.h>
#include "DbCardForC.h"
#include "DbPerson.h"


static sql::Driver* MYSQL_DRIVER_INSTANCE = get_driver_instance();
static sql::Connection* MYSQL_DB_CONNECTION =
                    MYSQL_DRIVER_INSTANCE->connect(DBHOST, USER, PASSWORD);

class TestDbPersonForC : public ::testing::Test
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


TEST_F(TestDbPersonForC, TestSelectPersonForC_RESULT_OK)
{
    CardInfo* info = NULL;
    int numberOfElement = 0;

    CardInfo item;
    strcpy(item.person.idPerson,"U0001");
    strcpy(item.person.namePerson,"Ngan");
    item.person.age = 21;
    
    
    CardInfo item1;
    strcpy(item1.person.idPerson,"U0002");
    strcpy(item1.person.namePerson,"Ha");
    item1.person.age = 22;

    std::vector<CardInfo> vectorPersonInfos;

    vectorPersonInfos.push_back(item);
    vectorPersonInfos.push_back(item1);

    CardInfo* listPersonInfoTmp = new CardInfo[vectorPersonInfos.size()];
    int numberOfElement1 = vectorPersonInfos.size();

    for (int index = 0; index < numberOfElement1; index++)
    {
        strcpy((listPersonInfoTmp[index]).person.idPerson,
                                        vectorPersonInfos[index].person.idPerson);
        strcpy((listPersonInfoTmp[index]).person.namePerson,
                                        vectorPersonInfos[index].person.namePerson);

        (listPersonInfoTmp[index]).person.age = vectorPersonInfos[index].person.age;
    }

    bool status = selectToDbPersonForC(&info, &numberOfElement);
    
    for( int i = 0 ; i < vectorPersonInfos.size() ; i++){
        EXPECT_EQ(strcmp(listPersonInfoTmp[i].person.idPerson, info[i].person.idPerson), 0);
        EXPECT_EQ(strcmp(listPersonInfoTmp[i].person.namePerson, info[i].person.namePerson),0);
        EXPECT_EQ(listPersonInfoTmp[i].person.age, info[i].person.age);
    }
    EXPECT_TRUE(status);
    
}