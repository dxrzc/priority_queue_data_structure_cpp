#include "pch.h"
#include "test_resource.helper.h"
#include "priority_queue.h"

TEST(swap, should_update_nelms)
{
	PriorityQueue<unsigned, char> test_queue_1;
	test_queue_1.push(0, 'a');
	test_queue_1.push(1, 'b');
	test_queue_1.push(2, 'c');
	const std::size_t queue1_size = test_queue_1.size();

	PriorityQueue<unsigned, char> test_queue_2;
	test_queue_2.push(0, 'z');
	test_queue_2.push(1, 'x');
	const std::size_t queue2_size = test_queue_2.size();

	test_queue_1.swap(test_queue_2);

	EXPECT_EQ(test_queue_1.size(), queue2_size);
	EXPECT_EQ(test_queue_2.size(), queue1_size);
}

TEST(swap, should_swap_elements_successfully)
{
	const unsigned queue1_key = 9;
	const char queue1_value = 'x';
	PriorityQueue<unsigned, char> test_queue_1;
	test_queue_1.push(queue1_key, queue1_value);

	const unsigned queue2_key = 11;
	const char queue2_value = 'z';
	PriorityQueue<unsigned, char> test_queue_2;
	test_queue_2.push(queue2_key, queue2_value);

	// swap
	test_queue_1.swap(test_queue_2);

	EXPECT_EQ(test_queue_1.front().first, queue2_key);
	EXPECT_EQ(test_queue_1.front().second, queue2_value);

	EXPECT_EQ(test_queue_2.front().first, queue1_key);
	EXPECT_EQ(test_queue_2.front().second, queue1_value);
}