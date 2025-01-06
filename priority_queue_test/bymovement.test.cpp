#include "pch.h"
#include "priority_queue.h"
#include "test_resource.helper.h"

TEST(constructor_by_movement, rhs_queue_head_should_remain_null_and_size_0)
{
	PriorityQueue<unsigned, std::string> test_queue;
	test_queue.push(120, "bar");
	test_queue.push(121, "foo");

	auto new_queue(std::move(test_queue));

	EXPECT_TRUE(test_queue.empty());
	EXPECT_EQ(test_queue.size(), 0);
}

TEST(constructor_by_movement, queue_should_contain_rhs_elements)
{
	PriorityQueue<unsigned, std::string, std::less> test_queue;
	test_queue.push(120, "bar");
	test_queue.push(121, "foo");

	auto new_queue(std::move(test_queue));

	EXPECT_EQ(new_queue.front().second, "foo");
	new_queue.pop();
	EXPECT_EQ(new_queue.front().second, "bar");
}

TEST(constructor_by_movement, size_should_be_updated)
{
	PriorityQueue<unsigned, std::string> test_queue;
	test_queue.push(120, "bar");
	test_queue.push(121, "foo");

	auto new_queue(std::move(test_queue));

	EXPECT_EQ(new_queue.size(), 2);
}

TEST_F(constructor_operations_test, movement_constructor_should_not_make_copies_or_move_elements)
{
	// 3 instances created
	test_resource resource_1;
	test_resource resource_2;
	test_resource resource_3;

	PriorityQueue<unsigned, test_resource> test_queue;	
	// 3 instances copied
	test_queue.push(120, resource_1);
	test_queue.push(121, resource_2);
	test_queue.push(122, resource_3);

	// queue "moved", pointers are reassigned
	auto new_queue(std::move(test_queue));

	EXPECT_EQ(test_resource::instances_created, 3);
	EXPECT_EQ(test_resource::instances_copied, 3);
	EXPECT_EQ(test_resource::instances_moved, 0);
}
