/*
	laddu.cpp
*/

#include <bits/stdc++.h>
using namespace std;

using num_laddu = int;

num_laddu contest_win(int rank)
{
	int bonus {0};
	if (rank <= 20)
		bonus = 20 - rank;
	return 300 + bonus;
}

int num_months_redeem(num_laddu laddu, string nationality)
{
	if (nationality == "INDIAN")
		return laddu / 200;
	return laddu / 400;
}

num_laddu total_laddu(string activity)
{
	if (activity == "CONTEST_WON")
	{
		int rank;
		cin >> rank;
		return contest_win(rank);
	} 
	else if (activity == "TOP_CONTRIBUTOR")
		return 300;
	else if (activity == "BUG_FOUND")
	{
		int severity;
		cin >> severity;
		return severity;
	}
	return 50;
}

int main()
{
	int t;
	cin >> t;

	vector<int> ans(t);

	for (auto& e : ans)
	{
		int n;
		string nationality {};
		cin >> n >> nationality;
		num_laddu laddu { 0 };

		for (int j = 0; j < n; j++)
		{
			string activity;
			cin >> activity;
			laddu += total_laddu(activity);
		}

		e = num_months_redeem(laddu, nationality);
	}

	for (auto& e : ans)
		cout << e << endl;

	return 0;
}