#pragma once

#include "pch.h"

class test_resource
{
private:
	std::string test_string;
	unsigned test_number;

public:
	static unsigned instances_copied;
	static unsigned instances_created;
	static unsigned instances_moved;
	static unsigned instances_destroyed;

	test_resource(const std::string test_string_ = "test", unsigned test_number_  = 0)
		: test_string(test_string_), test_number(test_number_)
	{
		++instances_created;
	}

	test_resource(const test_resource& rhs)
		: test_string(rhs.test_string), test_number(rhs.test_number)
	{
		++instances_copied;
	}

	test_resource(test_resource&& rhs) noexcept 
		: test_string(std::move(rhs.test_string)), test_number(rhs.test_number)
	{ 
		++instances_moved;
	}

	~test_resource() { --instances_destroyed; }
};

class constructor_operations_test : public ::testing::Test
{
protected:
	void SetUp() override
	{
		test_resource::instances_copied = 0;
		test_resource::instances_created = 0;
		test_resource::instances_moved = 0;
		test_resource::instances_destroyed = 0;
	}
};
