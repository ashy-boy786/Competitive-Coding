/*
    kangaroo_jumps.c

    You are choreographing a circus show with various animals. 
    For one act, you are given two kangaroos on a number line ready 
    to jump in the positive direction (i.e, toward positive infinity).

	The first kangaroo starts at location x1 and moves at a rate of v1 meters per jump.
	The second kangaroo starts at location x2 and moves at a rate of v2 meters per jump.
	You have to figure out a way to get both kangaroos at the same location at the same 
	time as part of the show. If it is possible, return YES, otherwise return NO.
*/

#include <iostream>
#include <math.h>
using namespace std;

void catchup(int x1, int v1, int x2, int v2)
{
	if ((x1 > x2 && v1 >= v2) || (x1 < x2 && v1 =< v2))
	{
		cout << "NO";
		return;
	}	
	
	int x = abs(x1 - x2);
	int v = abs(v1 - v2);

	if (x % v == 0)
		cout << "YES";
	else
		cout << "NO";
	return;
} 

int main()
{
	char line[1000];
	int x1, x2, v1, v2;
	sscanf(gets(line), "%d %d %d %d", &x1, &v1, &x2, &v2);

	catchup(x1, v1, x2, v2);
}