#include "StapelTest.h"

TEST_F(StapelTest, test_1)
{
	EXPECT_TRUE(object_under_test.is_empty());
}

TEST_F(StapelTest, test_2)
{
	object_under_test.push(1);
	EXPECT_FALSE(object_under_test.is_empty());
}