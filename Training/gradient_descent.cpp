/*
	gradient_descent.cpp

	This program shows another efficient
	searching algorithm gradient descent
	which works on sorted arrays and has
	the same time complexity as binary 
	search, O(log n)
*/

#include <iostream>
#include <algorithm>
#include <vector>

std::vector<int> input()
{
	int n;
	std::cout << "Enter number of elements: ";
	std::cin >> n;

	std::vector<int> v(n);

	for (auto& e : v)
	{
		std::cout << "Enter an element: ";
		std::cin >> e;
	}

	return v;
}

int main()
{
	std::vector<int> v { input() };
	std::sort(v.begin(), v.end());

	int val;
	std::cout << "Enter a value to be searched for: ";
	std::cin >> val;

	int pos = 0;
	for (int jump = v.size() / 2; jump >= 1; jump /= 2)
		while (pos + jump < v.size() && v[pos + jump] <= val)
			pos += jump;

	if (v[pos] == val)
		std::cout << "Value exists in array.\n";
	else 
		std::cout << "Value does not exist in array.\n";

	return 0; 
}