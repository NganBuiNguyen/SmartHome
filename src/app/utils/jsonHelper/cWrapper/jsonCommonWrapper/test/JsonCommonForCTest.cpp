#include <gtest/gtest.h>

#include "JsonCommonForC.h"

class JsonCommonForCTest : public ::testing::Test
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

TEST_F(JsonCommonForCTest, TestisSensorMessage_RESULT_OK)
{
    std::string message("R4897AB125;192.168.1.177:5600");
    bool status = isSensorMessageForC(message.c_str());
    EXPECT_TRUE(status);
}

TEST_F(JsonCommonForCTest, TestisSensorMessage_RESULT_FAILURE_1)
{
    std::string message("R4897AB125");
    bool status = isSensorMessageForC(message.c_str());
    EXPECT_FALSE(status);
}

TEST_F(JsonCommonForCTest, TestisSensorMessage_RESULT_FAILURE_2)
{
    std::string message("");
    bool status = isSensorMessageForC(message.c_str());
    EXPECT_FALSE(status);
}

TEST_F(JsonCommonForCTest, TestisSensorMessage_RESULT_FAILURE_3)
{
    std::string message("R4897AB125");
    bool status = isSensorMessageForC(message.c_str());
    EXPECT_FALSE(status);
}

TEST_F(JsonCommonForCTest,
						TestgetJSONMessageType_MESSAGE_TYPE_CARD)
{
    std::string message("R4897AB125");
    MESSAGE_TYPE messageType;
    getJSONMessageTypeForC(message.c_str(), &messageType);

    EXPECT_EQ(messageType, MESSAGE_TYPE_CARD);
}

TEST_F(JsonCommonForCTest, TestgetJSONMessageType_NOT_SENSOR_MESSAGE)
{
    std::string message("L4897AB125");
    MESSAGE_TYPE messageType;
    getJSONMessageTypeForC(message.c_str(), &messageType);

    EXPECT_EQ(messageType, MESSAGE_TYPE_DEFAULT);
}

TEST_F(JsonCommonForCTest, TestgetJSONMessageType_DEFAULT_TYPE)
{
    std::string message("NCADB");
    MESSAGE_TYPE messageType;
    getJSONMessageTypeForC(message.c_str(), &messageType);

    EXPECT_EQ(messageType, MESSAGE_TYPE_DEFAULT);
}