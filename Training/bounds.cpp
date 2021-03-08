/*
	bounds.cpp

	This program demonstrates some bound
	functions in C++.
*/

#include <iostream>
#include <algorithm>
#include <vector>

using vector = std::vector<int>;

vector input()
{
	int n;
	std::cout << "Enter number of elements: ";
	std::cin >> n;

	vector v(n);
	for (auto& e : v)
	{
		std::cout << "Enter a number: ";
		std::cin >> e;
	}
	return v;
}

int main()
{	
	vector v { input() };

	std::sort(v.begin(), v.end());
	int lowest {5};
	int greatest {7};

	auto l = std::lower_bound(v.begin(), v.end(), lowest);
	auto h = std::upper_bound(v.begin(), v.end(), greatest);

	if (l == v.begin() || l == v.end())
		std::cout << "A value with value at least " << lowest << " does not exist.\n";
	else
		std::cout << "First value with value at least " << lowest << ": " << *l << "\n";

	if (h == v.begin() || h == v.end())
		std::cout << "A value with value more than " << greatest << " does not exist.\n";
	else
		std::cout << "First value with value more than to " << greatest << ": " << *h << "\n";

	std::cout << "Enter a value: ";
	int val;
	std::cin >> val;

	auto a = std::lower_bound(v.begin(), v.end(), val);
	auto b = std::upper_bound(v.begin(), v.end(), val);

	std::cout << val << " occurs " << (b - a) << " times in array.\n";

	// This returns both the above pointers in a tuple
	auto r = std::equal_range(v.begin(), v.end(), val);
	std::cout << val << " occurs " << r.second - r.first << " times in array.\n";
}