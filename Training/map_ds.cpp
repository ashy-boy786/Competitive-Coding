/*
	map_ds.cpp

	This program shows the map
	datastructure in C++.
	
	map is like Python dictonary it has key, val
	map - O(log n)
	unordered_map - O(1)
*/

#include <iostream>
#include <string>
#include <map>

int main()
{
	std::map<std::string, int> m;
	m["monkey"] = 4;
	m["banana"] = 3;
	m["harpsichord"] = 9;

	std::cout << m["banana"] << "\n"; 

	for (const auto e : m)
		std::cout << e.first << ": " << e.second << "\n";
	
	// The count() function checks if a key exists in a map
	std::string key = "banana";

	if (m.count(key))
		std::cout << key << " key exists.\n";
	else
		std::cout << key << " key does not exist.\n";

	key = "apple";
	if (m.count(key))
		std::cout << key << " key exists.\n";
	else
		std::cout << key << " key does not exist.\n";
}