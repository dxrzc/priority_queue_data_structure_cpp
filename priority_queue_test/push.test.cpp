#include "pch.h"
#include "priority_queue.h"

TEST(push, should_update_size)
{
	PriorityQueue<unsigned, std::string> testQueue;
	testQueue.push(1, "dog");
	testQueue.push(2, "cat");
	EXPECT_EQ(testQueue.size(), 2);
}

TEST(push, elements_should_be_inserted_in_the_specified_order)
{
	PriorityQueue<unsigned, std::string, std::greater> testQueue;

	const std::string animal_1 = "dog";
	const std::string animal_2 = "cat";
	const std::string animal_3 = "horse";
	const std::string animal_4 = "cow";

	testQueue.push(3, animal_3);
	testQueue.push(1, animal_1);
	testQueue.push(4, animal_4);
	testQueue.push(2, animal_2);
	
	EXPECT_EQ(testQueue.front().second, animal_1);
	testQueue.pop();
	EXPECT_EQ(testQueue.front().second, animal_2);
	testQueue.pop();
	EXPECT_EQ(testQueue.front().second, animal_3);
	testQueue.pop();
	EXPECT_EQ(testQueue.front().second, animal_4);
}