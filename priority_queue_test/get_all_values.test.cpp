#include "pch.h"
#include "priority_queue.h"

TEST(get_all_values, should_return_values_successfully)
{
	PriorityQueue<unsigned, std::string, std::greater> pqueue;
	pqueue.push(10, "cat");
	pqueue.push(1, "dog");
	pqueue.push(100, "horse");
	pqueue.push(0, "cow");
	auto values_vector = pqueue.get_all_values();
	ASSERT_EQ(values_vector.size(), 4);
	EXPECT_EQ(values_vector[3], "horse");
	EXPECT_EQ(values_vector[2], "cat");
	EXPECT_EQ(values_vector[1], "dog");
	EXPECT_EQ(values_vector[0], "cow");
}

TEST(get_all_values, should_return_empty_vector_if_queue_empty)
{
	PriorityQueue<unsigned, std::string, std::greater> pqueue;
	auto values_vector = pqueue.get_all_values();
	ASSERT_TRUE(values_vector.empty());
}