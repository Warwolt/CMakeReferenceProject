#include "add.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h> // just checking includes

class AddTest : public ::testing::Test
{
protected:
    void SetUp() override
    {
        //
    }
};

TEST_F(AddTest, Sum_of_positive_terms_is_positive)
{
    EXPECT_EQ(add(2, 3), 5);
}

TEST_F(AddTest, Sums_are_commutative)
{
    EXPECT_EQ(add(7, 9), add(9, 7));
}

TEST_F(AddTest, Integers_have_inverse_element)
{
    EXPECT_EQ(add(13, -13), 0);
}
