/*
	number_42.cpp

	This program reads numbers and prints them until 
	it encounters the number 42.
*/

#include <iostream>
using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		if (n == 42)
			break;
		cout << n << endl;
	}
}