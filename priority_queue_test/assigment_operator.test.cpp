#include "pch.h"
#include "test_resource.helper.h"
#include "priority_queue.h"

TEST_F(constructor_operations_test, assigment_operator_should_clear_queue_before_assign)
{
	PriorityQueue<unsigned, test_resource> test_queue;

	PriorityQueue<unsigned, test_resource> new_queue;
	// 2 created in queue
	new_queue.emplace(0, "test", 0);
	new_queue.emplace(0, "test", 0);

	// 2 destroyed before assign
	new_queue = test_queue;

	EXPECT_EQ(test_resource::instances_created, 2);
	EXPECT_EQ(test_resource::instances_destroyed, 2);
}

TEST(assigment_operator, should_update_size)
{
	PriorityQueue<unsigned, char> test_queue;
	test_queue.emplace(0, 'a');
	test_queue.emplace(0, 'z');
	const auto test_queue_size = test_queue.size();

	PriorityQueue<unsigned, char> another_queue;

	another_queue = test_queue;

	EXPECT_EQ(another_queue.size(), test_queue_size);
}