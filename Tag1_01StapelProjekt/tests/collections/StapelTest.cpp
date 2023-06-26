#include "StapelTest.h"

namespace  collections
{
	TEST_F(StapelTest, is_empty__emptyStack__returnsTrue)
	{
		// Arrange
		

		//Act
		auto result = objectUnderTest.is_empty();

		// Assertion
		EXPECT_TRUE(result);
	}

	TEST_F(StapelTest, is_empty__notEmptyStack__returnsFalse)
	{
		// Arrange
		
		objectUnderTest.push(1);

		//Act
		auto result = objectUnderTest.is_empty();

		// Assertion
		EXPECT_FALSE(result);
	}

	TEST_F(StapelTest, push__fillupToLimit__noExceptionIsThrown)
	{
		// Arrange
		fillUpToLimit();
		
	}
	TEST_F(StapelTest, push__overflow__throwsStapelException)
	{
		// Arrange
		fillUpToLimit();

		//Act + Assertion
		EXPECT_THROW(objectUnderTest.push(1), StapelException);

	}
	TEST_F(StapelTest, push__overflow__throwsStapelException__alternative)
	{
		try {
			// Arrange
			fillUpToLimit();

			//Act
			objectUnderTest.push(1);
			FAIL() << "Exception erwartet";
			
		} catch (const StapelException & ex)
		{
			EXPECT_STREQ("Overflow", ex.what());
		}

	}
	
}
