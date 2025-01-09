#include "pch.h"
#include "priority_queue.h"

TEST(contains_key, should_return_true_if_queue_contains_the_key)
{
	const unsigned key = 100;

	PriorityQueue<unsigned, char> test_queue;
	test_queue.push(0, 'a');
	test_queue.push(key, 'z');
	test_queue.push(1, 'b');
	test_queue.push(2, 'c');

	EXPECT_TRUE(test_queue.contains_key(key));
}

TEST(contains_key, should_return_false_if_queue_contains_the_key)
{
	const unsigned key = 100;

	PriorityQueue<unsigned, char> test_queue;
	test_queue.push(0, 'a');	
	test_queue.push(1, 'b');
	test_queue.push(2, 'c');

	EXPECT_FALSE(test_queue.contains_key(key));
}

TEST(contains_key, should_return_false_if_queue_empty)
{
	const unsigned key = 100;
	PriorityQueue<unsigned, char> test_queue;
	EXPECT_FALSE(test_queue.contains_key(key));
}