/*
	vector_ds.cpp

	This program shows the vector data
	structure in C++.
*/

#include <iostream>
#include <vector>

using vector = std::vector<int>;

void printVector(const vector& v)
{
	for (const auto& e : v)
		std::cout << e << " ";
	std::cout << "\n";
}

int main()
{
	vector v;
	v.push_back(3); // [3]
	v.push_back(2); // [3, 2]
	v.push_back(5); // [3, 2, 5]

	printVector(v);
}