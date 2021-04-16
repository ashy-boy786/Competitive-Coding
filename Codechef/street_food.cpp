/*
	street_food.cpp
*/

#include <bits/stdc++.h>
using namespace std;

int getProfit(tuple<int, int, int> data)
{
	int s = get<0>(data);
	int v = get<1>(data);
	int p = get<2>(data);
	return (p / s) * v;
}

int main()
{
	int t;
	cin >> t;

	vector<int> prices(t);
	for (auto& pr : prices)
	{
		int n;
		cin >> n;
		vector<tuple<int, int, int>> data(n);
		
		for (auto& d : data)
		{
			int s, v, p;
			cin >> s >> v >> p;
			d = make_tuple(s, v, p);
			pr = max(pr, getProfit(d));
		}
	}

	for (auto& p : prices)
		cout << p << endl;
}