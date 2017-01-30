#include <gtest/gtest.h>

#include "common.h"

class CommonTest : public ::testing::Test
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

TEST_F(CommonTest, TestisSensorMessage_RESULT_OK)
{
    const std::string message("R123124;311246:124");
    bool status = isSensorMessage(message);
    EXPECT_TRUE(status);
}

TEST_F(CommonTest, TestisSensorMessage_RESULT_FAILURE_1)
{
    const std::string message("RCAD");
    bool status = isSensorMessage(message);
    EXPECT_FALSE(status);
}

TEST_F(CommonTest, TestisSensorMessage_RESULT_FAILURE_2)
{
    const std::string message("");
    bool status = isSensorMessage(message);
    EXPECT_FALSE(status);
}

TEST_F(CommonTest, TestisSensorMessage_RESULT_FAILURE_3)
{
    const std::string message("R123AHF");
    bool status = isSensorMessage(message);
    EXPECT_FALSE(status);
}

TEST_F(CommonTest, TestgetJSONMessageType_MESSAGE_TYPE_CARD)
{   
	const std::string message("RADB");
    MESSAGE_TYPE messageType = getJSONMessageType(message);
    EXPECT_EQ(messageType, MESSAGE_TYPE_CARD);
}

TEST_F(CommonTest, TestgetJSONMessageType_NOT_SENSOR_MESSAGE)
{
    const std::string message("NLCAD");
    MESSAGE_TYPE messageType = getJSONMessageType(message);
    EXPECT_EQ(messageType, MESSAGE_TYPE_DEFAULT);
}

TEST_F(CommonTest, TestgetJSONMessageType_DEFAULT_TYPE)
{
    const std::string message("NCADB");
    MESSAGE_TYPE messageType = getJSONMessageType(message);
    EXPECT_EQ(messageType, MESSAGE_TYPE_DEFAULT);
}
