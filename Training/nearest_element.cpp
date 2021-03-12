/*
	nearest_element.cpp

	This program inputs a list and finds
	the element nearest to a given value.
*/

#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using set = std::set<int>;
using vector = std::vector<int>;

set input()
{
	int n {};
	std::cout << "Enter number of elements: ";
	std::cin >> n;

	vector arr(n);
	for (auto& e : arr)
	{
		std::cout << "Enter a number: ";
		std::cin >> e;
	}

	set s {};
	for (const auto& e : arr)
		s.insert(e);

	return s;
}

int nearest_element(set& s, int x)
{
	auto r = std::lower_bound(s.begin(), s.end(), x);

	if (r == s.begin())
		return *r;
	if (r == s.end())
		return *(--r);

	auto a = *r;
	r--;
	auto b = *r;

	if (a == x)
		return x;
	else if (x - b < a - x)
		return b;
	return a;
}

int main()
{
	set s { input() };

	std::cout << "\n";
	for (const auto& x : s)
		std::cout << x << " ";
	std::cout << "\n";

	int val {};
	std::cout << "Enter a value: ";
	std::cin >> val;

	int nearest = nearest_element(s, val);
	std::cout << "Element nearest to " << val << ": " << nearest << "\n.";
}