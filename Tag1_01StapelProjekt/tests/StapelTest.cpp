#include "StapelTest.h"
// Given_emptyStack_when_is_empty_called_then_returns_true
TEST_F(StapelTest, is_empty__empty_stack__returnsTrue)
{
	// Arrange

	// Act
	bool result = object_under_test.is_empty();

	// Assertion
	EXPECT_TRUE(result);
}

TEST_F(StapelTest, is_empty__not_empty_stack__returnsFalse)
{
	// Arrange
	object_under_test.push(1);
	
	// Act
	bool result = object_under_test.is_empty();

	// Assertion
	EXPECT_FALSE(result);
}

TEST_F(StapelTest, is_empty__empty_again_stack__returnsFalse)
{
	// Arrange
	object_under_test.push(1);
	object_under_test.pop();

	// Act
	bool result = object_under_test.is_empty();

	// Assertion
	EXPECT_TRUE(result);
}

TEST_F(StapelTest, is_empty__fill_up_limit__no_exception_is_thrown)
{
	// Arrange + Act + Assertion
	fill_up_to_limit();
	
	
}

TEST_F(StapelTest, is_empty__overflow__stapelexception_exception_is_thrown)
{
	// Arrange + Act + Assertion
	fill_up_to_limit();
	EXPECT_THROW(object_under_test.push(1), StapelException);
	
}

TEST_F(StapelTest, is_empty__overflow__stapelexception_exception_is_thrown_and_errormessage_is_overflow)
{
	try {
		fill_up_to_limit();
		object_under_test.push(1);
		FAIL() << "Fehler: Exception erwartet";
	} catch (const StapelException &ex)
	{
		EXPECT_STREQ("Overflow", ex.what());
	}
}