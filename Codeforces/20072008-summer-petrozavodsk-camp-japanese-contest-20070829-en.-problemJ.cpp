#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vec = vector<tuple<ll, ll, ll, ll>>;

ll gcd(ll a, ll b)
{
    ll x = 1, y = 0;
    ll x1 = 0, y1 = 1, a1 = a, b1 = b;
    while (b1)
    {
        ll q = a1 / b1;
        tie(x, x1) = make_tuple(x1, x - q * x1);
        tie(y, y1) = make_tuple(y1, y - q * y1);
        tie(a1, b1) = make_tuple(b1, a1 - q * b1);
    }
    return a1;
}

string findSoln(ll m, ll n, ll a, ll k)
{
    ll x = 1, y = 0;
    ll g = gcd(m, a);
    if ((k - n) % g)
        return "Impossible";

    ll m1 = m;
    while (true)
    {
        if ((k - n - m) % a)
        {
            m1 = m;
            m += m1;
        }
        else
            break;
    }

    return to_string(n + m);
}

int main()
{
    vec input {};
    ll n {}, m {}, a {}, k {};
    while (true)
    {
        cin >> n >> m >> a >> k;
        if (n == 0 && m == 0 && a == 0 && k == 0)
            break;
        input.push_back(make_tuple(n, m, a, k));
    }

    vector<string> output {};
    for (ll i = 0; i < input.size(); i++)
        output.push_back(findSoln(get<0>(input[i]), get<1>(input[i]), 
                            get<2>(input[i]), get<3>(input[i])));

    for (const auto& e : output)
        cout << e << endl;
}