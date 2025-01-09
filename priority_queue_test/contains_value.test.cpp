#include "pch.h"
#include "priority_queue.h"

TEST(contains_value, should_return_true_if_queue_contains_the_value)
{
	const std::string value = "hello world";

	PriorityQueue<unsigned, std::string> test_queue;
	test_queue.push(0, "cat");
	test_queue.push(3, "dog");
	test_queue.push(9, value);

	EXPECT_TRUE(test_queue.contains_value(value));
}

TEST(contains_value, should_return_false_if_queue_does_not_contain_the_value)
{
	const std::string value = "hello world";

	PriorityQueue<unsigned, std::string> test_queue;
	test_queue.push(0, "cat");
	test_queue.push(3, "dog");

	EXPECT_FALSE(test_queue.contains_value(value));
}

TEST(contains_value, should_return_false_if_queue_empty)
{
	const std::string value = "hello world";
	PriorityQueue<unsigned, std::string> test_queue;
	EXPECT_FALSE(test_queue.contains_value(value));
}