#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vec = vector<pair<ll, ll>>;

ll gcd(ll a, ll b)
{
    while (b)
    {
        a %= b;
        ll temp = a;
        a = b;
        b = temp;
    }
    return a;
}

ll lcm(ll a, ll b)
{
    return gcd(a, b) ? a / gcd(a, b) * b : 0;
}

int main()
{
    ll t {};
    cin >> t;
    vec input(t);

    for (auto& e : input)
        cin >> e.first >> e.second;

    vec output {};
    
    for (int i = 0; i < t; i++)
    {
        ll a = input[i].first;
        ll b = input[i].second;

        output.push_back({gcd(a, b), lcm(a, b)});
    }

    for (const auto& e : output)
        cout << e.first << " " << e.second << endl;

    return 0;
}