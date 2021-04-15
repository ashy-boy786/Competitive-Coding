/*
	z_function.cpp
*/

#include <bits/stdc++.h>
using namespace std;

int z(int n)
{
	int c { 0 };
	while (n != 0)
		c += n /= 5;
	return c;
}

int main()
{
	int n {};
	cin >> n;

	vector<int> v(n);
	for (auto& e : v)
	{
		int m {};
		cin >> m;
		e = z(m);
	}

	for (auto& e : v)
		cout << e << endl;
}