/*
	lapindrome.cpp

	Inputs n strings, and checks if they 
	are lapindrome.
*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

string isLapindrome(string& s)
{
	int len = (int)s.size();
	string s1 = s.substr(0, len / 2);
	sort(s1.begin(), s1.end());
	string s2 = s.substr(ceil(len / 2.0));
	sort(s2.begin(), s2.end());
	
	for (int i = 0; i < len / 2; i++)
		if (s1[i] != s2[i])
			return "NO";
	return "YES";
}

int main()
{
	int n {};
	cin >> n;
	vector<string> truth_vals {};

	for (int i = 0; i < n; i++)
	{
		string s {};
		cin >> s;
		truth_vals.push_back(isLapindrome(s));
	}

	for (auto& e : truth_vals)
		cout << e << endl;
}