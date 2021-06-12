#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll MAX = 10000007;

using in_vec = vector<pair<ll, ll>>;

ll pow_mod(ll a, ll b)
{
    ll p = 1;
    while (b > 0)
    {
        if (b & 1)
            p = (p * a) % MAX;
        a = (a * a) % MAX;
        b >>= 1;
    }
    return p;
}

ll z(ll n, ll k)
{
    ll p1 = (pow_mod(n, k) + pow_mod(n, n)) % MAX;
    ll p2 = (2 * (pow_mod(n - 1, k) + pow_mod(n - 1, n - 1))) % MAX;
    return (p1 + p2) % MAX; 
}

int main()
{
    in_vec input {};
    ll n, k;

    do
    {
        cin >> n >> k;
        if (n == 0 && k == 0)
            break;
        input.push_back({n, k});
    } while (true);
    
    vector<ll> output {};
    for (ll i = 0; i < input.size(); i++)
        output.push_back(z(input[i].first, input[i].second));
    
    for (const auto& e : output)
        cout << e << endl;
}
