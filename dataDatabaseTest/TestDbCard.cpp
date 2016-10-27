#include <gtest/gtest.h>
#include "Card.h"
#include "DbCard.h"


class TestDbCard : public ::testing::Test
{
protected:
    void SetUp()
    {

    }
    void TearDown()
    {

    }
};


TEST_F(TestDbCard, TestGetSetCard)
{
    Card card;
    std::string kindCard("GCS2734");
    card.setKindCard(kindCard);

    EXPECT_STREQ(card.getKindCard().c_str(), kindCard.c_str());
}