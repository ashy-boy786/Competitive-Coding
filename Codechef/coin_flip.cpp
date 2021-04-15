/*
	coin_flip.cpp
*/

#include <bits/stdc++.h>
using namespace std;

int num_(int initial, int num_games, int q)
{
	if (initial == q)
		return num_games / 2;
	return ceil(num_games / 2.0);
}

int main()
{
	int t {};
	cin >> t;

	vector<int> ans;
	for (int i = 0; i < t; i++)
	{
		int g {};
		cin >> g;

		for (int j = 0; j < g; j++)
		{
			int initial, num_games, q;
			cin >> initial >> num_games >> q;
			ans.push_back(num_(initial, num_games, q));
		}
	}

	for (auto& e : ans)
		cout << e << endl;
}