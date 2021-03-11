/*
	breaking_records.cpp
*/

#include <iostream>

int main()
{
	int n {};
	std::cin >> n;

	int scores[n] {};
	for (int i = 0; i < n; i++)
		std::cin >> scores[i];

	int max {0}, min {0};
	int max_score {scores[0]}, min_score {scores[0]};

	for (int i = 1; i < n; i++)
	{
		if (scores[i] > max_score)
		{
			max_score = scores[i];
			max++;
		}
		if (scores[i] < min_score)
		{
			min_score = scores[i];
			min++;
		}
	}

	std::cout << max << " " << min;
}