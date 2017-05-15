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


    bool status = selectToDbCardForC(&info, &numberOfElement);
    
    
    EXPECT_TRUE(status);
    
}