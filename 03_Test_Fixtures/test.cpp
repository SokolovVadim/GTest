#include <iostream>
#include <vector>
#include "gtest/gtest.h"

class Student
{
public:
	Student(int age):
		age_(age)
	{}
	void Increment(int value)
	{
		age_ += value;
	}
	int getAge() const
	{
		return age_;
	}
private:
	int age_;
};

struct StudentTest: public testing::Test
{
	void SetUp()
	{
		std::cout << "Alive\n";
		sp = new Student(20);
	}
	void TearDown()
	{
		std::cout << "Dead\n";
		delete sp;
	}
	Student* sp;
};

// Fixture

TEST_F( StudentTest, Increment_by_1)
{
	// Act

	sp->Increment(1);

	// Assert

	ASSERT_EQ(sp->getAge(), 21);
}

TEST_F( StudentTest, Increment_by_10)
{
	// Act

	sp->Increment(10);

	// Assert

	ASSERT_EQ(sp->getAge(), 30);
}

TEST( StudentTesting, Increment_by_1)
{
	// Arrange 
	
	Student Vadim(20);

	// Act

	Vadim.Increment(1);

	// Assert

	ASSERT_EQ(Vadim.getAge(), 21);
}

TEST( StudentTesting, Increment_by_10)
{
	// Arrange 
	
	Student Vadim(20);

	// Act

	Vadim.Increment(10);

	// Assert

	ASSERT_EQ(Vadim.getAge(), 30);
}

class Stack
{
public:
	void push(int value)
	{
		vstack_.push_back(value);
	}
	int pop()
	{
		if(vstack_.size() > 0)
		{
			int value = vstack_.back();
			vstack_.pop_back();
			return value;
		}
		else
		{
			return EXIT_FAILURE;
		}
	}
	int size()
	{
		return vstack_.size();
	}
private:
	std::vector<int> vstack_;
};

struct StackTest: public testing::Test
{
	Stack stk{};
	void SetUp()
	{
		int value[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
		for(auto & val: value)
		{
			stk.push(val);
		}
	}
	
};

TEST_F(StackTest, PopTest)
{
	int last_popped_value(9);
	while(last_popped_value != 0)
	{
		EXPECT_EQ(stk.pop(), last_popped_value--);
	}
}

TEST_F(StackTest, SizeValidityTest)
{
	int size = stk.size();
	for(size; size > 0; size--)
	{
		ASSERT_NE(stk.pop(), -1);
	}
}


int main(int argc, char* argv[])
{
	testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}
