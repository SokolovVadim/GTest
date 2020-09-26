#include <iostream>
#include <vector>
#include <string>
#include "gtest/gtest.h"
#include "gmock/gmock.h"

using ::testing::AtLeast;
using ::testing::Return;
using ::testing::_;

class DatabaseConnect
{
public:
	virtual bool login(const std::string& username, const std::string& password)
	{
		return true;
	}
	virtual bool logout(const std::string& username)
	{
		return true;
	}
	virtual int fetchRecord()
	{
		return EXIT_FAILURE;
	}
};

class MockDB: public DatabaseConnect
{
public:
	MOCK_METHOD0(fetchRecord, int());
    MOCK_METHOD1(logout, bool (const std::string& username));
	MOCK_METHOD2(login, bool (const std::string& username, const std::string& password));
};

class Database
{
public:
	Database(DatabaseConnect& db):
		db_(db)
	{}
	int Init(const std::string& username, const std::string& password)
	{
		if(db_.login(username, password) != true)
		{
			std::cout << "DB failure!\n";
			return EXIT_FAILURE;
		}
		else
		{
			std::cout << "DB succeeded!\n";
			return 0;
		}
	}
private:
	DatabaseConnect& db_;
};

TEST(DBTest, LoginTest0)
{
	// Arrange

	MockDB mdb{};
	Database db(mdb);

	EXPECT_CALL(mdb, login("Vadim", "onetwothree"))
	.Times(1)
	.WillOnce(Return(true));

	// Act

	int retVal = db.Init("Vadim", "onetwothree");

	// Assert

	EXPECT_EQ(retVal, 0);
}

TEST(DBTest, LoginTest1)
{
	// Arrange

	MockDB mdb{};
	Database db(mdb);

	EXPECT_CALL(mdb, login("Vadim", "onetwothree"))
	.Times(1)
	.WillOnce(Return(true));

	// Act

	int retVal = db.Init("Vadim", "onetwothree");

	// Assert

	EXPECT_EQ(retVal, 0);
}

int main(int argc, char* argv[])
{
	testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}
