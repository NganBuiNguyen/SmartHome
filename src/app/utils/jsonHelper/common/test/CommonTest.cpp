#include <gtest/gtest.h>

#include "common.h"

class JsonCommonTest : public ::testing::Test
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

TEST_F(JsonCommonTest, TestisSensorMessage)
{
    std::string message("R123AB");
    isSensorMessage(message);
}