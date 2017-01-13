#include <cstdlib>
#include <gtest/gtest.h>

#include "JsonParser.h"


class JsonParserTest : public ::testing::Test
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

TEST_F(JsonParserTest, TestparseOpenDoorJson_RESULT_OK)
{
    bool status = false;
    char* jsonString = NULL;
    CardInfo info;

    boost::property_tree::ptree pTree;
    char* rootENV = std::getenv("LIDT_ROOT");
    std::string jsonFilePath(rootENV);
    jsonFilePath.append("/testData/jsonFile/");
    jsonFilePath.append("arduinoJsonMessage_1.json");

    boost::property_tree::read_json(jsonFilePath, pTree);
    std::stringstream jsonStrStream;
    boost::property_tree::write_json(jsonStrStream, pTree);
    status = parseOpenDoorJson(jsonStrStream.str(),info);
    

    EXPECT_TRUE(status);
    EXPECT_TRUE(strcmp(info.data.cardID, "4897AB125")==0);
    EXPECT_TRUE(info.sender.port == 5600);
    EXPECT_TRUE(strcmp(info.sender.ip, "197.168.1.177") == 0);
}