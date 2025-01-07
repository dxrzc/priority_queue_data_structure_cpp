#include "pch.h"
#include "test_resource.helper.h"
#include "priority_queue.h"

TEST(emplace, should_update_size)
{
	PriorityQueue<unsigned, std::string> test_queue;
	test_queue.emplace(0, "hello world");
	test_queue.emplace(1, "hello world!");

	EXPECT_EQ(test_queue.size(), 2);
}

TEST(emplace, elements_should_be_inserted_in_the_specified_order)
{
	PriorityQueue<unsigned, std::string, std::greater> testQueue;

	const std::string animal_1 = "dog";
	const std::string animal_2 = "cat";
	const std::string animal_3 = "horse";
	const std::string animal_4 = "cow";

	testQueue.emplace(3, animal_3);
	testQueue.emplace(1, animal_1);
	testQueue.emplace(4, animal_4);
	testQueue.emplace(2, animal_2);

	EXPECT_EQ(testQueue.front().second, animal_1);
	testQueue.pop();
	EXPECT_EQ(testQueue.front().second, animal_2);
	testQueue.pop();
	EXPECT_EQ(testQueue.front().second, animal_3);
	testQueue.pop();
	EXPECT_EQ(testQueue.front().second, animal_4);
}

TEST(emplace, should_be_successfully_inserted)
{
	PriorityQueue<unsigned, test_resource> test_queue;

	const unsigned key = 0;
	const std::string test_resource_arg1 = "foo";
	const unsigned test_resource_arg2 = 100;

	test_queue.emplace(key, test_resource_arg1, test_resource_arg2);

	const std::pair<unsigned, test_resource> pair_inserted = test_queue.front();
	EXPECT_EQ(pair_inserted.first, key);
	EXPECT_EQ(pair_inserted.second.get_test_string(), test_resource_arg1);
	EXPECT_EQ(pair_inserted.second.get_test_number(), test_resource_arg2);
}

TEST_F(constructor_operations_test, should_not_make_copies)
{
	PriorityQueue<unsigned, test_resource> test_queue;
	test_queue.emplace(0, "ten", 10);
	test_queue.emplace(2, "four", 4);
	test_queue.emplace(3, "nine", 9);

	EXPECT_EQ(test_resource::instances_created, 3);
	EXPECT_EQ(test_resource::instances_moved, 0);
	EXPECT_EQ(test_resource::instances_copied, 0);
}