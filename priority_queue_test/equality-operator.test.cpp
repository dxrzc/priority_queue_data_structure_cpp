#include "pch.h"
#include "test_resource.helper.h"
#include "priority_queue.h"

TEST(equality_operator, should_return_true_if_size_and_values_are_equal)
{
	PriorityQueue<unsigned, std::string> test_queue;
	test_queue.push(0, "test1");
	test_queue.push(2, "test2");

	PriorityQueue<unsigned, std::string> another_queue;
	another_queue.push(0, "test1");
	another_queue.push(2, "test2");

	EXPECT_TRUE(test_queue == another_queue);
}

TEST(equality_operator, should_return_false_if_size_is_not_equal)
{
	PriorityQueue<unsigned, std::string> test_queue;
	test_queue.push(0, "test1");
	test_queue.push(2, "test2");

	PriorityQueue<unsigned, std::string> another_queue;
	another_queue.push(0, "test1");
	another_queue.push(2, "test2");
	another_queue.push(4, "test3");

	EXPECT_FALSE(test_queue == another_queue);
}

TEST(equality_operator, should_return_false_if_values_are_not_equal)
{
	PriorityQueue<unsigned, std::string> test_queue;
	test_queue.push(0, "test1");
	test_queue.push(2, "test2");

	PriorityQueue<unsigned, std::string> another_queue;
	another_queue.push(0, "test1");
	another_queue.push(2, "a different value");	

	EXPECT_FALSE(test_queue == another_queue);
}

TEST(equality_operator, should_return_false_if_keys_are_not_equal)
{
	PriorityQueue<unsigned, std::string> test_queue;
	test_queue.push(0, "test1");
	test_queue.push(2, "test2");

	PriorityQueue<unsigned, std::string> another_queue;
	another_queue.push(0, "test1");
	another_queue.push(200000000000000000, "test2");

	EXPECT_FALSE(test_queue == another_queue);
}

TEST(equality_operator, should_return_true_if_queues_are_empty)
{
	PriorityQueue<unsigned, std::string> empty_queue_1;
	PriorityQueue<unsigned, std::string> empty_queue_2;

	EXPECT_TRUE(empty_queue_1 == empty_queue_2);
}