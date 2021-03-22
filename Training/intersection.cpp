/*
	intersection.cpp

	Given two arrays A and B, we should return 
	the number of elements common to both A
	and B.

	For example, A = [5, 2, 8, 9, 4] and B =
	[3, 2, 9, 5] then the answer is 3 because 
	2, 5, 9 are common to A and B.
*/

#include <vector>
#include <set>
#include <unordered_set>
#include <iostream>
#include <algorithm>

using vector = std::vector<int>;
using set = std::set<int>;
using o_set = std::unordered_set<int>;

int solnNaive(const vector& A, const vector& B) // O(n^2)
{
	int count { 0 };

	for (const auto& e1 : A)
	{
		for (const auto& e2 : B)
			if (e1 == e2)
				count++;
	} 
	return count;
}

int soln2(const vector& A, const vector& B) // O(n log n)
{
	// We construct a set of all elements in A
	// and use that to compare.
	// Since time complexity of searching in a set
	// is O(log n) and that of iterating through
	// B is O(n) so total complexity is O(n log n)
	set A_set;
	for (const auto& e : A)
		A_set.insert(e);

	int count { 0 };

	for (const auto& e : B)
		if (A_set.count(e) != 0)
			count++;

	return count;
}

int soln3(const vector& A, const vector& B) // O(n)
{
	// We do not require our set to be ordered, 
	// so we can declare an unordered set.
	// Time complexity of searching in unordered
	// set is O(1) so total is O(n)
	o_set A_set;

	for (const auto& e : A)
		A_set.insert(e);

	int count { 0 };

	for (const auto& e : B)
		if (A_set.count(e) != 0)
			count++;

	return count;
}

int soln4(vector& A, vector& B) // O(n log n)
{
	// We sort the two vectors. That is O (n log n)
	// Now we simultanesously traverse through the array and
	// find common elements. This is O(n log n) as we do a 
	// binary search on one vector with elements of other
	// vector. Since sorting and traversing are independent,
	// we take worst time complexity, so O(n log n)
	int count { 0 };

	std::sort(A.begin(), A.end());
	std::sort(B.begin(), B.end());

	for (const auto& e : A)
		if (std::binary_search(B.begin(), B.end(), e))
			count++;
	return count;
}

vector input(int n)
{
	vector v(n);
	std::cout << "Enter the elements: ";
	for (auto& e : v)
		std::cin >> e;

	return v;
}

int main()
{
	int n1, n2;
	std::cout << "Enter number of elements in A and B: ";
	std::cin >> n1 >> n2;

	vector v1 { input(n1) };
	vector v2 { input(n2) };

	int count { soln4(v1, v2) };
	std::cout << "Vectors v1 and v2 have " << count << " elements in common.\n";
}