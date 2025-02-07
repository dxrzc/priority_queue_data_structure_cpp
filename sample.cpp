#include "priority_queue.h"
#include <utility>

int main()
{
	PriorityQueue<unsigned, std::string, std::greater> pqueue;
	pqueue.push(1, "cat");
	pqueue.push(4, "hamster");
	pqueue.push(2, "dog");
	pqueue.push(5, "parrot");
	pqueue.push(3, "rabbit");
	std::cout << pqueue;
}