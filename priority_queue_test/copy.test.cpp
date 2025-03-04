#include "pch.h"
#include "priority_queue.h"
#include "test_resource.helper.h"

TEST(copy_constructor, should_update_nelms)
{
	PriorityQueue<unsigned, std::string, std::greater> pqueue;
	pqueue.push(10, "cat");
	pqueue.push(12, "dog");
	pqueue.push(98, "horse");

	PriorityQueue<unsigned, std::string, std::greater> test_queue = pqueue;

	EXPECT_EQ(test_queue.size(), pqueue.size());
}

TEST_F(constructor_operations_test, should_copy_every_element)
{
	PriorityQueue<unsigned, test_resource, std::greater> pqueue;
	// 3 created
	pqueue.emplace(10, "cat", 0);
	pqueue.emplace(12, "dog", 0);
	pqueue.emplace(98, "horse", 0);

	// 3 created by copy
	PriorityQueue<unsigned, test_resource, std::greater> test_queue = pqueue;

	EXPECT_EQ(test_resource::instances_created, 6);
	EXPECT_EQ(test_resource::instances_copied, 3);
}

TEST(copy_constructor, rhs_queue_is_empty_should_not_cause_failure)
{
	PriorityQueue<unsigned, std::string, std::greater> empty_queue;
	auto test_queue = empty_queue;

	EXPECT_TRUE(test_queue.empty());
	EXPECT_EQ(test_queue.size(), 0);
}