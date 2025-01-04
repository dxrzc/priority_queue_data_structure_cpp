#include "pch.h"
#include "priority_queue.h"

TEST(pop, should_pop_successfully)
{
	PriorityQueue<unsigned, std::string> test_queue;
	test_queue.push(121, "foo");

	test_queue.pop();

	// no elements remaining
	EXPECT_THROW(test_queue.pop(), std::out_of_range);
}

TEST(pop, should_throw_out_of_range_error_if_queue_empty)
{
	PriorityQueue<unsigned, std::string> test_queue;
	EXPECT_THROW(test_queue.pop(), std::out_of_range);
}

TEST(pop, should_update_size)
{
	PriorityQueue<unsigned, std::string> test_queue;
	test_queue.push(121, "foo");
	test_queue.push(120, "bar");
	test_queue.push(100, "z");

	test_queue.pop();	

	EXPECT_EQ(test_queue.size(), 2);
}

TEST(pop, pop_all_queue_should_be_in_a_correct_state)
{
	PriorityQueue<unsigned, std::string, std::greater> test_queue;
	test_queue.push(121, "foo");
	test_queue.push(120, "bar");

	test_queue.pop();
	test_queue.pop();

	EXPECT_NO_FATAL_FAILURE(test_queue.push(100, "z"));
	EXPECT_NO_FATAL_FAILURE(test_queue.push(101, "x"));
	EXPECT_EQ(test_queue.size(), 2);
	EXPECT_EQ(test_queue.front().second, "z");
	EXPECT_EQ(test_queue.front().first, 100);
}