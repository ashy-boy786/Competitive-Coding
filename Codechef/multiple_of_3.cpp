/*
	multiple_of_3.cpp
*/

#include <bits/stdc++.h>
using namespace std;

using huge = long long;

huge sum_digits(huge num_digits, huge d0, huge d1)
{
	huge sum { d0 + d1 };
	if (num_digits <= 3)
		return sum;

	vector<huge> digits;
	digits.push_back((d0 + d1) % 10);
	sum += digits[0];

	for (huge i = 1; i < num_digits - 2; i++)
	{
		huge d = (2 * digits[i - 1]) % 10;

		auto it = find(digits.begin(), digits.end(), d);

		if (it == digits.end())
		{
			digits.push_back(d);
			sum += digits[i];
		}
		else
		{
			huge d_sum = accumulate(it, digits.end(), 0);

			huge rem = num_digits - i - 2;
			huge length = digits.end() - it;

			sum += d_sum * (rem / length);

			for (auto j = it; j != it + rem % length; j++)
				sum += *j;
			break;
		}
	}
	return sum;
}

string is_divisible_by_3(huge k, huge d0, huge d1)
{
	if (sum_digits(k, d0, d1) % 3 == 0)
		return "YES";
	return "NO"; 
}

int main()
{
	huge t {};
	cin >> t;

	vector<string> ans(t);
	for (auto& e : ans)
	{
		huge k, d0, d1;
		cin >> k >> d0 >> d1;
		e = is_divisible_by_3(k, d0, d1);
	}

	for (auto& e : ans)
		cout << e << endl;
}