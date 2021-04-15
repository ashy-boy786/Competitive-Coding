/*
	smartphome.cpp

	This program calculates the maximum revenue
	which can be generated to potential customers.
*/

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

using giant = long long;

giant maxRevenue(vector<giant>& prices)
{
	sort(prices.begin(), prices.end());

	giant maxPrice { 0 };
	giant len = (giant)prices.size();

	for (auto& p : prices)
	{
		giant price { p * len-- };
		if (price > maxPrice) maxPrice = price;
	}
	return maxPrice;
}

int main()
{
	giant n {};
	cin >> n;
	vector<long long> prices(n);

	for (auto& v : prices)
		cin >> v;
	cout << maxRevenue(prices);

	return 0;
}