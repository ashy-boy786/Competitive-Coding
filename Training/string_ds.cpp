/*
	string_ds.cpp

	This program shows the string
	datastructure.
*/

#include <iostream>
#include <string>

int main()
{
	std::string a = "hatti";
	std::string b = a + a;
	std::cout << b << "\n";

	b[5] = 'v';
	std::cout << b << "\n";
	
	std::string c = b.substr(3, 4); // substring from position 3 of length 4
	std::cout << c << "\n";
}