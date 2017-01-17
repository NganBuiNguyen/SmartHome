#include <iostream>
#include <string.h>
#include <string>
#include <math.h>
#include <regex>
#include <cstdlib>

#include <gtest/gtest.h>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

#include "JsonParserForC.h"


class JsonParserForCTest : public ::testing::Test
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

TEST_F(JsonParserForCTest, TestparseOpenDoorJson_RESULT_OK)
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

    status = parseOpenDoorJsonForC(jsonStrStream.str().c_str(), &info);

    EXPECT_TRUE(status);
    EXPECT_TRUE(strcmp(info.data.cardID,"4897AB125")==0);
    EXPECT_TRUE(info.sender.port == 5600);
    EXPECT_TRUE(strcmp(info.sender.ip, "192.168.1.177") == 0);
}