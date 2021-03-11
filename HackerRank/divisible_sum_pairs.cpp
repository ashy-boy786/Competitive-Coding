/*
	divisible_sum_pairs.cpp

	Data can be found in Divisible Sum Pairs.mom
*/

#include <iostream>

int choose(int n, int k)
{
	if (n < 0 || k < 0)
		return 0;
	else if (n < k)
		return 0;
	
	// we need only nC1 and nC2 actually
	if (k == 1)
		return n;
	return n * (n - 1) / 2;
}

int calculate(int* arr, int n, int k)
{
	int rem[k] {}; // All numbers modulo k initialized to 0

	for (int i = 0; i < n; i++)
	{
		int val = arr[i] % k;
		rem[val]++;
	}
	// Eg if arr = [1, 2, 3, 4, 5, 6], k = 3
	// rem[3] = {0, 0, 0} initially
	// rem[0] = 2 {3, 6}
	// rem[1] = 2 {1, 5}
	// rem[2] = 2 {2, 5}
	// rem = {2, 2, 2} finally

	int v1 = k / 2 - 1;
	int sum { choose(rem[0], 2) };
	for (int i = 1; i <= v1; i++)
		sum += choose(rem[i], 1) * choose(rem[k - i], 1);

	if (k % 2 == 0)
		sum += choose(rem[k/2], 2);
	else
		sum += choose(rem[(k-1)/2], 1) * choose(rem[(k+1)/2], 1);
	return sum;
}

int main()
{
	int n, k;
	std::cin >> n >> k;
	int arr[n];

	for (int i = 0; i < n; i++)
		std::cin >> arr[i];

	std::cout << calculate(arr, n, k);
}