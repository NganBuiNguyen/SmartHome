#include <cstdlib>
#include <gtest/gtest.h>

#include "JsonBuilder.h"

extern bool buildJsonMessageType(const MESSAGE_TYPE& messageType,
                                boost::property_tree::ptree& messageTypeTree);
extern bool buildCardOpenJson(const std::string& message,
                                    boost::property_tree::ptree& dataTree);

class JsonBuilderTest : public ::testing::Test
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

TEST_F(JsonBuilderTest, TestbuildJsonMessageType_RESULT_OK)
{
    boost::property_tree::ptree messageTypeTree;
    MESSAGE_TYPE messageType = MESSAGE_TYPE_LIGHT_INTENSITY;
    
    boost::property_tree::ptree expectedTree;
    expectedTree.put("MESSAGE_TYPE", "LIGHT_INTENSITY_VALUE");

    bool status = buildJsonMessageType(messageType, messageTypeTree);

    EXPECT_TRUE(status);
    EXPECT_EQ(expectedTree, messageTypeTree);
}

TEST_F(JsonBuilderTest, TestbuildJsonMessageType_MESSAGE_TYPE_DEFAULT)
{
    boost::property_tree::ptree messageTypeTree;
    MESSAGE_TYPE messageType = MESSAGE_TYPE_DEFAULT;
    
    bool status = buildJsonMessageType(messageType, messageTypeTree);

    EXPECT_FALSE(status);
}

TEST_F(JsonBuilderTest, TestbuildCardIntensityJson_RESULT_OK)
{
    boost::property_tree::ptree dataTree;
    std::string message("R123AB");
    
    boost::property_tree::ptree expectedTree;
    expectedTree.put("ID", "16963");

    bool status = buildCardOpenJson(message, dataTree);

    EXPECT_TRUE(status);
    EXPECT_EQ(expectedTree, dataTree);
}

TEST_F(JsonBuilderTest, TestbuildCardIntensityJson_NOT_SENSOR_MESSAGE)
{
    boost::property_tree::ptree dataTree;
    std::string message("R123AB");

    bool status = buildCardOpenJson(message, dataTree);

    EXPECT_FALSE(status);
}

TEST_F(JsonBuilderTest, TestbuildCardIntensityJson_NOT_LIGHT_MESSAGE)
{
    boost::property_tree::ptree dataTree;
    std::string message("CCBDA");

    bool status = buildCardOpenJson(message, dataTree);

    EXPECT_FALSE(status);
}

TEST_F(JsonBuilderTest, TestbuildJson_RESULT_OK)
{
    std::string jsonString;
    std::string message("LCBDA");

    boost::property_tree::ptree expectedTree;
    char* rootENV = std::getenv("LIDT_ROOT");
    std::string jsonFilePath(rootENV);
    jsonFilePath.append("/testedData/jsonFiles/");
    jsonFilePath.append("arduinoJsonMessage_1.json");

    boost::property_tree::read_json(jsonFilePath, expectedTree);

    bool status = buildJson(message, jsonString);
    boost::property_tree::ptree actualTree;
    
    std::stringstream stringStream(jsonString);
    boost::property_tree::read_json(stringStream, actualTree);

    EXPECT_TRUE(status);
    EXPECT_EQ(expectedTree, actualTree);
}

TEST_F(JsonBuilderTest, TestbuildJson_MESSAGE_TYPE_RESULT_FAILURE_1)
{
    std::string jsonString;
    std::string message("R123AB");

    bool status = buildJson(message, jsonString);

    EXPECT_FALSE(status);
}

TEST_F(JsonBuilderTest, TestbuildJson_RESULT_FAILURE_2)
{
    std::string jsonString;
    std::string message("CCBDA");

    bool status = buildJson(message, jsonString);

    EXPECT_FALSE(status);
}

TEST_F(JsonBuilderTest, TestbuildJson_RESULT_FAILURE_3)
{
    std::string jsonString;
    std::string message("R123AB");

    bool status = buildJson(message, jsonString);

    EXPECT_FALSE(status);
}