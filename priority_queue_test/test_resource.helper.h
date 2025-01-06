#pragma once

#include "pch.h"

class test_resource
{
public:
	static unsigned instances_copied;
	static unsigned instances_created;
	static unsigned instances_moved;
	static unsigned instances_destroyed;

	test_resource() { ++instances_created; }
	test_resource(const test_resource& rhs) { ++instances_copied; }
	test_resource(test_resource&& rhs) noexcept { ++instances_moved; }
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
