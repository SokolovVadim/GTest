#include <iostream>
#include "gtest/gtest.h"

// Only one EQ | Assertion for the test
// Arrange -> Act -> Assert

TEST( TEST_STRUCTURE, Increment_by_5)
{
	// Arrange 
	int value = 100;
	int increment = 5;

	// Act

	value += increment;

	// Assert

	ASSERT_EQ(value, 105);
}

TEST( TEST_STRUCTURE, Increment_by_10)
{
	// Arrange 
	int value = 100;
	int increment = 10;

	// Act

	value += increment;

	// Assert

	ASSERT_EQ(value, 110);
}

class Student
{
public:
	Student(const std::string& name):
		name_(name)
	{}
	std::string GetName() const
	{
		return name_;
	}
private:
	std::string name_;
};

TEST( TEST_STRUCTURE, Student)
{
	// Arrange 
	
	Student Vadim("Vadim");

	// Act

	std::string name = Vadim.GetName();

	// Assert

	ASSERT_STREQ(name.c_str(), "Vadim");
}



int main(int argc, char* argv[])
{
	testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}