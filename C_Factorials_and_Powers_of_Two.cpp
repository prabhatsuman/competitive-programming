#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll m = 10e12;
vector<ll> fact;
vector<ll> fact_sum;

void factorial()
{
    ll temp = 6;
    fact.push_back(temp);
    for (int i = 4; i <= 14; i++)
    {
        temp *= i;
        fact.push_back(temp);
    }
}

void solve()
{
    ll n;
    cin >> n;
    int res = INT_MAX;
    ll rem = 0;
    // cout << (1 << 14) << '\n';
    for (ll i = 0; i < (1 << fact.size()); i++)
    {

        ll sum = 0LL;
        int count = 0;
        for (ll j = 0; j < fact.size(); j++)
        {
            if (i & (1 << j))
            {

                sum += fact[j];
                count++;
            }
        }
        if (sum > n)
            continue;
        else
        {
            ll rem = n - sum;

            count += __builtin_popcountll(rem);
            res = min(res, count);
        }
    }
    cout << res << '\n';
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    factorial();

    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
