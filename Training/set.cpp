/* 
	set.cpp

	This program shows the set data 
	structure. It is based on a balanced
	binary tree with its time complexity as 
	O(log n).

	std::unordered_set is based on a hash map.
	Thus its operations are usually O(1).
*/

#include <iostream>
#include <set>

int main()
{
	std::set<int> s;

	s.insert(3);
	s.insert(2);
	s.insert(5);

	std::cout << s.count(3) << "\n"; // Number of times 3 occurs in set
	std::cout << s.count(4) << "\n"; // 0

	s.erase(3);
	s.insert(4);

	std::cout << "3 occurs: " << s.count(3) << " times"<< "\n";
	std::cout << "4 occurs: " << s.count(4) << " times" << "\n";

	s.insert(4);
	s.insert(4); // Set contains only distinct elements. So repeated additions are useless.

	std::cout << "4 occurs: " << s.count(4) << " times." << "\n";
	std::cout << "Size of set: " << s.size() << "\n";

	// sets cannot be accessed by [] notation
	std::cout << "Elements of set:\n";
	for (const auto x : s)
		std::cout << x << " ";
	std::cout << "\n";

	// Multiset can contain repitions
	std::multiset<int> m = {5, 5, 5, 4, 3, 22, 22};
	std::cout << "In m, 5 occurs: " << m.count(5) << " times.\n";

	std::cout << "Elements of multiset m:\n";
	for (const auto z : m)
		std::cout << z << " ";
	std::cout << "\n";

	s.erase(4); // Removes all instances of 4
	std::cout << "4 occurs: " << s.count(4) << " times.\n";

	m.insert(3);
	m.insert(3);
	m.erase(m.find(3)); // Only one instance removed
	std::cout << "3 occurs: " << m.count(3) << " times.\n";
}