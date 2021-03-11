/*
	electronics_shop.cpp
*/

#include <algorithm>
#include <iostream>
#include <vector>

using prices = std::vector<int>;

prices getPrice(int n)
{
	prices arr(n);

	for (auto& p : arr)
		std::cin >> p;
	return arr;
}

int priceBuying(const prices& keyboard, const prices& drives, const int budget)
{
	int best_price {-1};
	for (const auto& k_price : keyboard)
	{
		if (k_price >= budget)
			continue;
		int rem = budget - k_price;
		for (const auto& d_price : drives)
		{
			if (d_price > rem)
				continue;

			if (k_price == rem)
				return budget;
			else
				best_price = std::max(best_price, d_price + k_price);
		}
	}
	return best_price;
}

int main()
{
	int b, n, m;
	// b = budget
	// n = number of keyboard models
	// m = number of USB models

	std::cin >> b >> n >> m;
	prices keyboard { getPrice(n) };
	prices drives { getPrice(m) };

	std::sort(keyboard.rbegin(), keyboard.rend());
	std::sort(drives.rbegin(), drives.rend());

	std::cout << priceBuying(keyboard, drives, b);
}