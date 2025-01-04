#include "pch.h"
#include "priority_queue.h"

TEST(empty, should_return_true_if_queue_has_not_been_used)
{
	PriorityQueue<unsigned, std::string> test_queue;
	EXPECT_TRUE(test_queue.empty());
}

TEST(empty, should_return_true_if_every_element_has_been_deleted)
{
	PriorityQueue<unsigned, std::string> test_queue;
	test_queue.push(120, "bar");
	test_queue.push(120, "bar");

	test_queue.pop();
	test_queue.pop();

	EXPECT_TRUE(test_queue.empty());
}