#include "priority_queue.h"
#include <utility>

int main()
{
	PriorityQueue<unsigned, std::string, std::greater> pqueue;
	pqueue.push(std::make_pair(10, "cat"));
	pqueue.push(std::make_pair(1, "dog"));
	pqueue.push(std::make_pair(100, "horse"));
	pqueue.push(std::make_pair(0, "cow"));
	std::cout << pqueue;
}