/*
	sales_by_match.cpp
*/

#include <iostream>
#include <vector>
#include <algorithm>

int num_pairs(const std::vector<int>& ar)
{
	int pairs {0};
	int last_index {0};
	for (int i = 0; i < (int)ar.size(); i++)
	{
		if (i > 0 && ar[i - 1] != ar[i])
		{
			pairs += (i - last_index) / 2;
			last_index = i;
		}
		if (i == (int)ar.size() - 1)
			pairs += (i + 1 - last_index) / 2;
	}
	return pairs;
}

int main()
{
	int n;
	std::cin >> n;

	std::vector<int> color_socks(n);
	for (auto& c : color_socks)
		std::cin >> c;

	std::sort(color_socks.begin(), color_socks.end());

	std::cout << num_pairs(color_socks); 
}