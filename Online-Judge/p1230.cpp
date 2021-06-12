#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vt = vector<tuple<ll, ll, ll>>;

ll binpowmod(ll a, ll b, ll n)
{
    ll p = 1;
    while (b > 0)
    {
        if (b & 1)
            p = (p * a) % n;
        a = (a * a) % n;
        b >>= 1;
    }
    return p;
}

int main()
{
    ll num {};
    cin >> num;

    vt input(num);
    for (auto& e : input)
        cin >> get<0>(e) >> get<1>(e) >> get<2>(e);
    ll end {};
    cin >> end;

    vector<ll> output(num);
    for (ll i = 0; i < num; i++)
        output[i] = binpowmod(get<0>(input[i]), get<1>(input[i]), get<2>(input[i]));
    
    for (const auto& e : output)
        cout << e << endl;
}