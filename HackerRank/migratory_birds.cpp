#include <iostream>
#include <algorithm>
#include <vector>

int index(const std::vector<int>& arr, const int& val, bool first)
{
	int start {0};
	int end { (int)arr.size() };
	int n { end };

	while (start <= end)
	{
		int m { (start + end) / 2 };
		if (!first && m < end - 1) m++;
		m %= n;
		
		if (val == arr[m])
		{
			int s { (m - 1) % n };
			if (s < 0) s = n + s;

			int e { (m + 1) % n };

			if (first && arr[s] == val)
				end = s;
			else if (!first && arr[e] == val)
				start = e;
			else
				return m;
		}
		else if (val < arr[m])
			end = m - 1;
		else
			start = m + 1;
	}
	return 0;
}

int freq(const std::vector<int>& arr, const int& val)
{
	int first_index { index(arr, val, true) };
	int last_index { index(arr, val, false) };

	if (first_index == (int)arr.size() - 1)
		return 1;
	if (last_index == 0)
		return 1;

	return (last_index - first_index + 1);
}

int max(std::vector<int> ar, int n)
{
	int index {0};
	for (int i = 0; i < n; i++)
	{
		if (ar[i] > ar[index])
			index = i;
	}
	return index + 1;
}

int main()
{
	int n {};
	std::cin >> n;

	std::vector<int> arr(n);
	for (auto& a : arr)
		std::cin >> a;

	std::sort(arr.begin(), arr.end());
	/*for (const auto& e : arr)
		std::cout << e << " ";
	std::cout << "\n";*/

	std::vector<int> f(arr[n - 1]);
	for (int i = 0; i < arr[n-1]; i++)
		f[i] = freq(arr, i + 1);

	std::cout << max(f, arr[n - 1]);
}