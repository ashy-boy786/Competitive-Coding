/*
	between_two_sets.cpp

	There will be two arrays of integers. Determine all integers that satisfy the following two conditions:

	1. The elements of the first array are all factors of the integer being considered
	2. The integer being considered is a factor of all elements of the second array

	These numbers are referred to as being between the two arrays. Determine how many such numbers exist.
*/

#include <iostream>

int gcf(int a, int b)
{
	int min = a;
	int max = b;
	if (a > b)
	{
		min = b;
		max = a;
	}

	for (int i = min; i >= 1; i--)
		if (max % i == 0 && min % i == 0)
			return i;
	return 1;
}

int hcf_ar(const int* arr, int n)
{
	int h { arr[0] };
	for (int i = 1; i < n; i++)
	{
		h = gcf(h, arr[i]);
		if (h == 1) return 1;
	}

	return h;
}

int lcm(int a, int b)
{
	return a * b / gcf(a, b);
}

int lcm_ar(const int* arr, int n)
{
	int l { arr[0] };
	for (int i = 1; i < n; i++)
		l = lcm(l, arr[i]);
	return l;
}

int num(int gcf, int lcm)
{
	int count {0};
	if (gcf % lcm != 0)
		return 0;

	gcf /= lcm;
	for (int i = 1; i * i <= gcf; i++)
	{
		if (gcf % i == 0)
		{
			count++;
			if (i * i != gcf)
				count++;
		}
	}
	return count;
}

int main()
{
	int n, m;
	std::cin >> n >> m;

	int a[n], b[m];
	for (int i = 0; i < n; i++)
		std::cin >> a[i];

	for (int i = 0; i < m; i++)
		std::cin >> b[i];

	int gcf { hcf_ar(b, m) };
	int lcm { lcm_ar(a, n) };

	std::cout << num(gcf, lcm);
}