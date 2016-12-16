#include <gtest/gtest.h>
#include "Person.h"

class PersonTest : public ::testing::Test
{
protected:
    void SetUp()
    {
    }

    void TearDown()
    {
    }

};

TEST_F(PersonTest, TestGetSetID)
{
    Person person;
    std::string personID("GCS2734");
    person.setPersonID(personID);

    EXPECT_STREQ(person.getPersonID().c_str(), personID.c_str());
}
