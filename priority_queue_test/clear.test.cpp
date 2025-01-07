#include "pch.h"
#include "test_resource.helper.h"
#include "priority_queue.h"

TEST_F(constructor_operations_test, clear_should_delete_every_element)
{
	PriorityQueue<unsigned, test_resource, std::less> test_queue;
	// test resources constructed directly in queue
	test_queue.emplace(0, "test_resource_1", 0);
	test_queue.emplace(1, "test_resource_1", 1);
	test_queue.emplace(2, "test_resource_1", 2);

	test_queue.clear();

	EXPECT_EQ(test_resource::instances_destroyed, 3);
}

TEST(clear, should_return_queue_to_its_initial_state)
{
	PriorityQueue<unsigned, char, std::less> test_queue;	
	test_queue.emplace(0, 'a');
	test_queue.emplace(1, 'a');
	test_queue.emplace(2, 'a');

	test_queue.clear();

	EXPECT_EQ(test_queue.size(), 0);	
	EXPECT_TRUE(test_queue.empty());	
}

TEST(clear, can_add_elements_after_call_clear)
{
	PriorityQueue<unsigned, char, std::less> test_queue;
	test_queue.emplace(0, 'a');
	test_queue.emplace(1, 'a');
	test_queue.emplace(2, 'a');

	test_queue.clear();

	EXPECT_NO_FATAL_FAILURE(test_queue.emplace(1, 'a'));
}

TEST(clear, should_not_throw_if_queue_empty)
{
	PriorityQueue<unsigned, char, std::less> test_queue;
	EXPECT_NO_FATAL_FAILURE(test_queue.clear());
}