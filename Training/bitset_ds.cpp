/*
	bitset_ds.cpp

	This program introduces the data structure
	bitset.
*/

#include <bitset>
#include <iostream>
#include <string>

using bitset = std::bitset<10>;

int main()
{
	bitset s;
	std::cout << "Before: " << s << "\n";

	s[0] = s[5] = s[8] = 1;
	std::cout << "After: " << s << "\n";

	bitset s2  { std::string("0010011010") };
	std::cout << "s2: " << s2 << "\n";

	std::cout << "~s | s2: " << (~s | s2) << "\n";
	std::cout << "s & s2: " << (s & s2) << "\n";
	std::cout << "s XOR s2: " << (s ^ s2) << "\n";

	std::cout << "No. of one's in s: " << s.count() << "\n";
}