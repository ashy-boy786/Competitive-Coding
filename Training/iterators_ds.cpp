/*
	iterators_ds.cpp

	This program demonstates iterators
	for data structures.
*/

#include <algorithm>
#include <iostream>
#include <vector>
#include <set>

using vector = std::vector<int>;
using set = std::set<int>;

void printVector(const vector& v)
{
	for (const auto& e : v)
		std::cout << e << " ";
	std::cout << "\n\n";
}

void printArray(const int* arr, int n)
{
	auto start = arr;
	auto end = arr + n;
	for (auto i = start; i < end; i++)
		std::cout << *i << " ";
	std::cout << "\n\n";
}

void printSet(const set& s)
{
	for (auto it = s.begin(); it != s.end(); it++)
		std::cout << *it << " ";
	std::cout << "\n\n";
}

int main()
{
	vector v {1, 4, 2, -9};
	std::cout << "Original vector:\n";
	printVector(v);

	std::reverse(v.begin(), v.end());
	std::cout << "After reversing:\n";
	printVector(v);

	std::sort(v.begin(), v.end());
	std::cout << "After sorting:\n";
	printVector(v);

	std::sort(v.rbegin(), v.rend());
	std::cout << "Reverse sorting:\n";
	printVector(v);

	std::random_shuffle(v.begin(), v.end());
	std::cout << "Random shuffle:\n";
	printVector(v);

	std::cout << "These iterators can be used "
			  << "with normal arrays also:\n";

	int n = 4;
	int a[n] {1, 4, 5, 0};

	std::cout << "Original array:\n";
	printArray(a, n);

	std::reverse(a, a + n);
	std::cout << "After reversing:\n";
	printArray(a, n);

	std::sort(a, a + n);
	std::cout << "After sorting:\n";
	printArray(a, n);

	std::random_shuffle(a, a + n);
	std::cout << "Random shuffle:\n";
	printArray(a, n);

	std::cout << "Iterators can also be used with sets:\n";
	set s {5, 6, 0, 2};
	std::cout << "Set: ";
	printSet(s);

	std::cout << "Sets are ordered by default.\n";
	auto it = s.end();
	it--;
	std::cout << "Largest element in the set: " << *it << "\n";

	// The find() function returns a pointer to the value
	// If the value does not exist, it returns end() pointer
	int x = 4;
	it = s.find(x);

	if (it == s.end())
		std::cout << x << " does not exist in set.\n";
	else
		std::cout << x << " exists in set.\n";
}