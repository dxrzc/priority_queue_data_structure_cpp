#include "pch.h"
#include "priority_queue.h"

TEST(get_all_keys, should_return_the_keys_successfully)
{
	PriorityQueue<unsigned, std::string, std::greater> pqueue;
	pqueue.push(10, "cat");
	pqueue.push(1, "dog");
	pqueue.push(100, "horse");
	pqueue.push(0, "cow");

	auto keys_vector = pqueue.get_all_keys();

	ASSERT_EQ(keys_vector.size(), 4);
	EXPECT_EQ(keys_vector[3], 100);
	EXPECT_EQ(keys_vector[2], 10);
	EXPECT_EQ(keys_vector[1], 1);
	EXPECT_EQ(keys_vector[0], 0);
}

TEST(get_all_keys, should_return_empty_vector_if_queue_empty)
{
	PriorityQueue<unsigned, std::string, std::greater> pqueue;
	auto keys_vector = pqueue.get_all_keys();
	ASSERT_TRUE(keys_vector.empty());
}