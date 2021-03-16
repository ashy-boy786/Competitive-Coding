/*
	deque_ds.cpp

	This program demonstrates the 
	deque datastructure.
*/

#include <deque>
#include <iostream>

using deque = std::deque<int>;

void printDeck(const deque& d)
{
	std::cout << "Deque: ";
	for (const auto& e : d)
		std::cout << e << " ";
	std::cout << "\n";
}

int main()
{
	// A deque is just like a vector, but can be resized
	// from both sides.
	deque d;

	d.push_back(1);
	printDeck(d);

	d.push_front(5);
	printDeck(d);

	d.push_back(2);
	printDeck(d);

	d.pop_front();
	printDeck(d);

	d.pop_back();
	printDeck(d);

	std::cout << d[0] << "\n";
}