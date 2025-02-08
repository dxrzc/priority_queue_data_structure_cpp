# Priority Queue Data Structure

Low level priority queue data structure in c++ (.sln)

## Features

### Custom Comparison
- The comparison function can be customized by providing a different template argument for CMP

### Deep Copy and Move Semantics
-	The class supports deep copying through a copy constructor and copy assignment operator.
-	Move semantics are also supported with a move constructor and move assignment operator.

### Insertion Methods
- emplace: Constructs the value directly on the queue
- push: Overloaded to support both lvalue and rvalue references for the value.

### Element Removal
- pop: Removes the element with the highest priority (based on the comparison function).

### Utility Methods
- clear: Removes all elements from the queue.
- front: Returns the element with the highest priority without removing it.
-	size: Returns the number of elements in the queue.
-	empty: Checks if the queue is empty.
-	swap: Swaps the contents of two priority queues.
-	operator==: Compares two priority queues for equality.
-	contains_value: Checks if a value exists in the queue.
-	contains_key: Checks if a key exists in the queue.
-	get_all_keys: Returns a vector of all keys in the queue.
-	get_all_values: Returns a vector of all values in the queue.

### Stream Output
- Overloaded operator<< to print the contents of the priority queue to an output stream
