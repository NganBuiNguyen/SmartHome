/****************************************************************************/
/*!
 * @file LightIntensityTest.cpp
 * @brief Unittest for LightIntensity class
 *
 * Copyright (c) Tien Nguyen Anh 2016 
 *
 * @detail The testing file of the implementation of LightIntensity class
 */
/****************************************************************************/

#include <gtest/gtest.h>

#include "LightIntensity.h"

class LightIntensityTest : public ::testing::Test
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

TEST_F(LightIntensityTest, TestDefaultConstructorAndGetter)
{
    LightIntensity lightIntensity;
    EXPECT_EQ(0, lightIntensity.getLightIntensity());
    EXPECT_EQ(0, lightIntensity.getMoment());
}
