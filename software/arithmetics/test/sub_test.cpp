#include "sub.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h> // just checking includes

class SubTest : public ::testing::Test
{
protected:
    void SetUp() override
    {
        //
    }
};

TEST_F(SubTest, Difference_between_two_terms_less_than_the_terms)
{
    EXPECT_TRUE(sub(5, 3) < 5);
    EXPECT_TRUE(sub(5, 3) < 3);
}

TEST_F(SubTest, Differences_are_not_associatve)
{
    EXPECT_NE(sub(11, sub(9, 7)), sub(sub(11, 9), 7));
}

TEST_F(SubTest, Elements_are_their_own_inverse_under_subtraction)
{
    EXPECT_EQ(sub(13, 13), 0);
}
