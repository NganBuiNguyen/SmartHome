#include <gtest/gtest.h>
#include "Status.h"


class StatusTest : public ::testing::Test
{
protected:
    void SetUp()
    {
    }
  
    void TearDown()
    {
    }
};


TEST_F(StatusTest , testGetSetName)
{
    Status st;
    bool status;
    status= false;
    st.setSatusName(status);

    ASSERT_FALSE(st.getStatusName());
}


