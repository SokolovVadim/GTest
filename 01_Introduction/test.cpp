#include <iostream>
#include "gtest/gtest.h"


TEST(TestAssert, Subtest0)
{
	ASSERT_TRUE(1 == 1);
}

TEST(TestAssert, Subtest1)
{
	ASSERT_FALSE(1 == 0);
}

// ----------------------------------------

// fatal error

TEST(TestEQ, Subtest0)
{
	ASSERT_EQ(1, 0);
	std::cout << "After assertion\n";
}

// Non fatal error

TEST(TestEQ, Subtest1)
{
	EXPECT_EQ(1, 0);
	std::cout << "After assertion\n";
}

// ----------------------------------------

// Not equal

TEST(TestNE, Subtest0)
{
	ASSERT_NE(1, 0);
}

TEST(TestNE, Subtest1)
{
	EXPECT_NE(1, 0);
}

// ----------------------------------------

// Less than

TEST(TestLT, Subtest0)
{
	ASSERT_LT(0, 1);
}

TEST(TestLT, Subtest1)
{
	EXPECT_LT(0, 1);
}

// ----------------------------------------

// Less than equal

TEST(TestLE, Subtest0)
{
	ASSERT_LE(1, 1);
}

TEST(TestLE, Subtest1)
{
	EXPECT_LE(0, 1);
}

// ----------------------------------------

// Greater than

TEST(TestGT, Subtest0)
{
	ASSERT_GT(1, 0);
}

TEST(TestGT, Subtest1)
{
	EXPECT_GT(1, 0);
}

// ----------------------------------------

// Greater than equal

TEST(TestGE, Subtest0)
{
	ASSERT_GE(1, 0);
}

TEST(TestGE, Subtest1)
{
	EXPECT_GE(1, 1);
}

// ----------------------------------------

int main(int argc, char* argv[])
{
	testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}