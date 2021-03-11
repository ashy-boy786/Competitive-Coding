/*
	bill_division.cpp
*/

#include <iostream>
#include <vector>

int main()
{
	int n, k;
	std::cin >> n >> k;

	std::vector<int> bill(n);
	for (auto& b : bill)
		std::cin >> b;

	int bill_paid {};
	std::cin >> bill_paid;

	int sum {};
	for (const auto& b : bill)
		sum += b;

	sum -= bill[k];
	int b_actual { sum / 2 };

	if (b_actual == bill_paid)
		std::cout << "Bon Appetit";
	else
		std::cout << (bill_paid - b_actual); 
}