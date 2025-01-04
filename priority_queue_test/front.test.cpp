#include "pch.h"
#include "priority_queue.h"

TEST(front, should_return_a_std_pair_with_key_and_value)
{
	PriorityQueue<unsigned, std::string> test_queue;

	const unsigned key = 120;
	const std::string value = "foo";

	test_queue.push(key, value);

	const std::pair<unsigned, std::string> front_pair = test_queue.front();
	EXPECT_EQ(front_pair.first, key);
	EXPECT_EQ(front_pair.second, value);
}

TEST(front, should_throw_out_of_range_error_if_queue_empty)
{
	PriorityQueue<unsigned, std::string> test_queue;
	EXPECT_THROW(test_queue.front(), std::out_of_range);
}