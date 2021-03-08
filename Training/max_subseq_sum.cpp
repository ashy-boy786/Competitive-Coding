/* 
	max_subseq_sum.cpp

	Calculates the maximum possible sum of 
	a subsequence in an array.
*/

#include <iostream>
#include <ctime>

double getTime()
{
	return (double)std::time(nullptr);
}

int sum_naive(int* arr, int n) // Time complexity = O(n^3)
{
	int best {0};
	for (int a = 0; a < n; a++)
	{
		for (int b = a; b < n; b++)
		{
			int sum = 0;
			for (int k = a; k <= b; k++)
				sum += arr[k];
			best = std::max(best, sum);
		}
	}
	return best;
}

int sum(int* arr, int n) // Time complexity = O(n^2)
{
	int best{0};
	for (int a = 0; a < n; a++)
	{
		int sum = 0;
		for (int b = a; b < n; b++)
		{
			sum += arr[b];
			best = std::max(best, sum);
		}
	}
	return best;
}

int sum_swag(int* arr, int n)
{
	int best {0}, sum {0};
	for (int k = 0; k < n; k++)
	{
		sum = std::max(arr[k], sum + arr[k]);
		best = std::max(sum, best);
	}
	return best;
}

int main()
{
	int n {};
	std::cout << "Enter length of array: ";
	std::cin >> n;

	int a[n] {};

	for (int i = 0; i < n; i++)
	{
		std::cout << "Enter a number: ";
		std::cin >> a[i];
	}

	double then = getTime();
	int best { sum_swag(a, n) };
	double now = getTime();
	std::cout << "Maximum sum of subsequence = " << best << ".\n";
	std::cout << "Took " << now - then << " seconds.";
}