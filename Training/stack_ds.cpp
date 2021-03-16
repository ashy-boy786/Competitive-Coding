/*
	stack_ds.cpp

	This program demonstrates the stack data
	structure.
*/

#include <stack>
#include <iostream>

using stack = std::stack<int>;

int main()
{
	// A stack provides two O(1) operations:
	// Adding an element to top
	// Removing an element from top
	// Can only access top no other members

	stack s;
	s.push(3);
	std::cout << s.top() << "\n";

	s.push(5);
	s.push(2);
	std::cout << s.top() << "\n";
	s.pop();

	std::cout << s.top() << "\n";

	// A queue works simiarly. It is for the last element instead of
	// first element 
}