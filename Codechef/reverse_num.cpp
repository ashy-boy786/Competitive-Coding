/*
	reverse_num.cpp

	Enter n nums and reverse them.
*/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

string reverse_(string& num)
{
	reverse(num.begin(), num.end());
	return num;
}

int main()
{
	int n {};
	cin >> n;
	vector<int> r_nums {};

	for (int i = 0; i < n; i++)
	{
		string num {};
		cin >> num;
		r_nums.push_back(stoi(reverse_(num)));
	}

	for (auto& e : r_nums)
		cout << e << endl;
}